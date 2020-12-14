#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

void create(char* FileName, int N, int min, int max)
{
    ofstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }
  
    int a;
    double test = 0;
    for (int i = 0; i < N; i++)
    {
        a = min + rand() % (max - min + 1);
        f.write((char*)&a, sizeof(int));
    }
   cout << endl;
}
double averageMinus(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }
    int a, l = 0;
    double avgMin = 0;
    while (f.read((char*)&a, sizeof(int)))
    {
        if (a < 0)
        {
            ++l;
            avgMin += a;
        }
    }
    if (l != 0)
        avgMin = avgMin / l;
    return avgMin;
}

double averagePlus(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }
    int a, l = 0;
    double avgPlus = 0;
    while (f.read((char*)&a, sizeof(int)))
    {
        if (a >= 0)
        {
            ++l;
            avgPlus += a;
        }
    }
    if (l!=0)
        avgPlus = avgPlus / l;
    return avgPlus;
}
void print(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }
    int a;
    while (f.read((char*)&a, sizeof(int)))
        cout << a << "   ";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    int N, min, max, menu;
    double avgMinus, avgPlus;
    char FileName[] = "1.dat";
    cout << "Виберіть пункт меню" << endl;
    do {
        cout << endl;
        cout << "[0] - Записати числа в бінарний файл: " << endl;
        cout << "[1] - Завантажити бінарний файл та вивести середнє арифметичне додатніх та від'ємних" << endl;
        cout << "[2] - Завантажити числа з бінарного файлу та вивести на екран" << endl;
        cout << "[інше] - Вийти з програми " << endl;
        cout << "Пункт меню: "; cin >> menu;
        switch (menu)
        {
        case 0:
            cout << endl;
            cout << "Введіть кількість чисел: "; cin >> N;
            cout << "Введіть мінімальне значення: "; cin >> min;
            cout << "Введіть максимальне значення: "; cin >> max;
            create(FileName, N, min, max);
            break;
        case 1:
            cout << endl;
            cout << "Середнє арифметичне від'ємних: " << averageMinus(FileName) << endl;
            cout << "Середнє арифметичне додатніх: " << averagePlus(FileName) << endl;
            break;
        case 2:
            print(FileName);
        default:
            break;
        }
    } while (menu == 0 || menu == 1 || menu == 2);
}