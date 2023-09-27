#include <iostream>
#include <list>
#include<vector>
using namespace std;

class ListNode {
	friend class LinkedList;
public:
	int data;
	int id;
	ListNode* next;
	ListNode* next1=0;
	bool gg = false;
	ListNode() :data(), id(), next() {};
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
	void Insert1(int x) {
		ListNode *newNode = new ListNode(x);
		newNode->gg = true;
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
	int pop() {
		LL current; 
		current.first = first;
		while (current.first->next != 0)
			current.first = current.first->next;
		Delete(getLength() - 1, 1);
		return current.first->data;
	}
	void Insert(int x) {//等於void push(int)
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
		ListNode *abc = this->first;
		while (x >= 1) {
			if(abc->gg==true)
				newnode.Insert1(first->data);
			else
				newnode.Insert(first->data);
			abc = abc->next;
			first = first->next;
			x--;
		}
		while (y > 0) {
			first = first->next;
			abc = abc->next;
			if (first == 0)
				break;
			y--;
		}
		while (first != 0) {
			if (abc->gg == true)
				newnode.Insert1(first->data);
			else
				newnode.Insert(first->data);
			abc = abc->next;
			first = first->next;
		}
		*this = newnode;
	}
	int &Head() {
		int a = first->data;
		headPtr = first;
		return a;
	}
	int &Tail() {
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
		for (int j = 1; j < getLength(); j++) {
			for (int k = 1; k < getLength(); k++) {
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
	int time() {
		int ans = 0;
		ListNode* current = first;
		if (current->next == 0) {
			ans = 1;
			return ans;
		}
		while (current!= 0) {
			ans++;
			if (current->gg == true) {
				break;
			}
			current = current->next;	
		}
			return ans;
	}
	void Sort1() {
		LL *current = this, abc, line; bool f = false;
		line.first = first;
		ListNode *a = first;
		int i = getLength();
		for (int j = 1; j < i; j++) {
			for (int k = 1; k < i; k++) {
				for (int k = 1; k < i; k++) {
					if (line.first->next == 0)
						break;
					if (a->data < line.first->next->data) {
						current->Delete(j-1, 1);
						if(a->gg==true)
							current->Insert1(a->data);
						else
							current->Insert(a->data);
						line = *current;
						break;
					}
					else
						line.first= line.first->next;
				}
				if (line.first->next == 0)
					break;
				for (int k = 1; k < j; k++) {
					line.first = line.first->next;
				}
				a = line.first;
			}
			if (a->gg == true)
				abc.Insert1(a->data);
			else
				abc.Insert(a->data);
			line = *current;
			for (int k = 1; k <= j; k++) {
				line.first = line.first->next;
			}
			a = line.first;
		}
		if (a->gg == true)
			abc.Insert1(a->data);
		else
			abc.Insert(a->data);
		*this = abc;
	}
	bool isEmpty() {
		if (first == 0) {
			return true;
		}
		else {
			return false;
		}	
	}
	bool search(int value, int &pos) {
		LL current; pos = 0;
		current.first = first;
		while (current.first != 0) {
			pos++;
			if (current.first->data == value) {
				cout << "找到了!!\n";
				return true;
			}
			current.first = current.first->next;
		}
		cout << "沒找到喔\n";
		return false;
	}
	void insertiddata(int a) {
		first->id = a;
	}
	void link(LL a) {
		this->first->next = a.first;
	}
	void link1(LL a) {
		this->first->next1 = a.first;
	}
	void printt() {
		LL abc = *this;
		LL abcc = *this;
		cout << first->data << ",";
		if (abc.first->next != 0) {
			abc.first = abc.first->next;
			abc.printt();
		}
		if (abcc.first->next1 != 0) {
			abcc.first = abcc.first->next1;
			return abcc.printt();
		}
	}
	bool truee() {
		if (first->next != 0) {
			return false;
		}
		else
			return true;
	}
	bool ee() {
		if (first!= 0) {
			return true;
		}
		else
			return false;
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
	int noden, linkn, idd, dataa, fid, cid;
	cin >> noden >> linkn;
	LL *a = new LL[noden+1]();
	for (int i = 0; i < noden; i++) {
		cin >> idd >> dataa;
		a[idd].Insert(dataa);
		a[idd].insertiddata(idd);
	}
	for (int i = 0; i < linkn; i++) {
		cin >> fid >> cid;
		if (a[fid].truee()) {
			a[fid].link(a[cid]);
		}
		else {
			a[fid].link1(a[cid]);
		}
	}
	if (a[0].ee()) {
		a[0].printt();
	}
	else {
		a[1].printt();
	}
	cout << "\b ";
}