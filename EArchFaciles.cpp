#include<iostream>
#include<string>
#include<string.h>
#include<functional>
#include<vector>
#include"listaDoble.h"
#include<fstream>
#include<algorithm>
#include<functional>
using namespace std;
using namespace System;
class Empleado1
{
private:
	char nombre[10];
	unsigned int edad;
	double salario;
	string nombrestr;
public:
	Empleado1(unsigned int edad,double salario,string nombre)
		:edad(edad),salario(salario){
		nombrestr.resize(10);
		for (int i = 0; i < 10; i++)
		{
			if (i<nombre.size()){
				this->nombre[i] = nombre[i];
				this->nombrestr[i] = nombre[i];
			}
			else {
				this->nombre[i] = ' ';
				this->nombrestr[i] = ' ';
			}
			
		}
	}
	~Empleado1(){}
	friend ostream& operator<<(ostream& o, Empleado1 a) {
		o << "\nNombre: " << a.nombrestr << endl;
		return o;
	}
};
class Empleado2
{
private:
	char codigo[8];
	unsigned int edad;
	double salario;
	string codigostr;
public:
	Empleado2(unsigned int edad, double salario, string codigo)
		:edad(edad), salario(salario) {
		codigostr.resize(8);
		for (int i = 0; i < 8; i++)
		{
			if (i < codigo.size()) {
				this->codigo[i] = codigo[i];
				this->codigostr[i] = codigo[i];
			}
			else {
				this->codigo[i] = ' ';
				this->codigostr[i] = ' ';
			}
		}
	}
	~Empleado2() {}
	friend ostream& operator<<(ostream& o, Empleado2 a) {
		o << "\nCodigo: " << a.codigostr << endl;
		return o;
	}
};
class Ejercicio1
{
private:
	ListaDoble<Empleado1> listaE;
	int opcion;
	string nombre;
	unsigned int edad;
	double salario;
	ofstream arch;
public:
	Ejercicio1(){
		opcion = 1;
	}
	~Ejercicio1(){
		listaE.eraseAll();
	}
	void leer() {
		ifstream arch("empleados.txt");
		string line;
		while (arch>>line)
		{
			if (opcion){
				this->nombre = line;
				opcion = 2;
			}
			else if (opcion == 2) {
				edad = std::stoi(line);
				opcion = 3;
			}
			else if (opcion == 3) {
				salario = std::stoi(line);
				opcion = 1;
				listaE.pushBack(Empleado1(edad, salario, nombre));
			}
		}
		arch.close();
	}
	void print() {
		listaE.print();
	}
	//ejercicio #2
	void _recursividad(Nodo<Empleado1>*& aux, ofstream& arch) {
		if (aux==nullptr){return;}
		_recursividad(aux->next, arch);
		arch << aux->dato << "\n";
	}
	void escribirInvers() {
		Nodo<Empleado1>* aux = listaE.getbegin();
		arch.open("segundaescritura.txt");
		_recursividad(aux, arch);
		delete aux;
		arch.close();
	}
	
};
class Ejercicio3
{
private:
	ListaDoble<Empleado2> lista;
	int opcion;
	string codigo;
	unsigned int edad;
	double salario;
public:
	Ejercicio3(){
		opcion = 1;
	}
	~Ejercicio3(){
		lista.eraseAll();
	}
	void leer2() {
		ifstream arch("datosborrados.txt");
		string line;
		while (arch>>line)
		{
			if (opcion)
			{
				if (int(line.at(0))%2==0){
					arch >> line;
					arch >> line;
					continue;
				}
				for (int i = 0; i < 8; i++) {
					if ((int)line[i] >= 48 && (int)line[i] <= 57)
					{
						codigo[i] = line.at(i);
					}
				}
				opcion = 2;
			}
			else if (opcion == 2) {
				edad = std::stoi(line);
				opcion = 3;
			}
			else if (opcion == 3) {
				salario = std::stoi(line);
				lista.pushBack(Empleado2(edad, salario, codigo));
				opcion = 1;
			}
		}
		arch.close();
	}
	void print() {
		lista.print();
	}
	void escribir() {
		ofstream archi("datosborrados2.txt");
		archi.clear();
		string line2;
		Nodo<Empleado2>* aux = lista.getbegin();
		while (aux!=nullptr){
			archi << aux->dato << "\n";
			aux = aux->next;
		}
		delete aux;
		archi.close();
	}
};
class Ejercicio4
{
private:

public:
	Ejercicio4(){}
	~Ejercicio4(){}
	int buscar(string palabra) {
		ifstream arch("encontrado.txt");
		string line;
		bool bandera = 0;
		int cont = 1;
		while (arch>>line)
		{
			if (palabra==line)
			{
				bandera = true;
				break;
			}
			else {
				cont++;
			}
		}
		if (bandera==false)
		{
			return -1;
		}
		else
		{
			return cont;
		}
		arch.close();
	}
	int buscar2(string palabra) {
		ifstream arch("encontrado2.txt");
		ifstream arch2("encontrado2.txt");
		string line;
		bool bandera = 0;
		int cont = 1;
		int i = 0;
		getline(arch, line);
		function<bool(char a)> compar = [](char a)->bool {return a == ' '; };
		int espacios = std::count_if(line.begin(), line.end(), compar);
		while (arch2>>line){
			i++;
			if (line==palabra){
				bandera = true;
				break;
			}
			if (i>espacios){
				i = 0;
				getline(arch, line);
				espacios = std::count_if(line.begin(), line.end(), compar);
				cont++;
			}
		}
		if (bandera){
			return cont;
		}else{
			return -1;
		}
		arch.close();
		arch2.close();
	}
};
class Ejercicio5
{
private:
	ifstream archL;
	ofstream archE;
public:
	Ejercicio5(){}
	~Ejercicio5(){}

