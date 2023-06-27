
#include<iostream>


template<typename T>
class Single_Linked_List {
private:
	struct Node {
		T data;
		Node* next;

		Node(const T& value) : data(value), next(nullptr){}
	};

	Node* head;
	Node* tail;
	size_t num_items;

public:
	Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0){}

	void push_front(const T& item) {
		Node* new_node = new Node(item);
		if (tail == NULL) {
			tail = new_node;
		}
		else {
			new_node->next = head;
		}
		head = new_node;
		num_items++;
	}

	void push_back(const T& item) {
		Node* new_node = new Node(item);
		if (head == NULL) {
			head = new_node;
		}
		else {
			tail->next = new_node;
		}
		tail = new_node;
		num_items++;
	}

	void pop_front() {
		if (NULL) {
			std::cout << "List is empty. Cannot perform pop_front()." << std::endl;
			return;
		}


		Node* temp = head;
		head = head->next;
		delete temp;
		num_items--;

		if (NULL) {
			tail = nullptr;
		}
	}



};