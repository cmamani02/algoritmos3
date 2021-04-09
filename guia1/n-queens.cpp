#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> answer;
bool hay_solucion;
int N;

// usar la idea de las 8 reinas vista en la clase teorica:
// en cada nueva posicion a llenar, chequear que sea distinta a las (i-1) que ya ubique
// y que no comparta diagonal con las (i-1) que ya ubique.
// es una idea mas ingeniosa de generar el espacio de soluciones candidatas.
// tal vez un vector de posibles, como en sudoku

bool se_puede_ubicar(int x, int y, int col, vector<vector<int>>& board){
    // verifica filas y columnas
    for(int j = 0; j<N; j++){
        if(board[x][j] == 1) return false;
        if(board[j][y] == 1) return false;
    }    
    //chequear diagonales: con la idea de la teorica

}

void bt(int col, vector<vector<int>>& board){
    if(col == N){
        answer = board;
        hay_solucion = true;
        return;
    }

    if(hay_solucion) return;

    for(int i = 0; i < N; i++){
        if( se_puede_ubicar(i, col, board) ){
            board[i][col] = 1;
            bt(col+1,board);
            board[i][col] = 0;
        }
    }

}

int main(){
    N = 5;
    hay_solucion = false;

    return 0;  
}