#include<iostream>
using namespace std;
#include"2Class.h"
int main() {
	cout << "�������Ͻǵ�";
 	CPoint P1;
	P1.CinDots();
	cout << "�������½ǵ�";
	CPoint P2;
	P2.CinDots();
	CRectangle R1(P1, P2);
	cout<<"���Ϊ"<<R1.Area()<<endl;
	cout<<"�ܳ�Ϊ"<<R1.Cir();
	return 0;
}