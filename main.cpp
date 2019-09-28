#include "Keeper.h"
#include "Child.h"
#include "Grandparents.h"
#include "Parents.h"
#include "Menu.h"

int main() {
	setlocale(LC_ALL, "");

	Keeper<Grandparents> ob1;
	Keeper<Parents> ob2;
	Keeper<Child> ob3;

	int menu;
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "1 - ������� � �������." << endl;
		cout << "2 - ��������." << endl;
		cout << "3 - �������." << endl;
		cout << "4 - �����." << endl;
		cout << "������� �����: "; 
		cin >> menu;
		switch (menu) {
		case 1: Menu(ob1, "Grandparents.txt"); break;
		case 2: Menu(ob2, "Parents.txt"); break;
		case 3: Menu(ob3, "Child.txt"); break;
		case 4: flag = 0; break;
		default: cout << "������" << endl; system("pause"); break;
		}
	}
}