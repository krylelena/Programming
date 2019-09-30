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
	Keeper() { size = 0; ptr_mas = nullptr; cout << "Âûçâàí êîíñòðóêòîð êëàññà Keeper" << endl; };
	~Keeper() { delete[] ptr_mas; cout << "Âûçâàí äåñòðóêòîð êëàññà Keeper" << endl; };

	void save(string);//ôóíêöèÿ ñîõðàíåíèÿ (çàïèñè) â ôàéë
	void read(string);//ôóíêöèÿ ÷òåíèÿ èç ôàéëà
	void add();
	void del(int index);
	void print();
};

template<class T>
void Keeper<T>::save(string s){//ïðèíèìàåì ïóòü ê ôàéëó
	ofstream fout(s, ios::out);
	
	try {
		if (size == 0)
			throw exception("Íåò ýëåìåíòîâ äëÿ ñîõðàíåíèÿ â ôàéë");

		fout << size << endl;
		for (int i = 0; i < size; i++) {
			fout << ptr_mas[i] << endl;
		}
		cout << "Çàïèñü â ôàéë çàâåðøèëàñü óñïåøíî" << endl;
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

	cout << "×òåíèå èç ôàéëà çàâåðøèëîñü óñïåøíî" << endl;
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
	if (size == 0)								//Åñëè ìàññèâ ïóñò, òî âûâîäèì ñîîáùåíèå îá ýòîì, è äàëüøå âûïîëíÿòü ôóíêöèþ íå íàäî
		cout << "Ìàññèâ ïóñò." << endl;
	else {										//Åñëè ìàññèâ íå ïóñò, òî âûïîëíÿåì äðóãóþ âåòêó ñ ïðîâåðêîé íà êîððåêòíîñòü èíäåêñà
		 
		try {

			if (index > size - 1 || index < 0) 
				throw exception("Íåâåðíûé èíäåêñ. Ïðîèçîøåë âûõîä çà ãðàíèöû ìàññèâà.");
		}
		catch (exception &ex) {
			while (index < 0 || index > size - 1) {
				cout << ex.what() << endl;
				cout << "Ââåäèòå êîððåêòíûé èíäåêñ:" << endl;
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
		cout << "Ýëåìåíò óñïåøíî óäàëåí." << endl;		//ñîáùåíèå îá óñïåøíîì óäàëåíèè
	}
}

template<class T>
void Keeper<T>::print(){

	if (size == 0)
		cout << "Ýëåìåíòîâ íåò" << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << ptr_mas[i] << endl;
		}
}
