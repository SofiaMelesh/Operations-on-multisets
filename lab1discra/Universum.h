#pragma once
#include <vector>
#include <map>
#include "Grey.h"
#include <iostream>
using namespace std;

class Universum
{
private:
	int n; //разрядность
	int m; //мощность 2^n

	//Universum
	map<vector <int>, int> elementsU; //элементы
	vector <int> kratnU;//кратности

	//A
	map<vector<int>, int> elementsA;
	vector <int> kratnA;

	//B
	map<vector<int>, int> elementsB;
	vector <int> kratnB;

	map<vector<int>, int> result;

public:

	Universum(int razr);

	void CreateSetA();
	void CreateSetB();

	vector<vector<int>> GreyCode();
	int Q(int i);

	void PrintUni();
	void PrintSetA();
	void PrintSetB();
	void PrintResult();

	//операции
	void Operations(int op);
	map<vector<int>, int> ComplementA();
	map<vector<int>, int> ComplementB();
	map<vector<int>, int> Union();
	map<vector<int>, int> Intersection();
	map<vector<int>, int> DifferenceAB();
	map<vector<int>, int> DifferenceBA();
	map<vector<int>, int> SymmetricDifference();
	map<vector<int>, int> Addition();
	map<vector<int>, int> SubtractionAB();
	map<vector<int>, int> SubtractionBA();
	map<vector<int>, int> Multiplication();
	map<vector<int>, int> DivisionAB();
	map<vector<int>, int> DivisionBA();
};


