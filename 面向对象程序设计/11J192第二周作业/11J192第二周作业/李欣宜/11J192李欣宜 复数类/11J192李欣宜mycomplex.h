//��Ķ���(mycomplex.h)
#pragma once
class CComplex
{
private:
	double m_real;		//������ʵ��
	double m_image;	//�������鲿
public:
	// double m_test;
	// Ĭ�Ϲ��캯��,��������
	CComplex()
	{
		m_real = 0; m_image = 0;
	}
	// ���캯��
	CComplex(double r, double i);
	//�������캯��
	CComplex(const CComplex& c);

	//����Ϊ���㺯��
	CComplex add(const CComplex& c) const;//�ӷ�����
	CComplex sub(const CComplex& c) const;//�������� 
	CComplex mul(const CComplex& c) const;//�˷����� 
	CComplex div(const CComplex& c) const;//�������� 

	//����Ϊ��������صĺ���
	CComplex operator+(const CComplex& c) const;//�ӷ�����
	CComplex operator-(const CComplex& c) const;//��������
	CComplex operator*(const CComplex& c) const;//�˷�����
	CComplex operator/(const CComplex& c) const;//��������

	//��ȡʵ��
	double getreal();
	//��ȡ�鲿
	double getimage();

	//�������������
	void print();
};

int main(){
	CComplex c1(1, 1);//������������
	CComplex c2(2, 2);
	cout << c1.getreal()<<endl;//���Ի�ȡʵ������
	cout << c1.getimage()<<endl;//���Ի�ȡ�鲿����
	//��������
	CComplex c;
	c = c1.add(c2);//���Լӷ�����
	c.print();
	c = c1.sub(c2);//���Լ�������
	c.print();
	c = c1.mul(c2);//���Գ˷�����
	c.print();
	c = c1.div(c2);//���Գ�������
	c.print();
	//�������������
	c = c1 + c2;//�ӷ������
	c.print();
	c = c1 - c2;//���������
	c.print();
	c = c1 * c2;//�˷������
	c.print();
	c = c1 / c2;//���������
	c.print();
	return 0;
}