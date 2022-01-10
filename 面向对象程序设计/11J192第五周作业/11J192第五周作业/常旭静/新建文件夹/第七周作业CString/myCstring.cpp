#include "myCstring.h"
#include<iostream>
#include"stdio.h"
using namespace std;
CString::CString() {//���캯��
	cout << "�������ַ����ĳ��ȣ�";
	cin >> m_len;
	m_buff = new char[m_len];
	cout << "�����������е��ַ���" << endl;
	for (int i = 0;i < m_len;i++) {
		cin >> m_buff[i];
	}

}


CString::CString(CString&& str) :m_len(str.m_len), m_buff(str.m_buff)
{
}

CString::~CString()//��������
{
		delete[]m_buff;
}

CString::CString(CString& str)
{
	int len = getlen(str);//ȡ���ַ�������
	m_buff = new char[len];//�����ڴ�ռ�
	for (int i = 0;i < len;i++)
		m_buff[i] = str.m_buff[i];//��ֵ
}

int CString::getlen(CString& str)
{
	return str.m_len;
}

void CString::Swap(CString& str)//���������ַ���
{
	int len = getlen(str);
	if (len != m_len) {
		cout << "���ݴ�С��һ�£����ɽ���";//���ݴ�С��һ�»ᵼ������������ʲ�������
	}
	else {
		for (int i = 0;i < len;i++) {//����ַ�����
			char t = 0;
			t = str.m_buff[i];
			str.m_buff[i] = m_buff[i];
			m_buff[i] = t;
		}
	}
}

void CString::erase()//ɾ�������ַ�
{
	char a;//��¼��Ҫɾ�����ַ�
	cout << "����������Ҫɾ�����ַ���" << endl;
	cin >> a;
	for(int i=0;i<m_len;i++){//Ѱ��Ŀ���ַ������丳ֵΪ0��
		if (m_buff[i] != a) {
			continue;
		}
		else {
			m_buff[i] = 0;
		}
	}
	int c = 0;//���ڼ�¼0�ĸ���
	for (int i = 0;i < m_len;i++) {
		if (m_buff[i] == 0) {
			int a = i;//��¼i�ĳ�ֵ
			int j = m_len - i;//��¼��������
			c++;//��¼0�ĸ���
			for (int b = 0;b < j;b++) {
				m_buff[i] = m_buff[i + 1];//����һλ��ֵ����ǰһλ
				i++;
			}
			i = a;//���´�i������ѭ��
		}
		else continue;
		m_len = m_len - c;//��0��ռ�ݵ�λ��������ֻ���ʣ�����Ч�ַ�
	}

}

void CString::replace()//�滻Ŀ���ַ�
{
	char a;
	char b;
	cout << "����������Ҫ�滻���ַ�" << endl;
	cin >> a;
	cout << "�������������滻���ַ���" << endl;
	cin >> b;
	for (int i = 0;i < m_len;i++) {//��������Ԫ��
		if (m_buff[i] == a) {
			m_buff[i] = b;
		}
		else continue;
	}
}

void CString::insert()//�����ַ�
{
	int num;
	cout << "������Ҫ������ַ����������е�λ�ã�" << endl;
	cin >> num;
	cout << "��������Ҫ������ַ���";
	char a;
	cin >> a;
	char* tem = new char(m_len);
	strcpy(tem, m_buff,m_len);
	delete[]m_buff;
	m_len++;
	m_buff = new char(m_len);
	for (int i = 0;i < m_len;i++) {
		if (i ==num - 1) {
			m_buff[num - 1] = a;

		}
		else if (i < num - 1)
			m_buff[i] = tem[i];
		else if (i > num - 1)
			m_buff [i]= tem[i - 1];
	}
	
}

void CString::assign()//����ֵ
{
	int newlen;
	cout << "������������Ҫ���õ��ַ������ȣ�";
	cin >> newlen;
		delete[]m_buff;
	m_len = newlen;
	m_buff = new char[m_len];
	cout << "���������ú�����飺";
	for (int i = 0;i < m_len;i++) {
		cin >> m_buff[i];
	}
	cout << "���ú������Ϊ��" << endl;
	print();
}

void CString::clear()
{
	m_buff = nullptr;
}

void CString::resize()//�ı䳤��
{
	cout << "��ǰ���鳤��Ϊ��" << m_len;
	cout << "������ı������鳤�ȣ�";
	int a;
	cin >> a;
	char* tem=nullptr;
	if (a > m_len) {
		 tem = new char[m_len];//tem��ʱ�������ڴ���m_buff��ֵ
		 int b = m_len;
	strcpy(tem, m_buff,m_len);
		delete[]m_buff;//���m_buff
		m_len = a;
		m_buff = new char[m_len];//�½�m_buff
		strcpy(m_buff, tem,b);
		for (int i = b;i < m_len;i++) {
			m_buff[i] = '0';//�Ѷ����λ�ø�ֵ�ɡ�0��
		}
	}
	if (a < m_len) {
		char* tem = new char[m_len];
		strcpy(tem, m_buff,m_len);
		delete[]m_buff;
		m_buff = new char[m_len];
		for (int i = 0;i < a;i++) {
			m_buff[i] = tem[i];//ֱ�ӿ������һ����
		}
	}
	delete[]tem;//ɾ��tem��ʱ����
}

void CString::print()
{
	for (int i = 0;i < m_len;i++) {
		if (i == m_len - 1) {
			cout << m_buff[i] << endl;
		}
		else {
			cout << m_buff[i] << "  ";
		}
		
	}
}

void CString::strcpy(char* a, char* b,int j)
{
	
	

	for (int i = 0;i < j;i++) {
		a[i] = b[i];
	}//���������ĸ��Ʋ���
}

ostream& operator<<(ostream& os, const CString& str)
{
	for (int i = 0; i < str.m_len; ++i)
		os << str.m_buff[i];
	return os;
	// TODO: �ڴ˴����� return ���
}
