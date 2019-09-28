#pragma once
#include "Keeper.h"

template <typename T>
void Menu(T& obj, string s) {
	int menu;
	int index;
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "1 - ����������." << endl;
		cout << "2 - ��������." << endl;
		cout << "3 - ������ �� �����." << endl;
		cout << "4 - ������ � ����." << endl;
		cout << "5 - ����� ������ �� �����." << endl;
		cout << "6 - ����� � ��������� ����." << endl;

		cout << "������� �����: ";
		cin >> menu;
		switch (menu) {
		case 1: obj.add(); break;
		
		//�������� system("pause"), ����� ����� ���� �������, ��� ��������� � ��������, ���� ������� �������, ���� ������ ����
		case 2: obj.print(); cout << "������� �������, ������� ����� �������: "; cin >> index; obj.del(index); system("pause"); break;
		case 3: obj.read(s); system("pause"); break;
		case 4: obj.save(s); system("pause"); break;
		case 5: obj.print(); system("pause"); break;
		case 6: flag = 0; break;
		default: cout << "������" << endl; system("pause"); break;
		}
	}
}