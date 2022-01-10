#pragma once
#include<iostream>
using namespace std;
class mystr {
	int m_length;//�ַ�����ĳ���
	char* m_buff;//ָ��̬�ַ�����
private:
	static int strlen(const char* ptr);//��ȡc����ַ�������
	static void strncpy(char* dest, const char* src, int n);//����srcָ���������ǰn���ַ���destָ���������
public:
	mystr(const char* val = nullptr);//Ĭ�Ϲ��캯��
	~mystr() { delete[]m_buff; }//��������
	int size() { return m_length; };
	friend ostream& operator<< (ostream&, const mystr&);//�����<<����
	friend mystr operator + (const mystr&, const mystr&);//�����+����
	mystr(const mystr& rhs);//���ƹ��캯��
	mystr& operator=(const mystr& rhs);//�Ⱥŵ�����
	mystr(mystr&& rhs);//�ƶ����캯��
	mystr& operator=(mystr&& rhs);//�ƶ���ֵ�����
	void swap(mystr&, mystr&);//���������ַ���������
	mystr max(const mystr&, const mystr&);//�Ƚ������ַ����ĳ��ȣ����ؽϴ��
	mystr insert(mystr&, const mystr&, int pos);//�����ַ�
};