#pragma once
using namespace std;

class MyStr {
	int m_length;
	char* m_buff;
public:
	MyStr(const char* val = nullptr);//Ĭ�Ϲ��캯��
	MyStr(const MyStr& rhs);//���ƹ��캯��
	MyStr(MyStr&& rhs);//�ƶ����캯��
	~MyStr() { delete[]m_buff; }//��������
	MyStr& operator=(const MyStr& rhs);//���ƹ��캯�������������
	MyStr& operator=(MyStr&& rhs);//�ƶ����캯�������������
	static void swap(MyStr& rhs, MyStr& rhs2);//���������ַ���������
	static void eras(MyStr& rhs, int n);//ɾ�������еĵ�n��Ԫ��
	friend MyStr operator+(const MyStr&, const MyStr&);//+���������
	void print(MyStr& rhs);//�������
private:
	static int strlen(const char* val);//��ȡconst�ַ�������
	static int strlen(char* val);//��ȡ�ַ�������
	static void strncpy(char* val2, const char* val, int n);//��valָ���������ǰn���ַ����Ƶ�val2ָ���������
	static void strncpy(char* val2, int n, char* val,int m);//��valָ���������ǰm���ַ����Ƶ�val2ָ���������(�ӵ�n��λ�ÿ�ʼ)
};

//��ȡconst�ַ�������
int MyStr::strlen(const char* val) {
	int len = 0;
	while (val && *val++ != '\0')
		len++;
	return len;
}
//��ȡ�ַ�������
int MyStr::strlen(char* val) {
	int len = 0;
	while (val && *val++ != '\0')
		len++;
	return len;
}
//�����ַ�
void MyStr::strncpy(char* val2, const char* val, int n) {
	for (int i = 0; i < n; ++i)
		val2[i] = val[i];
}
void MyStr::strncpy(char* val2, int n, char* val, int m) {
	for (int i = 0, j = n; i < m; i++, j++)
		val2[j]=val[i];
}
//���������
MyStr& MyStr::operator=(const MyStr& rhs) {
	if (this != &rhs) {
		delete[]m_buff;
		m_length = rhs.m_length;
		m_buff = new char[m_length];
		strncpy(m_buff, rhs.m_buff, m_length);
	}
	return *this;
}
MyStr& MyStr::operator=(MyStr&& rhs) {
	if (this != &rhs) {
		delete[]m_buff;
		m_length = rhs.m_length;
		m_buff = rhs.m_buff;
		rhs.m_buff = nullptr;
		rhs.m_length = 0;
	}
	return *this;
}
MyStr operator+(const MyStr& s1, const MyStr& s2) {
	MyStr res;
	res.m_length = s1.m_length + s2.m_length;
	res.m_buff = new char[res.m_length];
	MyStr::strncpy(res.m_buff, s1.m_buff, s1.m_length);
	MyStr::strncpy(res.m_buff, s1.m_length, s2.m_buff, s2.m_length);
	return res;
}

//���캯����
//Ĭ�Ϲ��캯��
MyStr::MyStr(const char* val) :m_length(strlen(val)), m_buff(m_length > 0 ? new char[m_length] : nullptr) {
	strncpy(m_buff, val, m_length);
}
//���ƹ��캯��
MyStr::MyStr(const MyStr& rhs) : m_length(rhs.m_length), m_buff(m_length > 0 ? new char[m_length] : nullptr) {
	strncpy(m_buff, rhs.m_buff, m_length);
}
//�ƶ����캯��
MyStr::MyStr(MyStr&& rhs) : m_length(rhs.m_length), m_buff(rhs.m_buff) {
	rhs.m_buff = nullptr;
	rhs.m_length = 0;
}

//��ӡ����
void MyStr::print(MyStr& rhs) {
	for (int i = 0; i < strlen(rhs.m_buff); i++)
		cout << rhs.m_buff[i];
}
//���������ַ���������
void MyStr::swap(MyStr& rhs, MyStr& rhs2) {
	char* val3 = rhs.m_buff;
	int len = rhs2.m_length;
	for (int i = 0; i < len; i++)
		rhs.m_buff[i] = rhs2.m_buff[i];
	rhs2.m_buff = val3;
}
//ɾ��valָ��������еĵ�n��Ԫ��
void MyStr::eras(MyStr& rhs, int n) {
	char* val2=0;
	int len = rhs.m_length;
	for (int i = 0; i < n - 1; i++)
		val2[i] = rhs.m_buff[i];
	for (int i = n - 1; i < len - 1; i++)
		val2[i] = rhs.m_buff[i + 1];
	rhs.m_buff = val2;
}

//���Ժ���
void test() {
	MyStr mystr1 = "I am a boy";
	MyStr mystr2 = "I am a girl";
	MyStr mystr3 = mystr1;
	MyStr mystr4 = mystr1 + mystr2;
	mystr1.print(mystr1);//����Ĭ�Ϲ��캯��
	mystr3.print(mystr3);//���Ը��ƹ��캯��
	mystr4.print(mystr4);//�����ƶ����캯��
	mystr3.eras(mystr3, 1); mystr3.print(mystr3);//����ɾ������
	mystr1.swap(mystr1, mystr2); mystr1.print(mystr1);//���Խ�������
}
