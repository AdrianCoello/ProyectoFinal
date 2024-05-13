#include <bits/stdc++.h>
#define INF 100000010
using namespace std;

vector<pair<int, int>> grafo[18] = {
    {{9, 1}, {14, 2}, {10, 3}, {15, 4}},
    {{13, 5}, {11, 6}, {8, 7}, {10, 13}},
    {{12, 8}, {8, 9}},
    {},
    {{15, 10}, {10, 14}, {14, 16}},
    {},
    {{8, 11}, {11, 12}},
    {},
    {},
    {{15, 13}},
    {},
    {},
    {},
    {},
    {{9, 15}, {11, 16}, {8, 17}},
    {{10, 5}},
    {{11, 15}, {14, 17}},
    {}
};

string carreras[18] = {
    "UPB", "Administración de Empresas", "Comunicación", "Diseño Gráfico", "Ingeniería Civil", "Analítica Gerencial de Datos",
    "Ingeniería Comercial", "Psicología Organizacional", "Marketing y Logística", "Derecho", "Arquitectura", "Economía",
    "Ingeniería Financiera", "Relaciones y Negocios Internacionales", "Ingeniería Electromecánica", "Ingeniería de Sistemas Computacionales",
    "Ingeniería Industrial y de Sistemas", "Bioingeniería en Recursos Naturales"
};

void dijkstra(int nodoInicial, vector<int>& distancia, vector<int>& previo) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> colaPrioridad;
    distancia.assign(18, INF);
    previo.assign(18, -1);
    distancia[nodoInicial] = 0;
    colaPrioridad.push({0, nodoInicial});

    while (!colaPrioridad.empty()) {
        int nodoActual = colaPrioridad.top().second;
        int distanciaActual = colaPrioridad.top().first;
        colaPrioridad.pop();

        for (const auto& vecino : grafo[nodoActual]) {
            int nodoVecino = vecino.second;
            int pesoVecino = vecino.first;

            if (distanciaActual + pesoVecino < distancia[nodoVecino]) {
                distancia[nodoVecino] = distanciaActual + pesoVecino;
                previo[nodoVecino] = nodoActual;
                colaPrioridad.push({distancia[nodoVecino], nodoVecino});
            }
        }
    }
}

void print(int nodoDestino, const vector<int>& distancia, const vector<int>& previo) {
    if (distancia[nodoDestino] == INF) {
        cout << "No hay camino desde " << carreras[0] << " hasta " << carreras[nodoDestino] << endl;
    } else {
        vector<int> nodosCamino;
        for (int i = nodoDestino; i != -1; i = previo[i]) {
            nodosCamino.push_back(i);
        }

        cout << "La distancia mínima desde " << carreras[0] << " hasta " << carreras[nodoDestino] << " es: " << distancia[nodoDestino] << endl;
        cout << "Camino: ";
        for (int i = nodosCamino.size() - 1; i >= 0; --i) {
            cout << carreras[nodosCamino[i]];
            if (i > 0) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

int main() {
    int nodoDestino;
    cout << "Carreras universitarias:\n";
    for (int i = 0; i < 18; i++) {
        cout << i << ": " << carreras[i] << endl;
    }
    cout << "Ingrese el número del nodo correspondiente a la carrera a la que desea calcular la distancia mínima desde UPB (carrera inicial): ";
    cin >> nodoDestino;

    vector<int> distancia(18), previo(18);
    dijkstra(0, distancia, previo); // Nodo inicial es 0 (UPB)

    print(nodoDestino, distancia, previo);

    return 0;
}
