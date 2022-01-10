#pragma once
#include<iostream>
using namespace std;
class MyStr 
{
	int m_length; // �ַ�����ĳ���
	char* m_buff; // ָ��̬�ַ�����
private:
	// ˽�о�̬��Ա����
	static int strlen(const char* ptr);//��ȡc����ַ�������
	//��srcָ���������ǰn���ַ����Ƶ�destָ���������
	static void strncpy(char* dest, const char* src, int n);

public:
	MyStr(const char* val = nullptr); // Ĭ�Ϲ��캯��
	MyStr(const MyStr& rhs);
	MyStr(MyStr&& rhs);
	~MyStr() { delete[] m_buff; }
	int size() { return m_length; }
	void insert(char text[],int index,char s);   //�����ַ�
	void erase(char text[], int del);   //ɾ���ַ�
	void clear(char text[]);   //����ַ�
	void replace(char text[],char rep,char s);  //����ַ�
	// ������������
	friend ostream& operator<<(ostream&, const MyStr&); //��ӡ�ַ���
	friend MyStr operator+(const MyStr&, const MyStr&);  //�ַ������
	MyStr& operator=(const MyStr&);
};