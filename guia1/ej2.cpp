n=3
c={1,2,3,4,5,6,7,8,9}

int cant_magicos = 0;
int magico = 0;
set<int> posibles;
bool hayMagico= False;

// solucion: BK_solver(0,0)

void BK_solver(int i , int j, int suma_fila, int suma_col){
  if (i == n ){
    if (check_valido()){
		cant_magicos++; 
    }
    return; 
  }
  
  if (i == 1 && j==0 ){
    for(int k = 0; k<n; k++){
    	magico += sudoku[0][k];
    }
    hayMagico = True;
  }
// magico = 10    

  int ip = i;
  int jp = j+1;
  if (jp == n) ip++, jp = 0;
  
  for(auto x:posibles){
     //podar.
    
    sudoku[i][j] = x;
    suma_fila += x;
    suma_col += x;
    posibles.erase(x);
    BK_solver(ip,jp);
    posibles.insert(x);
   }
  
   
}

for(y:sudoku){
  		suma_fila += sudoku[];
    	suma_col += sudoku[];
  	}
    if (suma_fila > magico && suma_col > magico && hayMagico){
  	return;
  }