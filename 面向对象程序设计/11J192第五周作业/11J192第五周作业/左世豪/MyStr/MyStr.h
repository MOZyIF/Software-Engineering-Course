#pragma once
#include<iostream>
using namespace std;

class MyStr {
	int m_length; // �ַ�����ĳ���
	char* m_buff; // ָ��̬�ַ�����
private:
	static int strlen(const char* ptr);//��ȡ�ַ�����
	static void strncpy(char* dest, const char* src, int n);//��ʾ��src��ָ����ַ�������src��ַ��ʼ��ǰn���ֽڸ��Ƶ�dest��ָ��������
public:
	MyStr(const char* val = nullptr);
	MyStr(const MyStr& s);
	~MyStr() { 
		delete[] m_buff; 
	}//����
	int size() { 
		return m_length; 
	};
	
	// ������������
	friend ostream& operator<<(ostream&, const MyStr&);//�ַ����
	
	friend MyStr operator+(const MyStr&, const MyStr&);//�ַ�����
	
	MyStr& operator=(const MyStr& s1);
	
	void swap(MyStr&, MyStr&);//�����ַ�����
	
	void operator+=(const MyStr&);//����ַ�
	
	void insert(char s, int n);//�����ַ�����n���ַ���
	
	void erase(int n);//ɾ����n���ַ�
	
	void clear();//����ַ�
	
	

	void resize(int length);//�ı��ַ�����
	
	void replace(char x, int n);//�滻��n���ַ�
};

