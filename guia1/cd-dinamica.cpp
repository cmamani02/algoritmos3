#include <bits/stdc++.h>

using namespace std;

#define BOTTOM -1

vector<vector<int>> DP;
vector<int> duracion;

// implementacion top down
int CD(int i, int k){
    if(i == 0) return 0; // fila 0
    // si no esta definido, calculo y guardo
    if(DP[i][k] == BOTTOM){
        if(duracion[i] > k){
            DP[i][k] = CD(i-1,k);
        }
        else{
            DP[i][k] = max(CD(i-1,k), CD(i-1,k-duracion[i]) + duracion[i]); 
        }
    }
    return DP[i][k];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;
    cin >> n >> k;
    duracion.resize(n);
    for(int i = 0; i<n; i++) cin >> duracion[i];
    
    //inicializamos el diccionario
    //el caso base i = 0 se simula en la funcion
    DP.resize(n+1, vector<int>(k+1, BOTTOM));
    
    int maxima_duracion = CD(n,k); // indices validos
    cout << maxima_duracion << "\n";

    return 0;    

}