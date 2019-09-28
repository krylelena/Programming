#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
 
using namespace std;

template <class T>
class Keeper {
	T* ptr_mas;
	int size;
public: 
	Keeper() { size = 0; ptr_mas = nullptr; cout << "Вызван конструктор класса Keeper" << endl; };
	~Keeper() { delete[] ptr_mas; cout << "Вызван деструктор класса Keeper" << endl; };

	void save(string);//функция сохранения (записи) в файл
	void read(string);//функция чтения из файла
	void add();
	void del(int index);
	void print();
};

template<class T>
void Keeper<T>::save(string s){//принимаем путь к файлу
	ofstream fout(s, ios::out);
	
	try {
		if (size == 0)
			throw exception("Нет элементов для сохранения в файл");

		fout << size << endl;
		for (int i = 0; i < size; i++) {
			fout << ptr_mas[i] << endl;
		}
		cout << "Запись в файл завершилась успешно" << endl;
	}
	catch(exception &ex){
		cout << ex.what() << endl;
	}
	fout.close();
}

template<class T>
void Keeper<T>::read(string s){
	ifstream fin(s, ios::in);

	fin >> size;

	if (ptr_mas != nullptr)
		delete[] ptr_mas;

	ptr_mas = new T[size];

	for (int i = 0; i < size; i++) {
		fin >> ptr_mas[i];
	}

	cout << "Чтение из файла завершилось успешно" << endl;
	fin.close();
}

template<class T>
void Keeper<T>::add(){
	T* tmp = new T[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = ptr_mas[i];
	}
	delete[] ptr_mas;
	cin >> tmp[size];
	ptr_mas = tmp;
	size++;
}

template<class T>
void Keeper<T>::del(int index){
	if (size == 0)								//Если массив пуст, то выводим сообщение об этом, и дальше выполнять функцию не надо
		cout << "Массив пуст." << endl;
	else {										//Если массив не пуст, то выполняем другую ветку с проверкой на корректность индекса
		 
		try {

			if (index > size - 1 || index < 0) 
				throw exception("Неверный индекс. Произошел выход за границы массива.");
		}
		catch (exception &ex) {
			while (index < 0 || index > size - 1) {
				cout << ex.what() << endl;
				cout << "Введите корректный индекс:" << endl;
				cin >> index;
			}
		}

		T* tmp = new T[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index)
				tmp[j++] = ptr_mas[i];
		}
		delete[] ptr_mas;
		ptr_mas = tmp;
		size--;
		cout << "Элемент успешно удален." << endl;		//Добавил собщение об успешном удалении
	}
}

template<class T>
void Keeper<T>::print(){

	if (size == 0)
		cout << "Элементов нет" << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << ptr_mas[i] << endl;
		}
}