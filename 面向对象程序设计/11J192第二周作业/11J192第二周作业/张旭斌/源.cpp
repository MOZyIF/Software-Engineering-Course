#include<iostream>
using namespace std;
class CMatrix {
public:
	CMatrix();//���캯��
	~CMatrix();//��������
	double show();//��ʾ
	CMatrix operator*(const CMatrix& a) {//���������
		CMatrix c;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				c.arr[i][j] = (arr[i][1] * a.arr[1][j]) + (arr[i][2] * a.arr[2][j]) + (arr[i][3] * a.arr[3][j]) + (arr[i][4] * a.arr[4][j]);
			}
		}
		return c;
	}
private:
	double arr[4][4] = { 0 };
};
CMatrix::CMatrix() {
	cout << "��ӵ�һ�д���ʼ�������ĸ�Ԫ��" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
}
double CMatrix::show() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}
int main() {
	CMatrix my_matrix_one;
	CMatrix my_matrix_two;
	CMatrix my_matrix_three;
	cout << "���о���ĳ˷�" << endl;
	my_matrix_three = my_matrix_one * my_matrix_two;
	cout << "��ʾ���" << endl;
	my_matrix_three.show();
	return 0;
}