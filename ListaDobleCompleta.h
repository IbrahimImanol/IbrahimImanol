#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include<functional>

using namespace std;
using namespace System;
template<typename T>
class Nodo{
public:
	T dato;
	Nodo<T>* next;
	Nodo<T>* back;
public:
	Nodo(T dato,Nodo<T>*next=nullptr,Nodo<T>* back=nullptr)
		:dato(dato),next(next),back(back){}
	~Nodo(){
		this->next = nullptr;
		this->back = nullptr;
	}
};

template<class T>
class ListaDoble{
public:
	class Iterator
	{
	private:
		Nodo<T>* node;
		size_t pos;
	public:
		Iterator(Nodo<T>* node=nullptr, size_t pos = 0) :node(node), pos(pos)
		{}
		~Iterator() {
			this->node = nullptr;
		}
		void operator++() {
			node = node->next;
			++pos;
		}
		void operator--() {
			node = node->back;
			--pos;
		}
		T operator*() {
			return this->node->dato;
		}
		bool operator!=(Iterator a) {
			return this->pos != a.pos;
		}
	};
	Nodo<T>* begin;
	Nodo<T>* end;
	Nodo<T>* aux;
	size_t size;
	Iterator* i_begin;
	Iterator* i_end;
	//empezar desde el inicio hasta el final
	//a recorrer normal
	Iterator Ibegin_N(){
		return new Iterator(begin, 0);
	}
	Iterator Iend_N() {
		return new Iterator(nullptr, size);
	}

	//empezar desde el final hasta el inicio
	//a recorrer normal
	Iterator Ibegin_I() {
		return new Iterator(end, size-1);
	}
	Iterator Iend_I() {
		return new Iterator(nullptr, -1);
	}
	void _InvertRecursi(Nodo<T>*& auxx,ListaDoble<T>& lista) {
		if(auxx ==nullptr){return;}
		_InvertRecursi(auxx->next,lista);
		lista.pushBack(auxx->dato);
	}
	void _rotar2(){
		end = end->back;
		end->next->next = begin;
		begin->back = end->next;
		begin = end->next;
		end->next = nullptr;
		begin->back = nullptr;
	}
	void _recursiRotar1(int cont, int cant) {
		if (cont >= cant){
			end = aux;
			begin = aux->next;
			begin->back = nullptr;
			end->next = nullptr;
			return;
		}
		aux = aux->back;
		_recursiRotar1(++cont, cant);
	}
	void _recursiRotar2(int cont, int cant) {
		if (cont >= cant) { return; }
		_rotar2();
		_recursiRotar2(++cont, cant);
	}

public:
	ListaDoble(){
		size = 0;
		aux = begin = end = nullptr;
	}
	~ListaDoble(){
		eraseAll();
	}
	
