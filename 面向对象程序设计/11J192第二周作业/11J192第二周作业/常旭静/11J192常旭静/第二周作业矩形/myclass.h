#pragma once
//��Ķ���(myclass.h)
class CPoint {//����һ������
public:
	CPoint(){};//Ĭ�Ϲ��캯��
	CPoint(double a, double b) ;//���ι��캯��
	~CPoint() {};//��������
	static double  miniusx(const CPoint& p, const CPoint& q);//�õ����εĿ�
	static double  miniusy(const CPoint& p, const CPoint& q);//�õ����εĳ�
private:
	double x, y;//��Ա����Ϊ��������
};
class CRectangle {
public:
	CRectangle(CPoint&a1, CPoint&a2);//���ι��캯��
	double area();//����������
	double cir();//��������ܳ�
private:
	CPoint P1;
	CPoint P2;//��Ա��Ϊ�������ϽǺ����½�����
};