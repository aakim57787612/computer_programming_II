#include <iostream>
#include <list>
using namespace std;

class ListNode {
	friend class LinkedList;
public:
	int data;
	ListNode* next;
	ListNode() :data(), next() {};
	ListNode(int a) :data(a), next() {};
};
class LL {
	friend ostream &operator<<(ostream &, const LL&);
	friend istream &operator>>(istream&, LL&);
private:
	ListNode* first;
public:
	LL Crop(int a, int b) {
		ListNode* current = first, *gg = 0;
		LL abc;
		for (int i = 1; i < a; i++) {
			gg = current->next;
			current = current->next;
		}
		current = current->next;
		for (int i = 1; i <= b; i++) {
			abc.Insert(current->data);
			current = current->next;
		}
		gg->next = current;
		return abc;
	}
	void operator+=(int a)
	{
		Insert(a);
	}
	void Insert(LL a)
	{
		ListNode* current = first;
		if (first == 0) {
			first = a.first;
			return;
		}
		while (current->next != 0) {
			current = current->next;
		}
		current->next = a.first;
	}
	void operator+=(LL a)
	{
		ListNode* current = first;
		while (current->next != 0) {
			current = current->next;
		}
		current->next = a.first;
	}
	//testLL2[1] = 1;
	LL &operator=(int a) {
		*this = a;
	}
	int &operator[](int sub) {
		ListNode* current = first;
		for (int i = 1; i <= sub; i++) {
			current = current->next;
		}
		return current->data;
	}
	LL() :first() {};
	LL(int a) :first() {};
	void ver() {
		LL newnode;
		while (first->next != 0) {
			newnode.Insert(first->data);
			first = first->next;
		}
		newnode.Insert(first->data);
		first = first->next;
		*this = newnode;
	}
	void Insert(int x) {
		ListNode *newNode = new ListNode(x);
		if (first == 0) {                      // 若list沒有node, 令newNode為first
			first = newNode;
			return;
		}
		ListNode *current = first;
		while (current->next != 0) {           // Traversal
			current = current->next;
		}
		current->next = newNode;
	}
	void Insert(int x, int y) {//x插入的位置 y插入的值
		LL newnode;
		while (x >= 0) {
			newnode.Insert(first->data);
			first = first->next;
			x--;
		}
		newnode.Insert(y);
		while (first != 0) {
			newnode.Insert(first->data);
			first = first->next;
		}
		*this = newnode;
	}
	void Insert(int x, int y, int z) {//x插入的位置 y為長度 z插入的值
		LL newnode;
		if (first == 0) {
			for (int i = 1; i <= y; i++)
				newnode.Insert(z);
			first = newnode.first;
			return;
		}
		while (x >= 0) {
			newnode.Insert(first->data);
			first = first->next;
			x--;
		}
		while (y > 0) {
			newnode.Insert(z);
			y--;
		}
		while (first != 0) {
			newnode.Insert(first->data);
			first = first->next;
		}
		*this = newnode;
	}
	void Delete(int x, int y) {//x插入的位置 y為長度
		LL newnode;
		while (x >= 1) {
			newnode.Insert(first->data);
			first = first->next;
			x--;
		}
		while (y > 0) {
			first = first->next;
			if (first == 0)
				break;
			y--;
		}
		while (first != 0) {
			newnode.Insert(first->data);
			first = first->next;
		}
		*this = newnode;
	}
	int Head() {
		int a = first->data;
		headPtr = first;
		return a;
	}
	int Tail() {
		ListNode* current = first;
		while (current->next != 0) {
			current = current->next;
		}
		int a = current->data;
		tailPtr = current;
		return a;
	}
	int getLength() {
		ListNode* current = first;
		int i = 0;
		while (current->next != 0) {
			current = current->next;
			i++;
		}
		i++;
		return i;
	}
	void Sort() {
		ListNode* current = first;
		int i = getLength();
		for (int j = 1; j < i; j++) {
			for (int k = 1; k < i; k++) {
				if (current->data < current->next->data) {
					swap(k);
					current = current->next;
				}
				else current = current->next;
			}
			current = first;
		}
	}
	void swap(int k) {
		ListNode* current = first;
		LL abc;
		for (int i = 1; i < k; i++) {
			abc.Insert(current->data);
			current = current->next;
		}
		int a = current->data, b = current->next->data;
		abc.Insert(b);
		abc.Insert(a);
		current = current->next;
		while (current->next != 0) {
			current = current->next;
			abc.Insert(current->data);
		}
		first = abc.first;
	}
	ListNode* headPtr;
	ListNode* tailPtr;
};

