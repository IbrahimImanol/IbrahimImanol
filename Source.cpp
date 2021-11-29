#include<iostream>
#include<functional>
#include<vector>
#include<string>
#include<string.h>
#include<list>
#include<stack>
#include<math.h>
using namespace std;
//#define CATCH_CONFIG_MAIN
#include"Header.h"
template<typename T>
class Tree;
template<typename T>
class Tree1;
template<typename T>
class Node
{
private:
	T dato;
	Node<T>* left;
	Node<T>* right;
	long long nivel;
	friend Tree<T>;
	friend Tree1<T>;
public:
	Node(T dato=T(),Node<T>* left=nullptr,Node<T>* right=nullptr)
		:dato(dato),left(left),right(right){
		this->nivel = NULL;
	}
	~Node(){}
	T& operator*() {
		return this->dato;
	}
};

template<typename T>
class Tree
{
private:
	Node<T>* root;
	function<int(T,T)> comp;
	function<void(T)> show;
	long long _size;
	void _insert(Node<T>*& n, T dato) {
		if (n==nullptr){
			n = new Node<T>(dato);
			++_size;
			return;
		}
		int opc = comp(dato, n->dato);
		if (opc>0){
			_insert(n->left, dato);
		}else if(opc<=0){
			_insert(n->right, dato);
		}
	}
	Node<T>* _getN(Node<T>*& n, T dato) {
		if (n!=nullptr){
			int opc = comp(dato, n->dato);
			if (opc==0){
				return n;
			}else if (opc==1){
				return _getN(n->left, dato);
			}else if (opc==-1){
				return _getN(n->right, dato);
			}
		}
		return new Node<T>();
	}
	T& _menordato(Node<T>*& n) {
		if (n!=nullptr){
			if (n->right!=nullptr){
				return _menordato(n->right);
			}else{
				return n->dato;
			}
		}
		return T();
	}
	void _menorelemento(Node<T>*& n,function<bool(T,T)> comp3,T& menor) {
		//bool(*ptr[1])(T, T);
		if (n!=nullptr){
			if (!comp3(menor, n->dato)) {
				menor = n->dato;
			}
			_menorelemento(n->right, comp3, menor);
		}
	}
	void _printInOrder(Node<T>*& n) {
		if (n!=nullptr){
			_printInOrder(n->left);
			show(n->dato);
			_printInOrder(n->right);
		}
		return;
	}
	void _printInOrderByNivel(Node<T>*& n,long long nivel) {
		if (n != nullptr){
			_printInOrderByNivel(n->left,nivel);
			if (n->nivel== nivel){
				show(n->dato);
			}
			_printInOrderByNivel(n->right,nivel);
		}
		return;
	}
	long _NivelTree(Node<T>*& n) {
		if (n != nullptr) {
			long left = _NivelTree(n->left) + 1;
			long right = _NivelTree(n->right) + 1;
			if (left>=right){return left;}
			else{return right;}
		}
		return -1;
	}
	void _actualizar(Node<T>*& n, function<void(T&)> comp) {
		if (n!=nullptr){
			_actualizar(n->left, comp);
			_actualizar(n->right, comp);
			comp(n->dato);
		}
		return;
	}
	void _podar(Node<T>*n) {
		if (n==nullptr){return;}
		_podar(n->left);
		_podar(n->right);
		delete n;
		n = nullptr;
	}
	void _minorElement_Way(Node<T>*&n, stack<Node<T>*>& pila) {
		if (n!=nullptr){
			pila.push(n);
			_minorElement_Way(n->right, pila);
		}
	}
	void _actualizarnivel(Node<T>*& n,Node<T>*padre=nullptr) {
		if (n != nullptr) {
			_actualizarnivel(n->left, n);
			_actualizarnivel(n->right, n);
			if (padre!=nullptr){
				n->nivel = padre->nivel + 1;
			}else{
				n->nivel = 1;
			}
		}
		return;
	}
public:
	Tree(function<int(T, T)> comp, function<void(T)> show){
		root = nullptr;
		_size = 0;
		this->comp = comp;
		this->show = show;
	}
	~Tree(){_podar(root);}
	void insert(T dato) { //o(n)
		_insert(root, dato);
		_actualizarnivel(root);
	}
	void printInOrder() {
		_printInOrder(root);
	}
	void printInOrderByNivel(long long nivel) {
		_printInOrderByNivel(root,nivel);
	}
	long long Nivel() {
		return root->nivel;
	}
	T& menordato() {
		return _menordato(root);
	}
	T& menorelemntos(function<bool(T,T)> comp3) {
		T menor=root->dato;
		_menorelemento(root, comp3,menor);
		return menor;
	}
	Node<T>* getN(T dato) {
		return _getN(root, dato);
	}
	long NivelTree() {
		return _NivelTree(root);
	}
	void actualizar(function<void(T&)> comp) {
		_actualizar(root,comp);
	}
	stack<Node<T>*>& minorElementWay() {
		stack<Node<T>*> pila;
		_minorElement_Way(root, pila);
		return pila;
	}
};

