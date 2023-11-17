
/*@ <authors>
 *
 * Daniel Fernandez Ortiz: TAIS 21
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define MAX_VALOR 500
#define MAX_SECTORES 50


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct solucion {
    int n_dardos;
    vector<int>dardos;
};

/*
s == sector, o == objetivo
sol(s, o)
*/

solucion resolver(int objetivo, vector<int>const&sectores) {
    return {};
}

bool resuelveCaso() {
    int objetivo, n_sectores; cin >> objetivo >> n_sectores;
    if (!cin) return false;
    vector<int>sectores(n_sectores);
    for (int i = 0; i < n_sectores; ++i) {
        cin >> sectores[i];
    }

    solucion sol = resolver(objetivo, sectores);

    if (sol.n_dardos == 0) cout << "IMPOSIBLE\n";
    else {
        cout << sol.n_dardos << ": ";
        for (int i : sol.dardos) cout << i << " ";
        cout << "\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   ifstream in("casos.txt");
   auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
