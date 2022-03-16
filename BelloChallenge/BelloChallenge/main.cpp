#include "Bello.h"

using namespace std;


int main()
{
	const char *caleFisier = "test3.txt";

	Graph *g = new Graph();
	g->construiesteGraf(caleFisier);
	cout << "Lungimea celui mai scurt drum de la sursa la destinatie este: " << g->lengthOfShortestPath() << endl;

	return 0;
}