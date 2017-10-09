#include "db.h"
#include <stdexcept>

DB::DB() : DB("Gares")
{

}

DB::DB(std::string nameBDD) : name(nameBDD), tables({})
{

}

DB::DB(std::string nameBDD, std::vector<Entity> tablesBDD) : name(nameBDD), tables(tablesBDD)
{

}

std::vector<Entity> DB::getTables() const
{
    return tables;
}

void DB::setTables(const std::vector<Entity> &value)
{
    tables = value;
}

const Entity *DB::getEntityByName(const std::string name) const
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

bool DB::addEntity(Entity &table)
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

std::string DB::getName() const
{
    return name;
}

void DB::saveTables() const
{
    for (int i = 0; i < (int)tables.size(); ++i)
    {
        tables[i].saveTable();
    }
}
