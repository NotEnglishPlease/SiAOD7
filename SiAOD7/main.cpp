#include <iostream>
#include "Stack.cpp"
#include <string>

using namespace std;

string transformExp(string exp); // преобразование инфиксной записи в постфиксную

int main() 
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1;
	string exp;

	while (flag)
	{
		system("cls");
		cout << "Практическая работа №7 ИКБО-33-21 Эрднеева Н.Д. Варинат 29" << "\n\n"
			"Меню\n"
			"1) Ввод инфиксной записи выражения.\n"
			"2) Преобразовать в постфиксную запись.\n"
			"3) Выход из программы.\n";
		cout << "Ваш выбор: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cout << "Введите выражение в инфиксной записи: ";
			cin >> exp;
			system("pause");
			break;
		case 2:
			cout << "Постфиксная запись введенного выражения: ";
			exp = transformExp(exp);
			cout << exp << endl;
			system("pause");
			break;
		case 3:
			break;
		default:
			cout << "Извините, я не совсем понимаю, что вы хотите сделать. Попробуйте в другой раз." << stop;
			system("pause");
		}
	}
	return 0;
}

string transformExp(string exp)
{
	Stack <string> stack; // создание стека
	string str = ""; // инициализация строки результата
	for (int i = 0; i < exp.length(); i++) // проход по исходной строке
	{
		if ((exp[i] == '+') || (exp[i] == '-')) // если оператор + или -
		{
			if (!stack.isEmpty()) // если стек пуст
			{
				stack.push(exp[i]); // поместить в стек текущий символ строки
			}
			else if (stack.top()=="(") // если верхний элемент стека = )
			{
				stack.push(exp[i]); // поместить в стек текущий символ строки
			}
			else // иначе 
			{
				str = str + stack.pop(); // извлечь верхний элемент в постфиксную строку
				stack.push(exp[i]); // поместить в стек текущий символ строки
			}
		}
		else if ((exp[i] == '*') || (exp[i] == '/')) // если операто * или /
		{
			if (!stack.isEmpty()) // если стек пуст
			{
				stack.push(exp[i]);  // поместить в стек текущий символ строки
			}
			else if ((stack.top() == "(") || (stack.top() == "+") || (stack.top() == "-")) 
				// если верхний элемент стека = ) или + или -
			{
				stack.push(exp[i]); // поместить в стек текущий символ строки
			}
			else // иначе
			{
				str = str + stack.pop(); // извлечь верхний элемент в постфиксную строку
				stack.push(exp[i]);  // поместить в стек текущий символ строки
			}
		}
		else if (exp[i] == '(') // если встречается открывающаяся скобка
		{
			stack.push(exp[i]); // поместить в стек текущий символ строки
		}
		else if (exp[i] == ')') // если встречается закрывающаяся скобка
		{
			while (stack.top()!="(") // пока не встретится открывающаяся скобка
			{
				str = str + stack.pop(); // извлечь верхний элемент в постфиксную строку
			}
			stack.del(); // удалить верхний элемент стека(открывающая скобка)
		}
		else // иначе (встречен операнд)
		{
			str = str + exp[i]; // добавить в строку текущий символ строки
		}
	}
	while (stack.isEmpty()) // добавить в строку оставшиеся элементы стека
	{
		str = str + stack.pop(); // извлечь верхний элемент в постфиксную строку
	}
	return str; // вернуть постфиксное выражение
}