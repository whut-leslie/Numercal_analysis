#include <iostream>
using namespace std;
//假设要解的方程为x^3-4x-1=0
double f(double x)
{
	return x * x * x + 4 * x - 7;
}
int main() {
	double a, b;//二分法区间，a<b
	double x;
	double e;
	cout << "请输入区间[a,b]和精确度，a、b、e:";
	cin >> a >> b>>e;
	while(1){
		x = (a + b) / 2;
		if (fabs(f(x)) < e || fabs(b - a) < e)
			break;
		else if (f(a) * f(b) < 0)
			b = x;
		else a = x;
	}
	cout << x;
	return 0;
}