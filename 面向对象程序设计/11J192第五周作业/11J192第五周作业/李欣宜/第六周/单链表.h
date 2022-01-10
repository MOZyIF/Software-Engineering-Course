#pragma once
using namespace std;

template<typename T>//���
class Node {
	T m_data;
	Node* m_next = nullptr;
public:
	Node(const T&val):m_data(val){}
	const T& data()const { return m_data; }
	T& data() { return m_data; }
	Node* next() { return m_next; }
};
template<typename T>ostream& operator<<(ostream&, const SList <T>&);
template<typename T>//������
class SList {
	friend ostream& operator<<<T>(ostream&, const SList<T>&);
	Node<T>* m_head = nullptr, * m_tail = nullptr;
public:
	SList()= default;//Ĭ�Ϲ��캯��
	~SList();
	void clear();//��յ�����
	void push_back(const T &val);//β��
	Node<T>* insert(Node<T>* pos, const T& val);//��λ��pos�����һ����
	void erase(const T& val);//ɾ����һ��ֵΪVal��Ԫ��
	Node<T>* find(const T& val);//���ص�һ��ֵΪval��Ԫ�صĵ�ַ
};
template<typename T>
ostream& operator<<(ostream& os, const SList<T>& list) {
	Node<T>* p = list.m_head;
	while (p != nullptr) {
		os << p->data() << "";
		p = p->next();
	}
	return os;
}
template<typename T>//��������
SList<T>::~SList() {
	clear();
}
template<typename T>//β��
void SList<T>::push_back(const T& val) {
	Node<T>* node = new Node<T>(val);
	if (m_head == nullptr)
		m_head = m_tail = node;
	else {
		m_tail->m_next = node; m_tail = node;
	}
}
template<typename T>//ָ��λ�ò���
Node<T>* SList<T>::insert(Node<T>* pos, const T& val) {
	Node<T>* node = new Node<T>(val);
	node->m_next = pos->m_next;
	pos->m_next = node;
	if (pos == m_tail)
		m_tail = node;
	return node;
}
template<typename T>//ɾ������
void SList<T>::erase(const T& val) {
	Node<T>* p = m_head, * q = p;
	while (p != nullptr && p->m_data != val) {
		q = p;
		p = p->m_next;
	}
	if (p)
		q->m_next = p->m_next;
	if (p == m_tail)
		m_tail = q;
	if (p == m_head)
		m_head = nullptr;
	delete p;
}
template<typename T>//�������
void SList<T>::clear() {
	Node<T>* p = nullptr;
	while (m_head != nullptr) {
		p = m_head;
		m_head = m_head->m_next;
		delete p;
	}
	m_tail = nullptr;
}


void test() {//���Ժ���
	SList<int>L;
	int val;
	while (cin >> val) {//����β�庯��
		L.push_back(val);
	}
	cout << L;//�������
	val = 2;
	Node<int>* pos = L.find(val);//���Բ��Һ���
	val = 5;
	L.insert(pos, val);//���Բ��뺯��
	cout << L;//�������
	L.erase(val);//����ɾ������
	cout << L;//�������
}