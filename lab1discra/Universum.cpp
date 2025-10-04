#include <map>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include "Universum.h"
#include "func.h"

using namespace std;
//конструктор
Universum::Universum(int razr) {
    if (razr == 0) {
        n = m = 0;
        elementsU = {};
    }
    else {
        n = razr;
        m = pow(2, n);
        GreyCode();

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1, 50);

        for (auto& pair : elementsU) {
            pair.second = dist(gen); //заполнение кратности
        }
    }
}
//создание А и В
void Universum::CreateSetA() {
    if (elementsU.empty()) return;

    map<vector<int>, int> elementsA;
    int choice;
    bool validInput = false;
    cout << "0 - выбрать элементы мультимножества A вручную" << endl << "1 - создать их автоматически." << endl << endl;
    while (!validInput) {
        cout << "Ввод: ";
        cin >> choice;
        if (cin.fail() || choice > 1 || choice < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Введите 0 или 1!" << endl;
        }
        else {
            validInput = true;
        }
        cout << endl;
    }

    if (choice == 0) {
        int num;
        cout << "Введите номер элемента 1 - " << elementsU.size() << " для множества." << endl
            << "Чтобы завершить ввод введите 0." << endl << endl;
        while (true) {
            cout << "Номер: ";
            cin >> num;
            if (cin.fail() || num < 0 || num > elementsU.size()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Нет элемента под таким номером!" << endl;
            }
            else if (num == 0) break;
            else {
                auto it = elementsU.begin();
                advance(it, num - 1);  //доступ к элементу по индексу
                int k;
                bool flag = true;
                while (flag) {
                    cout << "Введите кратность элемента от 1 до " << it->second << " включительно: ";
                    cin >> k;
                    if (cin.fail() || k < 1 || k > it->second) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ошибка ввода! Нет такой кратности!" << endl;
                    }
                    else {
                        elementsA[it->first] = k;
                        flag = false;
                        cout << endl;
                    }
                }
            }
        }
    }
    else {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, elementsU.size() - 1); //создает равномерное распределение целых чисел в диапазоне от 0 до размера elementsU - 1

        int subset_size = dist(gen) % elementsU.size(); //случайный размер подмножества
        //dist(gen) возвращает случайное число, и остаток от деления на elementsU.size() гарантирует, что оно будет меньше размера множества elementsU.
        for (int i = 0; i < subset_size; ++i) {
            int idx = dist(gen);
            auto it = elementsU.begin();
            advance(it, idx); //сдвигает итератор на idx
            uniform_int_distribution<> kratn_dist(1, it->second);
            elementsA[it->first] = kratn_dist(gen);
        }
    }

    this->elementsA = elementsA;
}
void Universum::CreateSetB() {
    if (elementsU.empty()) return;

    map<vector<int>, int> elementsB;
    int choice;
    bool validInput = false;
    cout << "0 - выбрать элементы мультимножества B вручную" << endl << "1 - создать их автоматически." << endl << endl;

    while (!validInput) {
        cout << "Ввод: ";
        cin >> choice;
        if (cin.fail() || choice > 1 || choice < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Введите 0 или 1!" << endl;
        }
        else {
            validInput = true;
        }
        cout << endl;
    }

    if (choice == 0) {
        int num;
        cout << "Введите номер элемента 1 - " << elementsU.size() << " для множества." << endl
            << "Чтобы завершить ввод введите 0." << endl << endl;
        while (true) {
            cout << "Номер: ";
            cin >> num;
            if (cin.fail() || num < 0 || num > elementsU.size()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Нет элемента под таким номером!" << endl;
            }
            else if (num == 0) break;
            else {
                auto it = elementsU.begin();
                advance(it, num - 1);
                int k;
                bool flag = true;
                while (flag) {
                    cout << "Введите кратность элемента от 1 до " << it->second << " включительно: ";
                    cin >> k;
                    if (cin.fail() || k < 1 || k > it->second) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ошибка ввода! Нет такой кратности!" << endl;
                    }
                    else {
                        elementsB[it->first] = k;
                        flag = false;
                        cout << endl;
                    }
                }
            }
        }
    }
    else {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, elementsU.size() - 1);

        int subset_size = dist(gen) % elementsU.size();
        for (int i = 0; i < subset_size; ++i) {
            int idx = dist(gen);
            auto it = elementsU.begin();
            advance(it, idx);
            uniform_int_distribution<> kratn_dist(1, it->second);
            elementsB[it->first] = kratn_dist(gen);
        }
    }

    this->elementsB = elementsB;
}
//принты
void Universum::PrintUni() {
    cout << "* МУЛЬТИМНОЖЕСТВО УНИВЕРСУМ *" << endl;
    if (elementsU.empty()) {
        cout << "Пустое множество." << endl;
    }
    else {
        int index = 1;
        for (const auto& pair : elementsU) {
            cout << index++ << ") ";
            for (const auto& elem : pair.first) {
                cout << elem << " ";
            }
            cout << "| Кратность: " << pair.second << endl;
        }
    }
    cout << endl;
}
void Universum::PrintSetA() {
    cout << "* МУЛЬТИМНОЖЕСТВО A *" << endl;
    if (elementsA.empty()) {
        cout << "Пустое мультимножество." << endl << endl;
    }
    else {
        for (const auto& pair : elementsA) {
            for (const auto& elem : pair.first) {
                cout << elem << " ";
            }
            cout << "| Кратность: " << pair.second << endl;
        }
    }
}
void Universum::PrintSetB() {
    cout << "* МУЛЬТИМНОЖЕСТВО В *" << endl;
    if (elementsB.empty()) {
        cout << "Пустое мультимножество." << endl << endl;
    }
    else {
        for (const auto& pair : elementsB) {
            for (const auto& elem : pair.first) {
                cout << elem << " ";
            }
            cout << "| Кратность: " << pair.second << endl;
        }
    }
}
void Universum::PrintResult() {
    cout << endl << "* РЕЗУЛЬТАТ ОПЕРАЦИИ *" << endl;
    if (result.empty()) {
        cout << "Пустое множество." << endl;
    }
    else {
        for (const auto& pair : result) {
            for (const auto& elem : pair.first) {
                cout << elem << " ";
            }
            cout << "| Кратность: " << pair.second << endl;
        }
    }
    cout << endl;
}
//грей
vector<vector<int>> Universum::GreyCode() {
    vector<int> B(n, 0);
    elementsU[B] = 0;  //начальный элемент
    for (int i = 1; i < m; ++i) {
        int elnum = Q(i);
        B[elnum - 1] = 1 - B[elnum - 1];
        elementsU[B] = 0;  //добавляем элемент с начальной кратностью 0 (будет изменена позже)
    }
    return {};
}
int Universum::Q(int i) {
    int q = 1;
    while (i % 2 == 0) {
        i /= 2;
        q++;
    }
    return q;
}
//операции
void Universum::Operations(int op) {
    switch (op)
    {
    case 1:
        ComplementA();
        break;
    case 2:
        ComplementB();
        break;
    case 3:
        Union();
        break;
    case 4:
        Intersection();
        break;
    case 5:
        DifferenceAB();
        break;
    case 6:
        DifferenceBA();
        break;
    case 7:
        SymmetricDifference();
        break;
    case 8:
        Addition();
        break;
    case 9:
        SubtractionAB();
        break;
    case 10:
        SubtractionBA();
        break;
    case 11:
        Multiplication();
        break;
    case 12:
        DivisionAB();
        break;
    case 13:
        DivisionBA();
        break;
    }
};
map<vector<int>, int> Universum::ComplementA() {

    for (const auto& pair : elementsU) {
        auto it = elementsA.find(pair.first);
        if (it != elementsA.end()) {
            int complementKratn = pair.second - it->second;  //разность кратностей
            if (complementKratn > 0) {
                result[pair.first] = complementKratn;
            }
        }
        else {
            result[pair.first] = pair.second;  //элемент есть только в U
        }
    }

    return result;
}
map<vector<int>, int> Universum::ComplementB() {

    for (const auto& pair : elementsU) {
        auto it = elementsB.find(pair.first);
        if (it != elementsB.end()) {
            int complementKratn = pair.second - it->second;  //разность кратностей
            if (complementKratn > 0) {
                result[pair.first] = complementKratn;
            }
        }
        else {
            result[pair.first] = pair.second;  //элемент есть только в U
        }
    }

    return result;
}
map<vector<int>, int> Universum::Union() {
    result = elementsA;  // копируем A в результат

    for (const auto& pair : elementsB) {
        auto it = result.find(pair.first);
        if (it != result.end()) {
            it->second = max(it->second, pair.second);  // берем максимальную кратность
        }
        else {
            result[pair.first] = pair.second;  // добавляем новый элемент
        }
    }

    return result;
}
map<vector<int>, int> Universum::Intersection() {

    // Обработка элементов из elementsA
    for (const auto& pair : elementsA) {
        auto itB = elementsB.find(pair.first);
        if (itB != elementsB.end()) {  // Элемент существует в elementsB
            int kratnost = std::min(pair.second, itB->second); // Находим минимальную кратность между A и B

            // Если кратность больше 0, добавляем в результат
            if (kratnost > 0) {
                result[pair.first] = kratnost;
            }
        }
    }

    // Обработка элементов из elementsB
    for (const auto& pair : elementsB) {
        if (result.find(pair.first) != result.end()) continue; // Пропускаем элементы, уже добавленные в результат

        auto itA = elementsA.find(pair.first);
        if (itA != elementsA.end()) {  // Элемент существует в elementsA
            int kratnost = std::min(pair.second, itA->second);

            // Если кратность больше 0, добавляем в результат
            if (kratnost > 0) {
                result[pair.first] = kratnost;
            }
        }
    }

    return result;

}
map<vector<int>, int> Universum::DifferenceAB() {
    result = elementsA;

    for (const auto& pair : elementsB) {
        auto it = result.find(pair.first);
        if (it != result.end()) {
            it->second -= pair.second;  // уменьшаем кратность
            if (it->second <= 0) {
                result.erase(it);  // удаляем элемент, если кратность <= 0
            }
        }
    }

    return result;
}
map<vector<int>, int> Universum::DifferenceBA() {
    result = elementsB;

    for (const auto& pair : elementsA) {
        auto it = result.find(pair.first);
        if (it != result.end()) {
            it->second -= pair.second;  // уменьшаем кратность
            if (it->second <= 0) {
                result.erase(it);  // удаляем элемент, если кратность <= 0
            }
        }
    }

    return result;
}
map<vector<int>, int> Universum::SymmetricDifference() {

    for (const auto& pair : elementsA) { // Обрабатываем элементы из elementsA
        auto it = elementsB.find(pair.first);
        if (it == elementsB.end()) {
            result[pair.first] = pair.second; // Элемент есть только в A
        }
        else {
            int difference = pair.second - it->second; // Элемент есть в обоих, но учитываем разность кратностей
            if (difference != 0) {
                result[pair.first] = abs(difference);
            }
        }
    }
    for (const auto& pair : elementsB) { // Обрабатываем элементы из elementsB, которых нет в elementsA
        if (elementsA.find(pair.first) == elementsA.end()) {
            result[pair.first] = pair.second;
        }
    }

    return result;
}
map<vector<int>, int> Universum::Addition() {
   result = elementsA;

    for (const auto& pair : elementsB) {
        auto it = result.find(pair.first);
        if (it != result.end()) {
            result[pair.first] += pair.second;  // складываем кратности

            auto it2 = elementsU.find(pair.first); // Ограничение по кратности универсального множества
            if (it2 != elementsU.end() && result[pair.first] > it2->second) {
                result[pair.first] = it2->second;
            }
        }
        else {
            result[pair.first] = pair.second;  // добавляем новый элемент
        }
    }

    return result;
}
map<vector<int>, int> Universum::SubtractionAB() {
    result = elementsA;

    for (const auto& pair : elementsB) {
        result[pair.first] -= pair.second;  // уменьшаем кратности

        if (result[pair.first] <= 0) { // Удаляем элементы с кратностью <= 0
            result.erase(pair.first);
        }
    }

    return result;
}
map<vector<int>, int> Universum::SubtractionBA() {
    result = elementsB;

    for (const auto& pair : elementsA) {
        result[pair.first] -= pair.second;  // уменьшаем кратности

        if (result[pair.first] <= 0) { // Удаляем элементы с кратностью <= 0
            result.erase(pair.first);
        }
    }

    return result;
}
map<vector<int>, int> Universum::Multiplication() {
    for (const auto& pair : elementsA) { // Проходим по элементам из elementsA и умножаем на кратности из elementsB
        auto itB = elementsB.find(pair.first);
        if (itB != elementsB.end()) {
            result[pair.first] = pair.second * itB->second; // Умножаем кратности, если элемент присутствует в обоих множествах
            auto itUni = elementsU.find(pair.first); // Ограничение по универсальному множеству (elementsU)
            if (itUni != elementsU.end() && result[pair.first] > itUni->second) {
                result[pair.first] = itUni->second;
            }
        }
    }

    return result;
}
map<vector<int>, int> Universum::DivisionAB() {
    for (const auto& pair : elementsA) { // Проходим по элементам из elementsA и делим их кратности на значения из elementsB
        auto itB = elementsB.find(pair.first);
        if (itB != elementsB.end() && itB->second != 0) { // Проверяем, что элемент есть в обоих и кратность в B не равна 0
            result[pair.first] = pair.second / itB->second;  // Делим кратности
            if (result[pair.first] <= 0) { // Удаляем элемент, если результат кратности <= 0
                result.erase(pair.first);
            }
        }
    }

    return result;
}
map<vector<int>, int> Universum::DivisionBA() {
    for (const auto& pair : elementsB) {
        auto itA = elementsA.find(pair.first);
        if (itA != elementsA.end() && itA->second != 0) {
            result[pair.first] = pair.second / itA->second;
            if (result[pair.first] <= 0) {
                result.erase(pair.first);
            }
        }
    }

    return result;
}
