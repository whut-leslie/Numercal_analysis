#include<stdio.h>
#include<math.h>
#include<iostream>
#include<cstdio>
using namespace std;

int Rk = 0;

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

//�������㷨
double Romberg(double a, double b, double e)
{
	int k = 1;
	//���������м��� 
	double T1, T2, S1, S2, C1, C2, R1, R2;
	//�����ʼ���� b-a
	if (a == 0)
		a = 0.0000001;//sinx/x����x����Ϊ0
	double h = b - a;
	double s;
	T1 = (fx(a) + fx(b)) * h / 2.0;
	int counter = 0;
	while (1)
	{
		Rk++;//��¼���ִ���
		counter++;
		s = getS(a, b, h);
		T2 = (T1 + h * s) / 2.0;
		S2 = (4.0 * T2 - T1) / 3.0;

		if (k == 1)
		{
			h /= 2.0;
			T1 = T2;
			S1 = S2;
			k++;
			continue;
		}
		C2 = (16.0 * S2 - S1) / 15.0;
		if (k == 2)
		{
			h /= 2.0;
			T1 = T2;
			S1 = S2;
			C1 = C2;
			k++;
			continue;
		}
		R2 = (64.0 * C2 - C1) / 63.0;
		if (k == 3)
		{
			h /= 2.0;
			T1 = T2;
			S1 = S2;
			C1 = C2;
			R1 = R2;
			k++;
			continue;
		}
		if (fabs(R1 - R2) < e || counter >= 100)break;
	}
	return R2;
}

int main()
{
	//0 1 0.5e-5
	double a, b, e;
	printf("��������޺;��ȣ� a b e:");
	//��������[a,b],�;���e
	double t;
	scanf_s("%lf%lf%lf", &a, &b, &e);
	t = Romberg(a, b, e);
	// �ֱ�����������㷨�����η��ļ���������Ӧ���ִ���
	printf("\nRomberg:����ֵ��%.7lf  --  ���ִ�����%d\n", t, Rk);
	
	return 0;
}
