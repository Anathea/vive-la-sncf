#include "entity.h"

Entity::Entity() : name(""), titles({}), content({})
{

}

Entity::Entity(std::string nameTable) : name(nameTable), titles({}), content({})
{

}

Entity::Entity(std::string nameTable, std::vector<Property> titlesTable, std::vector<Entry> contentTable) : name(nameTable), titles(titlesTable), content(contentTable)
{

}

std::string Entity::getName() const
{
    return name;
}

void Entity::setName(const std::string &value)
{
    name = value;
}

const Property *Entity::getPropertyByName(const std::string name) const
{
    for (const Property &column : titles)
    {
        if (column.getName() == name)
        {
            return &column;
        }
    }

    throw std::invalid_argument(name + " isn't a column");
}

bool Entity::addProperty(const Property &column)
{
    try
    {
        getPropertyByName(column.getName());
    }
    catch (std::exception&)
    {
        titles.push_back(column);
        return true;
    }

    return false; // You can't create a column that already exist!
}

Entry Entity::createEntryIfNotExist(std::map<std::string, Value> values)
{
    bool exist;

    for (Entry& line : content)
    {
        exist = true;

        for (auto element : values)
        {
            std::string key = element.first;
            Value value = element.second;

            if (value != getEntryValue(line, key))
            {
                exist = false;
                break;
            }
        }

        if (exist)
        {
            return line;
        }
    }

    return createEntry(values);
}

Entry Entity::createEntry(std::map<std::string, Value> values)
{
    Entry line((int) titles.size());

    for (const auto &element : values)
    {
        std::string key = element.first;
        Value value = element.second;
        int id = getTitleIdByName(key);

        if (id < 0)
        {
            throw std::invalid_argument(key + " doesn't exist.");
        }

        if (value.getType() != titles[id].getType())
        {
            throw std::invalid_argument("Types does not match.");
        }

        line.setValueById(id, value);

    }

    for (int i = 0; i < (int)titles.size(); ++i)
    {
        if (values.find(titles[i].getName()) == values.end())
        {
            line.setValueById(i, titles[i].getDefaultValue());
        }
    }

    content.push_back(line);

    return content.back();
}

std::string Entity::exportTitles() const
{
    std::string lineTitles;
    int titlesSize = (int)titles.size();

    for (int i = 0; i < titlesSize; ++i)
    {
        lineTitles += titles[i].getName();

        if (i < titlesSize - 1)
        {
            lineTitles += ";";
        }
    }

    return lineTitles;
}

std::string Entity::exportContent() const
{
    std::string allContent;
    int contentSize = (int)content.size();

    for (int i = 0; i < contentSize; ++i)
    {
        allContent += content[i].exportLine();

        if (i < contentSize -1)
        {
            allContent += "\n";
        }
    }

    return allContent;
}

std::string Entity::exportTable() const
{
    if (!exportTitles().empty())
    {
        return exportTitles() + "\n" + exportContent();
    }

    std::cout << "Titles' line is empty." << std::endl;
    return "";
}

const Value Entity::getEntryValue(Entry line, std::string nameColumn)
{
    int id = getTitleIdByName(nameColumn);

    if (id < 0)
    {
        throw std::invalid_argument("No column named " + nameColumn);
    }

    return line.getValueById(id);
}

void Entity::saveTable() const
{
    std::ofstream outputFile;
    outputFile.open("out/" + this->getName() + ".csv");

    outputFile << exportTable();

    outputFile.close();
}

int Entity::getTitleIdByName(std::string name)
{
    for (size_t i = 0; i < titles.size(); ++i)
    {
        if (titles[i].getName() == name)
        {
            return (int)i;
        }
    }

    return -1;
}
