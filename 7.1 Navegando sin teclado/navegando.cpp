
/*@ <authors>
*
* Daniel Fernandez Ortiz: TAIS 21
*
*@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include"DigrafoValorado.h"
using namespace std;


/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


class SOL {
private:
    int coste, origen, destino, v;
    vector<bool>visitados;
    vector<int>tiempos_de_carga;
public:
    SOL(DigrafoValorado<int>const& g, vector<int>const& tiempos) : coste(0), origen(0), v(g.V()), destino(v - 1), tiempos_de_carga(tiempos) {
        queue<int>cola;
        cola.push(0); visitados[0] = true;
        while (!cola.empty()) {
            int v = cola.front(); cola.pop();
            for (auto arista : g.ady(v)) {
                if (arista.hasta() == v - 1) {
                    visitados[v - 1] = true;
                    break;
                }
                if (!visitados[arista.hasta()]) {
                    visitados[arista.hasta()] = true;
                    cola.push(arista.hasta());
                    // TODO
                    // coste++;
                }
            }
        }
    }
    bool hayCamino() const { return visitados[v - 1]; }
    int getCoste() const { return coste; }

};


bool resuelveCaso() {

    int n; cin >> n;
    if (n == 0) return false;

    vector<int>tiempos_de_carga(n);

    for (int i = 0; i < n; i++) 
        cin >> tiempos_de_carga[i];

    DigrafoValorado<int>grafo(n);

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        grafo.ponArista({a - 1, b - 1, c});
    }

    // SOL sol(grafo, tiempos_de_carga);

    // if (!sol.hayCamino()) cout << "IMPOSIBLE\n";
    // else cout << sol.coste << "\n";


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
