#include "func.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Start() {
    cout << endl << "*********************"<<endl
               <<   "* ДОБРО ПОЖАЛОВАТЬ! *" << endl << 
                    "*********************" << endl << endl << "ПРИМЕЧАНИЕ: " << endl <<
        "Данное приложение реализует программу генерации бинарного кода Грея " <<
        "для заполнения универсума мультмножеств. " << endl 
        << "На основе универсума формируются " <<
        "два мультимножества (автоматически или вручную), " << endl
        << "над которыми можно проводить различные операции." << endl << endl << endl;

};

int UniversumInput() {
    cout << endl << "**************************************************************" << endl
                <<  "* ВВЕДИТЕ РАЗРЯДНОСТЬ ЭЛЕМЕНТОВ МУЛЬТИМНОЖЕСТВА n (0<=n<=10) *" << endl<<
                    "**************************************************************" << endl << endl;

    int n;
    bool validInput = false;

    cout << "Разрядность: ";
    while (!validInput) {
        cin >> n;
        if (cin.fail() || n > 10 || n < 0) {
            cin.clear(); //очистка флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //очистка буфера ввода
            cout << "Ошибка ввода! Введите число от 0 до 10 включительно!" << endl;
        }
        else {
            validInput = true; //ввод корректен
        }
    }
    cout << endl;
    return n;
}

void AInput() {
    cout  << endl << endl << "************************" << endl
        <<                   "* СОЗДАДИМ МНОЖЕСТВО А *" << endl <<
                             "************************" << endl << endl;
}

void BInput() {
    cout << endl << endl << endl << "************************" << endl
        <<                          "* СОЗДАДИМ МНОЖЕСТВО B *" << endl <<
                                    "************************" << endl << endl;
}

void Menu() {
    cout << endl << endl << endl << "*******************************************************" << endl
        << "* МЕНЮ ДОСТУПНЫХ ОПЕРАЦИЙ НАД МУЛЬТИМНОЖЕСТВАМИ A и B *" << endl <<
        "*******************************************************";
}

int OperationsMenu() { 
    cout << endl << endl<< "* ЛОГИЧЕСКИЕ ОПЕРАЦИИ *                 * БИНАРНЫЕ АРИФМЕТИЧЕСКИЕ ОПЕРАЦИИ *" << endl << endl;
    cout << "1) Дополнение А                              8) Сумма A + B" << endl
        << "2) Дополнение В                              9) Разность А - В" << endl
        << "3) Объединение A и B                         10) Разность B - A" << endl
        << "4) Пересечение А и B                         11) Произведение A * B" << endl
        << "5) Разность А \\ B                            12) Деление А \\ В" << endl
        << "6) Разность В \\ А                            13) Деление В \\ А" << endl
        << "7) Симметрическая разность" << endl << endl
        << "                     ДЛЯ ВЫХОДА ИЗ ПРИЛОЖЕНИЯ ВВЕДИТЕ 0"<<endl<<endl;
    cout << "Введите номер нужной операции (от 0 до 13 включительно)" << endl << endl;

    int op;
    bool validInput = false;
    while (!validInput) {
        cout << "Ввод: ";
        cin >> op;
        if (cin.fail() || op < 0 || op > 13) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Введите число от 0 до 13 включительно!" << endl;
        }
        else if (op == 0) {
            return 0 ;
        }
        else return op;
    }
}
void Bye() {
    cout << endl << "********************" << endl
        << "* ДО НОВЫХ ВСТРЕЧ! *" << endl <<
        "********************" << endl << endl;
}

int Continue() {
    cout << endl << "* Хотите ли вы продолжить работу со множествами? 1 - Да, 0 - Нет. *" << endl << endl;
    int op;
    bool validInput = false;
    while (!validInput) {
        cout << "Ввод: ";
        cin >> op;
        if (cin.fail() || op < 0 || op > 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Введите либо 0, либо 1!" << endl;
        }
        else return op;
    }
}
