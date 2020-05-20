#include <iostream>
#include <math.h>
using namespace std;
# define MAX 1005
# define q 0.000001
//��ŷ���ϵ��
double a[MAX][MAX];
double b[MAX];
//��ŵ��������еı���
double x[MAX];


//��������a[i][j]*x[j]�ĺ�
double getax(int i, int N) {
	double s = 0;
	for (int j = 1; j <= N; j++)
	{
		if (i != j)
			s += a[i][j] * x[j];
	}
	return s;
}

//�������NԪ���̣����ó��ɳڵ�����
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
		//���һ��
		cout << "��" << k << "�ε������Ϊ";
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
		cout << "����ʧ��";
	}

}

int main() {
	int N;
	cout << "�����뷽�̸���";
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cout << "�������" << i << "�����̵�ϵ��aij�ͳ���bj:";
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
		}
		cin >> b[i];
	}
	int n;
	cout << "�������������n";
	cin >> n;
	memset(x, 0, N);
	SOR(N, n);
	for (int i = 1; i <= N; i++)
		cout << x[i] << " ";
	return 0;
}
