#include<iostream>
#include<cmath>
using namespace std;
class point {
public:
	point(int a = 0, int b = 0) ://���캯����ʼ��
		x(a),y(b){ }
	friend class rectangle;
	int X() { return x;}//����x��
	int Y() { return y; }//����y��
private:
	int x;//����x
	int y;//����y
};
class rectangle {
public:
	rectangle() :
		length(1), width(1) {};//��û�д���ĵ㣬�����ʼ����
	rectangle(const point& A, const point& B) {//�������㣬�������ʼ��
		int mid1 = A.y - B.y;
		int mid2 = A.x - B.x;
		length = abs(mid1);
		width = abs(mid2);
	}
	const int Sarea() {
		area = length * width;//�������
		return area;
	}
	const int CR() {
		C = (length + width) * 2;//�����ܳ�
		return C;
	}
private:
	int length;//��
	int width;//��
	int area;//���
	int C;//�ܳ�

};
int main() {
	point A(1, 5);
	point B(2, 3);
	rectangle D(A, B);
	int b = D.Sarea();
	int a = D.CR();
	cout<<"�ܳ�"<<a << " " <<"���"<< b << endl;
}