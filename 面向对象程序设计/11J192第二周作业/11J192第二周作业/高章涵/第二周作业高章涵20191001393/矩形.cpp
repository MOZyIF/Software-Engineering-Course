#include<iostream>
using namespace std;

class Cpoint {//�������
	friend class Csquare;//������Ԫ
public:
	Cpoint() {
		X = 0; Y = 0;
	}//Ĭ�Ϲ���
	Cpoint(int x, int y) {
		X = x; Y = y;
	}//�вι���
	void show() {
		cout << "������Ϊ " << X << endl;
		cout << "������Ϊ " << Y << endl;
	}//�����������
private:
	int X, Y;
};
class Csquare {//���������

public:
	Csquare(Cpoint& a, Cpoint& b) {
		A = a; B = b;
	}
	int S(){
		return (A.X - B.X) * (A.Y - B.Y);
	}//�������
	int C() {
		return abs((A.X - B.X) + (A.Y - B.Y)) * 2;
	}//�����ܳ�
private:
	Cpoint A, B;
};
int main() {
	int x1=0, y1=0, x2=0, y2=0;
	cout << "�����һ����" << endl;
	cin >> x1 >> y1;
	cout << "����ڶ�����" << endl;
	cin >> x2 >> y2;
	Cpoint A(x1, y1), B(x2, y2);
	Csquare P(A, B);
	cout << "�þ������Ϊ" << P.S ()<< endl;
	cout << "�þ����ܳ�Ϊ" << P.C ()<< endl;
	return 0;
}
