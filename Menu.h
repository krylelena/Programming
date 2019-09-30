#pragma once
#include "Keeper.h"

template <typename T>
void Menu(T& obj, string s) {
	int menu;
	int index;
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "1 - Äîáàâëåíèå." << endl;
		cout << "2 - Óäàëåíèå." << endl;
		cout << "3 - ×òåíèå èç ôàéëà." << endl;
		cout << "4 - Çàïèñü â ôàéë." << endl;
		cout << "5 - Âûâîä äàííûõ íà ýêðàí." << endl;
		cout << "6 - Âûõîä â îñíîâàíîå ìåíþ." << endl;

		cout << "Ââåäèòå ïóíêò: ";
		cin >> menu;
		switch (menu) {
		case 1: obj.add(); break;
		
		case 2: obj.print(); cout << "Ââåäèòå ýëåìåíò, êîòîðûé íóæíî óäàëèòü: "; cin >> index; obj.del(index); system("pause"); break;
		case 3: obj.read(s); system("pause"); break;
		case 4: obj.save(s); system("pause"); break;
		case 5: obj.print(); system("pause"); break;
		case 6: flag = 0; break;
		default: cout << "Îøèáêà" << endl; system("pause"); break;
		}
	}
}
