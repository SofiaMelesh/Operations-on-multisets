#include <iostream>
#include "func.h"
#include "Universum.h"
#include "Grey.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Start(); //�������������� ����

	Universum universum(UniversumInput()); //�������� ���� � ����� 
	universum.PrintUni(); //������� ���������

	AInput(); //�������� ��������� �
	universum.CreateSetA();
	universum.PrintSetA();

	BInput(); //�������� ��������� B
	universum.CreateSetB();
	universum.PrintSetB();

	int tmp = 1;
	Menu();
	while (tmp) {
		tmp = OperationsMenu();
		universum.Operations(tmp); //���� ��������
		if (tmp == 0) break;
		universum.PrintResult(); //��������� ��������
		tmp = Continue();
	};
	Bye();



	return 0;
}