#pragma once
#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
using std::boolalpha;
template<class T>
class Stack {
private:
	int size;
	int top;
	T* arr;
public:
	Stack() //инициализация стека
	{ 
		arr = new T[1];
		size = 1;
		top = size-1;
	};
	
	virtual ~Stack() { delete[] arr; }

	void push(T _data)
	{
		if (top == size) //увеличение размерности стека в 2 раза при переполнении
		{
			T* temp = new T[size * 2];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			size *= 2;
			arr = temp;
		}
		arr[top] = _data;
		top++;
	}

	bool isEmpty() { return top == 0; } //проверка на пустоту стека

	T pop() //получить элемент из стека
	{
		if (!isEmpty())
			return arr[--top];
		else
			cerr << "stack is empty" << endl;
	}

	int GetSize() { return size; } //получить размер стека
};

#endif // !_STACK_H_

