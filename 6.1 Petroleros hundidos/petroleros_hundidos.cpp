
/*@ <authors>
 *
 * Daniel Fernandez Ortiz: TAIS 21
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"
using namespace std;

#define MAX 1000

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>



bool resuelveCaso() {

   int C, F; cin >> C >> F;
   if (!cin) return false;

   string mapa[MAX][MAX];

   for (int i = 0; i < F; i++) {
      for (int j = 0; j < C; j++) {
         char c; cin >> c; 
         mapa[i][j] = c;
      }
   }

   int manchas; cin >> manchas;
   for (int i = 0; i < manchas; i++) {
      int fila, columna; cin >> fila >> columna;
      mapa[fila][columna] = '#';

   }

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
