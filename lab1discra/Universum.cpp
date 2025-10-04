#include <map>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include "Universum.h"
#include "func.h"

using namespace std;
//�����������
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
            pair.second = dist(gen); //���������� ���������
        }
    }
}
//�������� � � �
void Universum::CreateSetA() {
    if (elementsU.empty()) return;

    map<vector<int>, int> elementsA;
    int choice;
    bool validInput = false;
    cout << "0 - ������� �������� ��������������� A �������" << endl << "1 - ������� �� �������������." << endl << endl;
    while (!validInput) {
        cout << "����: ";
        cin >> choice;
        if (cin.fail() || choice > 1 || choice < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������ �����! ������� 0 ��� 1!" << endl;
        }
        else {
            validInput = true;
        }
        cout << endl;
    }

    if (choice == 0) {
        int num;
        cout << "������� ����� �������� 1 - " << elementsU.size() << " ��� ���������." << endl
            << "����� ��������� ���� ������� 0." << endl << endl;
        while (true) {
            cout << "�����: ";
            cin >> num;
            if (cin.fail() || num < 0 || num > elementsU.size()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������ �����! ��� �������� ��� ����� �������!" << endl;
            }
            else if (num == 0) break;
            else {
                auto it = elementsU.begin();
                advance(it, num - 1);  //������ � �������� �� �������
                int k;
                bool flag = true;
                while (flag) {
                    cout << "������� ��������� �������� �� 1 �� " << it->second << " ������������: ";
                    cin >> k;
                    if (cin.fail() || k < 1 || k > it->second) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "������ �����! ��� ����� ���������!" << endl;
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
        uniform_int_distribution<> dist(0, elementsU.size() - 1); //������� ����������� ������������� ����� ����� � ��������� �� 0 �� ������� elementsU - 1

        int subset_size = dist(gen) % elementsU.size(); //��������� ������ ������������
        //dist(gen) ���������� ��������� �����, � ������� �� ������� �� elementsU.size() �����������, ��� ��� ����� ������ ������� ��������� elementsU.
        for (int i = 0; i < subset_size; ++i) {
            int idx = dist(gen);
            auto it = elementsU.begin();
            advance(it, idx); //�������� �������� �� idx
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
    cout << "0 - ������� �������� ��������������� B �������" << endl << "1 - ������� �� �������������." << endl << endl;

    while (!validInput) {
        cout << "����: ";
        cin >> choice;
        if (cin.fail() || choice > 1 || choice < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������ �����! ������� 0 ��� 1!" << endl;
        }
        else {
            validInput = true;
        }
        cout << endl;
    }

    if (choice == 0) {
        int num;
        cout << "������� ����� �������� 1 - " << elementsU.size() << " ��� ���������." << endl
            << "����� ��������� ���� ������� 0." << endl << endl;
        while (true) {
            cout << "�����: ";
            cin >> num;
            if (cin.fail() || num < 0 || num > elementsU.size()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������ �����! ��� �������� ��� ����� �������!" << endl;
            }
            else if (num == 0) break;
            else {
                auto it = elementsU.begin();
                advance(it, num - 1);
                int k;
                bool flag = true;
                while (flag) {
                    cout << "������� ��������� �������� �� 1 �� " << it->second << " ������������: ";
                    cin >> k;
                    if (cin.fail() || k < 1 || k > it->second) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "������ �����! ��� ����� ���������!" << endl;
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
//������
void Universum::PrintUni() {
    cout << "* ��������������� ��������� *" << endl;
    if (elementsU.empty()) {
        cout << "������ ���������." << endl;
    }
    else {
        int index = 1;
        for (const auto& pair : elementsU) {
            cout << index++ << ") ";
            for (const auto& elem : pair.first) {
                cout << elem << " ";
            }
            cout << "| ���������: " << pair.second << endl;
        }
    }
    cout << endl;
}
void Universum::PrintSetA() {
    cout << "* ��������������� A *" << endl;
    if (elementsA.empty()) {
        cout << "������ ���������������." << endl << endl;
    }
    else {
        for (const auto& pair : elementsA) {
            for (const auto& elem : pair.first) {
                cout << elem << " ";
            }
            cout << "| ���������: " << pair.second << endl;
        }
    }
}
void Universum::PrintSetB() {
    cout << "* ��������������� � *" << endl;
    if (elementsB.empty()) {
        cout << "������ ���������������." << endl << endl;
    }
    else {
        for (const auto& pair : elementsB) {
            for (const auto& elem : pair.first) {
                cout << elem << " ";
            }
            cout << "| ���������: " << pair.second << endl;
        }
    }
}
void Universum::PrintResult() {
    cout << endl << "* ��������� �������� *" << endl;
    if (result.empty()) {
        cout << "������ ���������." << endl;
    }
    else {
        for (const auto& pair : result) {
            for (const auto& elem : pair.first) {
                cout << elem << " ";
            }
            cout << "| ���������: " << pair.second << endl;
        }
    }
    cout << endl;
}
//����
vector<vector<int>> Universum::GreyCode() {
    vector<int> B(n, 0);
    elementsU[B] = 0;  //��������� �������
    for (int i = 1; i < m; ++i) {
        int elnum = Q(i);
        B[elnum - 1] = 1 - B[elnum - 1];
        elementsU[B] = 0;  //��������� ������� � ��������� ���������� 0 (����� �������� �����)
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
//��������
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
            int complementKratn = pair.second - it->second;  //�������� ����������
            if (complementKratn > 0) {
                result[pair.first] = complementKratn;
            }
        }
        else {
            result[pair.first] = pair.second;  //������� ���� ������ � U
        }
    }

    return result;
}
map<vector<int>, int> Universum::ComplementB() {

    for (const auto& pair : elementsU) {
        auto it = elementsB.find(pair.first);
        if (it != elementsB.end()) {
            int complementKratn = pair.second - it->second;  //�������� ����������
            if (complementKratn > 0) {
                result[pair.first] = complementKratn;
            }
        }
        else {
            result[pair.first] = pair.second;  //������� ���� ������ � U
        }
    }

    return result;
}
map<vector<int>, int> Universum::Union() {
    result = elementsA;  // �������� A � ���������

    for (const auto& pair : elementsB) {
        auto it = result.find(pair.first);
        if (it != result.end()) {
            it->second = max(it->second, pair.second);  // ����� ������������ ���������
        }
        else {
            result[pair.first] = pair.second;  // ��������� ����� �������
        }
    }

    return result;
}
map<vector<int>, int> Universum::Intersection() {

    // ��������� ��������� �� elementsA
    for (const auto& pair : elementsA) {
        auto itB = elementsB.find(pair.first);
        if (itB != elementsB.end()) {  // ������� ���������� � elementsB
            int kratnost = std::min(pair.second, itB->second); // ������� ����������� ��������� ����� A � B

            // ���� ��������� ������ 0, ��������� � ���������
            if (kratnost > 0) {
                result[pair.first] = kratnost;
            }
        }
    }

    // ��������� ��������� �� elementsB
    for (const auto& pair : elementsB) {
        if (result.find(pair.first) != result.end()) continue; // ���������� ��������, ��� ����������� � ���������

        auto itA = elementsA.find(pair.first);
        if (itA != elementsA.end()) {  // ������� ���������� � elementsA
            int kratnost = std::min(pair.second, itA->second);

            // ���� ��������� ������ 0, ��������� � ���������
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
            it->second -= pair.second;  // ��������� ���������
            if (it->second <= 0) {
                result.erase(it);  // ������� �������, ���� ��������� <= 0
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
            it->second -= pair.second;  // ��������� ���������
            if (it->second <= 0) {
                result.erase(it);  // ������� �������, ���� ��������� <= 0
            }
        }
    }

    return result;
}
map<vector<int>, int> Universum::SymmetricDifference() {

    for (const auto& pair : elementsA) { // ������������ �������� �� elementsA
        auto it = elementsB.find(pair.first);
        if (it == elementsB.end()) {
            result[pair.first] = pair.second; // ������� ���� ������ � A
        }
        else {
            int difference = pair.second - it->second; // ������� ���� � �����, �� ��������� �������� ����������
            if (difference != 0) {
                result[pair.first] = abs(difference);
            }
        }
    }
    for (const auto& pair : elementsB) { // ������������ �������� �� elementsB, ������� ��� � elementsA
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
            result[pair.first] += pair.second;  // ���������� ���������

            auto it2 = elementsU.find(pair.first); // ����������� �� ��������� �������������� ���������
            if (it2 != elementsU.end() && result[pair.first] > it2->second) {
                result[pair.first] = it2->second;
            }
        }
        else {
            result[pair.first] = pair.second;  // ��������� ����� �������
        }
    }

    return result;
}
map<vector<int>, int> Universum::SubtractionAB() {
    result = elementsA;

    for (const auto& pair : elementsB) {
        result[pair.first] -= pair.second;  // ��������� ���������

        if (result[pair.first] <= 0) { // ������� �������� � ���������� <= 0
            result.erase(pair.first);
        }
    }

    return result;
}
map<vector<int>, int> Universum::SubtractionBA() {
    result = elementsB;

    for (const auto& pair : elementsA) {
        result[pair.first] -= pair.second;  // ��������� ���������

        if (result[pair.first] <= 0) { // ������� �������� � ���������� <= 0
            result.erase(pair.first);
        }
    }

    return result;
}
map<vector<int>, int> Universum::Multiplication() {
    for (const auto& pair : elementsA) { // �������� �� ��������� �� elementsA � �������� �� ��������� �� elementsB
        auto itB = elementsB.find(pair.first);
        if (itB != elementsB.end()) {
            result[pair.first] = pair.second * itB->second; // �������� ���������, ���� ������� ������������ � ����� ����������
            auto itUni = elementsU.find(pair.first); // ����������� �� �������������� ��������� (elementsU)
            if (itUni != elementsU.end() && result[pair.first] > itUni->second) {
                result[pair.first] = itUni->second;
            }
        }
    }

    return result;
}
map<vector<int>, int> Universum::DivisionAB() {
    for (const auto& pair : elementsA) { // �������� �� ��������� �� elementsA � ����� �� ��������� �� �������� �� elementsB
        auto itB = elementsB.find(pair.first);
        if (itB != elementsB.end() && itB->second != 0) { // ���������, ��� ������� ���� � ����� � ��������� � B �� ����� 0
            result[pair.first] = pair.second / itB->second;  // ����� ���������
            if (result[pair.first] <= 0) { // ������� �������, ���� ��������� ��������� <= 0
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
