//��ʦ�������ļ�����һ����LNK2019�����������ܲ�ķ�������������ʲô�ģ��������������
#include<iostream>
#include<math.h>
using namespace std;
class CPoint {
public:
	CPoint(int i,int j);//���캯��
	~CPoint() {//��������
		cout << "��������" << endl;
	};
	int show();
	void getxy(int *px,int *py)const;//��ȡ x��y
private:
	int x;
	int y;
	friend class CPoint;//��Ԫ��
};
CPoint::CPoint(int i,int j) :x(i),y(j){}
int CPoint::show() {
	cout << "�������Ϊ" << "(" << x << "," << y << ")" << endl;
	return 0;
}
void CPoint::getxy(int *px,int *py)const{
	*px = x;
	*py = y;
}

class CPoint;
class CRectangle {
public:
	CRectangle();//���캯��
	~CRectangle();//��������
	int area(const CPoint& a, const CPoint& b);//�������
	int circumference(const CPoint& a, const CPoint& b);//�ܳ�����
private:
};
int CRectangle::area(const CPoint&a,const CPoint&b) {
	int p;
	int i(0), j(0), k(0), l(0);
	a.getxy(&i,& j);
	b.getxy(&k, &l);
	p = abs( i-k ) * abs(j -l );
	return p;
}
int CRectangle::circumference(const CPoint& a, const CPoint& b) {
	int  p;
	int i(0), j(0), k(0), l(0);
	a.getxy(&i,& j);
	b.getxy(&k, &l);
	p = (abs(i - k) + abs(j - l))*2;
	return p;
}
int main() {
	int i(0), j(0), k(0), l(0);
	CPoint a(i, j);//���Ͻǵ�
	CPoint b(k, l);//���½ǵ�
	cout << "���������Ͻǵ�����" << endl;
	cin >> i >> j;
	cout << "���������Ͻǵ�����" << endl;
	cin >> k >> l;
	CRectangle c;
	cout << "���ε����Ϊ" <<c.area(a,b)<<endl;
	cout << "���ε��ܳ�Ϊ" << c.circumference(a, b) << endl;
	return 0;
}