	void copiar(string archOrig, string archDestino) {
		archL.open(archOrig);
		archE.open(archDestino);
		string line;
		while (getline(archL,line))
		{
			archE << line << "\n";
		}
		archL.close();
		archE.close();
	}
	//ejercicio #6
	void convertidorA(string archOrig, string archDest) {
		archL.open(archOrig);
		ifstream archL2(archOrig);
		archE.open(archDest);
		string line;
		string aux;
		int i = 0;
		getline(archL, line);
		function<bool(char a)> compar = [](char a)->bool {return a == ' '; };
		int espacios = std::count_if(line.begin(), line.end(), compar);
		while (archL2 >>line)
		{
			i++;
			for (int i = 0; i < line.size(); i++)
			{
				if (line.at(i) == 'e' || line.at(i) == 'i' ||
					line.at(i) == 'o' || line.at(i) == 'u')
				{
					line.at(i) = 'a';
				}
				if (line.at(i) == 'E' || line.at(i) == 'I' ||
					line.at(i) == 'O' || line.at(i) == 'U')
				{
					line.at(i) = 'A';
				}
			}
			aux += line + " ";
			if (i>espacios){
				i = 0;
				getline(archL, line);
				espacios = std::count_if(line.begin(), line.end(), compar);
				archE << aux << "\n";
				aux.clear();
			}
		}
		archL.close();
		archL2.close();
		archE.close();
	}

};
class Frecuencia
{
private:
	int cantmayus;
	int cantminus;
public:
	Frecuencia(){
		cantmayus = 0;
		cantminus = 0;
	}
	~Frecuencia(){}
	void plusmayus() {
		cantmayus++;
	}
	void plusminus() {
		cantminus++;
	}
	int getcantminus() {
		return cantminus;
	}
	int getcantmayus() {
		return cantmayus;
	}
};
void contador(string line, size_t& cont_car,
	size_t& cont_espacios,
	size_t& cont_letras,
	size_t& cont_vocales,
	size_t& cont_mayusculas,
	size_t& cont_minusculas,
	size_t & cont_simbolos,
	function<void(vector<Frecuencia>& arr, char)> compar,vector<Frecuencia>& arr) {
	for (size_t i = 0; i < line.size(); i++) {
		compar(arr, line.at(i));
		if (line.at(i) == 'e' || line.at(i) == 'i' ||
			line.at(i) == 'o' || line.at(i) == 'u' || line.at(i) == 'a')
		{
			cont_vocales++;
		}
		if (line.at(i) == 'E' || line.at(i) == 'I' ||
			line.at(i) == 'O' || line.at(i) == 'U' || line.at(i) == 'A')
		{
			cont_vocales++;
		}
		if ((line.at(i) >= 65 && line.at(i) <= 90) ||
			(line.at(i) >= 97 && line.at(i) <= 122))
		{
			cont_letras++;
		}
		if ((line.at(i) >= 33 && line.at(i) <= 47) ||
			(line.at(i) >= 58 && line.at(i) <= 64))
		{
			cont_simbolos++;
		}
		if (line.at(i) == ' ')
		{
			cont_espacios++;
		}
		if (line.at(i) >= 65 && line.at(i) <= 90)
		{
			cont_mayusculas++;
		}
		if (line.at(i) >= 97 && line.at(i) <= 122)
		{
			cont_minusculas++;
		}
	}
}
class Ejercicio7
{
private:
	ifstream archL;
	ofstream archE;
	size_t cont_car;
	size_t cont_letras;
	size_t cont_espacios;
	size_t cont_simbolos;
	size_t cont_vocales;
	size_t cont_mayusculas;
	size_t cont_minusculas;
	vector<Frecuencia> arr;
	function<void(vector<Frecuencia>& arr, char)> compar;
public:
	Ejercicio7(function<void(vector<Frecuencia>& arr, char)> compar):compar(compar){
		cont_car = 0;
		cont_espacios = 0;
		cont_letras = 0;
		cont_simbolos = 0;
		cont_vocales = 0;
		cont_mayusculas = 0;
		cont_minusculas = 0;
		arr.resize(26);
	}
	~Ejercicio7(){}
	void estadisticas(function<bool(char a)> comparespacios) {
		archL.open("datos2.txt");
		ifstream archL2("datos2.txt");
		string line; 
		getline(archL2, line);
		int i = 0;
		
		int espacios = std::count_if(line.begin(),
			line.end(), comparespacios);
		while (archL>>line)
		{
			i++;
			contador(line,cont_car,cont_espacios);
			if (i++<espacios)
			{
				i = 0;

			}
		}
	}


};



int main() {
	
	Ejercicio4 eje4;
	cout<<eje4.buscar2("paraguas");
	
	Ejercicio5 eje5;
	eje5.convertidorA("archorigen.txt", "archivoDestino.txt");
	string line;
	getline(cin, line);
	return 0;
}

