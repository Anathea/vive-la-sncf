#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "entry.h"
#include "property.h"

class Entity // == Table
{
public:
    Entity();
    Entity(std::string nameTable);
    Entity(std::string nameTable, std::vector<Property> titlesTable);
    Entity(std::string nameTable, std::vector<Property> titlesTable, std::vector<Entry> contentTable);

    std::string getName() const;
    void setName(const std::string &value);

    const Property *getPropertyByName(const std::string name) const;
    bool addProperty(const Property &column);

    Entry createEntryIfNotExist(std::map<std::string, Value> values);
    Entry createEntry(std::map<std::string, Value> values);

    std::string exportTitles() const;
    std::string exportContent() const;
    std::string exportTable() const;

    const Value getEntryValue(Entry line, std::string nameColumn);

    void saveTable() const;

private:
    std::string name;
    std::vector<Property> titles;
    std::vector<Entry> content;

    int getTitleIdByName(std::string name);
};

#endif // ENTITY_H
