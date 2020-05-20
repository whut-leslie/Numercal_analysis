#include <iostream>
#include <math.h>
using namespace std;
# define MAX 1005
# define e 0.00001
//��ŷ���ϵ��
double a[MAX][MAX];
double b[MAX];
//��ŵ��������еı���
double x[MAX];//x(k)������ֵ
double y[MAX];//x(k+1)������ֵ

//��������a[i][j]*x[j]�ĺ�
double getax(int i,int N) {
	double s = 0;
		for (int j = 1; j <=N; j++)
		{
			if(i!=j)
			s += a[i][j] * x[j];
		}
	return s;
}

//�������NԪ���̣�����jacobi������
void Jacobi(int N,int n) {

	int k = 1;
	while (k <= n) {
		for(int i=1;i<=N;i++)
		{
			y[i] = (b[i] - getax(i,N))/ a[i][i];
		}
		//���һ��
		cout << "��" << k << "�ε������Ϊ";
		for (int i = 1; i <= N; i++) {
			cout << y[i] <<" ";
		}
		cout << endl;
		//�жϾ���
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
		cout << "����ʧ��";
	}

}

int main() {
	int N;
	cout << "�����뷽�̸���";
	cin >> N;
	for (int i = 1; i <=N; i++)
	{
		cout << "�������"<<i<<"�����̵�ϵ��aij�ͳ���bi:";
		for (int j = 1; j <=N; j++) {
			cin >> a[i][j];	
		}
		cin >> b[i];
	}
	int n;
	cout << "�������������n";
	cin >> n;
	//��������ֵΪ0
	memset(x, 0,MAX);
	memset(y, 0, MAX);
	Jacobi(N,n);
	for (int i = 1; i <= N; i++) {
		cout << y[i]<<" ";
	}
}
