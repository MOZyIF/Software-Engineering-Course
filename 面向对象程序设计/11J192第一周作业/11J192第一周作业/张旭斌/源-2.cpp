#include<iostream>
#include<string>
using namespace std;
template<typename T, int n>class Cclass {
	int size;
	T* a;
public:
	Cclass();//���캯��
	~Cclass();//��������
	int search(T);
	void set_a(int i,T& j)//������Ԫ�ظ�ֵ
};
template<typename T, int n>Cclass<T, n>::Cclass() {
	a = new T[size];//�����С��֪����newһ��
}
template<typename T, int n>Cclass<T, n>::~Cclass() {
	delete[]a;//������ֶ�ɾ�ڴ�
}
template<typename T, int n>int Cclass<T, n>::search(T k) {
	for (int i = 0; i < size; i++) {
		if (a[i] == k) {
			return i;//����оͷ������ֵ
		}
		return 0;//û�еĻ����ͷ���0.������������if��䣬��ִ��  cout
	}
}
template<typename T, int n>void Cclass<T, n>::set_a(int i, T& j) {
	a[i] = j;
}