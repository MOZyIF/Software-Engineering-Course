#pragma once
using namespace std;
 ostream& operator<<(ostream& os, CString& str);

class  CString {
	//friend ostream& operator<<(ostream& os, CString& str);
public:
	CString();//Ĭ�Ϲ��캯��

	CString(CString&& str);//�ƶ����캯��
	~CString();//��������
	CString(CString& str);//���ƹ��캯��
	int getlen(CString& str );//ȡ���ַ�������
	void Swap(CString& str);//���������ַ�������
	void erase();//��ȥĿ���ַ�
	void replace();//�滻�ַ�
	void insert();//�����ַ�
	void resize();//�ı��ַ�����
	void assign();//����ֵ
	void clear();//�Ƴ��ַ�
	void print();
	void strcpy(char *a, char* b,int j);
	
private:
	int m_len;//�ַ�������
	char* m_buff;//��̬����
};