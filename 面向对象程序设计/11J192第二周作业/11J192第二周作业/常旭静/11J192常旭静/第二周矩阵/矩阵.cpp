#include"����.h"
#include<iostream>
#include<fstream>
using namespace std;
 matrix:: matrix(int n ) {
	 if (n == 1) {
		 ifstream fin;//����һ���ļ����͵���
		 fin.open("test.txt", std::ios_base::in); // �򿪵�ǰ�����ֵ���ڵ��ļ�
		 if (!fin.is_open())
			 exit(EXIT_FAILURE);//��ֹ����
		 else
		 {
			 for (int i = 0;i < 4;i++) {
				 for (int j = 0;j < 4;j++) {
					 fin >> A[i][j];//����ǰ����ĳ�Ա���ݸ�ֵ
				 }
			 }
			 fin.close();//�ر��ļ�
		 }
	 }
	 else {
		 ifstream fin;
		 fin.open("test2.txt", std::ios_base::in); // ascii file
		 if (!fin.is_open())
			 exit(EXIT_FAILURE);
		 else
		 {
			 for (int i = 0;i < 4;i++) {
				 for (int j = 0;j < 4;j++) {
					 fin >> A[i][j];
				 }
			 }
			 fin.close();
		 }
	 }
}//���캯����ʼ����Ա����
 matrix::matrix() {
	 for (int i = 0;i < 4;i++) {
		 for (int j = 0;j < 4;j++) {
			 A[i][j] = 0;
		 }
	 }
 }//���캯��ʹ��Ա���ݵĳ�ֵΪ0��
 matrix  matrix::operator*(const matrix& a)const {//*���������
	 matrix c;
	 int n = 0;//�����ۼ������������ڸ�c.A[i][j]��ֵ
	 int m = 0;//���ڼ���c.A[j]��j��ֵ
	 for (int b = 0;b < 4;b++) {
			 for (int i = 0;i < 4;i++) {
				 for (int j = 0; j < 4;j++) {
					 n += A[b][j] * a.A[j][i];
				 }
				 c.A[b][i] = n;
				 n = 0;
			 }
	 }
	 return c;
 }
 void matrix::print() {
	 cout << "�˴μ�����Ϊ��" << endl;
	 for (int i = 0;i < 4;i++) {
		 for (int j = 0;j < 4;j++) {
			 if (j == 3) {
				 cout << A[i][j] << endl;//�����Ա���ݵ�ֵ
			 }
			 else cout << A[i][j] << " ";
		 }
	 }
 }