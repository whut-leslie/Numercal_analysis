#include <iostream>
using namespace std;
//假设常微分方程为y'= y - 2 * x / y
double f(double x, double y) {
	return y - 2 * x / y;
}
int main() {
	double x0, y0, h;
	double x1, y1, K1,K2,K3,K4;
	int N;
	cout << "输入x0，y0，h，N: ";
	cin >> x0 >> y0 >> h >> N;
	int n = 1;
	while (n != N)
	{
		x1 = x0 + h;
		K1 = f(x0, y0);
		K2 = f(x0 + h / 2, y0 + h * K1 / 2);
		K3 = f(x0 + h / 2, y0 + h * K2 / 2);
		K4 = f(x0 + h / 2, y0 + h * K3 / 2);
		y1 = y0 + h * (K1 + 2 * K2 + 2 * K3 + K4) / 6;
		cout << "x1:" << x1 << ",y1:" << y1 << endl;
		n++;
		x0 = x1;
		y0 = y1;
	}
	return 0;
}