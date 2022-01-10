#include <iostream>
#include <cmath>
using namespace std;
class Cpoint  //Cpoint������
{
public:
	Cpoint();
	Cpoint(int xx, int yy); //���캯��
	friend class Crectangle;//��Ԫ����
private:
	int x, y;//��ĺ�������
};
Cpoint::Cpoint() {
	x = 0;
	y = 0;
}
Cpoint::Cpoint(int xx, int yy) {
	x = xx;
	y = yy;
}
class  Crectangle//������
{
private:
	Cpoint p1, p2;//���ε�������
public:
	Crectangle(Cpoint a, Cpoint b);//���캯��
	int acreage();//��������ĺ���
	int perimeter();//�����ܳ��ĺ���
};
Crectangle::Crectangle(Cpoint a, Cpoint b) {
	p1 = a;
	p2 = b;
}
int Crectangle::acreage() {
	int length = abs(p1.x - p2.x);//���㳤��
	int high = abs(p1.y - p2.y);//����߶�
	return length * high;
}
int Crectangle::perimeter() {
	int length = abs(p1.x - p2.x);//���㳤��
	int high = abs(p1.y - p2.y);//����߶�
	return 2 * (length + high);
}
int main() {
	int i, j, m, n;
	cout << "�����������������" << endl;
	cin >> i >> j >> m >> n;
	Cpoint a(i, j), b(m, n);//����������
	Crectangle rec(a, b);//�������
	cout <<"���"<< rec.acreage() << endl;
	cout <<"�ܳ�"<< rec.perimeter() << endl;
	return 0;
}