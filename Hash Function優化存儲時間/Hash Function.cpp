#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

bool changet = false, checkt = false, countt = false, removet = false;
int countnum=0;
template<typename T>
class ListNode {
	friend class LinkedList;
public:
	T data;
	float dataf;
	string datas;
	int id;
	ListNode* next;
	ListNode* next1 = 0;
	bool gg = false;
	ListNode() :data(), id(), next() {};
	ListNode(T a) :data(a), next() {};
};
template<typename T>
class LL {
	friend ostream &operator<<(ostream &, const LL&);
	friend istream &operator>>(istream&, LL&);
private:
	ListNode <T>*first;
public:
	/*
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
	}*/
	void Insert(T x) {//等於void push(int)
		ListNode <T>*newNode = new ListNode<T>(x);
		if (first == 0) {                      // 若list沒有node, 令newNode為first
			first = newNode;
			return;
		}
		ListNode<T> *current = first;
		while (current->next != 0) {           // Traversal
			current = current->next;
		}
		current->next = newNode;
	}/*
	void Insertf(float x) {//等於void push(int)
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
	void Inserts(string x) {//等於void push(int)
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
			if (abc->gg == true)
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
		while (current != 0) {
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
						current->Delete(j - 1, 1);
						if (a->gg == true)
							current->Insert1(a->data);
						else
							current->Insert(a->data);
						line = *current;
						break;
					}
					else
						line.first = line.first->next;
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
	}*/
	void print() {
		LL abc = *this;
		LL abcc = *this;
		if (first == 0) {
			return;
		}
		else {
			cout << first->data << " ";
		}
		if (abc.first->next != 0) {
			abc.first = abc.first->next;
			abc.print();
		}
		if (abcc.first->next1 != 0) {
			abcc.first = abcc.first->next1;
			return abcc.print();
		}
	}/*
	void printid() {
		LL abc = *this;
		LL abcc = *this;
		if (first->data == 0) {
			if (first->dataf == 0) {
				cout << first->id << ", ";
			}
			else {
				cout << first->id << ", ";
			}
		}
		else {
			cout << first->id << ", ";
		}
		if (abc.first->next != 0) {
			abc.first = abc.first->next;
			abc.printid();
		}
		if (abcc.first->next1 != 0) {
			abcc.first = abcc.first->next1;
			return abcc.printid();
		}
	}
	void printr() {
		LL abc = *this;
		LL abcc = *this;
		if (first->data == 0) {
			if (first->dataf == 0) {
				for (int i = 0; i < first->datas.size() - 1; i++)
					cout << first->datas[i];
				cout << ", ";
			}
			else {
				cout << first->dataf - 0.1 << ", ";
			}
		}
		else {
			cout << first->data - 1 << ", ";
		}
		if (abc.first->next != 0) {
			abc.first = abc.first->next;
			abc.printr();
		}
		if (abcc.first->next1 != 0) {
			abcc.first = abcc.first->next1;
			return abcc.printr();
		}
	}
	bool truee() {
		if (first->next == 0) {
			return true;
		}
		else
			return false;
	}
	bool ee() {
		if (first != 0) {
			return true;
		}
		else
			return false;
	}*/
	template<typename T>
	void change(T data, T data1) {
		LL abc = *this;
		while (abc.first != 0) {
			if (abc.first->data == data) {
				abc.first->data = data1;
				changet = true;
				return;
			}
			else {
				abc.first = abc.first->next;
			}
		}
	}
	template<typename T>
	void check(T data) {
		LL abc = *this;
		while (abc.first != 0) {
			if (abc.first->data == data) {
				checkt = true;
				return;
			}
			else {
				abc.first = abc.first->next;
			}
		}
	}
	template<typename T>
	void count(T data) {
		LL abc = *this;
		while (abc.first != 0) {
			if (abc.first->data == data) {
				countt = true;
				countnum++;
			}
			abc.first = abc.first->next;
		}
	}
	template<typename T>
	void remove(T x) {
		if (first == 0)
			return;
		LL <T>newnode;
		ListNode <T>*abc = this->first;
		while (first->data != x) {
			newnode.Insert(first->data);
			abc = abc->next;
			first = first->next;
			if (first == 0) {
				*this = newnode;
				return;
			}	
		}
		removet = true;
		first = first->next;
		abc = abc->next;
		while (first != 0) {
			newnode.Insert(first->data);
			abc = abc->next;
			first = first->next;
		}
		*this = newnode;
	}
	ListNode<T>* headPtr;
	ListNode<T>* tailPtr;
	LL() :first() {};
	LL(T a) :first() {};
};
/*
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
}*/
template<typename T>
int hashfunc(T data,int number) {
	return data % number;
}
int main()
{
	string type,a,n,num; int number,key,j=0;
	ifstream inFile("input_mset_7_1.txt", ios::in);
	getline(inFile, type);
	getline(inFile, n);
	while (n[j] != ' ') {
		num += n[j];
		j++;
	}
	number = stoi(num);
	if (type == "int") {
		LL <int> *hash = new LL <int>[number];
		int data,data1;
		for (int i = 0; i < number; i++) {
			getline(inFile, n);
			data = stoi(n);
			key = hashfunc(data,number);
			hash[key].Insert(data);
		}
		string all; int funcnum;
		while (getline(inFile, all)) {
			string func;
			int i = 0;
			while (all[i] != ' '&& all[i] != '\0') {
				func += all[i];
				i++;
			}
			if (func == "print")
				funcnum = 1;
			else if (func == "add")
				funcnum = 2;
			else if (func == "change")
				funcnum = 3;
			else if (func == "check")
				funcnum = 4;
			else if (func == "count")
				funcnum = 5;
			else if (func == "remove")
				funcnum = 6;
			string abc;
			switch (funcnum) {
			case 1:
				cout << "print = ";
				for (int i = 0; i < number; i++) {
					hash[i].print();
				}
				cout << "\n";
				break;
			case 2:
				i++; abc = "";
				int aa;
				while (all[i] != ' '&& all[i] != '\0') {
					abc += all[i];
					i++;
				}
				aa = stoi(abc);
				key = hashfunc(aa, number);
				hash[key].Insert(aa);
				cout << "add(" << aa << ")\n";
				break;
			case 3:
				i++; abc = "";
				while (all[i] != ' '&& all[i] != '\0') {
					abc += all[i];
					i++;
				}
				data = stoi(abc);
				i++;abc = "";
				while (all[i] != ' '&& all[i] != '\0') {
					abc += all[i];
					i++;
				}
				data1 = stoi(abc);
				for (int i = 0; i < number; i++) {
					hash[i].change(data,data1);
					if (changet == true)
						break;
				}
				if (changet == false)
					cout << "change() exception: item " << data << " not exist\n";
				else
					cout << "change(" << data << "," << data1 << ")\n";
				changet = false;
				break;
			case 4:
				i++; abc = "";
				while (all[i] != ' '&& all[i] != '\0') {
					abc += all[i];
					i++;
				}
				data = stoi(abc);
				for (int i = 0; i < number; i++) {
					hash[i].check(data);
					if (checkt == true)
						break;
				}
				if (checkt == true) 
					cout << "check(" << data << ") = true\n";
				else
					cout << "check(" << data << ") = false\n";
				checkt = false;
				countnum = 0;
				break;
			case 5:
				i++; abc = "";
				while (all[i] != ' '&& all[i] != '\0') {
					abc += all[i];
					i++;
				}
				data = stoi(abc);
				for (int i = 0; i < number; i++) {
					hash[i].count(data);
				}
				if (countt == true)
					cout << "count(" << data << ") = " << countnum << "\n";
				else
					cout << "count(" << data << ") = 0\n";
				countt = false;
				countnum = 0;
				break;
			case 6:
				i++; abc = "";
				while (all[i] != ' '&& all[i] != '\0') {
					abc += all[i];
					i++;
				}
				data = stoi(abc);
				for (int i = 0; i < number; i++) {
					hash[i].remove(data);
					if (removet == true)
						break;
				}
				if (removet == true)
					cout << "remove(" << data << ")\n";
				else
					cout << "remove() exception: item " << data << " not exist\n";
				removet = false;
				break;
			}
		}
	}
	else if (type == "string") {
		LL <string> *hash = new LL <string>[number];
		string data, data1,line;
		for (int i = 0; i < number; i++) {
			getline(inFile, n);
			key = hashfunc(n[0], number);
			hash[key].Insert(n);
		}
		string all; int funcnum;
		while (getline(inFile, all)) {
			string func; int i = 0;
			while (all[i] != ' '&& all[i] != '\0') {
				func += all[i];
				i++;
			}
			if (func == "print")
				funcnum = 1;
			else if (func == "add")
				funcnum = 2;
			else if (func == "change")
				funcnum = 3;
			else if (func == "check")
				funcnum = 4;
			else if (func == "count")
				funcnum = 5;
			else if (func == "remove")
				funcnum = 6;
			string abc;
			switch (funcnum) {
			case 1:
				cout << "print = ";
				for (int i = 0; i < number; i++) {
					hash[i].print();
				}
				cout << "\n";
				break;
			case 2:
				i++; abc = "";
				int aa;
				while (all[i] != ' '&& all[i] != '\0') {
					abc += all[i];
					i++;
				}
				key = hashfunc(abc[0], number);
				hash[key].Insert(abc);
				cout << "add(" << abc << ")\n";
				break;
			case 3:
				i++; data = "",data1="";
				while (all[i] != ' '&& all[i] != '\0') {
					data += all[i];
					i++;
				}
				i++;
				while (all[i] != ' '&& all[i] != '\0') {
					data1 += all[i];
					i++;
				}
				for (int i = 0; i < number; i++) {
					hash[i].change(data, data1);
					if (changet == true)
						break;
				}
				if (changet == false)
					cout << "change() exception: item " << data << " not exist\n";
				else
					cout << "change(" << data << "," << data1 << ")\n";
				changet = false;
				break;
			case 4:
				i++; data = "";
				while (all[i] != ' '&& all[i] != '\0') {
					data += all[i];
					i++;
				}
				for (int i = 0; i < number; i++) {
					hash[i].check(data);
					if (checkt == true)
						break;
				}
				if (checkt == true)
					cout << "check(" << data << ") = true\n";
				else
					cout << "check(" << data << ") = false\n";
				checkt = false;
				countnum = 0;
				break;
			case 5:
				i++; data = "";
				while (all[i] != ' '&& all[i] != '\0') {
					data += all[i];
					i++;
				}
				for (int i = 0; i < number; i++) {
					hash[i].count(data);
				}
				if (countt == true)
					cout << "count(" << data << ") = " << countnum << "\n";
				else
					cout << "count(" << data << ") = 0\n";
				countt = false;
				countnum = 0;
				break;
			case 6:
				i++; data = "";
				while (all[i] != ' '&& all[i] != '\0') {
					data += all[i];
					i++;
				}
				for (int i = 0; i < number; i++) {
					hash[i].remove(data);
					if (removet == true)
						break;
				}
				if (removet == true)
					cout << "remove(" << data << ")\n";
				else
					cout << "remove() exception: item " << data << " not exist\n";
				removet = false;

				break;
			}
		}
	}
	else if (type == "date") {
		LL <int> *hash = new LL <int>[number];

	}
	
}