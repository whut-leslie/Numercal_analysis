#include <iostream>
using namespace std;
//����Ҫ��ķ���Ϊx^3-4x-1=0
double f(double x)
{
	return x * x * x + 4 * x - 7;
}
int main() {
	double a, b;//���ַ����䣬a<b
	double x;
	double e;
	cout << "����������[a,b]�;�ȷ�ȣ�a��b��e:";
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