template<class T>
class HashTable
{
private:
	vector<list<T>> ht;
	function<int(T)> hashfunction;
	long long _size;
	long long _sizevacios;
	void _insertinList(list<T>& lista,T dato) {
		lista.push_back(dato);
	}
	void _elemntsCoincidentes(function<bool(T)> comp,long long&num) {
		for (int i = 0; i < ht.size(); i++){
			for (auto var : ht.at(i)) {
				if (comp(var)){
					num++;
				}
			}
		}
	}
public:
	HashTable(long long _size, 
		function<int(T)> hashfunction)
		:_size(_size), hashfunction(hashfunction){
		ht.resize(_size);
		_sizevacios = _size;
	}
	~HashTable(){}
	long long size() {
		return _size;
	}
	long long sizevacios() {
		return _sizevacios;
	}
	void insert(T dato) {
		int pos = hashfunction(dato);
		if (pos<0||pos>=_size){
			return;
		}
		if (ht.at(pos).size()==0){
			_sizevacios--;
		}
		_insertinList(ht.at(pos), dato);
	}
	long long elemntsCoincidentes(function<bool(T)> comp) {
		long long num = 0;
		_elemntsCoincidentes(comp, num);
		return num;
	}
	void eliminarRango(long long numIni,long long numFin) {
		for (int i = 0; i < ht.size(); i++){
			if (i>=numIni&&i<=numFin){
				ht.erase(ht.begin() + i);
			}
		}
	}
	void print() {
		for (int i = 0; i < ht.size(); i++) {
			for (auto var : ht.at(i)) {
				cout << var<<" ";
			}
		}
	}
	void reamplazarElement(T dato,function<void(T&,T&)>intercamb,
		function<bool(T,T)> comp) {
		for (int i = 0; i < ht.size(); i++) {
			for (T& var : ht.at(i)) {
				if (comp(var,dato)) {
					intercamb(var, dato);
				}
			}
		}
	}
	int cantidadByCondition(T dato, function<bool(T,T)> comp) {
		long long num = 0;
		for (int i = 0; i < ht.size(); i++) {
			for (auto var : ht.at(i)) {
				if (comp(var,dato)) {
					num++;
				}
			}
		}
		return num;
	}
	int& moda(function<int(T)> getint) {
		vector<int> arr;
		int moda = 0;
		for (int i = 0; i < ht.size(); i++) {
			for each (T var in ht.at(i)){
				arr.push_back(getint(var));
			}
		}
		sort(arr.begin(), arr.end());
		bool valor = true;
		int contanterior = 0;
		int indicemoda=0;
		int cont = 0;
		int j = 0;
		for (int y = 1; y < arr.size(); y++){
			if (arr[j] == arr[y]) { 
				if (valor){
					cont += 2;
					valor = false;
				}else{
					cont++;
				}
				if (contanterior<cont){
					indicemoda = j;
				}
			}else{
				if (contanterior<cont){
					valor = true;
					contanterior = cont;
					indicemoda = j;
					cont = 0;
				}
			}
			j++;
		}
		moda = arr[indicemoda];
		return moda;
	}
};

