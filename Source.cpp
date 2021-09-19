#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<functional>
#include<vector>
#include<fstream>
#include"listaSimple.h"
#include"carchivos.h"
#include<algorithm>
using namespace std;
using namespace System;

class Empleado
{
private:
	char nombre[10];
	int edad;
	double salario;
	char codigo[8];
public:
	Empleado(int edad, double salario, char nombre[])
		:edad(edad), salario(salario) {
		for (int i = 0; i < 10; i++)
		{
			if (((int)nombre[i] >= 65 && (int)nombre[i] <= 90) ||
				((int)nombre[i] >= 97 && (int)nombre[i] <= 122))
			{
				this->nombre[i] = nombre[i];
			}
		}
	}
	Empleado(int edad, double salario, char codigo[],int linesize) :edad(edad), salario(salario) {
		for (int i = 0; i < linesize; i++)
		{
			if ((int)codigo[i] >= 48 && (int)codigo[i] <= 57)
			{
				this->codigo[i] = codigo[i];
			}
		}
	}
	~Empleado(){}
	void getnombre() {
		for (int i = 0; i < 10; i++)
		{
			cout << nombre[i];
		}
	}
	friend ostream& operator<<(ostream& o, Empleado a) {
		o << a.codigo << "\n"<<a.edad<<"\n"<<a.salario;
		return o;
	}
};

