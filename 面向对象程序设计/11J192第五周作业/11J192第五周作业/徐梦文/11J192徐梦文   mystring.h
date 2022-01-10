#include <iostream>
#include <string>
using namespace std;
class mstring {
public:
	mstring();//�޲ι��캯��
	//mystring(const char* s);//���캯��
	mstring(const mstring& str);//���ƹ��캯��
	mstring(mstring &&rhs);//�ƶ����캯��
    ~mstring();//��������

	static int strlen(const char* ptr);//�õ��ַ�������
	static void strcpy_s( char* dest,const char* src);//��ֵ����
   // void insert(const char* s, int n);//�����ַ�
	void swap(char* a, char* b);//���������ַ���������
	void appened();//����ַ�
	friend ostream& operator<<(ostream& out, const mstring& s);//<<���������
	mstring& operator=(const mstring& str);//=���������
	mstring& operator=(const char* s);//=���������

 
	char* p = {};//ָ���ַ������ڴ�ռ�
	int size=0;//����ĳ���
	int len=0;//�ַ�������
};

//�޲ι��캯��
mstring::mstring() {

}

//���캯��
/*mystring::mystring(const char *s) {
	if (s == NULL)
	{
		p = nullptr;
	}
	else {
		p = new char[strlen(s)+1];
		strcpy(p, s);
	}
}*/

//���ƹ��캯��
mstring::mstring(const mstring& str) {
	p = new char[strlen(str.p) + 1];//�ȴ����ڴ�ռ�
	strcpy_s(p, str.p);//��ֵ
	len = str.len;
	size = str.size;
}

//�ƶ����캯��
mstring::mstring(mstring&& rhs) :len(strlen(rhs.p)), p(rhs.p) {
	rhs.p = nullptr;
	rhs.len = 0;
}

//��������
mstring::~mstring() {
	delete[]p;
	cout << "����" << endl;
}

//�õ��ַ�������
int mstring::strlen(const char* ptr) {
	int len = 0;
	while (ptr && *ptr++ != '\0')
		len++;
	return len;
}

//��ֵ����
void mstring::strcpy_s(char* dest, const char* src) {
	for (int i = 0; i < strlen(src); i++)
		dest[i] = src[i];
}

//�����ַ� ��
/*void mstring::insert(const char* s, int n)//s�ǲ�����ַ���n�Ǵӵڼ����ַ������
{
	size = strlen(p) + strlen(s);//�ܳ���
	this->p = new char[size];//
	for (int i = n - 1, j = 0; i < size; i++, j++) {
		p[i + strlen(s)] = p[i];//�ѵ�n���ַ�����ַ�����
		p[i] = s[j];
	}
}*/

//���������ַ���������
void mstring::swap(char* a, char* b) {
	char* t = {};//�м���t
	strcpy_s(t, a);
	strcpy_s(a, b);
	strcpy_s(b, t);
}

//����ַ�
void mstring::appened() {
	char* s = {};
	cout << "��������ӵ��ַ�\n";
	cin >> s;
	size = strlen(p) + strlen(s);
	this->p = new char[size];
	for (int i = strlen(p), j = 0; i < size; i++, j++) {
		p[i] = s[j];
	}
	delete[]s;
}

//  <<��������غ���
ostream& operator<<(ostream& out, const mstring& s) {
	out << s.p;//��s.p����������
	return out;
}

//  =���������
mstring& mstring::operator=(const mstring& str) {
	if (this != &str) {
		delete[]p;
		p = new char[strlen(str.p) + 1];
		strcpy_s(p, str.p);
	}
	return *this;
}

mstring& mstring::operator=(const char* s)
{	//1 ���ڴ��ͷŵ�	
	if (p != NULL) {
		delete[] p;
		len = 0;
	}
	//2 ����p�����ڴ�
	if (s == NULL) {
		len = 0;
		p = new char[len + 1];
		strcpy_s(p, "");
	}
	else {
		len = strlen(s);
		p = new char[len + 1];
		strcpy_s(p, s);
	}
	return *this;
}

//test
int main() {
	mstring s1;
	mstring s2;
	s1 = "TEAMWANG";
	cout << s1 << endl;
	int i;
	i = s1.strlen(s1.p);
	cout << i << endl;
	s2 = "jacksonwertyuiop";
	swap(s2, s1);
	cout << s2 << endl;
	cout << s1 << endl;
	return 0;
}