#include<iostream>
using namespace std;
#include"myclass.h"
int main() {
	double a, b, c, d;//�����������������
	cout << "��������ε�����������������꣺" << endl;
	cin >> a >> b >> c >> d;
	CPoint P1(a, b);
	CPoint P2(c, d);//������������󣬷ֱ�Ϊ���ε������������������
	CRectangle R1(P1, P2);
	double area = R1.area();//����area��������������
	double cir = R1.cir();//����cir������������ܳ�
	cout << "�������Ϊ��" << area << endl;
	cout << "�����ܳ�Ϊ��" << cir;//����ܳ������
	return 0;
}