class Ejercicio1
{
private:
	List<Empleado> arr;
	List<bool> opcion;
	char nombre[10];
	int edad;
	double salario;
	ofstream arch;
public:
	Ejercicio1(){
		opcion.pushBack(1);
		opcion.pushBack(0);
		opcion.pushBack(0);
	}
	~Ejercicio1(){
		arr.~List();
		opcion.~List();
	}
	void leer() {
		ifstream arch("empleados.txt");
		string line;
		while (arch>>line)
		{
			if (opcion[0]){
				for (int i = 0; i < line.size(); i++)
				{
					if (i>=10) 
					{
						break;
					}
					nombre[i] = line.at(i);
				}
				opcion[0] = false;
				opcion[1] = true;
			}else if (opcion[1]){
				edad = std::stoi(line);
				opcion[1] = false;
				opcion[2] = true;
			}else if (opcion[2]){
				salario = std::stod(line);
				arr.pushBack(Empleado( edad, salario,nombre));
				edad = 0;
				salario = 0;
				opcion[2] = false;
				opcion[0] = true;
			}
		}
		arch.close();
	}
	void print2() {
		arr.print();
	}
	//ejercicio #2
	void recursivo(Node<Empleado>*& aux,ofstream& arch) {
		if (aux == nullptr) {
			return;
		}
		recursivo(aux->next, arch);
		arch << aux->value << "\n";
	}
	void escribirInvers() {
		Node<Empleado>* aux = arr.inicio;
		arch.open("segundaEscritura.txt");
		recursivo(aux,arch);
		delete aux;
		arch.close();
	}
	void leer2() {
		ifstream arch("empleados.txt");
		string line;
		while (arch >> line)
		{
			if (opcion[0]) {
				for (int i = 0; i < line.size(); i++)
				{
					if (i >= 10)
					{
						break;
					}
					nombre[i] = line.at(i);
				}
				opcion[0] = false;
				opcion[1] = true;
			}
			else if (opcion[1]) {
				edad = std::stoi(line);
				opcion[1] = false;
				opcion[2] = true;
			}
			else if (opcion[2]) {
				salario = std::stod(line);
				arr.pushBack(Empleado(edad, salario, nombre));
				edad = 0;
				salario = 0;
				opcion[2] = false;
				opcion[0] = true;
			}
		}
		arch.close();
	}
};
class Ejercicio3
{
private:
	List<Empleado> arr;
	List<bool> opcion;
	char codigo[10];
	int edad;
	double salario;
	ofstream arch;
public:
	Ejercicio3() {
		opcion.pushBack(1);
		opcion.pushBack(0);
		opcion.pushBack(0);
	}
	~Ejercicio3() {
		arr.~List();
		opcion.~List();
	}
	void leer2() {
		ifstream arch("datosborrados.txt");
		string line;
		while (arch >> line){
			if (opcion[0]) {
				if (int(line.at(0))%2==0){
					arch >> line;
					arch >> line;
					continue;
				}
				for (int i = 0; i < line.size(); i++){
					if (i >= 8){break;}
					if ((int)line[i] >= 48 && (int)line[i] <= 57)
					{
						codigo[i] = line.at(i);
					}
				}
				opcion[0] = false;
				opcion[1] = true;
			}else if (opcion[1]) {
				edad = std::stoi(line);
				opcion[1] = false;
				opcion[2] = true;
			}else if (opcion[2]) {
				salario = std::stod(line);
				arr.pushBack(Empleado(edad, salario, codigo,line.size()));
				edad = 0;
				salario = 0;
				opcion[2] = false;
				opcion[0] = true;
			}
		}
		arch.close();
	}
	void print2() {
		arr.print();
	}
	void escribir() {
		ofstream archi("datosborrados2.txt");
		archi.clear();
		string line2;
		Node<Empleado>* aux = arr.inicio;
		while (aux!=nullptr){
			archi << aux->value << "\n";
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
		ifstream arch("encontrardato.txt");
		string line;
		bool bandera=0;
		int cont = 1;
		while (arch >> line){
			if (palabra == line) {
				bandera = true;
				break;
			}else{
				cont++;
			}
		}
		if (bandera==false){
			return -1;
		}else{
			return cont;
		}
		arch.close();
	}
	int buscar2(string palabra) {
		ifstream arch("encontrardato2.txt");
		string line;
		bool bandera = 0;
		int cont = 1;
		string delimitador = " ";
		while (getline(arch, line)){
			size_t pos = 0;
			while(pos<line.size()){
				pos = line.find(delimitador);
				string line2= line.substr(0, line.find(delimitador));
				if (palabra == line2) {
					bandera = true;
					break;
				}
				line.erase(0,pos+delimitador.length());
			}
			if (bandera){
				return cont++;
			}
			cont++;
		}
		if (bandera == false)
		{
			return -1;
		}
		else
		{
			return cont;
		}
		arch.close();
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
	void hacercopia(string archOrig, string archDest) {
		ifstream archL(archOrig);
		ofstream archE(archDest);
		string line;
		string delimitador = " ";
		while (getline(archL,line))
		{
			archE << line<<"\n";
		}
		archL.close();
		archE.close();
	}
	//ejercicio #6
	void hacercopiaRARA(string archOrig, string archDest) {
		archL.open(archOrig);
		archE.open(archDest);
		string line;
		string delimitador = " ";
		
		while (getline(archL, line))
		{
			string auxline3="";
			size_t pos = 0;
			while ( line.size()>0) {
				//separador de espacios SOLO PALABRAS
				pos = line.find(delimitador);
				string line2 = line.substr(0, pos);
				for (size_t i = 0; i < line2.size(); i++)
				{
					if (line2.at(i)=='e'|| line2.at(i) == 'i'||
						line2.at(i) == 'o'|| line2.at(i) == 'u')
					{
						line2.at(i) = 'a';
					}
					if (line2.at(i) == 'E' || line2.at(i) == 'I' ||
						line2.at(i) == 'O' || line2.at(i) == 'U')
					{
						line2.at(i) = 'A';
					}
				}
				auxline3 += line2+" ";
				if (pos > line.size())
				{
					pos = line.size();
				}
				line.erase(0, pos + delimitador.length());
			}
			archE << auxline3 << "\n";
		}
		archL.close();
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
	function<void(vector<Frecuencia>&, char)> compar;
public:
	Ejercicio7(function<void(vector<Frecuencia>&,char)> compar):compar(compar){
		cont_car = 0;
		cont_letras = 0;
		cont_espacios = 0;
		cont_simbolos = 0;
		cont_vocales = 0;
		cont_mayusculas = 0;
		cont_minusculas = 0;
		arr.resize(26);
	}
	~Ejercicio7(){}
	void estadistica() {
		archL.open("DATOS2.txt");
		string line;
		string delimitador = " ";
		while (getline(archL, line)){
			string auxline3 = "";
			int pos = 0;
			while (line.size()>0) {
				//INGRESA CON ESPACIOS 
				pos = line.find(delimitador);
				if (pos<0)
				{
					pos = line.size();
				}
				string line2 = line.substr(0, pos+ delimitador.length());
				for (size_t i = 0; i < line2.size(); i++){
					compar(arr, line2.at(i));
					if (line2.at(i) == 'e' || line2.at(i) == 'i' ||
						line2.at(i) == 'o' || line2.at(i) == 'u'||line2.at(i)=='a')
					{
						cont_vocales++;
					}
					if (line2.at(i) == 'E' || line2.at(i) == 'I' ||
						line2.at(i) == 'O' || line2.at(i) == 'U'||line2.at(i)=='A')
					{
						cont_vocales++;
					}
					if ((line2.at(i)>=65&&line2.at(i)<=90)||
						(line2.at(i) >= 97 && line2.at(i) <= 122))
					{
						cont_letras++;
					}
					if ((line2.at(i) >= 33 && line2.at(i) <= 47) ||
						(line2.at(i) >= 58 && line2.at(i) <= 64))
					{
						cont_simbolos++;
					}
					if (line2.at(i)==' ')
					{
						cont_espacios++;
					}
					if (line2.at(i) >= 65 && line2.at(i) <= 90)
					{
						cont_mayusculas++;
					}
					if (line2.at(i) >= 97 && line2.at(i) <= 122)
					{
						cont_minusculas++;
					}
				}
				if (pos > line.size()){
					pos = line.size();
				}
				line.erase(0, pos + delimitador.length());
			}
		}
		cont_car += cont_letras + cont_simbolos + cont_espacios;
		archL.close();
		archE.close();
	}
	void escribirestat() {
		ofstream arch("datos.txt.estat.txt");
		string line;
		arch << "---------Estadisticas----------\n";
		arch << "Cantidad de Caracteres: " << cont_car<<"\n";
		arch << "Cantidad de Letras: " << cont_letras << "\n";
		arch << "Cantidad de Espacios: " << cont_espacios << "\n";
		arch << "Cantidad de Simbolos: " << cont_simbolos << "\n";
		arch << "Cantidad de Vocales: " << cont_vocales << "\n";
		arch << "Cantidad de Mayusculas: " << cont_mayusculas << "\n";
		arch << "Cantidad de Minusculas: " << cont_minusculas << "\n";
		arch << "\n------- Frecuencias de Letras-------\n";
		for (size_t i = 0; i < 26; i++)
		{
			arch << char(97 + i) << ": \n";
			arch << "\tCantidad de Mayusculas " <<
				arr.at(i).getcantmayus() << "\n";
			arch << "\tCantidad de Minusculas " <<
				arr.at(i).getcantminus() << "\n";
			arch << "\n";
		}
	}
};
class Ejercicio9
{
private:
	List<string>lista;
public:
	Ejercicio9(){}
	~Ejercicio9(){}
	void buscadorgoogle(string palabra) {
		if (palabra.size() <= 0) { return; }
		ifstream arch("buscarpala.txt");
		string line;
		while (arch>>line){
			string line2 = line.substr(0, palabra.size());
			if (line2==palabra){
				lista.pushBack(line);
			}
		}
	}
	void printlist() {
		lista.print();
	}
};
class Alumno
{
private:
	unsigned int edad;
	int promedio;
	string codigo;
	string nombre;
public:
	Alumno(unsigned int edad,int promedio,string codigo,string nombre)
		:edad(edad),promedio(promedio),codigo(codigo),nombre(nombre){}
	~Alumno(){}
	unsigned int getedad() {
		return edad;
	}
	int getpromedio() {
		return promedio;
	}
	string getcodigo() {
		return codigo;
	}
	string getnombre() {
		return nombre;
	}
	friend ostream& operator<<(ostream& o, Alumno a) {
		o << a.codigo;
		return o;
	}
};
class Ejercicio10
{
private:
	ifstream arch;
	string line;
	vector<bool>opciones;
	List<Alumno>listal;
	unsigned int edad;
	int promedio;
	string codigo;
	string nombre;
public:
	Ejercicio10(){
		opciones.push_back(1);
		opciones.push_back(0);
		opciones.push_back(0);
		opciones.push_back(0);
	}
	~Ejercicio10(){}
	void leerAlumnos() {
		arch.open("archivosalumnos.txt");
		while (arch>>line)
		{
			if (opciones[0]){
				edad = std::stoi(line);
				opciones[0] = 0;
				opciones[1] = 1;
				continue;
			}
			else if (opciones[1]) {
				promedio = std::stoi(line);
				opciones[1] = 0;
				opciones[2] = 1;
				continue;
			}
			else if (opciones[2]) {
				codigo =line;
				opciones[2] = 0;
				opciones[3] = 1;
				continue;
			}
			else if (opciones[3]) {
				nombre = line;
				opciones[3] = 0;
				opciones[0] = 1;
				listal.pushBack(Alumno(edad, promedio, codigo, nombre));
				continue;
			}
		}
	}
	void printlist() {
		listal.print();
	}
};



int main() {
	
	/*Ejercicio1 eje;
	eje.leer();
	eje.print2();
	eje.escribirInvers();*/

	/*Ejercicio3 eje3;
	eje3.leer2();
	eje3.print2();
	eje3.escribir();*/

	//Ejercicio4 eje;
	//cout<<eje.buscar("alo");
	//cout<<"\n";
	//cout << eje.buscar2("holis");
	
	/*Ejercicio5 eje5;
	eje5.hacercopia("archOrigen.txt", "archDestino.txt");
	eje5.hacercopiaRARA("archOrigen2.txt", "archDestino2.txt");*/

	//Ejercicio7 eje7;
	//eje7.estadistica();
	
	//Ejercicio7 eje7;
	//eje7.estadistica();

	//CArchivos arch;

	//function<void(vector<Frecuencia>&,char)> comp= [](vector<Frecuencia>& arr, char l) {
	//	for (size_t i = 0; i < 26; i++)
	//	{
	//		if (char(65+i)==l){
	//			arr.at(i).plusmayus();
	//			break;
	//		}
	//		if (char(97 + i) == l){
	//			arr.at(i).plusminus();
	//			break;
	//		}
	//	}
	//};
	//Ejercicio7 eje7(comp);
	//eje7.estadistica();
	//eje7.escribirestat();


	/*string palabra;
	cout << "Ingresa la palabra a buscar: "<<endl;
	cin >> palabra;
	palabra.clear();
	Ejercicio9 eje9;
	eje9.buscadorgoogle(palabra);
	eje9.printlist();*/


	//Ejercicio10 eje10;
	//eje10.leerAlumnos();
	//eje10.printlist();

	string line;
	getline(cin, line);
	return 0;
}




