
/*@ <authors>
 *
 * Daniel Fernandez Ortiz: TAIS 21
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
#include <deque>
#include <climits>
using namespace std;
using Camino = deque<int>;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


template<typename Valor>
class Dijkstra {
private:
    const Valor INF = numeric_limits<Valor>::max();
    int origen, pueblos, max_dist;
    vector<Valor>dist;
    vector<AristaDirigida<Valor>>ulti;
    IndexPQ<Valor>pq;
    void relajar(AristaDirigida<Valor>a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() && dist[w] <= d) {
            ++pueblos;
            dist[w] = dist[v] + a.valor();
            ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
public:
    Dijkstra(DigrafoValorado<Valor> const&g, int d, int b) : origen(orig), dist(g.V(), INF), ulti(g.V()) pq(g.V()), pueblos(b), max_dist(d) {
        // dist[origen] = 0;
        // pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }

    Camino<Valor> camino(int v) const {
        Camino<valor> cam;
        AristaDirigida<Valor>a;
        for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
            cam.push_front(a);
        cam.push_front(a);
        return cam;
    }

    void pushPQ(int v) {
        pq.push(v);
        dist[v] = 0;
    }
    int getPueblos() const {
        return pueblos;
    }
};

bool resuelveCaso() {

    int d, v, e; cin >> d >> v >> e;

    if (!std::cin) return false;

    DigrafoValorado<int>digrafo(v);

    for (int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        digrafo.ponArista({a, b, c});
        digrafo.ponArista({b, a, c});
    }

    int b; cin >> b;
    Dijkstra<int> dijkstra(digrafo, d, b);
    for (int i = 0; i < b; i++) {
        int v; cin >> v;
        dijkstra.pushPQ(v);
    }
    
    cout << dijkstra.getPueblos() << "\n";

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
