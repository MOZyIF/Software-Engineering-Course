#pragma once
#include <iostream>
using namespace std;
class Point {
public:
	double x, y;
};
class LineString { //�ɶ������ɵ��ߴ��࣬�� n ������ɵ����߰��� n-1 ���߶�
public:
	LineString (Point *pnts,int num);//���캯��,ͨ�����������������
	LineString (const LineString &another); // ���ƹ��캯��
    ~LineString (); // ��������
	LineString& operator =(const LineString& rhs); // ��ֵ����
	Point& operator[](int index);//�����ߴ��е� index ���������
private:
	Point  *m_data; // ���ڱ�������ߴ��ĵ�
	int    m_num;// �ߴ��е������ 
}; 

LineString::LineString(Point* pnts, int num): m_data(pnts) {
	m_num = num;
}
LineString::LineString(const LineString& another) {
	m_data = another.m_data;
	m_num = another.m_num;
}
LineString & LineString:: operator =(const LineString& rhs) {
	return LineString(rhs.m_data,rhs.m_num);
}
Point & LineString::operator[](int index) {
	Point temp;
	LineString templ(&temp,index);
	return temp;
}