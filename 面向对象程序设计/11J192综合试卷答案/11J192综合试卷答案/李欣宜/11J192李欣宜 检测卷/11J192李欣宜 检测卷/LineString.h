#pragma once
#include<iostream>
using namespace std;

class Point { 
public: 
    double x, y; 
};
class LineString { //�ɶ������ɵ��ߴ��࣬�� n ������ɵ����߰��� n-1 ���߶�
public:
    LineString (Point *pnts,int num); //���캯��,ͨ����������������� 
    LineString (const LineString &another); // ���ƹ��캯�� 
    ~LineString (); // ��������
    LineString & operator =(const LineString &rhs); // ��ֵ����
    Point& operator[](int index);//�����ߴ��е� index ���������
private:
    Point  *m_data; // ���ڱ�������ߴ��ĵ�
    int    m_num;// �ߴ��е������
};   
LineString::LineString(Point* pnts, int num) :m_data(pnts), m_num(num) {};
LineString::LineString(const LineString& another) :m_data(another.m_data), m_num(another.m_num) {};
LineString::~LineString() {};
LineString& LineString:: operator =(const LineString& rhs) {
    LineString a;
    a.m_data = rhs.m_data;
    a.m_num=rhs.m_num;
    return a;
}
Point& LineString::operator[](int index) {
    if (LineString.m_num = index) {
        Point a;
        a.x = LineString.m_data;
        a.y = LineString.m_data;
        return a;
    }
}
