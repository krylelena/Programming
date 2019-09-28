#include "Parents.h"

Parents::Parents() {
	cout << "Вызвался конструктор по умолчанию класса Parents" << endl;
	Surname_Name_Patronymic = "Нет данных";
	Parent_Knowledge = "Нет данных";
	Spouse_Knowledge = "Нет данных";
	Children_Knowledge = "Нет данных";
	Date_of_Birth = "Нет данных";
	Date_of_Death = "Нет данных";
	age = 0;
}

Parents::Parents(const Parents& obj) {
	*this = obj;
}

Parents::~Parents() {
	cout << "Вызвался деструктор класса Parents" << endl;
}

Parents& Parents::operator=(const Parents& other) {
	this->Surname_Name_Patronymic = other.Surname_Name_Patronymic;
	this->Parent_Knowledge = other.Parent_Knowledge;
	this->Children_Knowledge = other.Children_Knowledge;
	this->Spouse_Knowledge = other.Spouse_Knowledge;
	this->Date_of_Birth = other.Date_of_Birth;
	this->Date_of_Death = other.Date_of_Death;
	this->age = other.age;
	return *this;
}

istream& operator>>(istream& in, Parents& obj) {
	cout << "Введите ФИО: ";
	in >> obj.Surname_Name_Patronymic;

	cout << "Введите Знание о родителях: ";
	in >> obj.Parent_Knowledge;

	cout << "Введите Знание о супруге: ";
	in >> obj.Spouse_Knowledge;

	cout << "Введите Знание о детях: ";
	in >> obj.Children_Knowledge;

	cout << "Введите Дату Рождения: ";
	in >> obj.Date_of_Birth;

	cout << "Введите Дату смерти: ";
	in >> obj.Date_of_Death;

	cout << "Введите возраст: ";
	in >> obj.age;

	return in;
}

ostream& operator<<(ostream& out, Parents& obj) {
	out << "ФИО: " << obj.Surname_Name_Patronymic << endl;
	out << "Знание о родителях: " << obj.Parent_Knowledge << endl;
	out << "Знание о супруге: " << obj.Spouse_Knowledge << endl;
	out << "Знание о детях: " << obj.Children_Knowledge << endl;
	out << "Дата Рождения: " << obj.Date_of_Birth << endl;
	out << "Дата Смерти: " << obj.Date_of_Death << endl;
	out << "Возраст: " << obj.age << endl;
	return out;
}

ofstream& operator<<(ofstream& fout, Parents& obj)
{
	fout << obj.Surname_Name_Patronymic << endl;
	fout << obj.Parent_Knowledge << endl;
	fout << obj.Spouse_Knowledge << endl;
	fout << obj.Children_Knowledge << endl;
	fout << obj.Date_of_Birth << endl;
	fout << obj.Date_of_Death << endl;
	fout << obj.age << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Parents& obj)
{
	fin >> obj.Surname_Name_Patronymic;
	fin >> obj.Parent_Knowledge;
	fin >> obj.Spouse_Knowledge;
	fin >> obj.Children_Knowledge;
	fin >> obj.Date_of_Birth;
	fin >> obj.Date_of_Death;
	fin >> obj.age;
	return fin;
}
