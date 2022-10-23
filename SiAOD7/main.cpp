#include <iostream>
#include "Stack.cpp"
#include <string>

using namespace std;

string transformExp(string exp); // �������������� ��������� ������ � �����������

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
		cout << "������������ ������ �7 ����-33-21 �������� �.�. ������� 29" << "\n\n"
			"����\n"
			"1) ���� ��������� ������ ���������.\n"
			"2) ������������� � ����������� ������.\n"
			"3) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cout << "������� ��������� � ��������� ������: ";
			cin >> exp;
			system("pause");
			break;
		case 2:
			cout << "����������� ������ ���������� ���������: ";
			exp = transformExp(exp);
			cout << exp << endl;
			system("pause");
			break;
		case 3:
			break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���." << stop;
			system("pause");
		}
	}
	return 0;
}

string transformExp(string exp)
{
	Stack <string> stack; // �������� �����
	string str = ""; // ������������� ������ ����������
	for (int i = 0; i < exp.length(); i++) // ������ �� �������� ������
	{
		if ((exp[i] == '+') || (exp[i] == '-')) // ���� �������� + ��� -
		{
			if (!stack.isEmpty()) // ���� ���� ����
			{
				stack.push(exp[i]); // ��������� � ���� ������� ������ ������
			}
			else if (stack.top()=="(") // ���� ������� ������� ����� = )
			{
				stack.push(exp[i]); // ��������� � ���� ������� ������ ������
			}
			else // ����� 
			{
				str = str + stack.pop(); // ������� ������� ������� � ����������� ������
				stack.push(exp[i]); // ��������� � ���� ������� ������ ������
			}
		}
		else if ((exp[i] == '*') || (exp[i] == '/')) // ���� ������� * ��� /
		{
			if (!stack.isEmpty()) // ���� ���� ����
			{
				stack.push(exp[i]);  // ��������� � ���� ������� ������ ������
			}
			else if ((stack.top() == "(") || (stack.top() == "+") || (stack.top() == "-")) 
				// ���� ������� ������� ����� = ) ��� + ��� -
			{
				stack.push(exp[i]); // ��������� � ���� ������� ������ ������
			}
			else // �����
			{
				str = str + stack.pop(); // ������� ������� ������� � ����������� ������
				stack.push(exp[i]);  // ��������� � ���� ������� ������ ������
			}
		}
		else if (exp[i] == '(') // ���� ����������� ������������� ������
		{
			stack.push(exp[i]); // ��������� � ���� ������� ������ ������
		}
		else if (exp[i] == ')') // ���� ����������� ������������� ������
		{
			while (stack.top()!="(") // ���� �� ���������� ������������� ������
			{
				str = str + stack.pop(); // ������� ������� ������� � ����������� ������
			}
			stack.del(); // ������� ������� ������� �����(����������� ������)
		}
		else // ����� (�������� �������)
		{
			str = str + exp[i]; // �������� � ������ ������� ������ ������
		}
	}
	while (stack.isEmpty()) // �������� � ������ ���������� �������� �����
	{
		str = str + stack.pop(); // ������� ������� ������� � ����������� ������
	}
	return str; // ������� ����������� ���������
}