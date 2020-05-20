#include <iostream>
using namespace std;
double f(double x,double y){//假设常微分方程为y'=x + x * y
	return y - 2*x /y;
}

int main() {
	double x0, y0, h;
	double x1, y1, yp, yc;
	int N;
	cout << "输入x0，y0，h，N: ";
	cin >> x0 >> y0 >> h >> N;
	int n = 1;
	while (n != N)
	{
		 x1 = x0 + h;
		 yp = y0 + h * f(x0, y0);
		 yc = y0 + h * f(x1, yp);
		 y1 = (yp + yc) / 2;
		 cout << "x1:"<<x1 <<",y1:" <<y1 << endl;
		 n++;
		 x0 = x1;
		 y0 = y1;
	}
	return 0;

}