#pragma once
struct node {
	int data;
	node* next;
	node(int n) :data(n), next(nullptr) {};//��ʼ��
};
class linklist {
public:
	linklist();//���캯��
	void inserthead(int data);//��ͷ������ڵ�
	void insert(int data, int pos);//����ڵ�
	void remove(int data);//ɾ���ڵ�
	int getlength();//�õ�������
	int find(int data);//���ҽڵ�λ��
	void print();//��ӡ����
	~linklist();//��������
private:
	node* head;//ͷ�ڵ�
	int length;//����
};