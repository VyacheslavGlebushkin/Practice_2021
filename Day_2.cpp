#include <iostream>
#include <string>
using namespace std;

//Задание 3.1
struct Node {
	int val;
	Node* next;
};

// Инициализации элемента односвязного списка нулями
void init(int n, Node** node) {
	if (n > 0) {
		(*node) = new Node;
		(*node)->val = 0;
		(*node)->next = NULL;
		init(n - 1, &((*node)->next));
	}
}

// Отображения односвязного списка на экран
int show(Node* head_) {
	cout << head_->val << endl;
	if (head_->next == NULL) {
		cout << endl;
		return 0;
	}
	show(head_->next);
}

// Добавления элемента в односвязный список
void pushNode(Node* head_, Node* node) {
	Node* current = head_;
	for (int i = 1; current->next != NULL; i++) {
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
}

//Задание 3.2
int compareMas(Node* source, Node* dest, int b) {
	for (int i = 1; i <= b; i++) {
		if (source->val != dest->val) return -1;
		source = source->next;
		dest = dest->next;
	}
	return 0;
}

void init_(int n, Node** node) {
	if (n > 0) {
		(*node) = new Node();
		cin >> (*node)->val;
		(*node)->next = NULL;
		init_(n - 1, &((*node)->next));
	}
}

int testInit() {
	Node* head_;
	head_ = new Node;
	head_->next = NULL;
	head_->val = 0;
	init(3, &((head_)->next));
	for (int i = 1; i <= 3; i++) {
		if (head_->val != 0) return -1;
		head_ = head_->next;
	}
	return 0;
}

int testInit_() {
	Node* head_;
	head_ = new Node;
	head_->next = NULL;
	head_->val = 0;
	cout << "Введите 3 элемента списка: " << endl;
	init_(3, &((head_)->next));
	cout << "Введите их еще раз для проверки: " << endl;
	int a;
	head_ = head_->next;
	for (int i = 1; i <= 3; i++) {
		cin >> a;
		if (head_->val != a) return -1;
		head_ = head_->next;
	}
	return 0;
}

int testPushNode() {
	Node* head_;
	head_ = new Node;
	head_->next = NULL;
	head_->val = 0;
	init(3, &((head_)->next));
	Node* ded;
	ded = new Node;
	ded->next = NULL;
	ded->val = 1;
	pushNode(head_, ded);
	head_ = head_->next;
	for (int i = 1; i <= 3; i++) {
		if (head_->val != 0) return -1;
		head_ = head_->next;
	}
	if (head_->val != 1) return -1;
	return 0;
}

int testCompareMas() {
	Node* head_;
	head_ = new Node;
	head_->next = NULL;
	head_->val = 1;
	init(3, &((head_)->next));
	Node* ded;
	ded = new Node;
	ded->next = NULL;
	ded->val = 1;
	init(3, &((ded)->next));
	if (compareMas(head_, ded, 3) != 0) return -1;
	return 0;
}

void runTest(int (*testfunction)(), string testname) {
	if (testfunction() == 0)
		cout << "Тест " << testname << " пройден" << endl;
	else
		cout << "Тест " << testname << " не пройден" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Node* head_;
	head_ = new Node;
	head_->next = NULL;
	head_->val = 0;
	Node* node;
	node = new Node;
	node->next = NULL;
	node->val = 1;
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	runTest(testInit, "testInit");
	runTest(testInit_, "testInit_");
	runTest(testPushNode, "testPushNode");
	runTest(testCompareMas, "testCompareMas");
	init(n - 1, &((head_)->next));
	if (n != 0) show(head_);
	pushNode(head_, node);
	if (n != 0) show(head_);
	cout << "ЗАДАЧА 3.2" << endl;
	int m, k;
	cout << endl << "Введите количество элементов списка source: ";
	cin >> m;
	cout << "Введите элементы списка source: " << endl;
	Node* source;
	source = new Node;
	cin >> source->val;
	source->next = NULL;
	init_(m - 1, &((source)->next));
	cout << endl << "Введите количество элементов списка dest: ";
	cin >> k;
	cout << "Введите элементы списка dest: " << endl;
	Node* dest;
	dest = new Node;
	cin >> dest->val;
	dest->next = NULL;
	init_(k - 1, &((dest)->next));
	if (k == m) {
		if (compareMas(source, dest, k) == 0) cout << endl << "Равны" << endl;
		else cout << endl << "Не равны" << endl;
	}
	else cout << endl << "Не равны" << endl;
}