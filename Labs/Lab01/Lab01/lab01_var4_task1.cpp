#include "lab01_var4_task1.h"


double equation5(double n) {
	double root = pow(n, 3) + 2 * n - 1;
	return root;
}

double equation6(double n) {
	double root = pow(e, n) - 2;
	return root;
}

double getTheRoot3(double (*equation)(double), double a, double b) {
	double x = 0;
	double f1, f2;
	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		f1 = equation(x);
		f2 = equation(a);
		if (f1 * f2 <= 0)
			b = x;
		else
			a = x;
	}
	return x;
}

void doVariant4Task1() {
	int a;
	int b;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	cout << getTheRoot3(equation5, a, b) << endl;
	cout << getTheRoot3(equation6, a, b);
}