#include"myclass.h"
#include"math.h"
CPoint::CPoint(double a, double b) {
	x = a;
	y = b;
}//Ϊ��Ա���ݸ�ֵ
double CPoint::miniusx(const CPoint& p, const CPoint& q) {
	double wide = fabs(p.x - q.x);
	return wide;
}//miniusx������ʵ��
double CPoint::miniusy(const CPoint& p, const CPoint& q) {
	double length = fabs(q.y- p.y);
	return length;
}//miniusy������ʵ��

CRectangle::CRectangle(CPoint& a1, CPoint& a2) {
	P1 = a1;
	P2 = a2;
}//���ι��캯����ʵ��
double CRectangle::area() {
	double wide = CPoint::miniusx(P1, P2);
	double length = CPoint::miniusy(P1, P2);
	double area = wide * length;
	return area;
}//����������
double CRectangle::cir() {
	double wide = CPoint::miniusx(P1, P2);
	double length = CPoint::miniusy(P1, P2);
	double cir = (wide + length) * 2;
	return cir;
}//��������ܳ�


