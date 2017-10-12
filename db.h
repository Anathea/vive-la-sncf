#ifndef DB_H
#define DB_H

#include <iostream>
#include <vector>
#include "entity.h"

class DB // == Database
{
public:
    DB();
    DB(std::string nameDB);
    DB(std::string nameDB, std::vector<Entity> tablesDB);

    std::vector<Entity> getTables() const;
    void setTables(const std::vector<Entity> &value);

    const Entity *getEntityByName(const std::string name) const;

    bool addEntity(Entity &table);

    std::string getName() const;

    void saveTables() const;

private:
    std::string name;
    std::vector<Entity> tables;
};

#endif // DB_H
