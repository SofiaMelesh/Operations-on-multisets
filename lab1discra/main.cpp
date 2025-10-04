#include <iostream>
#include "func.h"
#include "Universum.h"
#include "Grey.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Start(); //приветственное окно

	Universum universum(UniversumInput()); //передаем ввод в класс 
	universum.PrintUni(); //выводим универсум

	AInput(); //создадим множество ј
	universum.CreateSetA();
	universum.PrintSetA();

	BInput(); //создадим множество B
	universum.CreateSetB();
	universum.PrintSetB();

	int tmp = 1;
	Menu();
	while (tmp) {
		tmp = OperationsMenu();
		universum.Operations(tmp); //меню операций
		if (tmp == 0) break;
		universum.PrintResult(); //результат операции
		tmp = Continue();
	};
	Bye();



	return 0;
}