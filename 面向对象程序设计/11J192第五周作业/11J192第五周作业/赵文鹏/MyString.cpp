#include"MyString.h"
//Ĭ�Ϲ��캯������
CMystr::CMystr(const char* val) :
	m_length(strlen(val)),m_buff(m_length>0? 
	new char[m_length]:nullptr)
{
	strncpy(m_buff, val, m_length);
}
//strlen��������
int CMystr::strlen(const char* ptr) {
	int len = 0;
	while (ptr && *ptr++ != '\0') {
		++len;
	}
	return len;
}
//strncpy�����Ķ���
void CMystr::strncpy(char* dest, const char* src, int n) {
	for (int i = 0; i < n; i++)
		dest[i] = src[i];
}
//������������
//����<<
ostream& operator<<(ostream& os, const CMystr& s) {
	for (int i = 0; i < s.m_length; +i)
		os << s.m_buff[i];
	return os;
}
//����+
CMystr operator+(const CMystr& s1, const CMystr& s2) {
	CMystr res;
	res.m_length = s1.m_length + s2.m_length;
	res.m_buff = new char[res.m_length];
	CMystr::strncpy(res.m_buff, s1.m_buff, s1.m_length);
	CMystr::strncpy(res.m_buff+s1.m_length, s2.m_buff, s1.m_length);
	return res;
}
//����=
CMystr& CMystr::operator=(const CMystr& rhs) {
	if (this != &rhs) {
		delete[] m_buff;
		m_length = rhs.m_length;
		m_buff = new char[m_length];//���·����ڴ�
		strncpy(m_buff, rhs.m_buff, m_length);

	}
	return *this;
}

//���ƹ��캯��
CMystr::CMystr(const CMystr& rhs) :
	m_length(rhs.m_length), m_buff(m_length > 0 ?
		new char[m_length] : nullptr) {
	strncpy(m_buff, rhs.m_buff, m_length);
}

//��������
void Swap(CMystr &s1, CMystr &s2) {
	CMystr temp=s1;
	s1 = s2;
	s2 = temp;
}

/*CMystr&  CMystr::assign(CMystr&,int l1,int l2)
{
	
}*/
//�����ַ������Ķ���
CMystr& CMystr::append(const CMystr& other)
{
	*this = *this+other;// ���øո������ص�+=  
	return *this;
}

int main()
{
	CMystr s1 = "zhaowenpeng", s2 = " is a boy", s3;
	s3=s1+s2;
	s3.show(); 
	cout << endl;
	Swap(s1, s2);
	s1.show();
	s1 = "zhaowenpeng";
	cout << endl;
	s1.show();
	cout << endl;
	s1.append(s2);
	s1.show();
	system("pause");
	return 0;
}
