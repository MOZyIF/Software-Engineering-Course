#pragma once
#include <iostream>
using namespace std;

class Complex {
public:
	Complex(double x=0.0, double y=0.0);//���캯��
	Complex operator+(Complex& c) { //+���������
		Complex com;
		com.a = this->a + c.a;
		com.b = this->b + c.b;
		return com;
	}
	Complex operator-(Complex& c) { //-���������
		Complex com;
		com.a = a - c.a;
		com.b = b - c.b;
		return com;
	}
	Complex operator*(Complex & c) { //�˷�*���������
			Complex com;
			com.a = a * c.a;
			com.b = b * c.b;
			return com;
		}
	Complex operator/(Complex& c){ //����/���������
		Complex com;
		com.a = a / c.a;
		com.b = b / c.b;
		return com;
	}
	friend ostream& operator<<(ostream& out,const Complex& c);//������������
private:
	double a;
	double b;
};
Complex::Complex(double x, double y):a(x),b(y) {

}

ostream& operator<<(ostream& out, const Complex& c) {
	if(c.b>0)
	    out << c.a << "+" << c.b << 'i';
	if (c.b < 0)
		cout << c.a << "-" << c.b << 'i';
	if (c.b == 0)
		cout << c.a;
	return out;
}