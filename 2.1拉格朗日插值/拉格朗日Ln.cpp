#include <iostream>
using namespace std;
#define MAX 100
double Lagrange(double x[], double y[], double x0, int N) {
	double y0= 0;//y0为近似解
	int k = 0;
	while (k < N)
	{
		double t = 1;
		for (int j = 0; j < N; j++)
		{ 
			if(j!=k)
            t = (x0- x[j]) / (x[k] - x[j])*t;
		}
		y0 = t * y[k] + y0;
		k++;
	}
	return y0;
}
int main()
{
	int N;//节点数
	double S;//函数f(x)在点x0的近似值
	double x[MAX];
	double y[MAX];
	double x0;
	 cin >> N;
	 for(int i=0;i<N;i++)
	 {
		 cin >> x[i] >> y[i];
	 }
	 cin >> x0;
	 S = Lagrange(x, y, x0, N);
	 printf("%.4f", S);;
	 return 0;
}