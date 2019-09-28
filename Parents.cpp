#include "Parents.h"

Parents::Parents() {
	cout << "�������� ����������� �� ��������� ������ Parents" << endl;
	Surname_Name_Patronymic = "��� ������";
	Parent_Knowledge = "��� ������";
	Spouse_Knowledge = "��� ������";
	Children_Knowledge = "��� ������";
	Date_of_Birth = "��� ������";
	Date_of_Death = "��� ������";
	age = 0;
}

Parents::Parents(const Parents& obj) {
	*this = obj;
}

Parents::~Parents() {
	cout << "�������� ���������� ������ Parents" << endl;
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
	cout << "������� ���: ";
	in >> obj.Surname_Name_Patronymic;

	cout << "������� ������ � ���������: ";
	in >> obj.Parent_Knowledge;

	cout << "������� ������ � �������: ";
	in >> obj.Spouse_Knowledge;

	cout << "������� ������ � �����: ";
	in >> obj.Children_Knowledge;

	cout << "������� ���� ��������: ";
	in >> obj.Date_of_Birth;

	cout << "������� ���� ������: ";
	in >> obj.Date_of_Death;

	cout << "������� �������: ";
	in >> obj.age;

	return in;
}

ostream& operator<<(ostream& out, Parents& obj) {
	out << "���: " << obj.Surname_Name_Patronymic << endl;
	out << "������ � ���������: " << obj.Parent_Knowledge << endl;
	out << "������ � �������: " << obj.Spouse_Knowledge << endl;
	out << "������ � �����: " << obj.Children_Knowledge << endl;
	out << "���� ��������: " << obj.Date_of_Birth << endl;
	out << "���� ������: " << obj.Date_of_Death << endl;
	out << "�������: " << obj.age << endl;
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
