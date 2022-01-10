#include <string>
#include <iostream>
using namespace std;


typedef int DataType;

class Node
{
public:
	DataType data;
	Node* next;
};

class LinkList
{
public:
	LinkList();//���캯��
	~LinkList();//��������
	int MYCreateLinkList(int size);//���쵥������
	int MYCLEAR();
	int MYTravalLinkList();
	int MYInsertLinklList(Node* data, int n);//����
	int MYDeleteLinklist(int n);//ɾ��

	int GetLen();
	bool IsEmply();

	Node* head;//д���ڲ�
	int size;
};

LinkList::LinkList()//���캯��
{
	head = new Node;
	head->data = 0;
	head->next = NULL;
	size = 0;
}

LinkList::~LinkList()//��������
{
	delete head;
}

int LinkList::MYCreateLinkList(int n)//����һ�������б�
{
	if (n < 0) {
		printf("error\n");
		return -1;
	}
	Node* ptemp = NULL;
	Node* pnew = NULL;

	this->size = n;
	ptemp = this->head;//ָ������ͷ��
	for (int i = 0; i < n; i++)//��֤ÿһ�������е�Nodeָ����һ���ڵ�
	{
		pnew = new Node;
		pnew->next = NULL;
		cout << "�����" << i + 1 << "���ڵ�ֵ" << endl;
		cin >> pnew->data;
		ptemp->next = pnew;
		ptemp = pnew;
	}
	cout << "�������" << endl;
	return 0;
}

int LinkList::MYCLEAR()
{
	Node* ptemp;
	if (this->head == NULL) {
		cout << "����ԭ����Ϊ��" << endl;
		return -1;
	}
	while (this->head)//��ʼ��������
	{
		ptemp = head->next;
		free(head);
		head = ptemp;
	}
	cout << "�����������" << endl;
	return 0;
}

int LinkList::MYTravalLinkList()//�����������
{
	Node* ptemp = this->head->next;
	if (this->head == NULL) {
		cout << "����Ϊ��" << endl;
		return -1;
	}
	while (ptemp)
	{
		cout << ptemp->data << "->";
		ptemp = ptemp->next;
	}
	cout << "NULL" << endl;
	return 0;
}

int LinkList::MYInsertLinklList(Node* data, int n)//�������
{
	Node* ptemp;
	if (this->head == NULL) {
		cout << "����Ϊ��" << endl;
		return -1;
	}
	if (data == NULL) {
		cout << "����ڵ�Ϊ��" << endl;
		return -1;
	}
	//ͷ��
	if (n < 2) {
		Node* pnew = new Node;
		pnew->data = data->data;
		pnew->next = this->head->next;
		this->head->next = pnew;
		this->size++;
		return 0;
	}
	//β��
	if (n > this->size) {
		ptemp = this->head;
		while (ptemp->next != NULL) {
			ptemp = ptemp->next;
		}
		Node* pnew = new Node;
		pnew->data = data->data;
		pnew->next = NULL;
		ptemp->next = pnew;
		this->size++;
		return 0;
	}
	//�м��
	else {
		ptemp = this->head;
		for (int i = 1; i < n; i++) {
			ptemp = ptemp->next;
		}
		Node* pnew = new Node;
		pnew->data = data->data;
		pnew->next = ptemp->next;
		ptemp->next = pnew;
		this->size++;
		return 0;
	}
}

int LinkList::MYDeleteLinklist(int n)//ɾ������
{
	Node* ptemp;
	Node* ptemp2;
	if (n > this->size) {
		cout << "n̫��" << endl;
		return -1;
	}
	//ɾͷ�ڵ�
	if (n < 2) {
		ptemp = this->head->next;
		this->head->next = ptemp->next;
		free(ptemp);
		this->size--;
		return 0;
	}
	//β��ɾ��
	if (n == this->size) {
		ptemp = this->head;
		for (int i = 1; i < this->size; i++) {
			ptemp = ptemp->next;
		}
		ptemp2 = ptemp->next;
		ptemp->next = NULL;
		free(ptemp2);
		this->size--;
		return 0;
	}
	//�м�ɾ��
	else
	{
		ptemp = this->head;
		for (int i = 1; i < n; i++) {
			ptemp = ptemp->next;
		}
		ptemp2 = ptemp->next;
		ptemp->next = ptemp2->next;
		free(ptemp2);
		this->size--;
		return 0;
	}
}

int LinkList::GetLen()//�õ����峤��
{
	return this->size;
}

bool LinkList::IsEmply()//����Ƿ�Ϊ��
{
	if (this->head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void main(void)
{
	LinkList list;
	LinkList* plist = &list;
	plist->MYCreateLinkList(5);
	plist->MYTravalLinkList();
	Node temp;
	temp.data = 100;
	temp.next = NULL;
	plist->MYInsertLinklList(&temp, 0);
	plist->MYTravalLinkList();
	plist->MYInsertLinklList(&temp, plist->GetLen() + 1);
	plist->MYTravalLinkList();
	plist->MYInsertLinklList(&temp, 5);

	plist->MYTravalLinkList();
	plist->MYDeleteLinklist(0);
	plist->MYTravalLinkList();
	plist->MYDeleteLinklist(list.GetLen());
	plist->MYTravalLinkList();
	plist->MYDeleteLinklist(2);
	plist->MYTravalLinkList();


	plist->MYCLEAR();
	system("pause");
}

