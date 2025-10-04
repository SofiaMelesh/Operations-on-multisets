#include "func.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Start() {
    cout << endl << "*********************"<<endl
               <<   "* ����� ����������! *" << endl << 
                    "*********************" << endl << endl << "����������: " << endl <<
        "������ ���������� ��������� ��������� ��������� ��������� ���� ���� " <<
        "��� ���������� ���������� �������������. " << endl 
        << "�� ������ ���������� ����������� " <<
        "��� ��������������� (������������� ��� �������), " << endl
        << "��� �������� ����� ��������� ��������� ��������." << endl << endl << endl;

};

int UniversumInput() {
    cout << endl << "**************************************************************" << endl
                <<  "* ������� ����������� ��������� ��������������� n (0<=n<=10) *" << endl<<
                    "**************************************************************" << endl << endl;

    int n;
    bool validInput = false;

    cout << "�����������: ";
    while (!validInput) {
        cin >> n;
        if (cin.fail() || n > 10 || n < 0) {
            cin.clear(); //������� ����� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //������� ������ �����
            cout << "������ �����! ������� ����� �� 0 �� 10 ������������!" << endl;
        }
        else {
            validInput = true; //���� ���������
        }
    }
    cout << endl;
    return n;
}

void AInput() {
    cout  << endl << endl << "************************" << endl
        <<                   "* �������� ��������� � *" << endl <<
                             "************************" << endl << endl;
}

void BInput() {
    cout << endl << endl << endl << "************************" << endl
        <<                          "* �������� ��������� B *" << endl <<
                                    "************************" << endl << endl;
}

void Menu() {
    cout << endl << endl << endl << "*******************************************************" << endl
        << "* ���� ��������� �������� ��� ����������������� A � B *" << endl <<
        "*******************************************************";
}

int OperationsMenu() { 
    cout << endl << endl<< "* ���������� �������� *                 * �������� �������������� �������� *" << endl << endl;
    cout << "1) ���������� �                              8) ����� A + B" << endl
        << "2) ���������� �                              9) �������� � - �" << endl
        << "3) ����������� A � B                         10) �������� B - A" << endl
        << "4) ����������� � � B                         11) ������������ A * B" << endl
        << "5) �������� � \\ B                            12) ������� � \\ �" << endl
        << "6) �������� � \\ �                            13) ������� � \\ �" << endl
        << "7) �������������� ��������" << endl << endl
        << "                     ��� ������ �� ���������� ������� 0"<<endl<<endl;
    cout << "������� ����� ������ �������� (�� 0 �� 13 ������������)" << endl << endl;

    int op;
    bool validInput = false;
    while (!validInput) {
        cout << "����: ";
        cin >> op;
        if (cin.fail() || op < 0 || op > 13) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������ �����! ������� ����� �� 0 �� 13 ������������!" << endl;
        }
        else if (op == 0) {
            return 0 ;
        }
        else return op;
    }
}
void Bye() {
    cout << endl << "********************" << endl
        << "* �� ����� ������! *" << endl <<
        "********************" << endl << endl;
}

int Continue() {
    cout << endl << "* ������ �� �� ���������� ������ �� �����������? 1 - ��, 0 - ���. *" << endl << endl;
    int op;
    bool validInput = false;
    while (!validInput) {
        cout << "����: ";
        cin >> op;
        if (cin.fail() || op < 0 || op > 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������ �����! ������� ���� 0, ���� 1!" << endl;
        }
        else return op;
    }
}
