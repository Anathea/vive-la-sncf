#include "utile.h"

#include <fstream>
#include <sstream>

using namespace std;


bool Utile::saveCSVFileByLine(const string fileName, vector<vector<string>> &datas)
{
    ifstream myfile;
    vector<vector<string>> rslt;
    string lineStr;
    myfile.open(fileName);

    if (!myfile.is_open())
    {
        cout << "Incorrect file name/Shadow build still on" << endl;
        return false;
    }

    while (getline(myfile, lineStr, '\n'))
    {
        lineStr.erase(std::remove(lineStr.begin(), lineStr.end(), '\r'), lineStr.end());

        if (lineStr.empty())
        {
            continue;
        }

        std::istringstream streamLine(lineStr);
        vector<string> lineTab;
        string element;

        while (getline(streamLine, element, ';'))
        {
            lineTab.push_back(element);
        }
        rslt.push_back(lineTab);
    }

    myfile.close();
    rslt.erase(rslt.begin());
    datas = rslt;

    return true;
}


