
#include<iostream>
#include<string>


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
	
	// push_front
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

	// push_back
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

	//pop_front
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

	// pop_back
	void pop_back() {
		if (NULL) {
			std::cout << "Cannot perform pop_back()." << std::endl;
			return;
		}

		if (head == tail) {
			delete head;
			head = tail = nullptr;
		}
		else {
			Node* temp = head;
			while (temp->next != tail) {
				temp = temp->next;
			}
			delete tail;
			tail = temp;
			tail->next = nullptr;
		}
		num_items--;
	}

	// front
	T front() const {
		if (NULL) {
			std::cout << "Cannot perform front()." << std::endl;
			return T();
		}
		return T();
	}

	// back
	T back() const {
		if (NULL) {
			std::cout << "Cannot perform " << std::endl;
			return T();
		}
		return tail->data;
	}

	// empty
	bool empty() const {
		return num_items == 0;
	}

	// void insert
	void insert(size_t index, const T& item) {
		if (index > num_items) {
			push_back(item);
			return;
		}

		if (index == 0) {
			push_front(item);
			return;
		}
		Node* new_node = new Node(item);
		Node* temp = head;
		for (size_t i = 1; i < index; i++) {
			temp = temp->next;
		}
		new_node->next = temp->next;
		temp->next = new_node;
		num_items++;
	}

	// bool remove
	bool remove(size_t index) {
		if (index >= num_items) {
			return false;
		}


		if (index == 0) {
			pop_front();
			return true;
		}

		Node* temp = head;
		for (size_t i = 1;i < index;i++) {
			temp = temp->next;
		}

		Node* node_to_remove = temp->next;
		temp->next = node_to_remove->next;
		delete node_to_remove;
		num_items--;
		return true;
	}

	// size_t
	size_t find(const T& item) {
		Node* temp = head;
		size_t index = 0;
		while (temp != nullptr) {
			if (temp->data == item) {
				return index;
			}
			temp = temp->next;
			index++;
		}
		return num_items;
	}
	void display() {
		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
};

// Employee
class Employee {
protected:
	std::string name;
public:
	Employee(const std::string& name) : name(name) {}

	virtual double calculateWeeklySalary() const = 0;
	virtual double computeHealthCareContributions() const = 0;
	virtual int computeVacationDays() const = 0;
};

// Professional 
class Professional : public Employee {
private:
	double monthlySalary;
	int vacationDays;
public:
	Professional(const std::string& name, double monthlySalary, int vacationDays)
		:Employee(name), monthlySalary(monthlySalary), vacationDays(vacationDays) {}

	double calculateWeeklySalary() const override {
		return monthlySalary / 4;
	}

	double computeHealthCareContributions() const override {
		return monthlySalary * 0.1;
	}

	int computeVacationDays() const override {
		return vacationDays;
	}
};
// Nonprofessional
class Nonprofessional : public Employee {
private:
	double hourlyRate;
	int workedHours;
public:
	Nonprofessional(const std::string& name, double hourlyRate,int workedHours)
		: Employee(name), hourlyRate(hourlyRate), workedHours(workedHours){}

	double calculateWeeklySalary() const override {
		return hourlyRate * workedHours;
	}

	double computeHealthCareContributions() const override {
		return hourlyRate * workedHours * 0.05;
	}

	int computeVacationDays() const override {
		return workedHours / 8;
	}
};

int main() {
	Single_Linked_List<int> list;

	// push_front
	list.push_front(10);
	list.push_front(20);
	list.push_front(30);
	list.display(); // Output: 30 20 10

	// push_back
	list.push_back(40);
	list.push_back(50);
	list.display(); // Output: 30 20 10 40 50

	// pop_front
	list.pop_front();
	list.display(); // Output: 20 10 40 50

	// pop_back
	list.pop_back();
	list.display(); // Output: 20 10 40

	// front and back
	std::cout << "Front: " << list.front() << std::endl; // Output: Front: 20
	std::cout << "Back: " << list.back() << std::endl;   // Output: Back: 40

	// empty
	std::cout << "Is empty? " << (list.empty() ? "Yes" : "No") << std::endl; // Output: Is empty? No

	// insert
	list.insert(1, 25);
	list.display(); // Output: 20 25 10 40

	// remove
	list.remove(2);
	list.display(); // Output: 20 25 40

/*	// find
	size_t index = list.find(25);
	if (index != list.size()) {
		std::cout << "Found at index: " << index << std::endl; // Output: Found at index: 1
	}
	else {
		std::cout << "Item not found" << std::endl;
	}
	*/

	// instances of professional and nonprofessional employees
	Professional professionalEmployee("John Doe", 5000, 15);
	Nonprofessional nonprofessionalEmployee("Jane Smith", 20, 40);

	// Testing methods
	std::cout << "Professional Employee:" << std::endl;
	std::cout << "Professional Employee:" << std::endl;
	std::cout << "Weekly Salary: " << professionalEmployee.calculateWeeklySalary() << std::endl;
	std::cout << "Health Care Contributions: " << professionalEmployee.computeHealthCareContributions() << std::endl;
	std::cout << "Vacation Days: " << professionalEmployee.computeVacationDays() << std::endl;

	std::cout << "\nNonprofessional Employee:" << std::endl;
	std::cout << "Weekly Salary: " << nonprofessionalEmployee.calculateWeeklySalary() << std::endl;
	std::cout << "Health Care Contributions: " << nonprofessionalEmployee.computeHealthCareContributions() << std::endl;
	std::cout << "Vacation Days: " << nonprofessionalEmployee.computeVacationDays() << std::endl;

	return 0;
}