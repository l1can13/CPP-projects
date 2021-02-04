// Fractional Calculator.
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char choice;
	long double state = 0.0, operand;
	int flag = 1;
	string ans;

	cout << "Initial state: 0.0" << endl;

	while (flag == 1) {

		cout << "Enter what kind of operationg you want to do: (+, -, *, /) > ";
		while (!(cin >> choice) || (cin.peek() != '\n') || (choice != '+') && (choice != '-') && (choice != '*') && (choice != '/')) {
			cin.clear();
			cout << "Error! Please enter (+, -, * or /) > ";
			while (cin.get() != '\n');
		}

		cout << "Enter an operand > ";
		while (!(cin >> operand) || (cin.peek() != '\n')) {
			cin.clear();
			cout << "Error! Please enter correct value > ";
			while (cin.get() != '\n');
		}

		/*if (choice == '+') {
			state += operand;
		}

		if (choice == '-') {
			state -= operand;
		}

		if (choice == '*') {
			state *= operand;
		}

		if (choice == '/') {
			state /= operand;
		}*/

		switch (choice) {
		case '+': state += operand; break;
		case '-': state -= operand; break;
		case '*': state *= operand; break;
		case '/': {
			while (operand == 0) {
				cout << "Error! Please enter correct value > ";
				cin >> operand;
			}
			state /= operand;
			break;
		}
		}

		cout << endl << "Result: " << state << endl;

		flag = 2;

		while (flag == 2) {

			cout << endl << "Do you want to continue? > ";

			while (!(cin >> ans) || (cin.peek() != '\n') || (ans != "yES") && (ans != "yeS") && (ans != "YeS") && (ans != "yEs") && (ans != "YEs") && (ans != "YES") && (ans != "Yes") && (ans != "Y") && (ans != "y") && (ans != "yes") && (ans != "nO") && (ans != "NO") && (ans != "No") && (ans != "N") && (ans != "no") && (ans != "n")) {

				cin.clear();
				cout << "Error! Please enter Y or N > ";
				while (cin.get() != '\n');

			}

			if (ans == "yES" || ans == "yeS" || ans == "YeS" || ans == "yEs" || ans == "YEs" || ans == "YES" || ans == "Yes" || ans == "Y" || ans == "y" || ans == "yes")
				flag = 1;

			if (ans == "nO" || ans == "NO" || ans == "No" || ans == "N" || ans == "no" || ans == "n")
				flag = 0;
			cout << endl;
		}
	}

}
