
/*
 �����ȷ���
 ����ҵ����
 ��Ӧ�ȸ��㷨����Ӧ�� =���ȴ�ʱ��+Ҫ�����ʱ�䣩/ Ҫ�����ʱ��
*/
#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;
const int N = 10;//10������
const int INF = 0x3f3f3f3f;

struct pcb
{
	int arrive;  //����ʱ��
	double rate;   //��Ӧ��
	string name; //����
	int cost;    //����ʱ��
	int end;    //����ʱ��
	int turn;      //��תʱ��
	double tune_weight;
	pcb* next;
};

pcb* pcb_head = new pcb;//ͷ
bool gzr;//�������
int cpu0 = 0;  //ʱ��1
int cpu1 = 0;  //ʱ��2
double sum_turn = 0;     //��תʱ��
double ave_turn_wei = 0;    //ƽ����Ȩ��תʱ��

void pre_work(){
	cpu0 = 0;
	cpu1 = 0;
	sum_turn = 0;
	ave_turn_wei = 0;
	ifstream iflie;
	iflie.open("test.txt");
	//��ʼ������ͷ
	pcb_head->next = NULL;
	pcb* t = new pcb;
	t->next = pcb_head->next;
	iflie >> t->name >> t->arrive >> t->cost;
	t->rate = 1;//��ʼ��
	pcb_head = t;

	for (int i = 0; i < 9; i++) 
	{
		pcb* temp = new pcb;
		iflie >> temp->name >> temp->arrive >> temp->cost;
		pcb* p = pcb_head;
		temp->rate = INF;
		while (p->next != NULL)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}
	iflie.close();
}


void out_put() {
	cout << "ƽ����ת��     " << sum_turn / N;
	cout << "      ƽ����Ȩ��ת�� " << ave_turn_wei / N << endl;
}


void out1(pcb* p) {
	if (gzr == 0)
		return;
	cout << p->name << setw(15) << p->end << setw(15) << p->turn << setw(15) << p->tune_weight << endl;
}


