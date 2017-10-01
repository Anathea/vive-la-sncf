#include "value.h"

Value::Value() : dataInt(-1), dataStr(""), type(ValueType::uninitialized)
{

}

Value::Value(int numericData) : dataInt(numericData), dataStr(""), type(ValueType::integer)
{

}

Value::Value(std::string stringData) : dataInt(-1), dataStr(stringData), type(ValueType::str)
{

}

void Value::setData(const std::string &value)
{
    if (type == ValueType::str)
    {
        dataStr = value;
    }
}

void Value::setData(const int value)
{
    if (type == ValueType::integer)
    {
        dataInt = value;
    }
}

std::string Value::getDataStr() const
{
    if (type == ValueType::str)
    {
        return dataStr;
    }

    return "";
}

int Value::getDataInt() const
{
    if (type == ValueType::integer)
    {
        return dataInt;
    }

    return -1;
}

std::string Value::exportData() const
{
    if (type != ValueType::str)
    {
        return std::to_string(this->getDataInt());
    }
    return this->getDataStr();
}

ValueType Value::getType() const
{
    return type;
}

bool Value::operator== (const Value &right) const
{
    if (this->getType() == ValueType::integer && right.getType() == ValueType::integer)
    {
        return this->getDataInt() == right.getDataInt();
    }

    if (this->getType() == ValueType::str && right.getType() == ValueType::str)
    {
        return this->getDataStr() == right.getDataStr();
    }

    throw std::invalid_argument("Type makes no sense, can't work with this '-'");
}

bool Value::operator!= (const Value &right) const
{
    return !(*this == right);
}
