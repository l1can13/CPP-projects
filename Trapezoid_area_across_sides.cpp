#include <iostream> //подключение библиотек
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");//подключение русского языка
	
	

	cout<< "Введите длины сторон трапеции:" << endl;

	int flag = 1; //переменная, отвечающая за ответ в цикле(да/нет)

	while (flag) //цикл, отвечающий за зацикливание калькулятора
	{
		float a; // объявление переменной a, в которой потом будет храниться значение стороны A
		cout << "Сторона А = ";


while (!(cin >> a) || (cin.peek() != '\n') || (a <= 0)) //цикл, отвечающий за проверку вводa
		{
			
			cin.clear();//удаляем флаг ошибки
			while (cin.get() != '\n');
cout << "\nОшибка!\nДлина стороны должна быть положительным числом, отличным от нуля\nСторона должна иметь числовое значение,а не буквенное\n" << "Введите длину > ";
		}

		float b;

		cout << "Сторона B = ";

while (!(cin >> b) || (cin.peek() != '\n') || (a == b) || (a <= b) || (b <= 0)) 
		{
cin.clear();
			while (cin.get() != '\n');
cout << "\nОшибка!\nДлина стороны должна быть положительным числом,отличным от нуля\nСторона B не должна быть равна стороне А\nСторона должна иметь числовое значение,а не буквенное\n" << "Введите длину > ";
		}

float polysum = (a + b) / 2; //переменная, которой присваивается значение полу суммы оснований - средняя линия
float powba = pow((b - a), 2);//переменная, в которой хранится значение квадрата разности оснований трапеции

float sl = 2 * (b - a); //переменной присваивается значение удвоенной разности оснований трапеции 

		float d; 

		cout << "Сторона D = ";


while (!(cin >> d) || (cin.peek() != '\n') || (d <= 0)) 
		{
cin.clear();
			while (cin.get() != '\n');
cout << "\nОшибка!\nДлина стороны должна быть положительным числом, отличным от нуля\nСторона должна иметь числовое значение, а не буквенное\n" << "Введите длину > ";
		}

		float c; 

		cout << "Сторона C = ";

while (!(cin >> c) || (cin.peek() != '\n') || (c <= 0) || (c * c <= (((powba + c * c - d * d) / sl) * ((powba + c * c - d * d) / sl)))) //цикл, отвечающий за проверку ввода
		{
cin.clear();
			while (cin.get() != '\n');
cout << "\nОшибка!\nДлина стороны должна быть положительным числом,отличным от нуля\nСторона должна иметь числовое значение,а не буквенное\nКвадрат стороны С должен быть больше квадрата разности сторон А и B,сложенного с разностью квадратов C и D.Все это\nвыражение делится на удвоенную разность сторон А и B.Причем все выше перечисленное возведено в квадрат\n" << "Введите длину > ";
		}

cout << "Площадь трапеции = " << polysum * sqrt(c * c - (((powba + c * c - d * d) / sl) * ((powba + c * c - d * d) / sl))) << endl;//подсчет и вывод значения площади трапеции

		string ans; 

			flag = 2;
while (flag == 2) //цикл, который отвечает за момент, когда пользователь не ввел Y/N
			{
				cout << "\nПосчитать еще раз? (Y/N) >  ";
				cin >> ans;
if (ans == "N" || ans == "NO" || ans == "no" || ans == "n" || ans == "No" || ans == "nO")
					flag = 0;
if (ans == "Y" || ans == "y" || ans == "Yes" || ans == "YEs" || ans == "YeS" || ans == "yES" || ans == "yEs" || ans == "yeS" || ans == "yes")
					flag = 1;
			}
		
	}
	return 0;
}