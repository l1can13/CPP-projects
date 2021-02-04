#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

double eps = 1.0e-4;

void print_vector(vector<int>& v, int n) //выводит массив
{

	if (n <= 15)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < 15; ++i)
		{
			cout << v[i] << " ";
		}
		cout << "..." << endl;
	}

}

void sort_vector(vector<int>& v, int first, int last)
{

	if (last - first < 2)
		return;
	if (last - first == 2) {
		if (v[first] > v[first + 1])
			swap(v[first], v[first + 1]);
		return;
	}

	sort_vector(v, first, first + (last - first) / 2); // рекурсия
	sort_vector(v, first + (last - first) / 2, last);

	vector<int> a;

	int a1 = first;
	int b = first + (last - first) / 2;
	int a2 = b;

	while (a.size() < last - first) {
		if (a1 >= b || (a2 < last && v[a2] <= v[a1])) {
			a.push_back(v[a2]);
			++a2;
		}
		else {
			a.push_back(v[a1]);
			++a1;
		}
	}

	for (int i = first; i < last; ++i)
		v[i] = a[i - first];

}

void keyboard_vector()
{

	//double eps = 1.0e-10;
	int n;
	vector<int> v;

	cout << "Enter lenght of vector: ";
	while (!(cin >> n) || (cin.peek() != '\n') || (n < 0)) {
		cin.clear();
		cout << "Error! Incorrect number entered, please try again!" << endl;
		while (cin.get() != '\n');
	}
	cout << endl;

	int i = 0;

	cout << "Enter the members of the vector:" << endl;
	while (i < n)
	{
		int buf;
		while (!(cin >> buf) || (cin.peek() != '\n')) {
			cin.clear();
			cout << "Error! Incorrect number entered, please try again!" << endl;
			while (cin.get() != '\n');
		}
		v.push_back(buf);
		++i;
	}

	vector<int> a = v;

	cout << endl << "Unsorted: ";
	print_vector(v, n);

	cout << "Sorted: ";
	double t1 = clock();
	sort_vector(v, 0, v.size());
	double t2 = clock();
	//double t = (t2 - t1) / (double)CLOCKS_PER_SEC;
	print_vector(v, n);

	if (((t2 - t1) / (double)CLOCKS_PER_SEC) < eps)
		cout << "Time of sort less then 0.0001!" << endl;
	else 
		cout << "Time of sort = " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;

	double t3 = clock();
	sort(a.begin(), a.end());
	double t4 = clock();
	//double t5 = (t4 - t3) / (double)CLOCKS_PER_SEC;

	cout << endl << "Sorted by library function: ";
	print_vector(a, n);

	if (((t4 - t3) / (double)CLOCKS_PER_SEC) < eps)
		cout << "Time of library sort less then 0.0001!" << endl;
	else
		cout << "Time of library sort = " << (t4 - t3) / (double)CLOCKS_PER_SEC << endl;

	//double acceleration = t / t5;

	if (((t2 - t1) / (double)CLOCKS_PER_SEC) < eps || ((t4 - t3) / (double)CLOCKS_PER_SEC) < eps)
		cout << "Acceleration too little!" << endl;
	else
		cout << "Acceleration = " << ((t2 - t1) / (double)CLOCKS_PER_SEC) / ((t4 - t3) / (double)CLOCKS_PER_SEC);

}

void rand_vector()
{
	//double eps = 1.0e-4;
	int n;
	vector<int> v;

	cout << "Enter lenght of vector: " << " ";
	while (!(cin >> n) || (cin.peek() != '\n') || (n <= 0)) {
		cin.clear();
		cout << "Error! Incorrect number entered, please try again!" << endl;
		while (cin.get() != '\n');
	}

	cout << endl;

	srand(time(NULL));

	/*for (int i = 0; i < n; ++i) {
		v.push_back(i);
	}

	for (int i = 0; i < v.size(); ++i) {
		swap(v[i], v[rand() % v.size()]);
	}*/

	int num;

	for (int i = 0; i < n; ++i)
	{
		num = rand();
		v.push_back(num);
	}

	vector<int> a = v;

	cout << "Unsorted: ";
	print_vector(v, n);

	double t1 = clock();
	sort_vector(v, 0, v.size());
	double t2 = clock();
	//double t = (t2 - t1) / (double)CLOCKS_PER_SEC;

	cout << "Sorted: ";
	print_vector(v, n);

	if (((t2 - t1) / (double)CLOCKS_PER_SEC) < eps)
		cout << "Time of sort less then 0.0001!" << endl;
	else
		cout << "Time of sort = " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;

	double t3 = clock();
	sort(a.begin(), a.end());
	double t4 = clock();
	//double t5 = (t4 - t3) / (double)CLOCKS_PER_SEC;

	cout << endl << "Sorted by library function: ";
	print_vector(a, n);

	if (((t4 - t3) / (double)CLOCKS_PER_SEC) < eps)
		cout << "Time of library sort less then 0.0001!" << endl;
	else
		cout << "Time of library sort = " << (t4 - t3) / (double)CLOCKS_PER_SEC << endl;

	//double acceleration = t / t5;

	if (((t2 - t1) / (double)CLOCKS_PER_SEC) < eps || ((t4 - t3) / (double)CLOCKS_PER_SEC) < eps)
		cout << "Acceleration too little!" << endl;
	else
		cout << "Acceleration = " << ((t2 - t1) / (double)CLOCKS_PER_SEC) / ((t4 - t3) / (double)CLOCKS_PER_SEC) << endl;

}

