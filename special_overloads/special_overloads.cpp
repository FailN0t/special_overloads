// special_overloads.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
using namespace std;

class Stroka {
    int* arr;
    const int size;
public:
    // Stroka(int size)
    Stroka(int size) :arr{ new int[size] }, size{ size } {
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = rand() % 10 + 1;
        }
    }
    Stroka() :Stroka(2) {}

    //int len() const  return size (Stroka);
    int len() const {
        return size;
    }
    int& operator [] (int i) {
        return arr[i];
    }
    int operator [] (int i) const {
        return arr[i];
    }
    ~Stroka() {
        cout << arr << " delete class: " << this << endl;
        delete[] arr;
    }
};


class Mtr {
    Stroka* stroka;
    int size;
public:
    Mtr(int size) :stroka{ new Stroka[size]}, size{size} {}
    Mtr() : Mtr(5) {}
    //int len() const  return size (Mtr);
    int len() const {
        return size;
    }
    Stroka& operator [] (int i) {
        return stroka[i];
    }
    Stroka operator [] (int i) const {
        return stroka[i];
    }

    void operator << (Mtr& mtr) const {
        for(size_t i = 0; i < mtr.len(); i++)
        {
            for (size_t j = 0; j < mtr[i].len(); j++)
            {
                cout << mtr[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    friend ostream& operator << (ostream& ost, Mtr& mtr) {
        for (size_t i = 0; i < mtr.len(); i++)
        {
            for (size_t j = 0; j < mtr[i].len(); j++)
            {
                ost << mtr[i][j] << "\t";
            }
            ost << endl;
        }
        ost << endl;
        return ost;
    }

    friend istream& operator >> (istream& ist, Mtr& mtr) {
        for (size_t i = 0; i < mtr.len(); i++)
        {
            for (size_t j = 0; j < mtr[i].len(); j++)
            {
                ist >> mtr[i][j];
            }
        }
        return ist;
    }

    ~Mtr() {
        cout << stroka << " delete class Mtr : " << this << endl;
        delete[] stroka;
    }
};


int main()
{
    Mtr mtr;
    mtr << mtr;

    cout << mtr;
    Mtr mtr2(2);
    cin >> mtr2;
    cout << mtr2;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
