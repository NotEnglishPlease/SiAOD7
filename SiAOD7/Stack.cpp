#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

template<typename T>
void Stack<T>::resizeArray(size_t newSize)
{
	T* newArray = new T[newSize];
	for (size_t i = 0; (i < this->size && i < newSize); i++)
	{
		newArray[i] = (this->array)[i];
	}
	delete[] array;
	array = newArray;
	this->size = newSize;
}

template<typename T>
T Stack<T>::pop()
{
	T popedEl = (this->array)[size - 1];
	resizeArray(this->size - 1);
	return(popedEl);
}

template<typename T>
void Stack<T>::del()
{
	resizeArray(this->size - 1);
}

template<typename T>
void Stack<T>::push(char element)
{
	resizeArray(size + 1);
	this->array[size - 1] = element;
}

template<typename T>
T Stack<T>::top()
{
	return (this->array[size - 1]);
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return (size > 0);
}