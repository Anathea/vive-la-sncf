#include "utile.h"

#include <fstream>
#include <sstream>

using namespace std;

vector<vector<string>> Utile::loadCSVFileLine(string nomFichier, bool &ok) // Chaque ligne du fichier est une case du tableau.
{
    vector<vector<string>> rslt;
    string line;
    ifstream myfile;
    myfile.open(nomFichier);

    if (myfile.is_open())
    {
        auto i = 0;
        while (getline(myfile, line))
        {
            std::istringstream streamLine(line);
            std::string valeurColonne;
            vector<string> colonne;

            while (std::getline(streamLine, valeurColonne, ';'))
            {
//                std::cout << valeurColonne << endl;
                colonne.push_back(valeurColonne);
            }

            cout << "colonne" << i << ".size() = " << colonne.size() << endl;
            rslt.push_back(colonne);
            i++;
        }

        myfile.close();
        ok = true;
        cout << "fichier.size() = " << rslt.size() << endl;
    }
    else
    {
        cout << "nom du fichier incorrect" << endl;
        ok = false;
    }

    return rslt;
}

vector<vector<string>> Utile::loadCSVFileColumn(const vector<vector<string>> &tabFichier)
{
    vector<vector<string>> rslt;
    string column;

    for (auto tabDansTab : tabFichier)
    {
        for (auto élément : tabDansTab)
        {

        }
    }
}
