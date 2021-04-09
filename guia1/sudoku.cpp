#include <bits/stdc++.h>

using namespace std;

//backtracking
vector<int> duracion;
int n;
int k;
vector<vector<int>> sudoku;
vector<vector<int>> solucion;

vector<int> posibles(int i, int j){
    vector<int> p;
    p.push_back(1);
    return p;
}

// idea 1: backtracking 
// sudoku_solver(i, j) ubica un numero en la celda (i,j)
// el tablero inicial puede tener numeros en algunas celdas
void sudoku_solver(int i=0, int j=0){
    if(!solucion.empty()) return;

    if(i == n){
        solucion = sudoku; // guardo la solucion
        return;
    }

    // defino la proxima celda a completar
    int ip = i;
    int jp = j + 1;
    if(jp == n) ip++, jp = 0;

    if(sudoku[i][j] == 0){ // celda vacia
        vector<int> s = posibles(i, j);
        // prueba todos los candidatos
        for(auto x : s){ //{6,7,8, .. 30}
            sudoku[i][j] = x; // lo PISA en la celda
            sudoku_solver(ip, jp);
            if(!solucion.empty()) return;
        }
        sudoku[i][j] = 0;// como la celda estaba vacia, la dejo vacia
        //clave: de no setear en cero, 
        //podes perderte de recorrer soluciones candidatas. Actuado
    }
    else{
        sudoku_solver(ip, jp);
    }

}

// idea 2: queremos guardar el subconjunto
vector<int> sol_parcial; // vector de 1's y 0's
vector<int> sol_optima;



int main(){
    cin >> n;
    sudoku.resize(n,vector<int>(n,0));

       
    return 0;
}