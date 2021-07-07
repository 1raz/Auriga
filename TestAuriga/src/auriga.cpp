#include "auriga.h"

Auriga::Auriga()
{
    setNumberOfPackages();
}
// Установка количества пакетов
void Auriga::setNumberOfPackages()
{
    int NumberOfPackages = 0;
    cout << "Enter the number of packages: ";
    cin >> NumberOfPackages;
    createPackages(NumberOfPackages);
}
// Создание данных пакета, в зависимости от XX
const string Auriga::createData(const int &size)
{
    string data;
    for(int i = 1; i <= size; ++i)
    {
        data += string("B" + to_string(i) + " ");
    }
    return data;
}
// Создание всех пакетов с заголовками
void Auriga::createPackages(const int &number)
{
    string paskages;
    int randomNum = 0;
    for(int i = 0; i < number; ++i)
    {
        randomNum = randomNumber(1, 9, i);
        paskages += string("FF FF 0" + to_string(randomNum) + " " +
                           createData(randomNum));
    }
    split(paskages, "FF FF");
}
//      Получение случайного числа.
//      bottom - нижняя граница числа, top - верхняя, seed - число для повышения случайности.
int Auriga::randomNumber(const int &bottom, const int &top, const int &seed)
{
    time_t seconds = time(nullptr) + seed;
    mt19937 random(seconds);
    uniform_int_distribution <int> uid(bottom, top); // распределение
    return int(uid(random));
}
// Функция разделения string, str - строка, delimiter - разделитель
void Auriga::split(const string &str, const string &delimiter)
{
    map <int, string> mapOfPackages;
    int start = 0;
    int count = 1;
    int end = str.find(delimiter);
    while (end != -1)
    {
        start = end + delimiter.size();
        end = str.find(delimiter, start);
        mapOfPackages[count] = str.substr(start, end - start);
        ++count;
    }
    printMap(mapOfPackages);
}
// Функция печати словаря пакетов
void Auriga::printMap(const map<int, string> &packages)
{
    for(auto it = packages.begin(); it != packages.end(); it++)
    {
        cout << to_string(it->first) + ". " << "[Size = " +
                it->second.substr(2, 2) + "] " <<
                "[Data = " + it->second.substr(4, it->second.size()) + "]" <<
                '\n';
    }
}
