# Vive la SNCF
First c++ dbms architecture. 

## Aim
Model a database and complete it with data from a csv (find datas in https://github.com/Anathea/vive-la-sncf/tree/master/res).
All datas must be in the database once.

## Technicaly
This project use oriented-object programing. It uses 5 objects which have a logical link, and one to parse datas from the csv.

### Value
Value is a data, one "cell" in a table. It can be an integer, a str (string) or unitialized.

### Entry
An entry is a line in a table. It is a list of value.

### Property
A property is the name of a column in a table. It only correspond to one column. It must have a type. It can be auto-incremented and have a default value.

### Entity
Entity is a table. It's composed of a vector of Property (column fields), a vector of Entry (which are a list of value) and the name of the table.
createEntryIfNotExist() is the most important in there. It returns the line already in the table if this entry already exist. Usefull to get the id of a value.

### DB
Database is a vector of Entity. It also has a name.

### Utile
Utile is full of static methods. You can find the parser for the csv file in the name of saveCSVFileByLine().

## Exemple
You can see the usage of this code in the main.cpp file. It needs to go as follow :
Database
Creation of every table with their property
Export of datas in each tables
Add every table to the database
Export database in csv.
