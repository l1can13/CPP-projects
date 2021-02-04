// Найти частоту всех символов, встречающихся в файле.
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	string path, ans;
	string s("");
	int freq[256] = { 0 };
	int sub = 0, all = 0, flag = 1;

	while (flag == 1) {
		cout << "Enter name of file > ";
		getline(cin, path);

		fin.open(path);

		if (!fin.is_open()) {
			cout << "Error! File is not open.\n";
			return 0;
		}
		else {
			cout << "File is open!\n";

			char c;
			while (fin.get(c)) {
				s += c;
			}
			fin.close();

			for (int i = 0; i < s.size(); ++i) {
				++all;
			}

			cout << "\nAmount of all elements > " << all << endl << endl;

			for (int i = 0; i < s.size(); ++i)
			{
				freq[(unsigned char)s[i]]++;
			}

			/*for (int i = 0; i < 70; ++i)
			{
				if (freq[i]) {
					cout << "'" << (char)i << "'" << " => " << (double)freq[i] / all << endl;
				}
			}
			cout << ". . . . . . . . . . . . . ." << endl;*/

			/*for (int i = 65; i < 123; ++i)
			{
				if ((i > 96) || (i < 91))
				{
					cout << "'" << (char)i << "'" << " => " << (double)freq[i] / all << endl;
				}
			}*/

			for (int i = 0; i < 256; ++i)
			{
				if (freq[i]) {
					cout << "'" << (char)i << "'" << " => " << (double)freq[i] / all << endl;
				}
			}

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
			cin.ignore();
		}

	}
}
