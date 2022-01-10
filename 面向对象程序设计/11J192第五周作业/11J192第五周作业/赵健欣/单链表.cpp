#include <iostream>
using namespace std;
template<typename T>
class Node {
	T m_data; //������
	Node* m_next = nullptr; //ָ����һ������ָ��
public:
	Node(const T& val) :m_data(val) { }
	const T& data() const { return m_data; }
	T& data() { return m_data; }
	Node* next() { return m_next; }
};
template<typename T>
class SList {
	Node<T>* m_head = nullptr, * m_tail = nullptr;
public:
	SList() = default; // ʹ��Ĭ�Ϲ��캯��
	~SList();
	void clear();
	void push_back(const T& val);
	Node<T>* insert(Node<T>* pos, const T& val);
	void erase(const T& val) {
		Node<T>* p = m_head, * q = p;
		while (p != nullptr && p->m_data != val) {
			q = p; // ָ��qָ��p
			p = p->m_next; // ָ��p����
		}
		if (p) q->m_next = p->m_next;
		if (p == m_tail) m_tail = q;
		if (p == m_head) m_head = nullptr;
		delete p;
	};
	Node<T>* find(const T& val);
};
template<typename T>
SList<T>::~SList() {
	clear();
}
template<typename T>
void SList<T>::push_back(const T& val) {
	Node<T>* node = new Node<T>(val);
	//�����½��
	if (m_head == nullptr)
		m_head = m_tail = node;
	else {
		m_tail->m_next = node;
		m_tail = node;
	}
}
template<typename T>
Node<T>* SList<T>::insert(Node<T>* pos, const
	T& val) {
	Node<T>* node = new Node<T>(val);
	// �����½��
	node->m_next = pos->m_next;
	pos->m_next = node;
	if (pos == m_tail) // �ж�pos�Ƿ�Ϊβ���
		m_tail = node;
	return node;
}
template<typename T>
void SList<T>::clear() {
	Node<T>* p = nullptr;
	while (m_head != nullptr) {
		p = m_head; //p ָ��ǰ��ͷ���
		m_head = m_head->m_next; //��ͷ������
		delete p; //�ͷ� p ��ָ����ڴ�
	}
	m_tail = nullptr; //��βָ�� tail �ÿ�
}
template<typename T>
ostream& operator<<(ostream&, const SList<T>&);

template<typename T>
class SList {
	friend ostream& operator<< <T>(ostream&, const SList<T>&);
	//������Ա���屣�ֲ���
};
template<typename T>
ostream& operator<<(ostream& os, const SList<T>& list) {
	Node<T>* p = list.m_head;
	while (p != nullptr) {
		os << p->data() << " ";
		p = p->next();
	}
	return os;
}
int main() {
	SList<int> l;
	int val;
	while (cin >> val) { // ����10 20 30��������
		l.push_back(val);
	}
	cout << l << endl;
	Node<int>* pos = l.find(20);
	l.insert(pos, 25);
	cout << l << endl;
	l.erase(25);
	cout << l << endl;
}