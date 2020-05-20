#include <iostream>
#include <math.h>
using namespace std;

//定义原函数,假设原函数为
double f(double x) {
	return x * exp(x) - 1;
}
//定义导函数
double f1(double x)
{
	return (x + 1) * exp(x);
}
int main() {
	int N,k;
	double x0, x1, e;//e为精度
	cout << "请输入 x0, e,N:";
	cin >> x0 >> e >> N;
	k = 1;
	while (k<=N) {
		if (f1(x0) == 0)
		{
			cout << "error";
			break;
		}
		x1 = x0 - f(x0) / f1(x0);
		if (fabs(x1 - x0) < e)
		{
			cout << x1;
			break;
		}
		k++;
		x0 = x1;
	}

	if (k == N)
		cout << "迭代失败";
	return 0;
}