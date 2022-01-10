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

class Clinklist
{
public:
	Clinklist() {
		head = new Node;
		head->data = 0;
		head->next = NULL;
		size = 0;
	};
	~Clinklist() {
		delete head;
	};
	int MyCreate(int size)//���������б�
	{
		if (n < 0) {
			printf("error\n");
			return -1;
		}
		Node* ptemp = NULL;
		Node* pnew = NULL;
		this->size = n;
		ptemp = this->head;//ָ��ͷ��
		for (int i = 0; i < n; i++)
		{
			pnew = new Node;
			pnew->next = NULL;
			cout << "�����" << i + 1 << "���ڵ�ֵ" << endl;
			cin >> pnew->data;
			ptemp->next = pnew;
			ptemp = pnew;
		}
		cout << "�����ɹ�" << endl;
		return 0;
	}
	int MyClear() {
		Node* ptemp;
		if (this->head == NULL) {
			cout << "����Ϊ��" << endl;
			return -1;
		}
		while (this->head)//��������
		{
			ptemp = head->next;
			free(head);
			head = ptemp;
		}
		cout << "���ٳɹ�" << endl;
		return 0;
	}
	int MyTraval(){//���
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
	int MyInsert(Node* data, int n){//�������
		Node* ptemp;
		if (this->head == NULL) {
			cout << "����Ϊ��" << endl;
			return -1;
		}
		if (data == NULL) {
			cout << "����ڵ�Ϊ��" << endl;
			return -1;
		}
		if (n < 2) {//ͷ��
			Node* pnew = new Node;
			pnew->data = data->data;
			pnew->next = this->head->next;
			this->head->next = pnew;
			this->size++;
			return 0;
		}
		if (n > this->size) {//β��
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
		else {//�м�
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
	int MyDelete(int n){//ɾ������
		Node* ptemp;
		Node* ptemp2;
		if (n > this->size) {
			cout << "n��ֵ����" << endl;
			return -1;
		}
		if (n < 2) {//ɾͷ�ڵ�
			ptemp = this->head->next;
			this->head->next = ptemp->next;
			free(ptemp);
			this->size--;
			return 0;
		}
		if (n == this->size) {//β��
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
		else{//�м�
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
	int GetLen(){//�õ�����
		return this->size;
	}
	bool IfEmply(){//����Ƿ�Ϊ��
		if (this->head == NULL) 
			return true;
		return false;
	}
	Node* head;//д���ڲ�
	int size;
};
void main(void)
{
	Clinklist list;
	Clinklist* plist = &list;
	plist->MyCreate(5);
	plist->MyTraval();
	Node temp;
	temp.data = 100;
	temp.next = NULL;
	plist->MyInsert(&temp, 0);
	plist->MyTraval();
	plist->MyInsert(&temp, plist->GetLen() + 1);
	plist->MyTraval();
	plist->MyInsert(&temp, 5);

	plist->MyTraval();
	plist->MyDelete(0);
	plist->MyTraval();
	plist->MyDelete(list.GetLen());
	plist->MyTraval();
	plist->MyDelete(2);
	plist->MyTraval();

	plist->MyClear();
	system("pause");
}