short AND(unsigned short a, unsigned short b) {
	return a & b;
}
short OR(unsigned short a, unsigned short b) {
	return a | b;
}
short XOR(unsigned short a, unsigned short b) {
	return a ^ b;
}
unsigned char NEG(unsigned char a) {
	return ~a;
}
short NEG1(short a) {
	return ~a;
}
bool iseven(unsigned short a) {
	return a & 1? false:true;
}
int funcion1(int a, int b) {
	int x = (a & b) << 1;
	int y = a ^ b;
	if (x == 0) { return y; }
	else {
		return funcion1(x, y);
	}
}
bool funcion2(int x){
	return x && (!(x & (x - 1)));
	// me da los numeros apartir de uno y luego este se empiza a multiplicar por 2
	//Estos numeros seran 1,2,4,8,16,32,64,128,256, etc......

}
int funcion3(int a, int b){//setear bit en una posicion tal b
	//set = 0 ->1 
	//b =3
	// 128  64  32  16 8 4 2 1
	// 0     0   0   0 1 0 0 1
	a |= (1 << b);
	return a;
}
//b puede ir desde 0 hasta 
int funcion4(int a, int b){//limpiar el bit en la posicion tal b
	// clear= 1 ->0 
	int aux = ~(1 << b);
	cout << "aux= " << aux<<" ";
	return a&aux;
}
int funcion5(int a, int b){//flip the status of the ith item os the set
	//flip = 0->1
	// 1->0
	a ^= (1 << b);
	return a;
}
//TEST_CASE("Caso de Prueba 1", "[factorial]") {
//	int n= 10;
//	REQUIRE(funcion1(10,6) == 2);
//    REQUIRE(funcion2(10) ==true);
//    funcion3(n,6);
//	funcion4(n,10);
//	funcion5(n,10);
//}

