#include<iostream>
using namespace std;
class CPoint {
public:
	int x, y;
	//Ĭ�Ϲ��캯��
	CPoint() {
		x = 0; y = 0;
	};
	//��ӡ����
	void print() {
		cout << "(" << x << "," <<y<< ")" << endl;
	};
	//�вι��캯��
	CPoint(int a, int b) {
		x = a;
		y = b;
	};
	//�������
	void printx() {
		cout<<"�����ĺ�����Ϊ"<<x<<endl;
	};
	//��������
	void printy() {
		cout<<"������������Ϊ"<<y<<endl;
	};
};
class CRetangle {
	CPoint p1, p2;
public:
	//�޲ι��캯��
	CRetangle() {
		p1.x = 0;
		p1.y = 0;
		p2.x = 0;
		p2.y = 0;
	};
	//�вι��캯��
	CRetangle(CPoint P1, CPoint P2) {
		p1 = P1;
		p2 = P2;
	};
	//���ܳ��ĺ���
	int perimeter() {
		cout << (p2.x - p1.x + p1.y - p2.y) * 2 << endl;
		return (p2.x - p1.x + p1.y - p2.y) * 2;
	};
	//������ĺ���
	int area() {
		cout << (p2.x - p1.x) * (p1.y - p2.y)<<endl;
		return (p2.x - p1.x) * (p1.y - p2.y);
	};
};
int main() {
	cout << "�밴��˳������þ������Ͻǵ�ĺ����������� ���������½ǵĵ�ĺ�����������" << endl;
	int a, b,c,d;
	cin >>a>>b>>c>>d;
	CPoint A(a, b),B(c,d);
	CRetangle C(A, B);
	cout << "�þ�������Ͻǵĵ�Ϊ"; A.print();
	cout << "�þ�������Ͻǵĵ�Ϊ";  B.print();
	cout << "�þ�����ܳ�Ϊ"; C.perimeter();
	cout << "�þ�������Ϊ";  C.area();
	
	return 0;
}