#ifndef BDD_H
#define BDD_H

#include <iostream>
#include <vector>
#include "entity.h"

class DB
{
public:
    DB();
    DB(std::string nameBDD);
    DB(std::string nameBDD, std::vector<Entity> tablesBDD);

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

#endif // BDD_H
