#include <iostream>
using namespace std;
#define MAX 100
int main() {
	int N;//�ڵ���
	double x[MAX];//�ڵ�ֵ
	double y[MAX];
	double a, b;//�������ϵ��
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
	cout << "���������������Ϊy=" << a << "+" << b<<"*x";
	return 0;
	
}