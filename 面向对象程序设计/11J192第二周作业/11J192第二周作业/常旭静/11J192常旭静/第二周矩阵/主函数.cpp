#include<iostream>
using namespace std;
#include"����.h"
#include<fstream>
int main() {
	matrix  a(1);
	matrix  b(2);
	matrix c = a * b;//�������˷�
	c.print();
	return  0;
}