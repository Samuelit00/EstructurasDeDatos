#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*  Nombre : Samuel Francisco Moncayo Moncayo
    Código de estudiante: 8973440
   Sección: B 
   Complejidad area de solución:
    Función :puntajeFinal
    R/ En esta función encontramos 2 ciclos anidados, sin embargo,
        hay que tener en cuenta que cada uno depende de una variable distinta.

        Si observamos ambos ciclos recorren un vector dependiendo del tamaño del
        mismo,por lo que ambos se iterarian n veces y como uno esta dentro del otro
        obtendriamos una complejidad O(n^2) */
void listaPilotos(int num, vector<int>& arr){

    for(int i = 1; i <= num; i++)
        arr.push_back(i);

}

void posicionesPilotos(int num2, int num3, vector<vector<int>>& maxvector){
    int position;
    for(int i = 0; i < num3; i++){
        vector<int> arr1;
        for(int x = 0; x < num2; x++){
            cin >> position;
            arr1.push_back(position);
        }
        maxvector.push_back(arr1);
    }
}
vector<int> puntajeFinal(vector<int> arr2,vector<int> clasificacion){
        vector<int> puntaje(arr2.size(),0);
        for(int y = 0; y < clasificacion.size(); y++){
            bool flag = true;
            for(int z = 0; z < arr2.size() && flag == true; z++){
                int acum;
                if(y + 1 == arr2[z]){
                    acum = z;
                    puntaje[acum] += clasificacion[y];
                    flag = false;
                }
            }    
        }
        return puntaje;
}
void creacionPremios(vector<int>& points){
        int premios , ganadores;
        cin >> ganadores;
        cin.ignore();   
        for(int x = 0; x < ganadores ; x++){
            cin >> premios; 
            points.push_back(premios);
        }
}

void ganadoresPrinx(vector<int> points, vector<int>& resultados){
    int mayor = INT16_MIN;
    for (int j = 0; j < points.size(); j++) {
        resultados[j] = resultados[j] + points[j];
    }
}

int main(){
    int p, g;
    cin >> g;
    cin >> p;
    while(g != 0 && p != 0){
        int s;
        vector<vector<int>> posiciones;
        vector<int> pilotos;
        listaPilotos(p,pilotos);
        posicionesPilotos(p, g, posiciones);
        cin >> s;
        for(int i = 0; i < s; i++){
            vector<int> clasificacion;
            vector<int> result(pilotos.size(),0);
            vector<int> vectorIndex;
            vector<int> acum;
            int mayor = INT16_MIN, max;
            creacionPremios(clasificacion);
            for(int i = 0; i < posiciones.size(); i++){
                vectorIndex = posiciones[i];
                acum = puntajeFinal(vectorIndex,clasificacion);
                ganadoresPrinx(acum,result);
            }
            for(int x = 0; x < result.size(); x++) {
                if(result[x] > mayor) {
                    mayor = result[x];
                    max = x;
                }
            }
            cout << max + 1;
            for(int j = 0; j < result.size(); j++){
                if(result[j] == mayor && j != max)
                    cout << " " << j+1 ;
            }
            cout << endl;
            }
        cin >> g;
        cin >> p;
    }
    return 0;
}