template<typename T>
class Tree1
{
private:
	Node<T>* root;
	function<int(T,T)> comp;
	long long _size;
	void _insert(Node<T>*& n,T dato) {
		if (n == nullptr) {
			n = new Node<T>(dato);
			++_size;
			return;
		}
		int opc = comp(dato, n->dato);
		if (opc>=0){
			_insert(n->right, dato);
		}else{
			_insert(n->left, dato);
		}
	}
	void _promedio(Node<T>* n,float& suma,function<int(T)>getint) {
		if (n==nullptr){return;}
		_promedio(n->left, suma,getint);
		_promedio(n->right, suma,getint);
		suma += getint(n->dato);
	}
	void _cont_ByCondition(function<bool(T)> comp, long long& canti,Node<T>* n) {
		if (n == nullptr) { return; }
		if (comp(n->dato)){
			canti++;
		}
		_cont_ByCondition(comp, canti, n->left);
		_cont_ByCondition(comp, canti, n->right);
	}
	void _mayor_bycondition(function<void(T, long long&)> filtrado,
		long long& mayor, Node<T>* n) {
		if (n==nullptr){return;}
		filtrado(n->dato, mayor);
		_mayor_bycondition(filtrado, mayor, n->left);
		_mayor_bycondition(filtrado, mayor, n->right);
	}
	void _sumatoria(float& suma,function<void(T, float&,float&)> procesar,float prom,Node<T>* n) {
		if (n==nullptr){return;}
		procesar(n->dato, suma,prom);
		_sumatoria(suma, procesar,prom, n->left);
		_sumatoria(suma, procesar,prom, n->right);
	}
	float sumatoria(function<void(T, float&, float&)> procesar, function<int(T)>getint) {
		float suma = 0;
		float prom = promedio(getint);
		_sumatoria(suma, procesar, prom, root);
		return suma;
	}
public:
	Tree1(function<int(T, T)> comp){
		root = nullptr;
		this->comp = comp;
		_size = 0;
	}
	~Tree1(){}
	void insert(T dato) {
		_insert(root, dato);
	}
	float promedio(function<int(T)>getint) {
		float suma = 0;
		_promedio(root, suma, getint);
		return (suma / _size);
	}
	long long cont_ByCondition(function<bool(T)> comp) {
		long long canti = 0;
		_cont_ByCondition(comp, canti,root);
		return canti;
	}
	long long mayor_bycondition(function<void(T,long long&)> filtrado) {
		long long mayor = 0;
		_mayor_bycondition(filtrado,mayor, root);
		return mayor;
	}
	float desviacionestad(function<void(T, float&, float&)> procesar,
		function<int(T)>getint) {
		float suma = 0;
		suma = sumatoria(procesar,getint);
		return std::sqrt(suma/(_size));
	}
};
class Alumno
{
private:
	int* id;
	string nombre;
	int* c1;
	int* c2;
	int* c3;
	int* c4;
public:
	Alumno(int id=NULL,string nombre="",
		int c1=NULL	,int c2=NULL,int c3=NULL,int c4=NULL){
		this->nombre = nombre;
		this->c1 = new int(c1);
		this->c2 = new int(c2);
		this->c3 = new int(c3);
		this->c4 = new int(c4);
		this->id = new int(id);
	}
	~Alumno(){}
	friend ostream& operator<<(ostream& os, const Alumno* al) {
		os << al->nombre << "\n";
		return os;
	}
	bool operator<(Alumno* al) {
		if (*this->c1<*al->c1){
			return true;
		}
		return false;
	}
	bool operator>(Alumno* al) {
		if (*this->c1 > *al->c1) {
			return true;
		}
		return false;
	}
	int* getid() {
		return id;
	}
	string getnombre() {
		return nombre;
	}
	int* getc1() {
		return c1;
	}
	int* getc2() {
		return c2;
	}
	int* getc3() {
		return c3;
	}
	int* getc4() {
		return c4;
	}
};
template<class T>
class ListaDoble;
template<class T>
class Nodo
{
private:
	T dato;
	Nodo<T>* next;
	Nodo<T>* back;
	friend ListaDoble<T>;
public:
	Nodo(T dato=T(),Nodo<T>*next=nullptr, Nodo<T>* back=nullptr)
	:dato(dato),next(next),back(back){}
	~Nodo(){}
	T& operator*() {
		return this->dato;
	}
};
template<typename T>
class ListaDoble
{
private:
	Nodo<T>* begin;
	Nodo<T>* end;
	Nodo<T>* aux;
	size_t _size;
public:
	ListaDoble() {
		_size = 0;
		aux = begin = end = nullptr;
	}
	~ListaDoble() {
		eraseAll();
	}
	void eraseAll() {
		while (_size>0){
			popfront();
		}
	}
	void popfront() {
		if (_size>0){
			aux = begin;
			if (_size>1){
				begin = begin->next;
			}
			delete aux;
		}
	}
	void pushFront(T dato) {
		Nodo<T>* nuevo = new  Nodo<T>(dato);
		if (_size == 0){
			begin = end = nuevo;
		}else{
			nuevo->next = begin;
			begin->back = nuevo;
			begin = nuevo;
		}
		if (_size == 1) { end = begin = nuevo; }
		_size++;
	}
	size_t size() {
		return this->_size;
	}
	void pushback(T dato) {
		if (_size == 0) { pushFront(dato); return; }
		else{
			Nodo<T>* nuevo = new Nodo<T>(dato);
			end->next = nuevo;
			nuevo->back = end;
			end = nuevo;
			_size++;
		}
	}
	void insertAt(T dato, int pos) {
		if (pos <= 0) { pushFront(dato); return; }
		else if (pos >= _size) { pushback(dato); return; }
		else {
			Nodo<T>* nuevo = new Nodo<T>(dato);
			aux = begin;
			int cont = 0;
			while (cont++ < pos)
			{
				aux = aux->next;
			}
		}
	}

