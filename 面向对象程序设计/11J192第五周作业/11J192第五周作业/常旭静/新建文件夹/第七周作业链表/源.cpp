#include<iostream>
#include"��ͷ.h"
using namespace std;
void text() {
	SList<int> l;
	int val;
	cout << "�������������ݣ�";//��ʹ�õĲ���������1 2 3
	while (cin >> val) {//ctrl+Z��������
		l.push_back(val);
	}//����ο��˽̲�
	cout << l << endl;
	Node<int>* pos = l.find(3);
	l.insert(pos, 4);
	cout << l << endl;
	l.erase(4);
	cout << l << endl;
}
int main() {
	text();
		return 0;
	}
	
