#include "property.h"

Property::Property() : name(""), type(ValueType::uninitialized), defaultValue(Value()), autoIncrement(false)
{

}

Property::Property(std::string nameProperty, ValueType typeVal, Value val, bool isAutoIncrement) : name(nameProperty), type(typeVal), defaultValue(val), autoIncrement(isAutoIncrement)
{
    if (autoIncrement == true
            && (ValueType::integer != type || ValueType::integer != defaultValue.getType()))
    {
        throw std::invalid_argument("This type can't be auto-incremented.");
    }

    if (type == ValueType::uninitialized
            || (val.getType() != ValueType::uninitialized && val.getType() != type))
    {
        throw std::invalid_argument("Invalid type argument");
    }
}

std::string Property::getName() const
{
    return name;
}

void Property::setName(const std::string &value)
{
    name = value;
}

Value Property::getDefaultValue()
{
    if (autoIncrement)
    {
        defaultValue.setData(defaultValue.getDataInt() + 1);
    }

    return defaultValue;
}

ValueType Property::getType() const
{
    return type;
}
