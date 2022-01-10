#include<iostream>
using namespace std;
template<typename T>class CMatrix {
public:
	CMatrix();
	void print();
	CMatrix product(const CMatrix& c);
	CMatrix(const CMatrix& c);
	CMatrix operator*(const CMatrix& c);
private:
	T a[4][4];
};
//���캯��
template< typename T>CMatrix<T>::CMatrix() {
	cout << "�ֶ�����ѡ��1����ʼ��Ϊ0����ѡ��0" << endl;
	int n;
	cin >> n;
	if(n==1){
		cout << "����������þ����Ԫ��(�����Ҵ��ϵ���)" << endl;
		int i, j;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				cin >> a[i][j];
			}
		}
	}
	if (n == 0) {
		cout << "�þ����Ԫ��ȫ����ʼ��Ϊ0" << endl;
		int i, j;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				 a[i][j]=0;
			}
		}
	}
	
};

//��ӡ����
template< typename T>void CMatrix<T>::print() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			cout<<"  "<<a[i][j];
		}
		cout << endl;
	}
}
//�˻�����
template<typename T>
CMatrix<T> CMatrix<T>::product(const CMatrix& c)
{
	cout << "���ɾ������ʼ��Ϊ0����" << endl;
	CMatrix<T> tem;
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			tem.a[i][j] = a[i][j] * c.a[j][i];
		}
	}
	return tem;
};
//���ƹ��캯��
template< typename T>CMatrix<T>::CMatrix(const CMatrix& c) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			a[i][j] =  c.a[i][j];
		}
	}
}

//���������
template<typename T>CMatrix<T> CMatrix<T>::operator*(const CMatrix& c) {
	cout << "���ɾ������ʼ��Ϊ0����" << endl;
	CMatrix<T> tem;
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			tem.a[i][j] = a[i][j] * c.a[j][i];
		}
	}
	return tem;
};
int main() {
	CMatrix<int> A,B,C;
	cout << "������ĵ�һ������Ϊ" << endl;
	A.print();
	cout << "������ĵڶ�������Ϊ" << endl;
	B.print();
	// C=A.product(B);
	 C = A * B;//��������ع���
	 cout << "����������ĳ˻�Ϊ" << endl;
	 C.print();
	 return 0;
}


