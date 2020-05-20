#include <iostream>
#include <math.h>
using namespace std;
double xpoint(double x1, double x2);//���x1, x2��ֱ����x��Ľ���
double root(double x1, double x2);//�������
double f(double x);//��x��ĺ�����ֵ

int main()
{
	double x1, x2, f1, f2, x;


	do {
		printf("������x1, x2��");
		cin >> x1 >> x2;
		f1 = f(x1);
		f2 = f(x2);
	} while (f1 * f2 >= 0);
	x = root(x1, x2);
	printf("���̵�һ����Ϊ��%.2f\n", x);

	return 0;
}


//����ֱ����X��Ľ���
double xpoint(double x1, double x2)
{
	double x = 0;

	x = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

	return x;
}

//���غ����ĸ�
double root(double x1, double x2)
{
	double x, y, y1, y2;

	y1 = f(x1);
	y2 = f(x2);
	do {
		x = xpoint(x1, x2);
		y = f(x);
		if (y * y1 > 0) {
			x1 = x;
			y1 = y;
		}
		else {
			x2 = x;
			y2 = y;
		}
	} while (fabs(y) >= 0.00001);

	return x;
}

//����x��ĺ���ֵ
double f(double x)
{
	double y = 0;

	y = x * exp(x) - 1;

	return y;
}