ostream& operator<<(ostream& output, const LL& abc) {
	if (abc.first == 0) {                      // 如果first node指向NULL, 表示list沒有資料
		output << "List is empty.\n";
		return output;
	}
	ListNode *current = abc.first;            // 用pointer *current在list中移動
	while (current != 0) {                 // Traversal
		output << current->data;
		if (current->next != 0)
			output << ", ";
		current = current->next;
	}
	output << endl;
	return output;
}

int main()
{
	std::cout << "Hello World!\n";
	LL testLL;
	testLL.Insert(2); // add new value in the end of list
	testLL.Insert(3);
	testLL.Insert(1);
	testLL.Insert(7);
	testLL.Insert(9);
	cout << "LL1 = " << testLL << endl; // LL1 = 2, 3, 1, 7, 9
	cout << "Head:" << testLL.Head() << endl;
	cout << "Tail:" << testLL.Tail() << endl << endl;
	cout << "Length:" << testLL.getLength() << endl << endl;

	cout << "insert(2, 5)" << endl;
	testLL.Insert(2, 5); // (pos, value)
	cout << testLL << endl << endl;

	cout << "insert(3, 2, -1)" << endl;
	testLL.Insert(3, 2, -1); // (pos, lenght, value)
	cout << testLL << endl << endl;

	cout << "delete(1, 2)" << endl;
	testLL.Delete(1, 2); // (pos, lenght)
	cout << testLL << endl << endl;

	cout << "delete(2, 2)" << endl;
	testLL.Delete(2, 2); // (pos, lenght)
	cout << testLL << endl << endl;

	cout << "sort" << endl;//大到小
	testLL.Sort(); // apply bubble sort
	cout << testLL << endl << endl;

	cout << "insert(3)" << endl;
	testLL.Insert(3); // add a new int(3) at the end of LL
	cout << testLL << endl << endl;

	cout << "+= 1" << endl;
	int scalar = 1;
	testLL += scalar; // add a new node(1) at the end of LL
	cout << testLL << endl << endl;

	cout << "[3] = " << testLL[3] << endl << endl;

	{
		LL testLL2;
		testLL2.Insert(0, 3, 4); // add 3 new int(4) in a empty LL
		testLL2[1] = 1;
		testLL2[2] = 3;
		cout << "LL2 = " << testLL2 << endl << endl;

		cout << "LL1 += LL2" << endl;
		testLL += testLL2; // concate 2 list
		cout << "LL1 = " << testLL << endl;
		cout << "LL2 = " << testLL2 << endl;
	} // testLL1 become out of scope (destructed)

	cout << "sort" << endl;
	testLL.Sort(); // apply bubble sort again
	cout << testLL << endl << endl;
	{
		LL testLL3;
		testLL3.Insert(testLL.Crop(2, 4));
		cout << "LL3.insert ( LL1.crop(2,4) )\n";
		cout << "LL1 = " << testLL << endl;
		cout << "LL3 = " << testLL3 << endl << endl;

		cout << "LL3.Delete(2, 3)" << endl;
		testLL3.Delete(2, 3); // (pos, lenght, value)
		cout << "LL3 = " << testLL3 << endl << endl;
	}
	cout << "LL1 = " << testLL << endl;
}