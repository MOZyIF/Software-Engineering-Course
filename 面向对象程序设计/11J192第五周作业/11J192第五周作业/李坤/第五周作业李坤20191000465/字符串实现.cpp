#include<iostream>
using namespace std;
class mystr {
public:
	mystr();//Ĭ�Ϲ��캯��
	mystr(const char* ptr1);//���캯��
	mystr(const mystr& ptr2);//�������캯��
	mystr( mystr&& ptr4);//�ƶ����캯��
	friend ostream& operator<<(ostream& os, const mystr& ptr2);//�������
	mystr &operator=(const mystr& ptr3);//��������
	mystr& operator=(mystr&& ptr5);//�ƶ���������
	void mystrpushback(const char* str4);//β������
	void myswap(mystr&ptr6);//����
	void myinsert(int n,const char* ptr8);//����
	void myerase(int n, int k);//ɾ��
	void myclear();//�Ƴ�ȫ���ַ���
	void myresize(int k);//���ô�С
	
	~mystr();//��������

private:
	char* mstr;//ָ��
	int mlenth;//�ַ�������
	static int mystrlen(const char*str1);//����ַ�������
	static void mystrcpy(char* str2, const char* str3, int n);//�����ַ���֮��Ŀ���
	 
};
mystr::mystr() :mlenth(0), mstr(nullptr) {};
int mystr::mystrlen(const char* str1) {
	int len = 0;
	if (str1) {//����ǿ�ָ��Ϳ�ʼ����
		while (str1 && *str1++ != '\0') {//
			len++;
		}
		return len;
	}
	else
		return len;//��������Ϊ0

}
void mystr::mystrcpy(char* str2, const char* str3, int n) {//��������forѭ��������
	for (int i = 0; i < n; i++) {
		str2[i] = str3[i];}
}
mystr::mystr(const char* ptr1)://���캯��
	mlenth(0),mstr(nullptr)
{
	mlenth = mystrlen(ptr1);//ȡ�ô�����ַ�������
	if (mlenth) {//����һ����̬����Ȼ��ֵ
		mstr = new char[mlenth];
		mystrcpy(mstr, ptr1, mlenth);
	}
	else
		mstr = nullptr;//���������һ����ָ�룬��ô����Ȼ�ǿ�ָ��

}
//��֪��Ϊʲô�ƶ����캯���о���
mystr::mystr(const mystr& ptr2)://�������캯��
	mlenth(ptr2.mlenth)
{
	if (mlenth) {//ȡԭ�ַ����ĳ��ȣ�Ȼ���ʼ��
		mstr = new char[mlenth];
		mystrcpy(mstr, ptr2.mstr, mlenth);
	}
	else
		mstr = nullptr;//�����һ�����ַ�������ôָ���ָ��

}
mystr::mystr( mystr&& ptr4):
   mlenth(ptr4.mlenth),mstr(ptr4.mstr)//�ƶ����캯�����ƽ���Ӧ�ĵ�ַ
{
	ptr4.mlenth = 0;
	ptr4.mstr = nullptr;
}
mystr::~mystr() {//��ֹ�ַ����Ƴ�ʱ�ٶ��ͷ��ڴ�
	if (mlenth != 0)
	{  delete[]mstr;
		mlenth = 0;
	}
}

ostream& operator<<(ostream& os, const mystr& ptr2) {//���������
	for (int i = 0; i < ptr2.mlenth; i++) {
		os << ptr2.mstr[i];//�������os
	}
	return os;
}
mystr& mystr::operator=(const mystr& ptr3) {//�������ƺ���
	if (this == &ptr3) {//��ֹ���Ҹ�ֵ
		return *this;
	}
	delete[]mstr;
	mlenth = ptr3.mlenth;
	mstr = new char[mlenth];
	mystrcpy(mstr, ptr3.mstr, mlenth);
}
mystr& mystr::operator=(mystr&& ptr5) {//�ƶ��������캯��
	if (this == &ptr5) {
		return *this;
	}
	delete[]mstr;
	mlenth = ptr5.mlenth;
	mstr = ptr5.mstr;
	ptr5.mlenth = 0;
	ptr5.mstr = nullptr;
}
void mystr::mystrpushback(const char* str4) {//β��
	int strlen = mystrlen(str4);//ȡ�ô��������ַ�����
	int pastmlenth = mlenth;//ȡ��ԭ�ַ����ĳ���
	mlenth = strlen + pastmlenth;//�ַ��������ĳ���
	char* newmstr = nullptr;
	newmstr = new char[mlenth];//������̬����
	int j = 0;//����ѭ��ʱҪ�õ���һ������
	mystrcpy(newmstr, mstr, pastmlenth);
	for (int i = pastmlenth; i < mlenth; i++) {//��ԭ�ַ���β����ʼ���в���
		
		newmstr[i] = str4[j];
		j=j+1;
	}
	delete[]mstr;//ɾ��ԭ�ַ����Ķ�̬���飬Ȼ���ٴ���һ����̬���鸳ֵ
	mstr = new char[mlenth];
	mystrcpy(mstr, newmstr, mlenth);
	delete[]newmstr;}
