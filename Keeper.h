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
	Keeper() { size = 0; ptr_mas = nullptr; cout << "������ ����������� ������ Keeper" << endl; };
	~Keeper() { delete[] ptr_mas; cout << "������ ���������� ������ Keeper" << endl; };

	void save(string);//������� ���������� (������) � ����
	void read(string);//������� ������ �� �����
	void add();
	void del(int index);
	void print();
};

template<class T>
void Keeper<T>::save(string s){//��������� ���� � �����
	ofstream fout(s, ios::out);
	
	try {
		if (size == 0)
			throw exception("��� ��������� ��� ���������� � ����");

		fout << size << endl;
		for (int i = 0; i < size; i++) {
			fout << ptr_mas[i] << endl;
		}
		cout << "������ � ���� ����������� �������" << endl;
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

	cout << "������ �� ����� ����������� �������" << endl;
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
	if (size == 0)								//���� ������ ����, �� ������� ��������� �� ����, � ������ ��������� ������� �� ����
		cout << "������ ����." << endl;
	else {										//���� ������ �� ����, �� ��������� ������ ����� � ��������� �� ������������ �������
		 
		try {

			if (index > size - 1 || index < 0) 
				throw exception("�������� ������. ��������� ����� �� ������� �������.");
		}
		catch (exception &ex) {
			while (index < 0 || index > size - 1) {
				cout << ex.what() << endl;
				cout << "������� ���������� ������:" << endl;
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
		cout << "������� ������� ������." << endl;		//������� �������� �� �������� ��������
	}
}

template<class T>
void Keeper<T>::print(){

	if (size == 0)
		cout << "��������� ���" << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << ptr_mas[i] << endl;
		}
}