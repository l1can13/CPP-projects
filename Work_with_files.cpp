//Заменить три последних символа у слов, больших определенной длины. Входные данные: строка. Выходные данные: строка.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>  
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<string>& v, int n)
{
    for (int i = 0; i < v.size(); ++i)
        if (v[i].size() > n)
            for (int j = v[i].size() - 3; j < v[i].size(); ++j)
                v[i][j] = '*';
}

void symbols_in_vector(vector<string>& v, string s)
{
    for (int i = 0; s[i]; ++i)
        if (isspace(s[i]) && !v.back().empty())
            v.push_back({}); 
        else if (s[i] == '.')
        {
            v.push_back(".");
            v.push_back({});
        }
        else if (s[i] == ',')
        {
            v.push_back(",");
            v.push_back({});
        }
        else if (s[i] == '!')
        {
            v.push_back("!");
            v.push_back({});
        }
        else if (s[i] == '?')
        {
            v.push_back("?");
            v.push_back({});
        }
        else if (s[i] == '\n') 
        {
            v.push_back("\n");
            v.push_back({});
        }
        else if (s[i] == ' ')
        {
            v.push_back(" ");
            v.push_back({});
        }
        else
            v.back() += s[i];
}

string vector_in_string(vector<string> v, string s)
{
    s.clear();
    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i + 1] != " " && v[i + 1] != "\n" && v[i + 1] != "." && v[i + 1] != "," && v[i + 1] != "!" && v[i + 1] != "?" && v[i] != " " && v[i] != "\n" && v[i] != "." && v[i] != "," && v[i] != "!" && v[i] != "?")
            s += v[i] + ' ';
        else
            s += v[i];

    }
    s += v[v.size() - 1];
    return s;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    ifstream fin;     
    ofstream fout("output.txt");  

    string s;                   
    fin.open("input.txt");

    if (!fin.is_open()) {
        cout << "Error! File not open!";
    }
    else {
        cout << "File is open!" << endl;
        char ch;
        while (!fin.eof()) {
            s = "";
            getline(fin, s);
            cout << s << endl;
        }
        fin.close();

        int n;
        cout << "Enter length of word > ";
        while (!(cin >> n) || (cin.peek() != '\n') || (n <= 0)) {
            cin.clear();
            cout << "Error! Please etner correct values > ";
            while (cin.get() != '\n');
        }

        vector<string> v(1);

        symbols_in_vector(v, s);

        swap(v, n);

        s = vector_in_string(v, s);
        fout << s;
        fout.close();
    }
}