	void buscar(T dato, function<bool(T, T)>comp) {
		aux = end;
		if (end = begin) {
			if (comp(dato, begin->dato)) {
				cout << "encontrado";
			}
		}
		while (aux->back == nullptr)
		{
			if (comp(aux->dato, dato))
			{
				cout << "encontrado";
			}
			aux = aux->back;
		}
	}
	void _rotar() {
		Nodo<T>* cambia = end;
		end = end->back;
		end->next = nullptr;
		cambia->next = begin;
		begin->back = cambia;
		begin = cambia;
	}
	void rotar(int n) {
		int cont = 0;
		while (cont++ != n) {
			_rotar();
		}
	}
	void print() {
		aux = begin;
		while (aux != nullptr) {
			cout << aux->dato << "\n";
			aux = aux->next;
		}
		cout << "nullptr";
	}
	template<class valor>
	void indexarfilas(Tree1<valor>& tree) {
		aux = begin;
		while (aux!=nullptr){
			tree.insert(aux);
			aux = aux->next;
		}
	}
	template<class valor>
	void indexarcolumn1(Tree1<valor>& tree,
		function<void(Tree1<valor>&,Nodo<T>*)> index) {
		aux = begin;
		index(tree, aux);
	}
	template<class valor>
	void indexarfilas(HashTable<valor>& hash) {
		aux = begin;
		while (aux != nullptr) {
			hash.insert((*(*aux)));
			aux = aux->next;
		}
	}
	int calcularsize_hash(function<int(T)> hashfunction) {
		aux = begin;
		int mayor= hashfunction(begin->dato);
		while (aux!=nullptr){
			int x = hashfunction(aux->dato);
			if (x>mayor){
				mayor = x;
			}
			aux = aux->next;
		}
		return mayor;
	}
	void sort(function<bool(T, T)> comp) {
		vector<T> arr;
		aux = begin;
		while (aux!=nullptr){
			arr.push_back(aux->dato);
			aux = aux->next;
		}
		_mergesort_v2(0, arr.size() - 1, arr,comp);
		aux = begin;
		int i = 0;
		while (aux != nullptr) {
			aux->dato = arr[i++];
			aux = aux->next;
		}
	}
	void _mergesort_v2(size_t inicio, size_t fin,vector<T>& arr,
		function<bool(T, T)> comp) {
		if (fin <= inicio)return;
		size_t m = (fin + inicio) / 2;
		_mergesort_v2(inicio, m,arr,comp);//dividimos por la izquierda
		_mergesort_v2(m + 1, fin,arr,comp);//dividimos por la derecha
		__merge_v2(inicio, m, fin,arr,comp);//combinamos
	}
	void __merge_v2(size_t ini, size_t med, size_t fin,vector<T>& arr,
		function<bool(T,T)> comp) {
		T* auxArr = new T[(fin - ini) + 1];
		size_t i, j, k;
		i = ini;
		j = med + 1;
		k = 0;
		while (i <= med && j <= fin) {
			if (comp(arr[i],arr[j])) {
				auxArr[k++] = arr[j++];
			}else{
				auxArr[k++] = arr[i++];
			}
		}
		while (i <= med) {
			auxArr[k++] = arr[i++];
		}
		while (j <= fin) {
			auxArr[k++] = arr[j++];
		}
		k = 0;
		for (size_t i = 0; i < (fin - ini) + 1; i++) {
			arr[i + ini] = auxArr[k++];
		}
		delete auxArr;
	}
	
};

int main1() {
	auto comp = [](int a, int b)->int {
		if (a>b){
			return 1;
		}
		if (b>a){
			return -1;
		}
		if (a==b){
			return 0;
		}
	};
	auto show = [](int a) {
		cout << a << " ";
	};
	auto comp3 = [](int a, int b)->bool {
		if (a < b) {
			return true;
		}
		else return false;
	};
	auto comp4 = [&](int& a)->void {
		a += 1;
	};
	bool(*ptr[1])(int, int);
	ptr[0] = comp3;
	Tree<int> tree=Tree<int>(comp,show);
	tree.insert(12);
	tree.insert(34);
	tree.insert(56);
	tree.insert(3);
	tree.insert(6);
	tree.insert(666);
	//int menor =tree.menorelemntos(comp3);
	//cout << menor;
	//tree.actualizar(comp4);
	tree.printInOrderByNivel(4);
	//cout<<(**tree.getN(3));
	auto hashfunction = [](int a)->int {
		return a;
	};
	auto comp5 = [](int a, int b)->bool {
		if (a>b){return true;}
	};
	auto intercambiar = [&](int& a, int& b)->void {
		a = b;
	};
	auto comp6 = [](int a, int b)->bool {
		if (a==(b-1)){return true;}
	};
	auto comp7 = [](int a)->bool {
		if (a>6&& a<9 ) { return true; }
	};
	HashTable<int> ht=HashTable<int>(14,hashfunction);
	ht.insert(3);
	ht.insert(5);
	ht.insert(5);
	ht.insert(5);
	ht.insert(5);
	ht.insert(8);
	ht.insert(1);
	ht.insert(6);
	//cout<<"numero de elementos menores iguales a 5 "
		//<<ht.cantidadByCondition(5, comp5);

	//ht.print();
	//cout << "\n\n";
	//ht.eliminarRango(3, 7);
	//ht.print();

	/*ht.print();
	cout << "\n\n";
	ht.reamplazarElement(6, intercambiar, comp6);
	ht.print();*/

	//cout << ht.sizevacios();

	cout << ht.elemntsCoincidentes(comp7);


	/*int menor =tree.menorelemntos(comp3);
	cout << menor;*/
	system("pause");
	return 0;
}


