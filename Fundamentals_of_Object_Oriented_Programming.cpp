/* Реализовать на C++ консольное приложение, предназначенное
для работы с массивом экземпляров класса. Входные данные:
количество элементов массива, экземпляры класса. Выходные
данные: массив экземпляров класса и массив результатов работы
метода по обработке данных.*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Students
{

private:

	ifstream fin;
	ofstream fout;
	string name;
	int marks[3];

public:

	Students() {}
	Students(string names, int b[3])
	{
		name = names;
		marks[0] = b[0];
		marks[1] = b[1];
		marks[2] = b[2];
	}

	~Students() {
	}

	Students(const Students& students) 
	{
		name = students.name;
		marks[0] = students.marks[0];
		marks[1] = students.marks[1];
		marks[2] = students.marks[2];
	}

	string print_vector()
	{
		return name;
	}

	bool is_space(std::string& str)
	{
		for (unsigned char c : str) {
			if (!isspace(c)) {
				return false;
			}
		}
		return true;
	}

	bool is_alpha(std::string& str)
	{
		for (unsigned char c : str) {
			if (!isalpha(c)) {
				return false;
			}
		}
		return true;
	}

	bool is_digit(std::string& str)
	{
		for (auto c : str) {
			if (!isdigit(c)) {
				return false;
			}
		}
		return true;
	}

	void erase_space(string& s)
	{
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == ' ') {
				s.erase(i, 1);
			}
		}
	}

	double average_mark()
	{
		double sum = 0.0;
		for (int i = 0; i <= 2; ++i)
		{
			sum += marks[i];
		}
		return sum / 3;
	}
	friend ifstream& operator >> (ifstream& in, Students& students);
	friend ostream& operator << (ostream& out, Students& students);
	friend istream& operator >> (istream& in, Students& students);

};

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include "Class.h"

//ostream& operator<<(ostream& out, Students& students)
//{
//	std::cout << std::endl << "Select the type of output : 1 - if in a file, 0 - if in the console > ";
//	while (!(std::cin >> students.ch) || (std::cin.peek() != '\n') || (students.ch != 0) && (students.ch != 1)) {
//		std::cin.clear();
//		std::cout << "Error! Please enter 0 or 1 > ";
//		while (std::cin.get() != '\n');
//	}
//
//	switch (students.ch) {
//	case 0:
//		std::cout << std::endl;
//		for (int i = 0; i < students.n; ++i) {
//			std::cout << "Average mark for " << students.v[i].print_vector() << " " << students.avg[i] << std::endl;
//		}
//		break;
//
//	case 1:
//
//		students.fout.open("output.txt");
//		if (!students.fout.is_open()) {
//			std::cout << "Error! File is not open!";
//		}
//		else {
//			for (int i = 0; i < students.n; ++i) {
//				std::cout << std::endl;
//				students.fout << "Average mark for " << students.v[i].print_vector() << " " << students.avg[i] << std::endl;
//			}
//		}
//		students.fout.close();
//		break;
//	}
//	return out;
//}

//istream& operator>>(istream& in, Students& students)
//{
//
//	std::cout << "Select the type of input data : 1 - if from a file, 0 - if from the console > ";
//	while (!(in >> students.choice) || (in.peek() != '\n') || (students.choice != 1) && (students.choice != 0)) {
//		std::cin.clear();
//		std::cout << "Error! Please enter 0 or 1 > ";
//		while (std::cin.get() != '\n');
//	}
//
//	switch (students.choice) {
//	case 1:
//
//		students.fin.open("amount.txt");
//		if (!students.fin.is_open()) {
//			std::cout << "Error! File is not open.";
//		}
//		else {
//			students.fin >> students.n;
//		}
//		if (isdigit(students.n) || students.n < 1) {
//			std::cout << "Error! Incorrect data in 'amount.txt'";
//			return in;
//		}
//		students.fin.close();
//
//		students.fin.open("names.txt");
//		if (!students.fin.is_open()) {
//			std::cout << "Error! File is not open.";
//		}
//		else {
//			for (int i = 0; i < students.n; ++i) {
//				while (!students.fin.eof()) {
//					students.fin >> students.s;
//					if (students.is_alpha(students.s)) {
//						students.v.push_back(Students(students.s));
//					}
//					else {
//						std::cout << "Error! Incorrect data in 'names.txt'" << std::endl;
//						return in;
//					}
//				}
//			}
//			if (students.v.size() != students.n) {
//				std::cout << "Error! Data inconsistency between files 'amount.txt' and 'names.txt'" << std::endl;
//				return in;
//			}
//			students.fin.close();
//
//			students.fin.open("marks.txt");
//			if (!students.fin.is_open()) {
//				std::cout << "Error! File is not open.";
//			}
//			else {
//				while (!students.fin.eof()) {
//					for (int i = 0; i < students.v.size(); ++i) {
//						std::cout << std::endl << "Name of student > " << students.v[i].print_vector() << " - ";
//						std::getline(students.fin, students.s);
//						students.erase_space(students.s);
//						if (students.is_digit(students.s) && !students.is_space(students.s)) {
//							for (int i = 0; i < students.s.size(); ++i) {
//								students.marks.push_back(students.s[i] - '0');
//							}
//							for (int j = 0; j < students.marks.size(); ++j) {
//								std::cout << students.marks[j] << " ";
//							}
//						}
//						else {
//							std::cout << "Error! Incorrect data in 'marks.txt'" << std::endl;
//							return in;
//						}
//						students.avg.push_back(students.average_mark(students.marks));
//						students.marks.clear();
//					}
//				}
//			}
//			std::cout << std::endl;
//			students.fin.close();
//			break;
//		}
//
//	case 0:
//
//		std::cout << "Enter amount of names vector > ";
//		while (!(in >> students.n) || (in.peek() != '\n') || students.n < 1) {
//			std::cin.clear();
//			std::cout << "Error! Incorrect value entered, please try again > ";
//			while (std::cin.get() != '\n');
//		}
//
//		for (int i = 0; i < students.n; ++i) {
//			std::cout << "\nEnter name > ";
//			while (!(std::cin >> students.name) || (in.peek() != '\n') || !students.is_alpha(students.name)) {
//				std::cin.clear();
//				std::cout << "Error! Incorrect value entered, please try again > ";
//				while (std::cin.get() != '\n');
//			}
//			students.v.push_back(Students(students.name));
//			std::cout << "Enter amount of marks > ";
//			while (!(in >> students.m) || (in.peek() != '\n') || students.m < 1) {
//				std::cin.clear();
//				std::cout << "Error! Incorrect value entered, please try again > ";
//				while (std::cin.get() != '\n');
//			}
//
//			std::cout << std::endl;
//			for (int j = 1; j < students.m + 1; ++j) {
//				std::cout << "Enter mark #" << j << " > ";
//				while (!(std::cin >> students.marksint) || (in.peek() != '\n') || (students.marksint != 2) && (students.marksint != 3) && (students.marksint != 4) && (students.marksint != 5)) {
//					std::cin.clear();
//					std::cout << "Error! Incorrect value entered, please try again > ";
//					while (std::cin.get() != '\n');
//				}
//				students.marks.push_back(students.marksint);
//			}
//			students.avg.push_back(students.average_mark(students.marks));
//			students.marks.clear();
//		}
//	}
//	return in;
//}

ostream& operator << (ostream& out, Students& students) {

	if (students.name == "Incorrect input of marks.") {
		out << students.name;
	}
	else {
		out << students.name << "'s average mark: " << students.average_mark();
	}
	return out;

}

istream& operator >> (istream& in, Students& students)
{

	while (!(in >> students.name) || (in.peek() != '\n') || !students.is_alpha(students.name)) {
		in.clear();
		std::cout << "Error! Incorrect value entered, please try again > ";
		while (std::cin.get() != '\n');
	}

	std::cout << "Enter mark #1 > ";
	while (!(in >> students.marks[0]) || (in.peek() != '\n') || (students.marks[0] > 5 && students.marks[0] <= 0)) {
		in.clear();
		std::cout << "Error! Incorrect value entered, please, try again > ";
		while (in.get() != '\n');
	}

	std::cout << "Enter mark #2 > ";
	while (!(in >> students.marks[1]) || (in.peek() != '\n') || (students.marks[1] > 5 && students.marks[1] <= 0)) {
		in.clear();
		std::cout << "Error! Incorrect value entered, please, try again > ";
		while (in.get() != '\n');
	}

	std::cout << "Enter mark #3 > ";
	while (!(in >> students.marks[2]) || (in.peek() != '\n') || (students.marks[2] > 5 && students.marks[2] <= 0)) {
		in.clear();
		std::cout << "Error! Incorrect value entered, please, try again > ";
		while (in.get() != '\n');
	}

	return in;

}

ifstream& operator >> (ifstream& in, Students& students)
{

	in >> students.name;
	if (!(in >> students.marks[0]) || (students.marks[0] > 5 || students.marks[0] <= 0)) {
		in.clear();
		while (in.get() != ' ');
		students.name = "Incorrect input of marks.";
	}
	if (!(in >> students.marks[1]) || (students.marks[1] > 5 || students.marks[1] <= 0)) {
		in.clear();
		while (in.get() != ' ');
		students.name = "Incorrect input of marks.";
	}
	if (!(in >> students.marks[2]) || (students.marks[2] > 5 || students.marks[2] <= 0)) {
		in.clear();
		while (in.get() != '\n');
		students.name = "Incorrect input of marks.";
	}

	return in;

}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Students> v;
	std::cout << "Select the type of input data : 1 - if from a file, 0 - if from the console > ";
	int choice;
	while (!(std::cin >> choice) || (std::cin.peek() != '\n') || (choice != 0) && (choice != 1)) {
		std::cin.clear();
		std::cout << "Error! Incorrect value entered, please, try again > ";
		while (std::cin.get() != '\n');
	}

	switch (choice) {
	case 0:
		std::cout << "Enter amount of students > ";
		int n;
		while (!(cin >> n) || (cin.peek() != '\n') || (n < 0)) {
			cin.clear();
			std::cout << "Error! Incorrect value entered, please, try again > ";
			while (std::cin.get() != '\n');
		}
		std::cout << "Enter names > ";
		for (int i = 0; i < n; i++) {
			Students students;
			cin >> students;
			v.push_back(students);
		}
		break;
	case 1:
		string s;
		ifstream fin("input.txt");
		if (fin.is_open()) {
			Students students;
			for (int i = 0; i < 3; i++) {
				fin >> students;
				v.push_back(students);
			}
		}
		else {
			std::cout << "File is not found. Please, try again: ";
		}
		fin.close();
		break;
	}

	int ch;
	std::cout << "Select the type of output : 1 - if in a file, 0 - if in the console > ";
	while (!(std::cin >> ch) || (std::cin.peek() != '\n') || (ch != 0) && (ch != 1)) {
		std::cin.clear();
		std::cout << "Error! Incorrect value entered, please, try again > ";
		while (std::cin.get() != '\n');
	}

	switch (ch) {
	case 0:
		for (int i = 0; i < v.size(); i++) {
			std::cout << v[i] << endl;
		}
		break;
	case 1:
		ofstream fout("output.txt");
		for (int i = 0; i < v.size(); i++) {
			fout << v[i] << endl;
		}
		break;
	}
}
