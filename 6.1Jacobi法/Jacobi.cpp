#include <iostream>
#include <math.h>
using namespace std;
# define MAX 1005
# define e 0.00001
//存放方程系数
double a[MAX][MAX];
double b[MAX];
//存放迭代过程中的变量
double x[MAX];//x(k)迭代老值
double y[MAX];//x(k+1)迭代新值

//用来计算a[i][j]*x[j]的和
double getax(int i,int N) {
	double s = 0;
		for (int j = 1; j <=N; j++)
		{
			if(i!=j)
			s += a[i][j] * x[j];
		}
	return s;
}

//假设求解N元方程，运用jacobi迭代法
void Jacobi(int N,int n) {

	int k = 1;
	while (k <= n) {
		for(int i=1;i<=N;i++)
		{
			y[i] = (b[i] - getax(i,N))/ a[i][i];
		}
		//输出一下
		cout << "第" << k << "次迭代结果为";
		for (int i = 1; i <= N; i++) {
			cout << y[i] <<" ";
		}
		cout << endl;
		//判断精度
		double maxnum=0;
		for (int i = 1; i <= N; i++)
		{
			if (fabs(x[i] - y[i]) > maxnum)
				maxnum = fabs(x[i] - y[i]);
		}
		if (maxnum < e)
			return;
		else
		{
			for (int i = 1; i <=N; i++) 
			{
				x[i] = y[i];
			}
			k++;	
		}
	}
	if (k == n)
	{
		cout << "迭代失败";
	}

}

int main() {
	int N;
	cout << "请输入方程个数";
	cin >> N;
	for (int i = 1; i <=N; i++)
	{
		cout << "请输入第"<<i<<"个方程的系数aij和常数bi:";
		for (int j = 1; j <=N; j++) {
			cin >> a[i][j];	
		}
		cin >> b[i];
	}
	int n;
	cout << "请输入迭代次数n";
	cin >> n;
	//赋迭代初值为0
	memset(x, 0,MAX);
	memset(y, 0, MAX);
	Jacobi(N,n);
	for (int i = 1; i <= N; i++) {
		cout << y[i]<<" ";
	}
}
