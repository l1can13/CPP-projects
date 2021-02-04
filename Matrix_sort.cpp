// Поразрядная сортировка матрицы
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int flag = 1;
	int rows;
	int columns;
	string ans;
	while (flag == 1) {
		cout << "Enter n > ";
		while (!(cin >> rows) || (cin.peek() != '\n') || (rows <= 0)) {
			cin.clear();
			cout << "Error! Please enter correct value > ";
			while (cin.get() != '\n');
		}

		cout << "Enter m > ";
		while (!(cin >> columns) || (cin.peek() != '\n') || (columns <= 0)) {
			cin.clear();
			cout << "Error! Please enter correct value > ";
			while (cin.get() != '\n');
		}

		vector<vector <int>> v(rows, vector<int>(columns));

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				cout << "Enter the element (" << i + 1 << ";" << j + 1 << ") > ";
				while (!(cin >> v[i][j]) || (cin.peek() != '\n')) {
					cin.clear();
					cout << "Error! Please enter correct value > ";
					while (cin.get() != '\n');
				}
			}
			cout << endl;
		}

		cout << "Initial matrix:" << endl;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				cout << v[i][j] << "\t";
			}
			cout << endl;
		}

		int x, k = 0;
		for (int y = 0; y < rows; ++y) {
			for (int i = 0; i < (rows - 1); ++i) {
				for (k = 0; k < columns; k++) {
					if (v[i][columns - k - 1] > v[i + 1][columns - k - 1]) {
						for (int j = 0; j < columns; ++j) {
							x = v[i][j];
							v[i][j] = v[i + 1][j];
							v[i + 1][j] = x;
						}
					}
				}
			}
		}

	
		cout << endl << "Sorted matrix:" << endl;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				cout << v[i][j] << "\t";
			}
			cout << endl;
		}

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
	}

}
