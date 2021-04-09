#include <bits/stdc++.h>

using namespace std;

//backtracking
int valor_solucion = 0;
vector<int> duracion;
int n;
int k;

// idea 1: backtracking 
void CD(int suma, int i){ //{d_i, .. d_n}
    if(i==n){
        if(suma <= k and suma > valor_solucion){
            valor_solucion = suma;
        }
    }
    else{
       CD(suma+duracion[i], i+1); // lo agrego
       CD(suma, i+1); // no lo agrego
    }
}
// CD(0,0) resuelve el problema

// idea 2: queremos guardar el subconjunto
vector<int> sol_parcial; // vector de 1's y 0's
vector<int> sol_optima;

void CD2(int suma, int i){
    if(i==n){
        if(suma <= k and suma > valor_solucion){
            valor_solucion = suma;
            sol_optima = sol_parcial;
        }
    }
    else{
        sol_parcial[i] = 1;
        CD2(suma+duracion[i], i+1);
        sol_parcial[i] = 0; // vuelvo a estado anterior (dejo como estaba)
        CD2(suma, i+1);
    }
}
// CD2(0,0) resuelve el problema

// idea 3: poda por factibilidad
// si ya superamos la capacidad del CD, dejamos de explorar.
void CD3(int suma, int i){
    if(suma > k) return; // poda si nos pasamos
    
    // caso la suma es menor que k:
    if(i==n){
        if(suma > valor_solucion){
            valor_solucion = suma;
            sol_optima = sol_parcial;
        }
    }
    else{
        sol_parcial[i] = 1;
        CD3(suma+duracion[i], i+1);
        sol_parcial[i] = 0; // vuelvo a estado anterior (dejo como estaba)
        CD3(suma, i+1);
    }
}
// CD3(0,0) resuelve el problema

// idea 4: poda por optimalidad: si agregando todas las canciones
// que todavia no explore no puedo superar el optimo, retorna.

// inicialmente, suma_sufijo es la suma de todas las duraciones
void CD4(int suma, int suma_sufijo, int i){
    if(suma > k) return; // poda si nos pasamos
    
    // no puede superar el optimo:
    if(suma + suma_sufijo <= valor_solucion) return; // poda optimalidad

    // caso la suma es menor que k:
    if(i==n){
        if(suma > valor_solucion){
            valor_solucion = suma;
            sol_optima = sol_parcial;
        }
    }
    else{
        suma_sufijo -= duracion[i];
        sol_parcial[i] = 1;
        CD4(suma+duracion[i], suma_sufijo, i+1);

        sol_parcial[i] = 0; // vuelvo a estado anterior (dejo como estaba)
        CD4(suma, suma_sufijo, i+1);
    }
}
// CD4(0, suma_sufijo, 0) resuelve el problema



int main(){
    // k n 
    cin >> k >> n;
    duracion.resize(n);
    sol_parcial.resize(n,0);
    sol_optima.resize(n,0);

    for(int i = 0; i<n; i++) cin >> duracion[i];

    // idea 1:
    //CD(0, 0);
    
    // idea 2:
    //CD2(0,0);

    // idea 4: poda optimalidad
    int suma_inicial = 0;
    for(int i = 0; i<n; i++) suma_inicial += duracion[i];
    
    CD4(0, suma_inicial, 0);
    cout << valor_solucion << "\n";
    // imprime el subconjunto solucion:
    for(int i = 0; i<n; i++){
        if(sol_optima[i] == 1) cout << duracion[i] << " ";
    } 
    cout << "\n";
        
    return 0;
}