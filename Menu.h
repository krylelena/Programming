#pragma once
#include "Keeper.h"

template <typename T>
void Menu(T& obj, string s) {
	int menu;
	int index;
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "1 - Добавление." << endl;
		cout << "2 - Удаление." << endl;
		cout << "3 - Чтение из файла." << endl;
		cout << "4 - Запись в файл." << endl;
		cout << "5 - Вывод данных на экран." << endl;
		cout << "6 - Выход в основаное меню." << endl;

		cout << "Введите пункт: ";
		cin >> menu;
		switch (menu) {
		case 1: obj.add(); break;
		
		//Добавили system("pause"), чтобы можно было увидеть, что произошло с массивом, либо удалили элемент, либо массив пуст
		case 2: obj.print(); cout << "Введите элемент, который нужно удалить: "; cin >> index; obj.del(index); system("pause"); break;
		case 3: obj.read(s); system("pause"); break;
		case 4: obj.save(s); system("pause"); break;
		case 5: obj.print(); system("pause"); break;
		case 6: flag = 0; break;
		default: cout << "Ошибка" << endl; system("pause"); break;
		}
	}
}