	void sprint(){
		cout << "\n";
		i_begin = Ibegin_N();
		i_end = Iend_N();
		while (*(i_begin)!=*(i_end)){
			T dato = *(*(i_begin));
			cout << dato;
			cout << "-->";
			++(*(i_begin));
		}
		cout << "\n";
		delete i_begin;
		delete i_end;
		i_begin = i_end = nullptr;
	}
	void eraseAll() {
		while (!empty()){
			popFront();
		}
	}
	void popFront() {
		if (size <= 0) { return; }
		Nodo<T>* eliminado = begin;
		begin = begin->next;
		begin->back = nullptr;
		eliminado->next = nullptr;
		delete eliminado;
		/*begin = begin->next;
		if (size!=1){
			begin->back->next = nullptr;
			delete begin->back;
			begin->back = nullptr;
		}*/
		--size;
		if (size==0){begin = end = nullptr;	}
		if (size==1){end = begin;}
	}
	void popBack() {
		if (size <= 0) { return; }
		if (size==1){popFront(); return;}
		/*Nodo<T>* eliminado = end;
		end = end->back;
		eliminado->back = nullptr;
		end->next = nullptr;
		delete eliminado;*/
		
		end = end->back;
		end->next->back = nullptr;
		delete end->next;
		end->next = nullptr;
		--size;
		if (size==1){end = begin;}
		if (size==0){end = begin = nullptr;}
	}
	void eraseAt(int pos) {
		if (size<=0){return;}
		else if (pos <= 0) { popFront(); return; }
		else if (pos >= size-1) { popBack(); return; }
		else
		{
			aux = begin;
			int cont = 0;
			while (cont++<pos-1){
				aux = aux->next;
			}
			Nodo<T>* eliminado = aux->next;
			aux->next = aux->next->next;
			aux->next->back = aux;
			eliminado->next = nullptr;
			eliminado->back = nullptr;
			delete eliminado;

			/*aux->next->back = nullptr;
			aux->next->next = nullptr;
			aux->next = aux->next->next;
			delete aux->next->back;
			aux->next->back = aux;*/
			--size;
		}
	}
	T& front() {
		return begin->dato;
	}
	T& back() {
		return end->dato;
	}
	T& getDato(int pos) {
		aux = begin;
		if (size >= 0) {
			if (size == 1 || pos <= 0) {return this->front(); }
			else if (pos >= size - 1) { return this->back(); }
			else{
				aux = begin;
				int cont = 0;
				while (cont++ < pos) {
					aux = aux->next;
				}
				return aux->dato;
			}
		}
	}
	T& operator[](size_t pos) {
		aux = begin;
		if (size >= 0) {
			if (size == 1 || pos <= 0) { return this->front(); }
			else if (pos >= size - 1) { return this->back(); }
			else {
				aux = begin;
				int cont = 0;
				while (cont++ < pos) {
					aux = aux->next;
				}
				return aux->dato;
			}
		}
	}
	void pushFront(T dato) {
		Nodo<T>* nuevo = new Nodo<T>(dato);
		if (size==0){
			begin = end = nuevo;
		}else{
			nuevo->next = begin;
			begin->back = nuevo;
			begin = nuevo;
		}
		size++;
	}
	void pushBack(T dato){
		if (size==0){pushFront(dato);}
		else
		{
			Nodo<T>* nuevo = new Nodo<T>(dato);
			end->next = nuevo;
			nuevo->back = end;
			end = nuevo;
			size++;
		}
	}
	void insertAt(T dato, int pos) {
		if (pos <= 0){pushFront(dato);return;}
		else if (pos >= size) {pushBack(dato);return;}
		else{
			aux = begin;
			Nodo<T>* nuevo = new Nodo<T>(dato);
			int cont = 0;
			while (cont++<pos-1){
				aux = aux->next;
			}
			nuevo->next = aux->next;
			nuevo->next->back = nuevo;
			nuevo->back = aux;
			aux->next = nuevo;
			size++;
		}
	}
	void rotar1(int cant){
		if (size <= 0||size==1) { return; }
		else if (cant <=0) { return; }
		int cont = 0;
		aux = end;
		end->next = begin;
		begin->back = end;
		while (cont++< cant){
			aux = aux->back;
		}
		end = aux;
		begin = aux->next;
		begin->back = nullptr;
		end->next = nullptr;
	}
	
	void recursiRotar1(int cant) {
		if (size <= 0 || size == 1) { return; }
		else if (cant <= 0) { return; }
		int cont = 0;
		aux = end;
		end->next = begin;
		begin->back = end;
		_recursiRotar1(cont, cant);
	}
	
	void recursiRotar2(int cant) {
		if (size <= 0) { return; }
		else if (size == 1) { return; }
		else if (cant <= 0) { return; }
		aux = begin;
		int cont = 0;
		_recursiRotar2(cont, cant);
	}
	void rotar2(int cant) {
		if (size<=0){return;}
		else if (size == 1) { return; }
		else if (cant <= 0) { return; }
		aux = begin;
		int cont = 0;
		while (cont++< cant){
			_rotar2();
		}
	}
	void  InvertRecursi(ListaDoble<T>& lista) {
		aux = begin;
		_InvertRecursi(aux,lista);
	}
	bool empty() {
		return size == 0;
	}
	void print() {
		aux = begin;
		while (aux!=nullptr){
			cout << aux->dato << "-->";
			aux = aux->next;
		}
		cout << "nullptr\n";
	}
	void modifyFront(T dato){
		if (size<=0){return;}
		begin->dato = dato;
	}
	void modifyBack(T dato){
		if (size<=0){return;}
		end->dato = dato;
	}
	void modifyAt(T dato,int pos){
		if (size<=0){return;}
		else if (pos <= 0) { modifyFront(dato); return; }
		else if (pos >= size) { modifyBack(dato); return; }
		else{
			aux = begin;
			int cont = 0;
			while (cont++<pos){
				aux = aux->next;
			}
			aux->dato = dato;
		}
	}
	void filterShow(function<bool(T)> comp) {
		aux = begin;
		while (!this->empty()){
			if (comp(aux->dato)){
				cout << aux->dato << "-->";
			}
			aux = aux->next;
		}
		cout << "\n";
	}
	void filterList(function<bool(T)> comp,ListaDoble<T>& lista) {
		aux = begin;
		while (aux!=nullptr){
			if (comp(aux->dato)){
				lista.pushBack(aux->dato);
			}
			aux = aux->next;
		}
	}
	void printWriteArch(string nombrearch) {
		ofstream arch(nombrearch);
		aux = begin;
		while (aux!=nullptr){
			arch << aux->dato;
			aux = aux->next;
		}
		arch.close();
	}
};


