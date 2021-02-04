#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x;
	double alpha;
	double alphan;
	double an;
	double an1;
	double s;
	int n;
	int flag = 1;

	while (flag == 1) {
		cout << "Please enter x: ";
		while (!(cin >> x) || (cin.peek() != '\n') || (x < (-1)) || (x > 1)) {
			cin.clear();
			cout << "Error! Incorrect number entered, please try again: " << endl;
			while (cin.get() != '\n');
		}
		cout << "Please enter alpha: ";
		while (!(cin >> alpha) || (cin.peek() != '\n') || (alpha <= 0)) {
			cin.clear();
			cout << "Error! Incorrect value entered, please try again: " << endl;
			while (cin.get() != '\n');
		}
		if ((int)alpha != 0) {
			s = 0;
			n = alpha;
			/*cout << "Please enter x: ";
			while (!(cin >> x) || (cin.peek() != '\n') || (x < (-1)) || (x > 1)) {
				cin.clear();
				cout << "Error! Incorrect number entered, please try again: " << endl;
				while (cin.get() != '\n');
			}*/
			for (int alpha = 1; alpha <= n; alpha++) {
				an = pow((-1), (alpha + 1)) * (pow(x, 2 * alpha) / (2 * alpha * (2 * alpha - 1)));
				s += an;
				an1 = pow((-1), alpha) * (pow(x, (2 * alpha + 2)) / ((2 * alpha + 2) * (2 * alpha + 1)));
				alphan = fabs(an1 / s);
				if (x == 0) {
					an = 0;
					s = 0;
					an1 = 0;
					alphan = 0;
				}
				cout << "n = " << alpha << " " << "an = " << an << " " << "s = " << s << " " << "alphan = " << alphan << endl << endl;
			}
		}
		else
		{
			int n;
			alphan = 1;
			an1 = 1;
			s = 0;
			n = 1;
			/*cout << "Please enter x: ";
			while (!(cin >> x) || (cin.peek() != '\n') || (x < (-1)) || (x > 1)) {
				cin.clear();
				cout << "Error! Incorrect value entered, please try again: " << endl;
				while (cin.get() != '\n');
			}*/
			while (fabs(alphan) > alpha) {
				an = pow((-1), (n + 1)) * (pow(x, 2 * n) / (2 * n * (2 * n - 1)));
				an1 = pow((-1), n) * (pow(x, (2 * n + 2)) / ((2 * n + 2) * (2 * n + 1)));
				s += an;
				alphan = fabs(an1 / s);
				if (x == 0) {
					an = 0;
					an1 = 0;
					s = 0;
					alphan = 0;
				}
				cout << "n = " << n << " " << "an = " << an << " " << "s = " << s << " " << "alphan = " << alphan << endl << endl;
				n++;
			}
		}
		string ans;
		flag = 2;
		while (flag == 2) {
			cout << "Please enter Y or N: ";
			while (!(cin >> ans) || (cin.peek() != '\n') || (ans != "N") && (ans != "n") && (ans != "Y") && (ans != "y")) {
				cin.clear();
				cout << "Error! Please enter Y or N: " << endl;
				while (cin.get() != '\n');
			}
			if (ans == "N" || ans == "n")
				flag = 0;
			if (ans == "Y" || ans == "y")
				flag = 1;
		}
	}
	return 0;
}