void mystr::myswap(mystr& ptr6) {
	char* mid = nullptr;//����һ����̬����C
	int midlen = mlenth;
	mid = new char[mlenth];
	mystrcpy(mid, mstr, mlenth);//��ԭ�ַ�������C
	delete[]mstr;
	mlenth = ptr6.mlenth;
	mstr = new char[mlenth];
	mystrcpy(mstr, ptr6.mstr, mlenth);//�Ѵ��������ַ����������ڵ��ַ���
	delete[]ptr6.mstr;//��C�ַ����������������ַ���
	ptr6.mlenth = midlen;
	ptr6.mstr = new char[midlen];
	mystrcpy(ptr6.mstr, mid, midlen);
	delete[]mid;
	mid = nullptr;

}
void mystr::myinsert(int n, const char* ptr8)//n������ڵڼ���֮�� 
{
	int ptrlen = mystrlen(ptr8);//ȡ�ò����ַ�������
	int midlen = n + ptrlen;//�м����ַ�������
	int j = 0;//����ѭ��
	int k = n;//�ڼ����ַ���ʼ����
	int newlen = mlenth + ptrlen;//�µ��ַ�������
	char* midstr = nullptr;
	midstr = new char[newlen];
	for (int i = 0; i < n; i++) {//�����ַ�ǰ���ַ���
		midstr[i] = mstr[i];
	}
	for (int i = n; i < midlen; i++) {//������ַ���
		midstr[i] = ptr8[j];
		j++;
	}
	for (int i = midlen; i < newlen; i++) {//�������ԭ�ַ�����β���ַ�
		midstr[i] = mstr[k];
		k++;
	}
	delete[]mstr;
	mlenth = newlen;
	mstr = new char[mlenth];
	mystrcpy(mstr, midstr, mlenth);//���¸�ֵ
	delete[]midstr;
};
void mystr::myerase(int n, int k)//����n����ɾȥ�ӵڼ����ַ���k������
{
	if (n > mlenth || n < 0)
	{
		cout << "�������" << endl;
		return;
	}
	int start = n-1;
	int midlen = mlenth - start ;
	if (k > midlen || k < 0) {
		cout << "ɾȥ�ֽڳ�������" << endl;
		return;
	}
	int newlen = mlenth - k;//ɾȥ���ַ�������
	char* newstr = nullptr;
	newstr = new char[newlen];
	for (int i = 0; i < start; i++) {//ɾ��λ��֮ǰ���ַ���
		newstr[i] = mstr[i];
	}
	int endstart = n + k - 1;
	for (int i = endstart; i < mlenth; i++) {//ɾ�����Ժ�ʣ����ַ���
		newstr[start] = mstr[i];//��֪��Ϊʲô�����о��棬ϣ����ʦָ�������������
		start++;
	}
	mlenth = mystrlen(newstr);//���¸�ֵ
	delete[]mstr;
	mstr = new char[mlenth];
	mystrcpy(mstr, newstr, mlenth);



	

}
void mystr::myclear() {//�Ƴ��ַ���
	delete[]mstr;
	mlenth = 0;
	mstr = nullptr;
}
void mystr::myresize(int k) {//���ô�С
	if (k >0) {
		char* newstr = nullptr;
		newstr = new char[k];
		mystrcpy(newstr, mstr, mlenth);
		delete[]mstr;
		mstr = nullptr;
		mlenth = k;
		mstr = new char[mlenth];
		mystrcpy(mstr, newstr, mlenth);


	}
	if (k == 0) {
		mlenth = 0;
		delete[]mstr;
		mstr = nullptr;
	}
	if (k < 0) {
		cout << "�������" << endl;
		return;
	}
	
}
int main() {
	mystr a1("hello,C++");
	mystr a2(a1);
	cout << "���Ը��ƹ��캯��" << endl;
	cout << a2 << endl;
	mystr a3("i love C++");
	cout << a3 << endl;
	cout << "�����������뵥����ͬ�ַ���" << endl;
	a1.mystrpushback("iiiii");
	cout << a1 << endl;
	cout << "����β�����벻ͬ���ַ���" << endl;
	a3.mystrpushback("I love Miss.liang");
	cout << a3 << endl;
	a3.myswap(a1);
	cout << "������a1" << endl;
	cout << a1 << endl;
	cout << "������a3" << endl;
	cout << a3 << endl;
	mystr a5("love forever");
	cout << "����ǰ" << endl;
	cout << a5 << endl;
	cout << "�����" << endl;
	a5.myinsert(4, " you ");
	cout << a5 << endl;
	cout << "ɾ����2λ��ʼ�ܼ�2���ַ�������" << endl;
	a5.myerase(2, 2);
	cout << a5 << endl;
	return 0;
	

}
