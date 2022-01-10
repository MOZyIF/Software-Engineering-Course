#pragma once

//ǰ������
template<typename T>class SList;
//�����ģ��
template<typename T>
class Node
{
	friend class SList<T>;   //��SList����ΪNode����Ԫ
	T m_data;  //������
	Node* m_next = nullptr;  //ָ����һ���ڵ��ָ��
public:
	Node(const Node& rhs) = delete;
	Node& operator=(const Node& rhs) = delete;
	Node(const T&val):m_data(val){}
	const T& data()const { return m_data; }  //const�汾
	T& ddata() { return m_data; }  //��const�汾
	Node* next() { return m_next; }
};

//ǰ������
template<typename T>ostream& operator<<(ostream&, const SList<T>&);
//��������ģ��
template<typename T>
class SList
{
	friend ostream& operator<<<T>(ostream&, const SList<T>&);
	Node<T>* m_head = nullptr, * m_tail = nullptr;
public:
	SList(const SList&) = delete;
	SList& operator=(const SList&) = delete;
	SList() = default;  //ʹ��Ĭ�Ϲ��캯��
	~SList();
	void clear();     //�������
	void push_back(const T& val);  //β������һ�����
	Node<T>* insert(Node<T>* pos, const T& val);   //��λ��pos�����һ���½��
	void erase(const T& val);
	Node<T>* find(const T& val);
};