#include "bdd.h"
#include <stdexcept>

BDD::BDD() : BDD("Gares")
{

}

BDD::BDD(std::string nameBDD) : name(nameBDD), tables({})
{

}

BDD::BDD(std::string nameBDD, std::vector<Entity> tablesBDD) : name(nameBDD), tables(tablesBDD)
{

}

std::vector<Entity> BDD::getTables() const
{
    return tables;
}

void BDD::setTables(const std::vector<Entity> &value)
{
    tables = value;
}

const Entity *BDD::getEntityByName(const std::string name) const
{
    for (const Entity &table : tables)
    {
        if (table.getName() == name)
        {
            return &table;
        }
    }

    throw std::invalid_argument(name + " isn't a table");
}

bool BDD::addEntity(Entity &table)
{
    try
    {
        getEntityByName(table.getName());
    }
    catch (std::exception&)
    {
        tables.push_back(table);

        return true;
    }

    return false; // You can't create a table that already exist!
}

std::string BDD::getName() const
{
    return name;
}

void BDD::saveTables() const
{
    for (int i = 0; i < (int)tables.size(); ++i)
    {
        tables[i].saveTable();
    }
}
