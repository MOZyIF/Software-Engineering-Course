#include <iostream>
#include<cstddef>
#include<cstring>
using namespace std;
class Cstring{
public:
    Cstring(const char* str = NULL);// ��ͨ���캯��  
    Cstring(const Cstring& str);// �������캯��  
    ~Cstring(void);// ��������  
    Cstring& operator = (const Cstring& str);// ��ֵ����  
    Cstring operator +(const Cstring& str)const;//����+
    Cstring& operator+=(const Cstring& str);//����ַ�����
    Cstring(Cstring&& str)noexcept;//�ƶ����캯��
    int size()const {
        return length;
    };//��ȡ����
    const char* c_str()const {
        return data;
    };//��ȡ�ַ�
    friend istream& operator>>(istream& is,const Cstring& str);//����
    friend ostream& operator<<(ostream& os,const Cstring& str);//���
private:
    char* data;// ���ڱ����ַ���  
    size_t length;//����
};
Cstring::Cstring(const char* str) {//��ͨ���캯��
    if (!str) {
        length = 0;
        data = new char[1];
        *data = '\0';
    }
    else {
        length = strlen(str);
        data = new char[length + 1];
        strcpy_s(data,strlen(str)+1, str);
    }
}
Cstring::Cstring(const Cstring& str){//�������캯��
    length = str.size();
    data = new char[length + 1];
    strcpy_s(data, strlen(str.c_str())+1,str.c_str());
}
Cstring::~Cstring()//��������
{
    delete[]data;
    length = 0;
}
Cstring Cstring::operator+(const Cstring& str) const{//����+
    Cstring newCstring;
    newCstring.length = length + str.size();
    newCstring.data = new char[newCstring.length + 1];
    strcpy_s(newCstring.data,strlen(data)+1, data);
    strcat_s(newCstring.data,newCstring.length+1,str.data);
    return newCstring;
}
Cstring& Cstring::operator=(const Cstring& str){//����=
    if (this == &str) {
        return *this;
    }
    delete[]data;
    length = str.length;
    data = new char[length + 1];
    strcpy_s(data, strlen(str.c_str())+1,str.c_str());
    return *this;
}
Cstring& Cstring::operator+=(const Cstring& str){//����+=
    length += str.length;
    char* newData = new char[length + 1];
    strcpy_s(newData,strlen(data)+1, data);
    strcat_s(newData, length+1,str.data);
    delete[]data;
    data = newData;
    return *this;
}
Cstring::Cstring(Cstring&& str)noexcept :length(str.length),data(str.data) {//�ƶ����캯��
    str.data = NULL;
    str.length = 0;
} 
istream& operator>>(istream& is,const Cstring& str) {
    for (int i = 0; i < str.length; i++)
        is >> str.data[i];
    return is;
}
ostream& operator<<(ostream& os,const Cstring& str) {
    for (int i = 0; i < str.length; i++)
        os << str.data[i];
    return os;
}
int main() {
    Cstring a;
    cin >> a;
    cout << a << endl;
    char a1[] = "China", a2[] = "NO.1";
    Cstring a3(a1), a4(a2);
    Cstring a5 = a3 + a4;
    cout << a5<<endl;
    cout << a3 << "+" << a4 << "=" << a3 + a4 << "���߱���Ϊ" << a3 << '\0' << a4<<endl;
    a4 += a3;
    cout << a4 << endl;
    return 0;
}


