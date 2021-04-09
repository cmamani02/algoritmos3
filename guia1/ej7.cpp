#include <bits/stdc++.h>

using namespace std;

//ej7:
//vector<int> p = {3,2,5,6};

vector<int> p = {3,6,10};


const int min_inf = -500;

int mgm(int c, int j){
    if(c<0 || c>j) return min_inf;
    if(j==p.size()) return 0;

    int max_aux = max(mgm(c+1,j+1) - p[j], mgm(c-1,j+1) + p[j]);
    return max(max_aux, mgm(c,j+1));
}


int main(){
    int ans = mgm(0,0);
    cout << ans << "\n";

    return 0;
}