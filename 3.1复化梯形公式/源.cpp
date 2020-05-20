#include <iostream>
#include <math.h>
using namespace std;
int Rk = 0;
int Tk = 0;
int Sk = 0;
double fx(double x)   //���屻���������˴�Ϊsin(x)/x
{
	//    return exp(x); 
	return sin(x)/ x;
}

//�����ۼӼ��� fx��ֵ 
double getS(double a, double b, double h)
{
	double res = 0.0;
	for (double i = a + h / 2.0; i < b; i += h) {
		res += fx(i);
	}

	return res;
}
//���������
double Tn(double a, double b, double e)
{
	double h = b - a;
	double T1, T2;
	double s = 0;
	T1 = (fx(a) + fx(b)) * h / 2.0;
	while (1) {
		Tk++;//��¼���ִ���
		s = getS(a, b, h);
		T2 = (T1 + h * s) / 2.0;
		if (fabs(T2 - T1) < e)break;
		else
		{
			h /= 2.0;
			T1 = T2;
		}
	}
	return T2;
}
int main() {
	double a, b, e,t;
	printf("��������޺;��ȣ� a b e:");
	scanf_s("%lf%lf%lf", &a, &b, &e);
	t = Tn(a, b, e);
	printf("     Tn:����ֵ��%.7lf  --  ���ִ�����%d\n", t, Tk);

}