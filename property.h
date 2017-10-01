#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include "value.h"

class Property // == Colonne
{
public:
    Property();
    Property(std::string nameProperty, ValueType typeVal, Value val = Value(), bool isAutoIncrement = false);

    std::string getName() const;
    void setName(const std::string &value);

    Value getDefaultValue();
    ValueType getType() const;

private:
    std::string name;
    ValueType type;
    Value defaultValue;
    bool autoIncrement;
};

#endif // PROPERTY_H
