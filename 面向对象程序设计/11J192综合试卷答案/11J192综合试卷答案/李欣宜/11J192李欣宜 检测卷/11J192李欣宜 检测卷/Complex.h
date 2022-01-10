#pragma once
#include <iostream> 
using namespace std;

class Complex
{
private:
	double m_real;	//������ʵ��
	double m_image;	//�������鲿
public:
	Complex()
	{
		m_real = 0; m_image = 0;
	}
	// ���캯��
	Complex(double r, double i);
	//��������ص�
	Complex operator+(const Complex& c) const;//�ӷ�
	Complex operator-(const Complex& c) const;//����
	Complex operator*(const Complex& c) const;//�˷�
	friend ostream& operator<<(ostream& os, const Complex& c);//���
};
Complex::Complex(double r, double i)
{
	m_real = r;
	m_image = i;
}
Complex Complex::operator+(const Complex& c) const
{
	Complex rtn;
	rtn.m_real = m_real + c.m_real;
	rtn.m_image = m_image + c.m_image;
	return rtn;
}
Complex Complex::operator-(const Complex& c) const
{
	Complex rtn;
	rtn.m_real = m_real - c.m_real;
	rtn.m_image = m_image - c.m_image;
	return rtn;
}
Complex Complex::operator*(const Complex& c) const
{
	Complex rtn;
	rtn.m_real = m_real * c.m_real - m_image * c.m_image;
	rtn.m_image = m_image * c.m_real + c.m_image * m_real;
	return rtn;
}
ostream& operator<<(ostream& os, const Complex& c)
{
	os << "(" << c.m_real << "," << c.m_image << ")";
	return os;
}
