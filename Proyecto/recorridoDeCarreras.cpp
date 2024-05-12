#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define INF 100000010

using namespace std;

int visitados[100000]; // marcamos si lo visitamos
int distancia[100000]; // guardamos su distancias para ir comparando
int previo[1000000];

void dijkstra(int verticeInicial)
{
    for (int i = 0; i < 100000; i++)
    { // todos empiezan en infinito para comparar
        distancia[i] = INF;
        previo[i] = -1;
    }
    memset(visitados, 0, sizeof(visitados)); // Todos los nodos como no visitado
    multiset<pair<int, int>> colaPrioridad;  // ordena por prioridad según las distancias
    distancia[verticeInicial] = 0;
    // no recorre nada todavía
    colaPrioridad.insert(make_pair(0, verticeInicial));

    while (!colaPrioridad.empty())
    {
        pair<int, int> verticeActual = colaPrioridad.begin(); // para dar el valor del primer datp de colaprioridad
        colaPrioridad.erase(colaPrioridad.begin());            // borra al que acabamos de recibir su valor
        int vertice = verticeActual.second;                    // el nodo de donde esta viniendo
        int peso = verticeActual.first;                        // distancia
        if (!visitados[vertice])
        {                              // no pasamos por este antes
            visitados[vertice] = true; // ya lo visitamos
            for (int i = 0; i < grafo[vertice].size(); i++)
            {
                int verticeVecino = grafo[vertice][i].second;
                int pesoVecino = grafo[vertice][i].first;
                if (distancia[verticeVecino] > distancia[vertice] + pesoVecino)
                { // Relajacion
                    distancia[verticeVecino] = distancia[vertice] + pesoVecino;
                    //
                    previo[verticeVecino] = vertice;
                    //
                    colaPrioridad.insert(make_pair(distancia[verticeVecino], verticeVecino));
                }
            }
        }
    }
}

void print(int destination)
{
    if (previo[destination] != -1) //si aun poseo un vertice previo
        print(previo[destination]); //recursivamente sigo explorando
    cout << info[destination];     //terminada la recursion imprimo los vertices recorridos
}

int main()
{
    // Inicializar la semilla para el generador de números aleatorios
    srand(time(0));

    // Crear una matriz de adyacencia de 18x18 con pesos aleatorios entre 7 y 15
    vector<vector<int>> grafo(18, vector<int>(18));
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 18; ++j) {
            // Asignar un peso aleatorio entre 7 y 15 (ambos inclusive)
            int peso = rand() % 5 + 7;
            grafo[i][j] = peso;
        }
    }

    cout <<"agregar el texto aqui ";
    int source, destination;
    cin >> source;
    source = source;
    cout << "Ahora añade el último lugar que desearías visitar o el lugar que no te puedes perder: ";
    cin >> destination;
    destination = destination;
    dijkstra(source);
    cout << distancia[destination] << endl;
    print(destination);
}