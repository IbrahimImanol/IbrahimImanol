#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<string.h>
#include<functional>

using namespace std;
using namespace System;

size_t cont(string line, function<bool(char a)> comparar) {
	size_t cont = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (comparar(line.at(i)))
		{
			++cont;
		}
	}
	return cont;
}
void leerenMtraiz(vector<vector<int>>& m) {
	ifstream arch("datos_matriz.txt");
	ifstream arch1("datos_matriz.txt");
	string line;
	std::getline(arch, line);
	vector<int>arraux;
	int size = std::count_if(line.begin(), line.end(), [](char a)->bool {return a == ' '; });
	int i = 0;
	while (arch1 >>line)
	{
		i++;
		arraux.push_back(std::stoi(line));
		if (i>size)
		{
			i = 0;
			m.push_back(arraux);
			arraux.clear();
		}
	}
}
void conveertmatriz(vector<vector<int>>& m, int filas, int columnas) {
	if (filas*columnas!=m.size()*m.at(0).size())
	{
		cout << "No se puede convertir la matriz sorry\n";
		return;
	}
	else
	{
		vector<int> arraux;
		for (int i = 0; i < m.size(); i++)
		{
			for (int j = 0; j < m.at(0).size(); j++)
			{
				arraux.push_back(m[i][j]);
			}
		}
		m.clear();
		vector<int> arraux2;
		int cont = 0;
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				arraux2.push_back(arraux.at(cont++));
			}
			m.push_back(arraux2);
			arraux2.clear();
		}
	}
}
void print(vector<vector<int>> m) {
	for (size_t i = 0; i < m.size(); i++)
	{
		for (size_t j = 0; j < m.at(0).size(); j++)
		{
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
}
void escribirMatrz(string nombrearch,vector<vector<int>> m) {
	ofstream archE(nombrearch);
	for (size_t i = 0; i < m.size(); i++)
	{
		for (size_t j = 0; j < m.at(0).size(); j++)
		{
			archE << m[i][j] << " ";
		}
		archE << "\n";
	}
}
void leerEnListas(list<int>& lista1,list<int>&lista2) {
	ifstream archL("LeerenListas.txt");
	ifstream archL1("LeerenListas.txt");
	string line1;
	getline(archL, line1);
	int size = cont(line1, [](char a)->bool {return a == ' '; });
	int auxline = 0;
	int i = 0;
	list<int> listaAcum;
	while (archL1>>line1)
	{
		i++;
		listaAcum.push_back(std::stoi(line1));
		if (i>size)
		{
			i = 0;
			if (auxline==0)
			{
				lista1 = listaAcum;
				auxline++;
				listaAcum.clear();
			}
			else
			{
				lista2 = listaAcum;
				auxline++;
				listaAcum.clear();
			}
		}
	}
}
void print(list<int> lista){
	if (lista.empty()){return;}
	cout << lista.front() << " ";
	lista.pop_front();
	print(lista);
}
void convertirListas(list<int>& lista1, list<int>&lista2,
	list<int>&lista3,function<bool(int a,int b)>comparar) {
	
	while (!lista1.empty()&&!lista2.empty()){
		if (comparar(lista1.front(),lista2.front()))
		{
			lista3.push_back(lista2.front());
			lista2.pop_front();
		}
		else {
			lista3.push_back(lista1.front());
			lista1.pop_front();
		}
	}
	while (!lista1.empty())
	{
		lista3.push_back(lista1.front());
		lista1.pop_front();
	}
	while (!lista2.empty())
	{
		lista3.push_back(lista2.front());
		lista2.pop_front();
	}
}
void guardarLista(list<int> lista) {
	ofstream archE("resultadoListas.txt");
	while (!lista.empty())
	{
		archE << lista.front() << " ";
		lista.pop_front();
	}
}
int main() {
	/*vector<vector<int>> m;

	leerenMtraiz(m);
	conveertmatriz(m, 4, 2);
	print(m);
	escribirMatrz("matrizescribida.txt", m);*/
	list<int> lista1;
	list<int> lista2;
	list<int> listaconver;
	leerEnListas(lista1, lista2);
	cout << "Lista 1: ";
	print(lista1);
	cout << "\n";
	cout << "Lista 2: ";
	print(lista2);
	cout << "\n";
	function<bool(int, int)> filtrador = [](int a, int b)->bool {return a < b; };
	convertirListas(lista1, lista2, listaconver, filtrador);
	cout << "Lista 3: ";
	print(listaconver);
	guardarLista(listaconver);
	string line;
	getline(cin, line);
	return 0;
}
