#include<iostream>
using namespace std;
typedef int DataType;
#define Node ElemType
#define ERROR NULL
class Node{
public:
	int data;     //������
	Node* next;  //ָ����
};
class LinkList{//��������
public:
	LinkList();					  //��ʼ��һ��������;���캯��
	~LinkList();                  //����һ��������;��������
	void CreateLinkList(int n);   //����һ��������
	void CoutLinkList();        //�������Ա�������ӡ����
	int GetLength();              //��ȡ���Ա���
	ElemType* Find(DataType data); //���ҽڵ�
	void InsertElemAtEnd(DataType data);            //��β������ָ����Ԫ��
	void InsertElemAtIndex(DataType data, int n);    //��ָ��λ�ò���ָ��Ԫ��
	void DeleteAll();             //ɾ����������
private:
	ElemType* head;              //ͷ���
};
//��ʼ��������
LinkList::LinkList(){
	head = new ElemType;
	head->data = 0;               //��ͷ������������Ϊ0
	head->next = NULL;            //ͷ������һ������ΪNULL
}
//���ٵ�����
LinkList::~LinkList(){
	delete head;                 //ɾ��ͷ���
}
//����һ��������
void LinkList::CreateLinkList(int n){
	ElemType* pnew, * ptemp;
	ptemp = head;
	if (n < 0) {       //�������ֵ����ʱ
		cout << "����Ľڵ��������" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++) {        //��ֵһ��һ�����뵥������
		pnew = new ElemType;
		cout << "�������" << i + 1 << "��ֵ: ";
		cin >> pnew->data;
		pnew->next = NULL;          
		ptemp->next = pnew;         
		ptemp = pnew;               
	}
}
//����������
void LinkList::CoutLinkList(){
	if (head == NULL || head->next == NULL) {
		cout << "����Ϊ�ձ�" << endl;
	}
	ElemType* p = head;                 //��ָ��ָ��ͷ���
	while (p->next != NULL){        //��ָ�����һ����ַ��Ϊ��ʱ��ѭ�����p��������
		p = p->next;               //pָ��p����һ����ַ
		cout << p->data << " ";
	}
}
//��ȡ������ĳ���
int LinkList::GetLength(){
	int count = 0;                  //����count����
	ElemType* p = head->next;           //����pָ��ͷ���
	while (p != NULL) {               //��ָ�����һ����ַ��Ϊ��ʱ��count+1
		count++;
		p = p->next;                //pָ��p����һ����ַ
	}
	return count;                   //����count������
}
//���ҽڵ�
ElemType* LinkList::Find(DataType data){
	ElemType* p = head;
	if (p == NULL) {                           //��Ϊ�ձ�ʱ�����쳣
		cout << "������Ϊ������" << endl;
		return ERROR;
	}
	else
	{
		while (p->next != NULL) {              //ѭ��ÿһ���ڵ�
			if (p->data == data) {
				return p;                     //����ָ����
			}
			p = p->next;
		}
		if (p->data == data){
			return p;
		}
		return NULL;                           //δ��ѯ�����
	}
}
//��β������ָ����Ԫ��
void LinkList::InsertElemAtEnd(DataType data){
	ElemType* newNode = new ElemType;    //����һ��Node���ָ��newNode
	newNode->next = NULL;         //����newNode���������ָ����
	newNode->data = data;
	ElemType* p = head;              //����ָ��pָ��ͷ���
	if (head == NULL) {           //��ͷ���Ϊ��ʱ������newNodeΪͷ���
		head = newNode;
	}
	else                          //ѭ��֪�����һ���ڵ㣬��newNode���������
	{
		while (p->next != NULL){
			p = p->next;
		}
		p->next = newNode;
	}
}
//��ָ��λ�ò���ָ��Ԫ��
void LinkList::InsertElemAtIndex(DataType data, int n){
	if (n<1 || n>GetLength())                   //���������쳣
		cout << "�����ֵ����" << endl;
	else
	{
		ElemType* ptemp = new ElemType;        //����һ���µĽڵ�
		ptemp->data = data;                     //����������
		ElemType* p = head;                    //����һ��ָ��ָ��ͷ���
		int i = 1;
		while (n > i){                           //������ָ����λ��
			p = p->next;
			i++;
		}
		ptemp->next = p->next;                 //���½ڵ���뵽ָ��λ��
		p->next = ptemp;
	}
}
//ɾ����������
void LinkList::DeleteAll(){
	ElemType* p = head->next;
	ElemType* ptemp = new ElemType;
	while (p != NULL){                    //��ͷ������һ���ڵ����ɾ���ڵ�
		ptemp = p;
		p = p->next;
		head->next = p;
		ptemp->next = NULL;
		delete ptemp;
	}
	head->next = NULL;                
}
//���Ժ���
int main(){
	LinkList l;
	int i;
	cout << "1.����������\n";
	cout << "2.����������\n";
	cout << "3.��ȡ������ĳ���\n";
	cout << "4.��ȡ�ڵ�\n";
	cout << "5.��β������ָ��Ԫ��\n";
	cout << "6.��ָ��λ�ò���ָ��Ԫ��\n";
	cout << "7.ɾ������Ԫ��" << endl;
	cout << "0.�˳�" << endl;
	do{
		cout << "����������Ҫ�ù���: ";
		cin >> i;
		switch (i)
		{
		case 1:
			int n;
			cout << "�����뵥����ĳ���: ";
			cin >> n;
			l.CreateLinkList(n);
			break;
		case 2://��ӡ����
			l.CoutLinkList();
			break;
		case 3:
			cout << "�õ�����ĳ���Ϊ" << l.GetLength() << endl;
			break;
		case 4:
			DataType data;
			cout << "������Ҫ��ȡ�ڵ��ֵ: ";
			cin >> data;
			cout << "�ýڵ��ֵΪ" << l.Find(data)->data << endl;
			break;
		case 5:
			DataType endData;
			cout << "������Ҫ��β�������ֵ: ";
			cin >> endData;
			l.InsertElemAtEnd(endData);
			break;
		case 6:
			DataType pointData;
			int index;
			cout << "������Ҫ���������: ";
			cin >> pointData;
			cout << "������Ҫ�������ݵ�λ��: ";
			cin >> index;
			l.InsertElemAtIndex(pointData, index);
			break;
		case 7:
			l.DeleteAll();
			break;
		default:
			break;
		}
	} while (i != 0);
	system("pause");
	return 0;
}