//FIFS
void fun1() {
	cout << "�����ȷ����㷨��" << endl;
	pre_work();
	if (gzr) {
		cout << "����       ����ʱ��      ��תʱ��        ��Ȩ��תʱ�� " << endl;
	}
	bool flag;
	for (int i = 0; i < N; i++) {
		pcb* p = new pcb;
		pcb* q = new pcb;
		p = pcb_head;
		flag = false;
		q->arrive = INF;
		q->next = NULL;
		//ִ��
		while (p != NULL) {
			if (p->cost != 0 && p->arrive <= q->arrive && (p->arrive <= cpu0 || p->arrive <= cpu1))
			{
				q = p;
				flag = true;
			}
			p = p->next;
		}
		if (flag == false) {
			p = pcb_head;
			while (p != NULL)
			{
				if (p->cost != 0 && p->arrive < q->arrive)q = p;
				p = p->next;
			}
		}
		if (cpu0 <= cpu1)
		{
			//q�����ȵ��Ľ���
			if (i == 0) cpu0 = q->arrive;
			if (!flag) cpu0 = q->arrive;
			cpu0 += q->cost;
			q->end = cpu0;
			q->turn = q->end - q->arrive;      
			sum_turn += q->turn;
			q->tune_weight = q->turn / (q->cost * 1.0);   
			ave_turn_wei += q->tune_weight;
			q->cost = 0;
			out1(q);
		}
		else {
			if (i == 1 || flag == false)cpu1 = q->arrive;
			cpu1 += q->cost;
			q->end = cpu1;
			q->turn = q->end - q->arrive;      
			sum_turn += q->turn;
			q->tune_weight = q->turn / (q->cost * 1.0);   
			ave_turn_wei += q->tune_weight;
			q->cost = 0;
			out1(q);
		}
	}
	out_put();
}
//����ҵ����
void fun2() {
	cout << "�̽��������㷨��" << endl;
	pre_work();
	if (gzr)cout << "����       ����ʱ��      ��תʱ��        ��Ȩ��תʱ�� " << endl;
	bool flag;
	for (int i = 0; i < N; i++) {
		pcb* p = new pcb;
		pcb* q = new pcb;
		p = pcb_head;
		flag = false;
		q->cost = INF;
		q->next = NULL;
		q->arrive = INF;
		while (p != NULL)
		{
			if (cpu0 <= cpu1 && p->arrive <= cpu0)
			{
				if (p->cost != 0 && p->cost <= q->cost)
				{
					q = p;
					flag = true;
				}
			}
			if (cpu0 > cpu1 && p->arrive <= cpu1)
			{
				if (p->cost != 0 && p->cost <= q->cost)
				{
					q = p;
					flag = true;
				}
			}
			p = p->next;
		}
		if (flag == false) {
			p = pcb_head;
			while (p != NULL)
			{
				if (p->cost != 0 && p->arrive < q->arrive)q = p;
				p = p->next;
			}
		}
		if (cpu0 <= cpu1)
		{
			if (i == 0 || !flag) cpu0 = q->arrive;
			cpu0 += q->cost;
			q->end = cpu0;
			q->turn = q->end - q->arrive;      sum_turn += q->turn;
			q->tune_weight = q->turn / (q->cost * 1.0);   ave_turn_wei += q->tune_weight;
			q->cost = 0;
			out1(q);
		}
		else {
			if (i == 1 || flag == false)cpu1 = q->arrive;
			cpu1 += q->cost;
			q->end = cpu1;
			q->turn = q->end - q->arrive;      sum_turn += q->turn;
			q->tune_weight = q->turn / (q->cost * 1.0);   ave_turn_wei += q->tune_weight;
			q->cost = 0;
			out1(q);

		}
	}
	out_put();
}
//��Ӧ�ȸ�������
void fun3() {
	pre_work();
	cout << "��Ӧ�������㷨��" << endl;
	if (gzr)cout << "����       ����ʱ��      ��תʱ��        ��Ȩ��תʱ�� " << endl;
	//�Ƿ����������Ϣ
	bool flag;
	for (int i = 0; i < N; i++) {
		pcb* p = new pcb;
		pcb* q = new pcb;
		p = pcb_head;
		flag = false;
		q->rate = -INF;
		q->next = NULL;
		q->arrive = INF;
		//ѡ�����Ǹ�CPU������Ӧ��
		if (cpu0 <= cpu1 && p->arrive <= cpu0) {
			pcb* t = pcb_head;
			while (t != NULL) {
				//����ʣ����Ӧ��
				if (t->cost != 0)t->rate = (cpu0 - t->arrive) / (t->cost * 1.0) + 1;
				t = t->next;
			}

		}
		else if (cpu0 > cpu1 && p->arrive <= cpu1)
		{
			pcb* t = pcb_head;
			while (t != NULL)
			{
				if (t->cost != 0)t->rate = (cpu1 - t->arrive) / (t->cost * 1.0) + 1;
				t = t->next;
			}
		}
		if (p->arrive <= cpu1 || p->arrive <= cpu0)
			while (p != NULL)
			{
				if (p->cost != 0 && p->rate >= q->rate) {
					q = p;
					flag = true;
				}
				p = p->next;
			}
		if (flag == false) {
			p = pcb_head;
			while (p != NULL)
			{
				if (p->cost != 0 && p->arrive < q->arrive)q = p;
				else if (p->cost != 0 && p->arrive == q->arrive) {//�������
					if (p->cost < q->cost)q = p;
				}
				p = p->next;
			}
		}
		if (cpu0 <= cpu1)
		{
			if (i == 0 || !flag) cpu0 = q->arrive;
			cpu0 += q->cost;
			q->end = cpu0;
			q->turn = q->end - q->arrive;      sum_turn += q->turn;
			q->tune_weight = q->turn / (q->cost * 1.0);   ave_turn_wei += q->tune_weight;
			q->cost = 0;
			out1(q);
		}
		else {
			if (i == 1 || flag == false)cpu1 = q->arrive;
			cpu1 += q->cost;
			q->end = cpu1;
			q->turn = q->end - q->arrive;      sum_turn += q->turn;
			q->tune_weight = q->turn / (q->cost * 1.0);   ave_turn_wei += q->tune_weight;
			q->cost = 0;
			out1(q);

		}
	}
	out_put();
}




void fun4() {
	gzr = 0;
	fun1();
	fun2();
	fun3();
}
void fun5() {
	pre_work();
	cout << "����   ����ʱ��   ����ʱ��" << endl;
	pcb* pp = new pcb;
	pp = pcb_head;

	while (pp != NULL)
	{
		cout << pp->name << setw(10) << pp->arrive << setw(10) << pp->cost << endl;
		pp = pp->next;
	}
	cout << endl;
}
int main() {
	while (1) {
		cout << "************ѡ����ҵ�����㷨************** " << endl;
		cout << "            1.FCFS�㷨               " << endl;
		cout << "            2.SJF�㷨 " << endl;
		cout << "            3.HRRN�㷨 " << endl;
		cout << "            4.�鿴�����㷨���ܱȽϱ� " << endl;
		cout << "            5.�鿴�������̵���Ϣ " << endl;
		char ch;
		cin >> ch;
		cout << endl;
		switch (ch)
		{
		case '1':
			gzr = 1; 
			fun1();
			break;
		case '2':
			gzr = 1; 
			fun2();
			break;
		case '3':
			gzr = 1; 
			fun3();
			break;
		case '4': 
			fun4();
			break;
		case '5':
			fun5();
			break;
		default:
			cout << "�������󣡣�" << endl;
			break;
		}
	}
}