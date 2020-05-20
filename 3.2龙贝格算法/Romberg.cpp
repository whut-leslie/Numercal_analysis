#include<stdio.h>
#include<math.h>
#include<iostream>
#include<cstdio>
using namespace std;

int Rk = 0;

double fx(double x)   //定义被积函数，此处为sin(x)/x 
{
	//    return exp(x); 
	return sin(x)/ x;
}


//二分累加计算 fx的值 
double getS(double a, double b, double h)
{
	double res = 0.0;
	for (double i = a + h / 2.0; i < b; i += h) {
		res += fx(i);
	}

	return res;
}

//龙贝格算法
double Romberg(double a, double b, double e)
{
	int k = 1;
	//定义所有中间量 
	double T1, T2, S1, S2, C1, C2, R1, R2;
	//定义初始步长 b-a
	if (a == 0)
		a = 0.0000001;//sinx/x函数x不能为0
	double h = b - a;
	double s;
	T1 = (fx(a) + fx(b)) * h / 2.0;
	int counter = 0;
	while (1)
	{
		Rk++;//记录二分次数
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
	printf("输入积分限和精度： a b e:");
	//输入区间[a,b],和精度e
	double t;
	scanf_s("%lf%lf%lf", &a, &b, &e);
	t = Romberg(a, b, e);
	// 分别输出龙贝格算法和梯形法的计算结果和相应二分次数
	printf("\nRomberg:积分值：%.7lf  --  二分次数：%d\n", t, Rk);
	
	return 0;
}
