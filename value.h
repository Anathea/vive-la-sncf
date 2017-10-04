#ifndef VALUE_H
#define VALUE_H

#include <iostream>
#include <string>
#include <stdexcept>

enum class ValueType
{
    str,
    integer,
    uninitialized
};

class Value
{
public:
    Value();
    Value(int numericData);
    Value(std::string stringData);

    void setData(const std::string &value);
    void setData(const int value);

    std::string getDataStr() const;
    int getDataInt() const;

    std::string exportData() const;

    ValueType getType() const;

    bool operator ==(const Value &right) const;
    bool operator !=(const Value &right) const;

private:
    int dataInt;
    std::string dataStr;
    ValueType type;
};

#endif // VALUE_H
