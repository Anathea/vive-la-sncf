#ifndef UTILE_H
#define UTILE_H

#include <iostream>
#include <vector>

class Utile
{
public:
  static std::vector<std::vector<std::string>> loadCSVFileLine(std::string nomFichier, bool &ok);
};

#endif // UTILE_H
