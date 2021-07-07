#ifndef AURIGA_H
#define AURIGA_H
#include <iostream>
#include <random>
#include <time.h>
#include <map>
#include <sstream>

using namespace std;

class Auriga
{
public:
    Auriga();
private:
    void setNumberOfPackages();
    void createPackages(const int &number);
    const string createData(const int &size);
    int randomNumber(const int &bottom, const int &top, const int &seed = 0);
    void split(const string &str, const string &delimiter);
    void printMap(const map <int, string> &packages);
};

#endif // AURIGA_H
