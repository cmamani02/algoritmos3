#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define forn(i,n) forsn(i,0,n)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, a_i;
    cin >> t;
    int sum;
    forn(i,t){
        cin >> n;
        sum = 0;
        forn(j,n){
            cin >> a_i;
            sum += a_i;
        }
        if(sum % 2 == 1){
            cout << "NO\n";
        }else if(n % 2 == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        //TAREA: corregir con editorial
    }
    
    return 0;
}