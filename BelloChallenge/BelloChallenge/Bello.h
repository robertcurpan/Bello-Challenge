#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <fstream>

using namespace std;


class Graph
{
private:
	int V, E;
	vector<int> *listaAdiacenta;
	int *dist;
	int *prev;
	int s, d;
public:
	void adaugaMuchie(int from, int to);
	void construiesteGraf(const char *caleFisier);
	void afisareListaAdiacenta();
	bool bello(int sursa, int destinatie);        // indica daca exista un drum de la sursa la destinatie si populeaza vectorii dist si prev
	int lengthOfShortestPath();
};
