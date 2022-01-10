#include<iostream>
using namespace std;
class Cpoint {
public:
	int x;
	int y;
	Cpoint(int m, int n) :x(m), y(n) {};
	Cpoint(const Cpoint& c);
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
};
Cpoint::Cpoint(const Cpoint& c) {
	x = c.x;
	y = c.y;
}
class rectangular {
	Cpoint x1;//���Ͻǵĵ�
	Cpoint x2;//���½ǵĵ�
public:
	rectangular(Cpoint p, Cpoint q) :x1(p), x2(q) {};
	void square();
	void length();
}; 
void rectangular::square() {
	int s;
	s = fabs((x1.x - x2.x) * (x1.y - x2.y));
	cout << "�������Ϊ��" << s << endl;
}//�����
void rectangular::length() {
    int l;
    l = 2 * (fabs(x1.x - x2.x) + fabs(x1.y- x2.y));
	cout << "�����ܳ�Ϊ��" << l << endl;
}//���ܳ�
int main() {
	cout << "������������ϽǺ����½ǵ����꣺" << endl;
	int m, n, p, q;
	cin >> m >> n >> p >> q;
	Cpoint a(m,n), b(p,q);
	rectangular w(a,b);
	w.square();
	w.length();
	return 0;
}