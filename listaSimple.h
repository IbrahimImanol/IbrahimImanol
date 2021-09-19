#pragma once
template<class G>
class Node
{
public:
	G value;
	Node<G>* next;
public:
	Node(G value, Node<G>* next = nullptr) :value(value), next(next) {

	}
	~Node() {}
};

template<typename T>
class List
{
public:
	Node<T>* inicio;
	unsigned long size;
public:
	List() {
		inicio = nullptr;
		size = 0;
	}
	~List() {
		while (size > 0) {
			popFront();
		}
	}
	void pushFront(T value) {
		Node<T>* newNode = new Node<T>(value);
		if (size > 0) {
			newNode->next = inicio;
		}
		inicio = newNode;
		++size;
	}
	void pushBack(T value) {
		if (size == 0) {
			pushFront(value);
		}
		else {
			Node<T>* aux = inicio;
			for (unsigned long i = 0; i < size - 1; i++) {
				aux = aux->next;
			}
			Node<T>* newNode = new Node<T>(value);
			aux->next = newNode;
			++size;
		}
	}
	void print() {
		Node<T>* aux = inicio;
		while (aux != nullptr) {
			cout << aux->value << "-->";
			aux = aux->next;
		}
		cout << "nullptr\n";
	}
	void insertarAt(T value, size_t pos) {
		if (pos == 0)pushFront(value);
		else if (pos >= size)pushBack(value);
		else {
			Node<T>* aux = inicio;
			for (size_t i = 0; i < pos - 1; i++) {
				aux = aux->next;
			}
			Node<T>* newNode = new Node<T>(value);
			newNode->next = aux->next;
			aux->next = newNode;
			++size;
		}
	}
	void popFront() {
		if (size == 0)return;
		Node<T>* eliminado = inicio;
		inicio = eliminado->next;
		eliminado->next = nullptr;
		delete eliminado;
		--size;
	}
	void popBack() {
		if (size == 0)return;
		if (size == 1) { popFront(); return; }
		Node<T>* penultimo = inicio;
		for (unsigned long i = 0; i < size - 2; i++) {
			penultimo = penultimo->next;
		}
		delete penultimo->next;
		penultimo->next = nullptr;
		--size;
	}
	void eraseAt(size_t pos) {
		if (pos == 0) {
			popFront();
		}
		else if (pos >= size - 1) {
			popBack();
		}
		else {
			Node<T>* aux = inicio;
			for (unsigned long i = 0; i < pos - 1; i++) {
				aux = aux->next;
			}
			Node<T>* eliminado = aux->next;
			aux->next = aux->next->next;
			delete eliminado;
			--size;
		}
	}
	T& operator[](size_t pos) {
		Node<T>* aux = inicio;
		for (unsigned long i = 0; i < pos; ++i) {
			aux = aux->next;
		}
		return aux->value;
	}
};