//ʵ��һ���ַ����࣬������string��ͬ��
#include<iostream>
using namespace std;
#include<string>
class CMystr {
private:
	//˽�г�Ա����
	int m_length;//�ַ�������ĳ���
	char* m_buff;//ָ��̬����
	//˽�о�̬��Ա����
	static int strlen(const char* ptr);//��ȡ�ַ�������
	static void strncpy(char* dest, const char* src, int n);
	
public:
	//Ĭ�Ϲ��캯��
	CMystr(const char* val = nullptr);
	//���������
	CMystr& operator=(const CMystr& rhs);
	//���ƹ��캯��
	CMystr(const CMystr&);
	//��������
	~CMystr() { delete[] m_buff;
	
	}//������������̬�����ͷ�
	//�ַ������Ⱥ���
	int size() { return m_length; }
	//չʾ�ַ���
	void show() {
		for (int i = 0; i < m_length; i++)
			cout << m_buff[i];
		return ;
	}
	//����ַ�����
	CMystr& append(const CMystr&);
	//���뺯��
	CMystr& insert(int l, const CMystr&);
	//
	CMystr& assign( CMystr&,int l1,int l2);
	// erase ɾ��  
	CMystr& erase(int l1, int l2);
	//������������d
	friend void Swap(CMystr& c1, CMystr& c2);//�໥�����ַ���
	friend ostream& operator<<(ostream&, const CMystr&);//��ӡ�ַ���
	friend CMystr operator+(const CMystr&, const CMystr&);//�����ַ�����ӵ�����
};

