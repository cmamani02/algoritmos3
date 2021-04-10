#include <bits/stdc++.h>
#include <tuple>

using namespace std;

const int INF = 1000000000;

tuple<int,int> minime(tuple<int,int> a, tuple<int,int> b){
    int a1 = get<0> (a);
    int a2 = get<1> (a);
    int b1 = get<0> (b);
    int b2 = get<1> (b); 
    
    if(a1 < b1){
        return a;
    } // a1 >= b1
    else if(a1 == b1){
        if(a2 < b2) return a;
        else return b;
    }
    else{
      return b;  
    } // a1 > b1
}

tuple<int,int> sume(tuple<int,int> a, tuple<int,int> b){
    return make_tuple (get<0> (a) + get<0> (b), 
                       get<1> (a) + get<1> (b));
}

// b: implementacion recursiva
// i es es indice de el elemento a procesar
// j es el monto a alcanzar

//cc(0, k) es la solucion
tuple<int,int> cc(vector<int> &B, int i, int j){
    if(i == B.size()) return make_tuple (j > 0 ? INF : 0, 0);
    
    if( c < 0 ) make_tuple (0, 0);
    
    tuple<int, int> aux = make_tuple (B[i], 1);
    tuple<int,int> r = minime( sume(aux, cc(B, i+1, j-B[i])), 
                                cc(B, i+1, j) );
    
    
    
    return r;
}
// Hola, para el ejercicio 6.a se me ocurrio esta funcion recursiva para cc(B,c):

// || 
//(cprima, q)
//k valor objetivo
// cc({b1 ..bn}, c) = 

// { ( c > 0 ? INFINITO : 0 , 0 ) si n = 0

// { min{ (bn, 1) + cc({b1 ..bn-1}, c-bn) ,   si n > 0
// 			c({b1 ..bn-1}, c) } 

// ||

// || en el caso base no tengo billetes disponibles:
// si c > 0: INFINITO parece un valor apropiado.
// si c <= 0: ya no hay nada que pagar entonces devuelvo 0.
// y en ambos casos q = 0 porque no hay billetes. ||





int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;
    cin >> n >> k;

    return 0;    

}


