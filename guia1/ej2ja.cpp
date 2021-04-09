void FBMagico(vector<bool> &setNum, int n, int i, int j, vector<vector<int>> &sol, int &res, bool verbose) {
    /*
     * Con los números de setNum arma todas las combinaciones posibles y contabiliza los soluciones válidas
     * o sea aquellas que son cuadrado mágico
     *
     * (i,j) = posicion de la celda de la matriz donde se prueban todas las combinaciones disponibles en setNum
     * setNum = conjunto de numeros aún no utilizados en la solucion (setNum[i-1] = true sii el numero i
     *          está disponible para ser incluido en la solucion)
     * sol = matriz solucion con el cuadrado magico si la funcion esSolucionValida es true
     * res = contabiliza la cantidad de cuadrados magicos
     * verbose = true imprime las soluciones que va contabilizando
     *
     */
    if(i==n) {
        if (esSolucionValida(n, sol)) {
            res++;
            if(verbose) {
                cout << res << "." << endl;
                imprimir(sol, n);
            }
        }
        return;
    }
    int m = n * n;
    for(int k = 0; k < m; k++) {
        sol[i][j] = setNum[k] ? k+1 : sol[i][j];
        if (setNum[k]) {
            setNum[k] = false;  // Saco el elemento de la lista de numeros disponibles
            FBMagico(setNum, n, i+((j+1)==n), (j+1)%n, sol, res, verbose);
            setNum[k] = true;   // Pongo el elemento nuevamente disponible en la lista
            sol[i][j]=0;        // Quito el valor seteado en la celda (i,j)
        }
    }
};
