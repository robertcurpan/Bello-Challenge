#include "Bello.h"

using namespace std;

#define inf INT_MAX


void Graph::adaugaMuchie(int from, int to)
{
	// fiind un graf neorientat, "inseram" muchia in ambele sensuri
	listaAdiacenta[from].push_back(to);
	listaAdiacenta[to].push_back(from);
}

void Graph::construiesteGraf(const char *caleFisier)
{
	ifstream fin(caleFisier);

	if (fin.is_open())
	{
		int nrNoduri;
		fin >> V;
		fin >> s >> d;
		E = 0;
		listaAdiacenta = new vector<int>[V];
		dist = new int[V];
		prev = new int[V];

		while (fin)
		{
			int f, t;
			fin >> f >> t;
			adaugaMuchie(f, t);
			++E;
		}
	}
	else
		cout << "Fisierul nu s-a deschis!" << endl;

	fin.close();

}


void Graph::afisareListaAdiacenta()
{
	for (int i = 0; i < V; i++)
	{
		cout << "Nod " << i << ": ";
		for (int j = 0; j < listaAdiacenta[i].size(); j++)
			cout << listaAdiacenta[i][j] << " ";

		cout << endl;
	}
}


bool Graph::bello(int sursa, int destinatie)
{
	for (int i = 0; i < V; i++)
	{
		dist[i] = inf;
		prev[i] = -1;
	}
	dist[sursa] = 0;   // distanta de la nodul sursa la el insusi este 0

	vector<bool> visited(V, false);
	list<int> q;  // coada care ne va ajuta la aplicarea BFS
	q.push_back(sursa);

	while (!q.empty())
	{
		int nod = q.front();
		q.pop_front();
		visited[nod] = true;

		for (int i = 0; i < listaAdiacenta[nod].size(); i++)
		{
			int vecin = listaAdiacenta[nod][i];
			if (!visited[vecin])
			{
				visited[vecin] = true;
				dist[vecin] = dist[nod] + 1;
				prev[vecin] = nod;
				q.push_back(vecin);

				if (listaAdiacenta[nod][i] == destinatie) // am gasit distanta minima pana la destinatie
					return true;
			}
		}
	}

	return false;
}


int Graph::lengthOfShortestPath()
{
	bool ok = bello(s, d);

	if (ok)
	{
		int nod = d;
		vector<int> shortestPath;
		shortestPath.push_back(nod);
		while (prev[nod] != -1)
		{
			shortestPath.push_back(prev[nod]);
			nod = prev[nod];
		}

		cout << "Calea cea mai scurta de la nodul sursa (" << s << ") la cel destinatie (" << d << ") este: ";
		for (int i = shortestPath.size() - 1; i > 0; i--)
			cout << shortestPath[i] << " -> ";
		cout << shortestPath[0] << endl;

		return dist[d];
	}
	else
	{
		cout << "Nu exista un drum de la sursa la destinatie!" << endl;
		return -1;
	}
	
}