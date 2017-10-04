#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <vector>
#include "value.h"

class Entry // == Ligne
{
public:
    Entry();
    Entry(int sizeOfLine);
    Entry(std::vector<Value> fullLine);

    std::vector<Value> getLine() const;
    void setLine(const std::vector<Value> &value);

    const Value getValueById(const int id) const;
    void setValueById(const int id, const Value &value);

    std::string exportLine() const;

private:
    std::vector<Value> line;
};

#endif // ENTRY_H
