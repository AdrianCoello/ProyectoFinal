#include<bits/stdc++.h>
using namespace std;

#define INF 30

vector<pair<int, int>> grafo[18] = {{{1, 9}, {2, 14}, {3, 10}, {4, 15}},
                                     {{5, 13}, {6, 11}, {7, 8}, {13, 10}},
                                     {{8, 12}, {9, 8}},
                                     {},
                                     {{10, 15}, {14, 10}, {16, 14}},
                                     {},
                                     {{11, 8}, {12, 11}},
                                     {},
                                     {},
                                     {{13, 15}},
                                     {},
                                     {},
                                     {},
                                     {},
                                     {{15, 9}, {16, 11}, {17, 8}},
                                     {{5, 10}},
                                     {{15, 11}, {17, 14}},
                                     {}};

string carreras[18] = {"UPB", "Administración de Empresas", "Comunicación", "Diseño Gráfico", "Ingeniería Civil", "Analítica Gerencial de Datos", "Ingeniería Comercial", "Psicología Organizacional", "Marketing y Logística", "Derecho", "Arquitectura", "Economía", "Ingeniería Financiera", "Relaciones y Negocios Internacionales", "Ingeniería Electromecánica", "Ingeniería de Sistemas Computacionales", "Ingeniería Industrial y de Sistemas", "Bioingeniería en Recursos Naturales"};

int visitados[18]; // marcamos si lo visitamos
int distancia[18]; // guardamos su distancias para ir comparando
int previo[18]; 

void dijkstra(int verticeInicial, int destination)
{
    for (int i = 0; i < 18; i++)
    { // todos empiezan en infinito para comparar
        distancia[i] = INF;
        previo[i] = -1;
    }
    memset(visitados, 0, sizeof(visitados)); // Todos los nodos como no visitado
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> colaPrioridad;  // ordena por prioridad según las distancias
    distancia[verticeInicial] = 0;
               // no recorre nada todavía
    colaPrioridad.push(make_pair(0, verticeInicial));

    while (!colaPrioridad.empty())
    {
        pair<int, int> verticeActual = colaPrioridad.top(); // para dar el valor del primer datp de colaprioridad
        colaPrioridad.pop();            // borra al que acabamos de recibir su valor
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
                    previo[verticeVecino]= vertice;
                    //
                    colaPrioridad.push(make_pair(distancia[verticeVecino], verticeVecino));
                }
            }
        }
    }
}

void print(int destination) {
    if (previo[destination] != -1) { // si aun poseo un vertice previo
        print(previo[destination]);  // recursivamente sigo explorando
    }
    cout << carreras[destination] << " -> "; // mostrar cada paso
}

int main()
{
    cout << "Bienvenido a esta guía para conocer las carreras de la UPB\nA continuación podrás observar la lista de carreras disponibles:\n";
    cout << "0: UPB\n1: Administración de Empresas\n2: Comunicación\n3: Diseño Gráfico\n4: Ingeniería Civil\n5: Analítica Gerencial de Datos\n";
    cout << "6: Ingeniería Comercial\n7: Psicología Organizacional\n8: Marketing y Logística\n9: Derecho\n10: Arquitectura\n";
    cout << "11: Economía\n12: Ingeniería Financiera\n13: Relaciones y Negocios Internacionales\n14: Ingeniería Electromecánica\n";
    cout << "15: Ingeniería de Sistemas Computacionales\n16: Ingeniería Industrial y de Sistemas\n17: Bioingeniería en Recursos Naturales\n";
    cout << "Ahora añade la carrera final o la carrera que te gustaría conocer: ";
    int destination;
    cin >> destination;
    destination=destination;
    dijkstra(0, destination);
    cout << "¡Excelente! Para llegar a " << carreras[destination] << ", tendrás que pasar por:\n";
    print(destination);
    cout << "FIN\n"; // indicar el final del camino
    cout << "Y tardarás aproximadamente " << distancia[destination] << " unidades en llegar. Gracias por visitarnos.\n";

    return 0;
}
