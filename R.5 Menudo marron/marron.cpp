
/*@ <authors>
 *
 * Daniel Fernandez Ortiz: TAIS 21
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <limits>
#include"Grafo.h"
using namespace std;
const int INF = std::numeric_limits<int>::max();


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class solution {
private:
    Grafo g;
    int cheaperPrice;
    void query(int s, vector<int>const&supermarkets) {
        queue<int>q;
        vector<bool>visited(g.V(), false);
        q.push(s);
        cheaperPrice = min(INF, supermarkets[s]);
        visited[s] = true;
        while (!q.empty()) {
            int front = q.front(); q.pop();
            for (int w : g.ady(front)) {
                if (!visited[w]) {
                    visited[w] = true;
                    q.push(w);
                    cheaperPrice = min(cheaperPrice, supermarkets[w]);
                }
            }
        }
    }
public:
    solution(Grafo const&g) : g(g) {
        // for (int i = 0; i < markets.size(); ++i) 
        //     supermarkets.push_back(markets[i]);
    }
    void print(int s, vector<int>const&supermarkets) {
        query(s, supermarkets);
        if (cheaperPrice == INF)
            cout << "MENUDO MARRON\n";
        else 
            cout << cheaperPrice << "\n";
    }
};

bool resuelveCaso() {
    int n, c; cin >> n >> c;
    if (!cin) return false;
    Grafo g(n);
    for (int i = 0; i < c; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        g.ponArista(a, b);
    }
    int s; cin >> s;
    vector<int>supermarkets(n, INF);
    for (int i = 0; i < s; ++i) {
        int node, price; cin >> node >> price;
        --node;
        supermarkets[node] = price;
    }
    int k; cin >> k;
    solution sol(g);
    for (int i = 0; i < k; ++i) {
        cin >> s;
        sol.print(s - 1, supermarkets);
    }
    cout << "---\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
