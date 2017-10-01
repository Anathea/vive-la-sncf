#ifndef UTILE_H
#define UTILE_H

#include <iostream>
#include <vector>

class Utile
{
public:
  static bool saveCSVFileByLine(const std::string nomFichier, std::vector<std::vector<std::string>> &datas);

  template <typename T>
  static void printVectorVector(const std::vector<std::vector<T>> tab)
  {
      for (auto tabInTab : tab)
      {
          for (auto element : tabInTab)
          {
              std::cout << element << " ; ";
          }
          std::cout << " #" << std::endl;
      }
  }

  template <typename T>
  static void printVector(const std::vector<T> tab)
  {
      for (auto element : tab)
      {
          std::cout << element << std::endl;
      }
  }
};

#endif // UTILE_H
