#include <iostream>
#include "utile.h"
#include "db.h"

using namespace std;

int main()
{
    vector<vector<string>> csvTab;
    if (!Utile::saveCSVFileByLine("res/gares.csv", csvTab))
    {
        cout << "CSV to vector : not ok" << endl;
        return 0;
    }

    cout << "CSV to vector : ok" << endl;

    DB bdd;

    Entity codeP("CodePostal");
    codeP.addProperty(Property("Idcodepostal", ValueType::integer, Value(0), true));
    codeP.addProperty(Property("Numcodepostal", ValueType::integer));

    Entity dep("Departement");
    dep.addProperty(Property("Iddepartement", ValueType::integer, Value(0), true));
    dep.addProperty(Property("Numdepartement", ValueType::integer));
//    dep.addProperty(Property("Nomdepartement", ValueType::str)); /* Not in csv */

    Entity gare("Gare");
    gare.addProperty(Property("Idgare", ValueType::integer, Value(0), true));
    gare.addProperty(Property("Nomgare", ValueType::str));
    gare.addProperty(Property("Idville", ValueType::integer));
    gare.addProperty(Property("Idcodepostal", ValueType::integer));

    Entity ligne("Ligne");
    ligne.addProperty(Property("Idligne", ValueType::integer, Value(0), true));
    ligne.addProperty(Property("Codeligne", ValueType::integer));

    Entity ligneLien("Ligne_dessert_gare_naturedesserte");
    ligneLien.addProperty(Property("WGS84", ValueType::str));
    ligneLien.addProperty(Property("Latitude_wgs84", ValueType::str));
    ligneLien.addProperty(Property("Longitude_wgs84", ValueType::str));
    ligneLien.addProperty(Property("Idgare", ValueType::integer));
    ligneLien.addProperty(Property("Idligne", ValueType::integer));
    ligneLien.addProperty(Property("Iddesserte", ValueType::integer));

    Entity desserte("Naturedesserte");
    desserte.addProperty(Property("Iddesserte", ValueType::integer, Value(0), true));
    desserte.addProperty(Property("Naturedesserte", ValueType::str));

    Entity vil("Ville");
    vil.addProperty(Property("Idville", ValueType::integer, Value(0), true));
    vil.addProperty(Property("Nomville", ValueType::str));
    vil.addProperty(Property("Iddepartement", ValueType::integer));

    Entity vilLien("Ville_Posseder_Codepostal");
    vilLien.addProperty(Property("Idville", ValueType::integer));
    vilLien.addProperty(Property("IdcodePostal", ValueType::integer));

    for (auto line : csvTab)
    {
        int code_ligne = stoi(line[0]);
        string nom = line[1];
        string nature = line[2];
        string latitude_wgs84 = line[3];
        string longitude_wgs84 = line[4];
        string wgs84 = line[5];
        int dept = stoi(line[6]);
        int cp = stoi(line[7]);
        string ville = line[8];

        map<string, Value> values;
        values["Numcodepostal"] = Value(cp);

        Entry cpEntry = codeP.createEntryIfNotExist(values);
        Value idCodePostal = codeP.getEntryValue(cpEntry, "Idcodepostal");

        values.clear();
        values["Numdepartement"] = Value(dept);

        Entry dptEntry = dep.createEntryIfNotExist(values);
        Value idDept = dep.getEntryValue(dptEntry, "Iddepartement");

        values.clear();
        values["Codeligne"] = Value(code_ligne);

        Entry ligneEntry = ligne.createEntryIfNotExist(values);
        Value idLigne = ligne.getEntryValue(ligneEntry, "Idligne");

        values.clear();
        values["Naturedesserte"] = Value(nature);

        Entry desserteEntry = desserte.createEntryIfNotExist(values);
        Value idDesserte = desserte.getEntryValue(desserteEntry, "Iddesserte");

        values.clear();
        values["Nomville"] = Value(ville);
        values["Iddepartement"] = idDept;

        Entry villeEntry = vil.createEntryIfNotExist(values);
        Value idVille = vil.getEntryValue(villeEntry, "Idville");

        values.clear();
        values["Idville"] = idVille;
        values["IdcodePostal"] = idCodePostal;

        vilLien.createEntryIfNotExist(values);

        values.clear();
        values["Nomgare"] = Value(nom);
        values["Idville"] = idVille;
        values["Idcodepostal"] = idCodePostal;

        Entry gareEntry = gare.createEntryIfNotExist(values);
        Value idGare = gare.getEntryValue(gareEntry, "Idgare");

        values.clear();
        values["WGS84"] = Value(wgs84);
        values["Latitude_wgs84"] = Value(latitude_wgs84);
        values["Longitude_wgs84"] = Value(longitude_wgs84);
        values["Idgare"] = idGare;
        values["Idligne"] = idLigne;
        values["Iddesserte"] = idDesserte;

        ligneLien.createEntryIfNotExist(values);
    }

    bdd.addEntity(codeP);
    bdd.addEntity(dep);
    bdd.addEntity(gare);
    bdd.addEntity(ligne);
    bdd.addEntity(ligneLien);
    bdd.addEntity(desserte);
    bdd.addEntity(vil);
    bdd.addEntity(vilLien);

    bdd.saveTables();

    return 0;
}
