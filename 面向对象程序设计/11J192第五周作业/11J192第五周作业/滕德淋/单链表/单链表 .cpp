#include<iostream>
using namespace std;

//�����ڵ�
struct student
{
	char name[20];
	int age;
	student* next;
};

int length(student*head)
{
	int counnt = 0;
	student* p = head->next;
	while (p != 0)
	{
		counnt++;
		p = p->next;
	}
	return counnt;
}

//��������
student* creatlist(int n)
{
	student* head = new student;//ͷ�ڵ㣬��������
	student* ptr = head;//����ǰptrָ��ͷ�ڵ�
	for (int i = 0; i < n; i++)
	{
		student* p = new student;//�´���һ���ڵ�
		cout << "�������" << i + 1 << "��ͬѧ��Ϣ�� ";
		cin >> p->name >> p->age;

		ptr->next = p;//��һ���ڵ��ָ����ָ��ǰ�ڵ�
		ptr = p;//����ǰ�ڵ����һ���ڵ�
		p->next = nullptr;//����һ���ڵ��ָ����ֵΪ��ָ��
	}
	return head;
}


//��ӡ����
void display(student *head)
{
	student* p = head->next;
	while (p != NULL)
	{
		cout << "������ " << p->name << " ���䣺 " << p->age << endl;
		p = p->next;//����ڵ��ָ����ֵ������ڵ㣨��һ���ڵ����һ���ڵ㣩
	}
}


//����ڵ�
void setlist(student *head,int index)
{
	if (head == nullptr || index > length(head))
	{
		cout << "��������ȷ�Ĵ�С" << endl;
	}
	student* ptr = head;//ָ��ͷ�ڵ�
	for (int i = 0; i < index; i++)
	{
		ptr = ptr->next;
	}
	student* newnode = new student;
	cout << "�������µĽڵ���Ϣ�� " << endl;
	cin >> newnode->name >> newnode->age;
	newnode->next = ptr->next;
	ptr->next = newnode;
}


//ɾ���ڵ�
void deletenode(student *head,int index)
{
	if (head == NULL || index > length(head) - 1)
	{
		cout << "��������ȷ�Ĵ�С" << endl;
	}
	student* ptr = head;
	for (int i = 0; i < index; i++)
	{
		ptr = ptr->next;
	}
	student* p = ptr->next;//p����Ҫɾ���Ľڵ�
	ptr->next = ptr->next->next;
}


int main()
{
	int n = 5;
	student* head = creatlist(n);
	
	setlist(head, 2);
	int t;
	while (1)
	{
		if (length(head) == NULL)
		{
			cout << "�����Ѿ�Ϊ�գ�������ɾ��" << endl;
			break;
		}
		cout << "��������Ҫɾ���Ľڵ㣺 ";
		cin >> t;
		deletenode(head, t);
		display(head);
	}
	system("pause");
	return 0;
}