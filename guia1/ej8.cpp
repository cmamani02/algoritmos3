// corte(0, L) // sol al problema

// ej8:
corte(i, j) = 
{ INF   si j < i // parece que esta mal porque nunca se alcanza

{0        si {i+1, .. j-1} interseccion C = VACIO }  <-- (0,2) SI entra en este caso como queria.
//{0        si i = j
    
{(j-i) + min {corte(i,c) + corte(c,j)  | c pretenece C && i < c < j }  en caso recursivo
  

//OBS: si no hay ningun corte posible, cae en el caso base.
// sino se resuelve en el caso recursivo.

//caso en que hay cortes para hacer:
corte(0,10) = (10-0) + min{ 2 , 4, 5, 7} // luego de resolver los llamados recursivos
 
 


 
 // 9:
 void m_n_v(){
   -inf 																			si (i,j < 0 || i,j > n)
							max(1,1-Aij) 															si (i=n-1) and (j=n-1)
							max(1,m_n_v(i,j+1)-Aij)  									si ( i=n-1 and j != n-1)
							max(1,m_n_v(i+1,j)-Aij)  									si ( i!=n-1 and j = n-1)
							max(1,m_n_v(i+1,j)-Aij,m_n_v(i,j+1)-Aij)  si (i != n-1) and (i!=n-1) 
}