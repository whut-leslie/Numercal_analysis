#include <iostream>
#include <math.h>
using namespace std;
# define MAX 1005
# define q 0.000001
//存放方程系数
double a[MAX][MAX];
double b[MAX];
//存放迭代过程中的变量
double x[MAX];


//用来计算a[i][j]*x[j]的和
double getax(int i, int N) {
	double s = 0;
	for (int j = 1; j <= N; j++)
	{
		if (i != j)
			s += a[i][j] * x[j];
	}
	return s;
}

//假设求解N元方程，运用超松弛迭代法
void SOR(int N, int n) {

	int k = 1;
	while (k <= n) {
		double e = 0;
		int i = 1;
		while (i <= N)
		{
			double t = x[i];
			x[i] = (b[i] - getax(i, N)) / a[i][i];
			if (fabs(x[i] - t) > e)
				e = fabs(x[i] - t);
			i++;
		}
		//输出一下
		cout << "第" << k << "次迭代结果为";
		for (int i = 1; i <= N; i++) {
			cout << x[i] << " ";
		}
		cout << endl;
		//
		if (e < q)
			return;
		k++;

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
	for (int i = 1; i <= N; i++)
	{
		cout << "请输入第" << i << "个方程的系数aij和常数bj:";
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
		}
		cin >> b[i];
	}
	int n;
	cout << "请输入迭代次数n";
	cin >> n;
	memset(x, 0, N);
	SOR(N, n);
	for (int i = 1; i <= N; i++)
		cout << x[i] << " ";
	return 0;
}
