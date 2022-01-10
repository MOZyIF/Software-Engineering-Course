#include"string.h"//�ַ�����
mystr::mystr(const char* val) :
	m_length(strlen(val)), m_buff(m_length > 0 ? new char[m_length]: nullptr) {
	strncpy(m_buff, val, m_length);
}//Ĭ�Ϲ��캯��
int mystr::strlen(const char* ptr) {
	int len = 0;
	while (ptr&&*ptr++ != '/0') {
		++len;
	}
	return len;
}//��ȡc����ַ�������
void mystr::strncpy(char* dest, const char* src, int n) {
	for (int i = 0; i < n; ++i) {
		dest[i] = src[i];
	}
}//����srcָ���������ǰn���ַ���destָ���������
ostream& operator<<(ostream& os, const mystr& s) {
	for (int i = 0; i < s.m_length; ++i) {
		os << s.m_buff[i];
		return os;
	}
}//�����<<����
mystr operator+ (const mystr&s1, const mystr&s2) {
	mystr res;
	res.m_length = s1.m_length + s2.m_length;
	res.m_buff = new char[res.m_length];
	mystr::strncpy(res.m_buff, s1.m_buff, s1.m_length);
	mystr::strncpy(res.m_buff + s1.m_length, s2.m_buff, s2.m_length);
	return res;
}//�����+����
mystr::mystr(const mystr& rhs) :
	m_length(rhs.m_length),m_buff(m_length>0?new char[m_length]:nullptr){
	strncpy(m_buff, rhs.m_buff, rhs.m_length);
}//���ƹ��캯��
mystr& mystr::operator=(const mystr& rhs) {
	if (this != &rhs) {
		delete[]m_buff;
		m_length = rhs.m_length;
		m_buff = new char[m_length];//���·����ڴ�
		strncpy(m_buff, rhs.m_buff, m_length);
	}
	return *this;
}//�Ⱥŵ�����
mystr::mystr(mystr&& rhs):m_length(rhs.m_length), m_buff(m_length > 0 ? new char[m_length] : nullptr) {
	strncpy(m_buff, rhs.m_buff, m_length);
}
mystr& mystr:: operator=(mystr&& rhs) {
	if (this != &rhs) {
		delete[]m_buff;
		m_length = rhs.m_length;
		m_buff = rhs.m_buff;
		rhs.m_buff = nullptr;
		rhs.m_length = 0;
	}
	return *this;
}//�ƶ���ֵ�����
void mystr::swap(mystr&s1, mystr&s2) {
	mystr s3;
	s3 = s1;
	s1 = s2;
	s2 = s3;
}//���������ַ���������
mystr mystr:: max(const mystr&s1, const mystr&s2) {
	if (s1.m_length > s2.m_length) {
		return s1;
	}
	else return s2;
}//�Ƚ������ַ����ĳ��ȣ����ؽϴ��
mystr mystr::insert( mystr&s1, const mystr&s2, int pos) {
	mystr a,b,c;
	a.m_length = s1.m_length + s2.m_length;
	a.m_buff = new char[a.m_length];
	b.m_length = pos - 1;
	b.m_buff = new char[b.m_length];
	strncpy(b.m_buff, s1.m_buff, pos - 1);
	c = s1;
	c.m_length = s1.m_length - (pos - 1);
	c.m_buff = c.m_buff + pos - 1;
	a = b + s2 + c;
	return a;
}//�����ַ�

int main() {
	mystr a=  "lx";
	mystr b = "lc";
	mystr c = a + b;
	cout << c;
	swap(a, b);
	cout << a << b << endl;
	return 0;
}
