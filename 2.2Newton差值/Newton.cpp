#include <iostream>
using namespace std;
#define MAX 100
double Newton(double x[], double y[], double x0, int N){
	int k = 1;
	while (k < N) {
		for (int i = k; i < N; i++) {
		
			y[i] = y[k - 1] + (y[i] - y[k - 1]) * (x0 - x[k - 1]) / (x[i] - x[k - 1]);
		}
		k++;
	}
	
	return y[N - 1]; 

}

int main() 
{
	int N;//节点数
	double S;//函数f(x)在点x0的近似值
	double x[MAX];
	double y[MAX];
	double x0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x[i] >> y[i];
	}
	cin >> x0;
	S = Newton(x, y, x0, N);
	cout <<S;
	return 0;
}