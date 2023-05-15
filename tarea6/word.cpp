#include <iostream>
#include <vector>
#include <string>
#include <map>
/*  Nombre : Samuel Francisco Moncayo Moncayo
    Código de estudiante: 8973440
   Sección: B
      Complejidad area de solución función coincidenciasAbc()
    R/ 
    Si le soy sincero profe esa complejidad esta medio maluca pero,
    encontramos un for que itera hasta n( n = tamaño del vector), asimismo
    dentro de este encontramos un ciclo que itera hasta el final de un mapa
    k(tamaño mapa), en el peor de los casos cada una se itera hasta el final, 
    no hay que olvidar que acceder al valor de la key de un mapa es log(n) y esta
    anidado en el for entonces al realizar los calculos tendriamos algo parecido a
    una complejidad tipo O(n2*log(n))*/
using namespace std;

int coincidenciasAbc(vector<map<char,int>>& abc, map<char,int>& ocurrencias){
    int size = abc.size();
    map<char,int> mapa;
    int acum = 0;
    for(int i = 0 ; i < size; i++){
        mapa = abc[i];
        bool flag = true;
        for (map<char,int>::iterator it = mapa.begin(); it != mapa.end() && flag ; ++it) {
            int valor = it->second;
            char key = it->first;
            if(ocurrencias[key] < valor){
                flag = false;
            }
        }
        if(flag)
            acum++;
    }
    return acum;  
}

int main(){
    vector<map<char,int>> abc;
    string palabra;
    getline(cin,palabra);
    while(palabra != "#"){
        map<char,int> tmp;
        if(palabra != "#"){
            for (int i = 0; i < palabra.size(); i++) {
                char elemento = palabra[i];
                if(tmp.find(elemento) != tmp.end())
                    tmp[elemento]++;
                else
                    tmp.insert(make_pair(elemento, 1));
            }
            abc.push_back(tmp);
        }
        getline(cin,palabra);
    }
    string dicc;
    getline(cin,dicc);
    while(dicc != "#"){
        map<char,int> ocurrencias;
        if(dicc != "#"){
            for (int i = 0; i < dicc.size(); i++) {
                char x = dicc[i];
                if(ocurrencias.find(x) != ocurrencias.end())
                    ocurrencias[x]++;
                else
                    ocurrencias.insert(make_pair(x, 1));
            }
            int x = coincidenciasAbc(abc,ocurrencias);
            cout << x << endl;
        }
        getline(cin,dicc);
    }


    /*    for (const auto& par : mapa) {
        char clave = par.first;
        int valor = par.second;
        cout << "Clave: " << clave << ", Valor: " << valor << std::endl;
    } */

    return 0;
}