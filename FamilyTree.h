#pragma once
#include "Keeper.h"

class FamilyTree {
protected:
	string Surname_Name_Patronymic;
	string Parent_Knowledge;
	string Spouse_Knowledge;			//знание о супруге
	string Children_Knowledge;
	string Date_of_Birth;
	string Date_of_Death;
	int age;
public:
	FamilyTree() { cout << "Вызвался конструктор класса FamilyTree" << endl; }
	virtual ~FamilyTree() { cout << "Вызвался деструктор класса FamilyTree" << endl; }
};

