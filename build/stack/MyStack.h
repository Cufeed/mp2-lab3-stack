#pragma once

#include <iostream>
#include <string>
using namespace std;


template <class T>
class TStack {
protected:
	int size;
	int top;
	T* mas;
public:
	TStack(int n = 0) : size(n), top(0)
	{
		if (n < 0)
			throw std::out_of_range("Incorrect");
		mas = new T[n];

	}
	TStack(TStack<T>& stack): size(stack.size), top(stack.top) 
	{
		mas = new T[size];
		for (int i = 0; i < top; i++)
			mas[i] = stack.mas[i];
	}

	~TStack() {
		delete[] mas;
	}

	void Clear() {
		top = 0;
	}

	void Push(T a) {
		if (IsFull()) {
			throw std::out_of_range("Stack is full");
		}
		mas[top] = a;
		top++;
	}
	T Get() {
		if (this->IsEmpty()) {
			throw std::out_of_range("Stack is empty");
		}
		top--;
		return mas[top];
	}
	T TopView() {
		if (this->IsEmpty()) {
			throw std::out_of_range("Stack is empty");
		}
			return mas[top-1];
	}

	int GetSize() { return size; }
	int GetTop() { return top; }

	//template <typename T>
	friend ostream& operator<<(ostream& os, const TStack<T>& stack) {
		for (int i = 0; i < stack.top; i++) {
			os << stack.mas[i] << " ";
		}
		return os;
	}

	//template <typename T>
	friend istream& operator>>(istream& is, TStack<T>& stack) {
		for (int i = 0; i < stack.size; i++) {
			is >> stack.mas[i];
			stack.top++;
		}
		return is;
	}

	

	bool IsFull() {
		return top == size;
	}
	bool IsEmpty() {
		return top == 0;
	}

	TStack& operator=(const TStack<T>& stack)
	{
		if (this != &stack) {
			delete[] mas;
			size = stack.size;
			top = stack.top;
			mas = new T[size];
			for (int i = 0; i < top; i++)
				mas[i] = stack.mas[i];
		}
		return *this;
	}

};



template <class T>
class TQueue {
protected:
	int size;
	int start;
	int end;
	int count;
	T* mas;

public:
	TQueue(int n = 0) : size(n), start(0), end(0), count(0)
	{
		if (n < 0) {
			throw std::out_of_range("Incorrect");
		}
		if (n == 0) {
			mas = nullptr;
		}
		else {
			mas = new T[n];
		}

	}
	TQueue(TQueue <T>& q) : size(q.size), start(q.start), end(q.end), count(q.count)
	{
		mas = new T[size];
		for (int i = 0; i < size; i++) {
			mas[i] = q.mas[i];
		}
	}
	~TQueue() {
		delete[] mas;
	}

	void Push(T a) {
		if (this->IsFull())
			throw std::out_of_range("Queue is full");
		else
		{
			mas[end++] = a;
			if (end == size)
				end = 0;
			this->count++;
		}
	}
	T Get() {
		T tmp = mas[start++];
		if (this->IsEmpty())
			throw std::out_of_range("Queue is empty");
		else {
			if (start == size)
				start = 0;
			count--;
		}
		return tmp;
	}

	bool IsFull() {
		return count == size;
	}
	bool IsEmpty() {
		return count == 0;
	}

	//операторы вводы и выводы
	friend ostream& operator<< (ostream& os, const TQueue& queue) {
		int index = queue.start;
		for (int i = 0; i < queue.count; i++) {
			os << queue.mas[index++] << " ";
			if (index == queue.size) {
				index = 0;
			}
		}
		return os;
	}

	friend istream& operator>> (istream& is, TQueue& queue) {
		for (int i = 0; i < queue.size; i++) {
			T value;
			is >> value;
			queue.Push(value);
		}
		return is;
	}

};

class TCalculator
{
private:
	string infix;
	string postfix;
	TStack<char> st;
	TStack<double> st2;
	int Priority(char elem) {
		switch (elem) {
		case's':
		case '(':
		case')': return 1;
		case '+':
		case '-': return 2;
		case'*':
		case '/':
			return 3;
		default: throw elem;
		}
	}
public:
	TCalculator() :st(100), st2(100) {
		infix = "";
		postfix = "";
	}
	string GetExpression() {
		return infix;
	}
	void SetExpression(string expr) {
		infix = expr;
	}
	string GetPostfix() {
		return postfix;
	}
	void ToPostfix() {
		st.Clear();
		postfix = "";
		string src = "(" + infix + ")";
		char elem;
		unsigned int i = 0;
		while (i < src.size()) {
			
			if (src[i] >= '0' && src[i] <= '9' || src[i] == '.') {
				postfix += src[i];
			}
			else if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/') {
				postfix += " ";
				if (!st.IsEmpty()) {
					elem = st.Get();
					while (!st.IsEmpty() && Priority(elem) >= Priority(src[i])) {
						postfix += elem;
						if (!st.IsEmpty())
							elem = st.Get();
					}
					st.Push(elem);
				}
				st.Push(src[i]);
				postfix += " ";
			}
			else if (src[i] == '(') {
				st.Push(src[i]);
			}
			else if (src[i] == ')') {
				while (!st.IsEmpty() && st.GetTop() > 0 && st.TopView() != '(') {
					postfix += st.Get();
				}
				if (!st.IsEmpty())
					st.Get();
			}
			i++;
		}
	}
	double CalcPostfix()
	{
		unsigned int i = 0;
		st2.Clear();
		while (i < postfix.size())
		{
			if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.') {
				string temp;
				while (i < postfix.size() && (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.')) {
					temp += postfix[i];
					i++;
				}
				st2.Push(stod(temp)); // Здесь мы конвертируем строку в double и добавляем элемент.
				continue;
			}
			else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
			{
				double k2 = st2.Get();
				double k1 = st2.Get();
				switch (postfix[i]) {
				case'+': {st2.Push(k1 + k2); break; }
				case'-': {st2.Push(k1 - k2); break; }
				case'*': {st2.Push(k1 * k2); break; }
				case'/': {st2.Push(k1 / k2); break; }
				}
			}
			i++;
		}
		return st2.Get();
	}
	double Calc(){
		ToPostfix();
		return CalcPostfix();
	}


};

