#pragma once
#include "Keeper.h"

class FamilyTree {
protected:
	string Surname_Name_Patronymic;
	string Parent_Knowledge;
	string Spouse_Knowledge;			//������ � �������
	string Children_Knowledge;
	string Date_of_Birth;
	string Date_of_Death;
	int age;
public:
	FamilyTree() { cout << "�������� ����������� ������ FamilyTree" << endl; }
	virtual ~FamilyTree() { cout << "�������� ���������� ������ FamilyTree" << endl; }
};

