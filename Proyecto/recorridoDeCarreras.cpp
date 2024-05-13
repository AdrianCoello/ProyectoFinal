#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int>& d, vector<int>& p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main() {
    int n = 18; // número de vértices
    adj.resize(n);

    // Añade las aristas aquí. Por ejemplo, adj[a].push_back({b, w}); donde a y b son dos vértices y w es el peso entre ellos.
    adj[0] = {{1, 9}, {2, 14}, {3, 10}, {4, 15}};
    adj[1] = {{5, 13}, {6, 11}, {7, 8}, {13, 10}};
    adj[2] = {{8, 12}, {9, 8}};
    adj[4] = {{10, 15}, {14, 10}, {16, 14}};
    adj[6] = {{11, 8}, {12, 11}};
    adj[9] = {{13, 15}};
    adj[14] = {{15, 9}, {16, 11}, {17, 8}};
    adj[15] = {{5, 10}};
    adj[16] = {{15, 11}, {17, 14}};

    vector<int> d, p;
    int target;
    cout << "Ingresa el número de la carrera a la que quieres llegar: ";
    cin >> target;
    dijkstra(0, d, p); // 0 es el vértice inicial (UPB)

    // Imprime la distancia más corta a la carrera que elijas.
    cout << "La distancia más corta a la carrera " << target << " es: " << d[target] << endl;

    return 0;
}

