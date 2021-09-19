#include<iostream>
#include<string>
#include<string.h>
#include<functional>
#include<vector>
#include<list>
#include<fstream>
#include<algorithm>
#include"ListaDobleCompleta.h"
#include<stack>
using namespace std;
using namespace System;

class Empleado1
{
private:
	char nombre[10];
	string nombrestr;
	unsigned int edad;
	double salario;
public:
	Empleado1(unsigned int edad,double salario,string nombre):edad(edad),salario(salario){
		nombrestr.resize(10);
		for (size_t i = 0; i < 10; i++){
			if (nombre.size()>i){
				this->nombre[i] = nombre[i];
				this->nombrestr[i]= nombre[i];
			}else{
				this->nombre[i] = ' ';
				this->nombrestr[i] = ' ';
			}
		}
		
	}
	
	~Empleado1(){}
	friend ostream& operator<<(ostream& o, Empleado1 a) {
		o << "\nNombre: " << a.nombrestr <<endl;
		return o;
	}
};
class Ejercicio1
{
private:
	list<Empleado1>listaE;
	int opcion;
	string nombre;
	unsigned int edad;
	double salario;
	void _recursiEscribir(ofstream& arch,list<Empleado1> lista1) {
		lista1.pop_front();
		if (lista1.empty()){return;}
		_recursiEscribir(arch,lista1);
		arch << lista1.front();
	}
public:
	Ejercicio1(){
		opcion = 1;
	}
	~Ejercicio1(){
		listaE.clear();
	}
	list<Empleado1>& getlista() {
		return listaE;
	}
	void leerEmpleados() {
		ifstream arch("leerEmpleados.txt");
		string line;
		while (arch>>line){
			if (opcion==1){
				nombre = line;
				nombre.substr(0, 11);
				opcion = 2;
			}
			else if (opcion == 2){
				edad = std::stoi(line);
				opcion = 3;
			}
			else if (opcion == 3){
				salario = std::stoi(line);
				listaE.push_back(Empleado1(edad, salario, nombre));
				opcion = 1;
			}
		}
		arch.close();
	}
	void print(list<Empleado1> lista){
		while (!lista.empty()){
			cout << lista.front();
			lista.pop_front();
		}
	}
	void escribirEmpleados(list<Empleado1> lista){
		ofstream arch("escribirEmpleados.txt");
		string line;
		while (!lista.empty()){
			arch << lista.front();
			lista.pop_front();
		}
	}
	void recursiMostrar(list<Empleado1>lista){
		if (lista.empty()){return;}
		cout << lista.front();
		lista.pop_front();
		recursiMostrar(lista);
	}
	void recursiRellenar(list<Empleado1> lista, list<Empleado1> listaERInver){
		if (lista.empty()) { return; }
		lista.pop_front();
		recursiMostrar(lista);
		listaERInver.push_back(lista.front());
	}
	void recursiEscribir(list<Empleado1>lista){
		ofstream arch("escribirRecursiEmpleados.txt");
		_recursiEscribir(arch, lista);
	}
	list<Empleado1>& filtrar(function<bool(Empleado1)> comp,list<Empleado1>lista){
		list<Empleado1> listaFiltr;
		while (!lista.empty()){
			if (comp(lista.front())){
				listaFiltr.push_back(lista.front());
			}
			lista.pop_front();
		}
		return listaFiltr;
	}
};
bool llaves(string line) {
	return line == "{" || line == "}";
}
bool parenteshis(string line) {
	return line == "(" || line == ")";
}
bool corchetes(string line) {
	return line == "[" || line == "]";
}
bool apertura(string line) {
	return line == "(" || line == "{" || line == "[";
}
bool cerrada(string line) {
	return line == ")" || line == "}" || line == "]";
}
void verificarlector() {
	ifstream arch("lectordatos.txt");
	string line;
	while (arch>>line)
	{
		for (size_t i = 0; i < line.size(); i++)
		{
			if (apertura(std::to_string(line.at(i))))
			{

			}
		}
	}
}

class complex {
private:
	double re;
	double im;
public:
	complex(double real = 0.0, double imag = 0.0) : re(real), im(imag) {}
	friend ostream& operator<<(ostream& os, complex& c) {
		os << c.re << std::showpos << c.im;
		return os;
	}
};



int main() {
	/*ListaDoble<int> lista;
	lista.pushBack(1);
	lista.pushBack(2);
	lista.pushBack(3);
	lista.pushBack(5);
	lista.print();
	lista.eraseAt(0);
	lista.popBack();
	lista.print();
	lista.popFront();
	lista.print();
	lista.insertAt(23, 0);
	lista.insertAt(43, 3);
	lista.insertAt(44, 3456);
	lista.print();
	lista.modifyAt(234, 2);
	lista.pushBack(4546);
	lista.pushBack(4578);
	lista.pushFront(9877);
	lista.print();
	lista.eraseAt(3);
	lista.print();
	lista.eraseAll();
	lista.pushBack(456);
	lista.pushFront(66577);
	lista.pushFront(657);
	lista.pushFront(67);
	lista.pushFront(77);
	lista.pushFront(6);
	lista.print();
	cout << "dato: " << lista.getDato(3) << "\n";
	cout<<lista[4]<<"\n";
	ListaDoble<int>listinver;
	lista.InvertRecursi(listinver);
	listinver.print();
	lista = listinver;
	lista.print();
	lista.rotar1(8);
	lista.print();

	lista.recursiRotar2(4);
	lista.print();

	lista.modifyAt(777, 2);
	lista.print();

	ListaDoble<int>::Iterator it = lista.Ibegin_N();
	cout << "\nIteradores en Listas: \n";
	for (it;it!=lista.Iend_N();++it){
		cout << (*it) << "\n";
	}*/

	/*int v = 5;
	int* p;
	int** pp;
	p = &v;
	pp = &p;
	cout << v << " " << p << " " << pp;*/

	Ejercicio1 eje1;
	eje1.leerEmpleados();
	eje1.print(eje1.getlista());
	eje1.escribirEmpleados(eje1.getlista());
	eje1.recursiMostrar(eje1.getlista());
	list<Empleado1> lista;
	eje1.recursiRellenar(eje1.getlista(),lista);
	eje1.print(lista);

	string line;
	getline(cin, line);
	return 0;
}

