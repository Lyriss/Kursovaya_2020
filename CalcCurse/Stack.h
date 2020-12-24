#pragma once
template<typename T>
class Stack
{
public:
	class Node
	{
	public:
		Node(T data = T(), Node* next = NULL) {
			this->data = data;
			this->next = next;
		}
		T data;
		Node* next;
	};
	Stack(Node* head = NULL, int Counter = 0) {
		this->head = head;
		this->Counter = Counter;
	}
	~Stack() {
		while (head != NULL) {
			Node* cur = head->next;
			delete head;
			head = cur;
		}
	}
	void push(T current) {// добавление в стек
		if (head != NULL) {
			Node* cur = new Node(current);
			cur->next = head;
			head = cur;
		}
		else {
			head = new Node(current);
		}
		this->Counter++;
	}
	T pop() { // удаление из стека. Возвращает удаленный элемент
		if (head != NULL) {
			Node* current = head;
			T cur = head->data;
			head = head->next;
			delete current;
			this->Counter--;
			return cur;
		}
		else throw std::out_of_range("out_of_range");
	}
	T peek() { // возвращает элемент с верхушки стека
		return head->data;
	}
	int get_size() { // возвращает количество элементов в стеке
		return Counter;
	}
	bool isEmpty() {
		if (this->Counter == 0)
			return true;
		else 
			return false;
	}
private:
	Node* head;
	int Counter;
};