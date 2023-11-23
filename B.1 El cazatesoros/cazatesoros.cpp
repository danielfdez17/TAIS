
/*@ <authors>
 *
 * Daniel Fernandez Ortiz: TAIS 21
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include "Matriz.h"
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

struct Objeto {
    int profundidad, cantidad;
};

int cazatesorosRec(vector<Objeto>const&objetos, int i, int j, Matriz<int>&dp) {
    if (dp[i][j] != -1) 
        return dp[i][j];
    if (i == 0 || j <= 0) 
        return dp[i][j];
    if (3 * objetos[i - 1].profundidad > j) 
        return cazatesorosRec(objetos, i - 1, j, dp);
    return dp[i][j] = max(cazatesorosRec(objetos, i - 1, j, dp), cazatesorosRec(objetos, i - 1, j - 3 * objetos[i - 1].profundidad, dp) + objetos[i - 1].profundidad);
}

int cazatesoros(vector<Objeto>const&objetos, int N, int T, vector<Objeto>&sol) {
    Matriz<int>dp(N + 1, T + 1, -1);
    int cantidadMaxima = cazatesorosRec(objetos, N, T, dp);
    int i = N, j = T;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            j -= objetos[i - 1].profundidad;
            sol.push_back(objetos[i - 1]);
        }
        --i;
    }
    return cantidadMaxima;
}

bool resuelveCaso() {

    int T; cin >> T;

    if (!std::cin) return false;
    vector<Objeto>objetos, sol;
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        Objeto o; cin >> o.profundidad >> o.cantidad;
        objetos.push_back(o);
    }
    int tesoros = cazatesoros(objetos, N, T, sol);
    
    cout << tesoros << "\n" << 
        sol.size() << "\n";
    for (Objeto o : sol) cout << o.profundidad << " " << o.cantidad << "\n";
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
