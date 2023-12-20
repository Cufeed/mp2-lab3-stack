#include <iostream>
#include "../build/stack/MyStack.h"
int main()
{
	TStack<int> t(5);
	t.Push(5);
	t.Push(4);
	t.Push(3);
	cout << t;
	t.Get();
	cout << " | ";
	cout << t;
	cout << endl << "=====" << endl;

	TQueue<int> q(5);
	q.Push(5);
	q.Push(4);
	q.Push(3);
	cout << q;
	q.Get();
	cout << " | ";
	cout << q;
	TCalculator calc;
	string exp;

	cout << "Enter arithmetic:";
	cin >> exp;
	calc.SetExpression(exp);
	try {
		calc.ToPostfix();
		double res2 = calc.CalcPostfix();
		cout << res2 << " ===> res2 " << endl;
		double result = calc.Calc();
		cout << "Result: " << result << endl;
		string p = calc.GetPostfix();
		cout << p << endl;
	}
	catch (std::exception& e) {
		cout << "Error:" << e.what() << endl;
		return 1;
	}


	return 0;
}
