#pragma once
#include<iostream>
using namespace std;
class MyString
{
public:
	size_t strLength; // �ַ�����ĳ���
	char* p_str; // ָ��̬�ַ�����
private:
	// ˽�о�̬��Ա����
	static int strlen(const char* ptr);
	static void strncpy(char* dest, const char* src, int n);
public:
	MyString(const char* val = nullptr); // Ĭ�Ϲ��캯��
	MyString(const MyString& rhs);//���ƹ��캯��
	~MyString() { delete p_str; }     //��������
	int size() { return strLength; }



	// ������������
	MyString& append(const MyString&);
	MyString& erase(size_t, size_t);
	MyString& insert(size_t, const MyString&);
	void swap(MyString& lhs, MyString& rhs);
	MyString& assign(MyString&, size_t, size_t);
	MyString& replace_all(const char oldc, const char newc = NULL);




	//���������
	MyString& operator=(const MyString& str);
	friend ostream& operator<<(ostream&, const MyString&);
	friend istream& operator>> (istream&, MyString&);
	friend MyString operator+(const MyString&, const MyString&);
};
void test01();