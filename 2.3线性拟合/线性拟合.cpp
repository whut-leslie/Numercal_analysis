#include <iostream>
using namespace std;
#define MAX 100
int main() {
	int N;//节点数
	double x[MAX];//节点值
	double y[MAX];
	double a, b;//线性拟合系数
	double sumx=0;
	double sumy=0;
	double sumx2 = 0;
	double sumxy = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < N; i++)
	{
		sumx += x[i];
		sumy += y[i];
		sumx2 += x[i] * x[i];
		sumxy += x[i] * y[i];
	}
	b= (sumxy - sumy * sumx / N)/(sumx2-sumx* sumx / N);
	a = (sumy - sumx * b) / N;
	cout << "线性数据拟合曲线为y=" << a << "+" << b<<"*x";
	return 0;
	
}