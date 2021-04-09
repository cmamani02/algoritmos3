#include <bits/stdc++.h>

using namespace std;

//ej3:
int n;
int k;
vector<int> C(n);
int mejor_suma = 0;
vector<int> sol_global(k);
vector<int> sol_parcial(k);

int h(int u, int v){
    return max(u,v);
}

//index_i: indice en solucion parcial
//index_j: implementa el conjunto {c_index_j, .. c_n}  
void mejor_equipo(int suma, int index_i, int index_j){
    if(index_i == k){//completo equipo
        if(suma > mejor_suma){
            mejor_suma = suma;
            sol_global = sol_parcial;
        }
        return;
    }

    if(index_j == n) return; // no hay mas jugadores

    for(int j = index_j; j<n; j++){
        int s_aux = suma;
        sol_parcial[index_i] = C[j]; // agrego jugador
        //actualizar s_aux:
        // falta esto
        mejor_equipo(s_aux, index_i+1, j+1);
    }

}

int main(){
  
}