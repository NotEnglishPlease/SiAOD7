#pragma once
#include <string>

using namespace std;

template<typename T>
class Stack 
{
private:
	T* array = new T[0];
	size_t size = 0;
	void resizeArray(size_t newSize); // изменение размера стека
public:
	Stack() {};
	~Stack() { delete[] array; };
	T pop(); // возвращение верхнего элемента и его удаление из стека
	void push(char element); // добавление эемента сверху
	T top(); // возвращени верхнего элемента
	void del(); // удаление верхнего элемента
	bool isEmpty(); // проверка, пуст ли стек
};