void reverse_vector()
{
	//double eps = 1.0e-10;
	int n;
	vector<int> v;

	cout << "Enter lenght of vector: " << " ";

	while (!(cin >> n) || (cin.peek() != '\n') || (n < 0)) {
		cin.clear();
		cout << "Error! Incorrect number entered, please try again!" << endl;
		while (cin.get() != '\n');
	}

	cout << endl;
	srand(time(NULL));

	/*for (int i = 0; i < n; ++i) {
		v.push_back(i);
	}

	for (int i = 0; i < v.size(); ++i) {
		swap(v[i], v[rand() % v.size()]);
	}*/

	int num;

	for (int i = 0; i < n; ++i)
	{
		num = rand();
		v.push_back(num);
	}

	cout << "Unsorted: ";
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	vector<int> a = v;
	print_vector(v, n);

	double t1 = clock();
	sort_vector(v, 0, v.size());
	double t2 = clock();
	//double t = (t2 - t1) / (double)CLOCKS_PER_SEC;

	cout << "Sorted: ";
	print_vector(v, n);

	if (((t2 - t1) / (double)CLOCKS_PER_SEC) < eps)
		cout << "Time of sort less then 0.0001!" << endl;
	else
		cout << "Time of sort = " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;

	double t3 = clock();
	sort(a.begin(), a.end());
	double t4 = clock();
	//double t5 = (t4 - t3) / (double)CLOCKS_PER_SEC;

	cout << endl << "Sorted by library function: ";
	print_vector(a, n);

	if (((t4 - t3) / (double)CLOCKS_PER_SEC) < eps)
		cout << "Time of library sort less then 0.0001!" << endl;
	else
		cout << "Time of library sort = " << (t4 - t3) / (double)CLOCKS_PER_SEC << endl;

	//double acceleration = t / t5;

	if (((t2 - t1) / (double)CLOCKS_PER_SEC) < eps || ((t4 - t3) / (double)CLOCKS_PER_SEC) < eps)
		cout << "Acceleration too little!" << endl;
	else
		cout << "Acceleration = " << ((t2 - t1) / (double)CLOCKS_PER_SEC) / ((t4 - t3) / (double)CLOCKS_PER_SEC);

}

int main()
{
	int choice;
	int flag = 1;
	string ans;

	while (flag == 1) {
		cout << "If you want to choose a reverse sorted random, enter 2, if random vector type, enter 1, if entered by you, 0: " << " ";
		while (!(cin >> choice) || (cin.peek() != '\n') || (choice != 1) && (choice != 0) && (choice != 2)) {
			cin.clear();
			cout << "Incorrect number entered, please try again!" << endl;
			while (cin.get() != '\n');
		}

		/*if (choice == 2)
			reverse_vector();

		if (choice == 1)
			rand_vector();

		if (choice == 0) {
			keyboard_vector();
		}*/

		switch (choice) {
		case 0: keyboard_vector(); break;
		case 1: rand_vector(); break;
		case 2: reverse_vector(); break;
		}

		//flag = 2;

		//while (flag == 2) {
			cout << endl << "Do you want to continue?" << " ";
			while (!(cin >> ans) || (cin.peek() != '\n') || (ans != "yES") && (ans != "yeS") && (ans != "YeS") && (ans != "yEs") && (ans != "YEs") && (ans != "YES") && (ans != "Yes") && (ans != "Y") && (ans != "y") && (ans != "yes") && (ans != "nO") && (ans != "NO") && (ans != "No") && (ans != "N") && (ans != "no") && (ans != "n")) {
				cin.clear();
				cout << "Error! Please enter Y or N: " << " ";
				while (cin.get() != '\n');
			}

			if (ans == "yES" || ans == "yeS" || ans == "YeS" || ans == "yEs" || ans == "YEs" || ans == "YES" || ans == "Yes" || ans == "Y" || ans == "y" || ans == "yes")
				flag = 1;

			if (ans == "nO" || ans == "NO" || ans == "No" || ans == "N" || ans == "no" || ans == "n")
				flag = 0;
			cout << endl;
		//}
	}
}
