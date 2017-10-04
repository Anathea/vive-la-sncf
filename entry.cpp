#include "entry.h"

Entry::Entry() : line({})
{

}

Entry::Entry(int sizeOfLine) : line(sizeOfLine)
{

}

Entry::Entry(std::vector<Value> fullLine) : line(fullLine)
{

}

std::vector<Value> Entry::getLine() const
{
    return line;
}

void Entry::setLine(const std::vector<Value> &value)
{
    line = value;
}

const Value Entry::getValueById(const int id) const
{
    return line[id];
}

void Entry::setValueById(const int id, const Value &value)
{
    if (line[id].getType() == ValueType::uninitialized || line[id].getType() == value.getType())
    {
        line[id] = value;
    }
}

std::string Entry::exportLine() const
{
    std::string rsltLine;

    int lineSize = line.size();

    for (int i = 0; i < lineSize; ++i)
    {
        rsltLine += line[i].exportData();

        if (i < lineSize - 1)
        {
            rsltLine += ";";
        }
    }

    return rsltLine;
}
