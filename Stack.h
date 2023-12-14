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
	Stack() //������������� �����
	{ 
		arr = new T[1];
		size = 1;
		top = size-1;
	};
	
	virtual ~Stack() { delete[] arr; }

	void push(T _data)
	{
		if (top == size) //���������� ����������� ����� � 2 ���� ��� ������������
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

	bool isEmpty() { return top == 0; } //�������� �� ������� �����

	T pop() //�������� ������� �� �����
	{
		if (!isEmpty())
			return arr[--top];
		else
			cerr << "stack is empty" << endl;
	}

	int GetSize() { return size; } //�������� ������ �����
};

#endif // !_STACK_H_

