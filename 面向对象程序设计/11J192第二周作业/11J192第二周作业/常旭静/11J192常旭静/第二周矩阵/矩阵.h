#pragma once
//����һ��֧�־����������(matrix.h)
class matrix {
public:
    matrix();//Ĭ�Ϲ��캯����
	matrix(int);//�Զ��幹�캯����n��ʾ�ļ���Ӧ��ѡ��
	void print();//�����ǰ������A�е�Ԫ��
	matrix operator*(const matrix& a)const;//�˷���������أ����ھ���ļ���
private:
	int A[4][4];//��Ա����Ϊ2ά���飬����ʢ�ž����ֵ
};