int main() {
	auto comp = [&](Nodo<Alumno*>* a,
		Nodo<Alumno*>* b)->int {
		if ((***a).getc1() > (***b).getc1()) { return 1; }
		else if ((***a).getc1() == (***b).getc1()) { return 0; }
		else return -1;
	};
	auto comp2 = [&](int* a,
		int* b)->int {
			if ((*a) > (*b)) { return 1; }
			else if ((*a) == (*b)) { return 0; }
			else return -1;
	};
	auto indexacol = [&](Tree1<int*>& tree, Nodo<Alumno*>* aux)->void {
		tree.insert((***aux).getc1());
		tree.insert((***aux).getc2());
		tree.insert((***aux).getc3());
		tree.insert((***aux).getc4());
	};
	auto comp3 = [&](Nodo<Alumno*>* n)->bool {
		if (*(***n).getc1()>=13&&
			*(***n).getc2() >= 13&&
			*(***n).getc3() >= 13&&
			*(***n).getc4() >= 13){
			return true;
		}
	};
	auto procesar = [&](int* var,float& suma,float& prom)->void {
		suma += std::pow(((*var) - prom), 2);
	};
	auto getiint = [&](int* a)->int  {
		return *a;
	};
	auto filtrado = [&](int* a,long long& mayor)->void {
		if (*a>mayor){mayor = *a;}
	};
	auto hashsfunction = [&](Alumno* al)->int {
		int suma = 0;
		string nombre = (*al).getnombre();
		for (int i = 0; i < nombre.length(); i++){
			suma += nombre[i];
		}
		return suma;
	};
	auto getint2 = [&](Alumno* al)->int {
		return *(*al).getc1();
	};
	auto comp5 = [&](Alumno* al1,Alumno* al2)->bool {
		if ((*al1).getnombre().compare((*al2).getnombre())>=0){
			return false;
		}else{
			return true;
		}
	};
	Tree1<Nodo<Alumno*>*> treefilas(comp);
	Tree1<int*> treecolumna1(comp2);
	
	ListaDoble<Alumno*> lista;
	lista.pushback( new Alumno(1, "Juan", 3, 12, 14, 17));
	lista.pushback( new Alumno(2, "Alejandro", 3, 18, 13, 14));
	lista.pushback( new Alumno(3, "Heber", 3, 17, 12, 16));
	lista.pushback( new Alumno(4, "Jaime", 2, 6, 15, 13));
	lista.pushback( new Alumno(5, "Agustin", 6, 14, 17, 15));
	lista.pushback( new Alumno(6, "Carlos", 6, 10, 16, 16));
	lista.pushback( new Alumno(7, "Silvia", 7, 18, 12, 13));
	lista.pushback( new Alumno(8, "Karla", 7, 16, 14, 15));

	lista.indexarfilas<Nodo<Alumno*>*>(treefilas);
	lista.indexarcolumn1<int*>(treecolumna1, indexacol);
	cout << "\n\n";
	cout<<"Alumnos aprobados en todos los examenes: "<<
		treefilas.cont_ByCondition(comp3)<<"\n\n";
	
	cout<<treecolumna1.desviacionestad(procesar, getiint)<<"\n";
	cout<<"Mayor nota del ciclo de la fila 1: "<<
		treecolumna1.mayor_bycondition(filtrado);

	int sizeHash=lista.calcularsize_hash(hashsfunction)+1;
	HashTable<Alumno*> ht = HashTable<Alumno*>(sizeHash, hashsfunction);
	lista.indexarfilas<Alumno*>(ht);
	cout << "\n\nModa del total de calificaciones: " <<
		ht.moda(getint2);
	lista.sort( comp5);

	lista.print();




	system("pause");
	return 0;
}

