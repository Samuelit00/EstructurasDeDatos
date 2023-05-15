#include <iostream>
#include <stack>
#include <string>
#include <list>
/*  Nombre : Samuel Francisco Moncayo Moncayo
    Código de estudiante: 8973440
   Sección: B
   Complejidad función posibleRail
    Tenemos un while que itera hasta que la lista entregada
    este vacia o la flag sea falsa, adentro tenemos una serie
    de condicionales con diferentes funciones que todas ellas
    tienen una complejidad constante y en el peor de los casos 
    la suma de todos los if seria el n(iteraciones hasta final del while)
    a pesar de que el ciclo dependa de una o de la otra la complejidad de
    todo no varia, por lo que al hacer todos los calculos obtenemos
    una complejidad lineal O(n)*/
using namespace std;

bool posibleRail(list<int> riel, int num){
    stack<int> station;
    bool flag = true;
    int acum = 1;
    list<int>::iterator it = riel.begin();
    while(flag && !riel.empty()){
        bool flag1 = true;
        if(acum < num){
            if(!station.empty()){
                if(station.top() == *it){
                    station.pop();
                    riel.pop_front();
                    it = riel.begin(); 
                    flag1 = false;
                }
            } 
            if(*it == acum && flag1){
                riel.pop_front();
                acum++;
            } else if(*it != acum && flag1){
                station.push(acum);
                acum++;
            }
            it = riel.begin(); 
        } else {
            if(*it == acum)
                riel.pop_front();
            else if(station.top() == *it){
                station.pop();
                riel.pop_front();
            } else {
                station.push(num);
            }
            it = riel.begin();
        }
        if(!station.empty()){
            if(station.top() == num && num != *it)
                flag = false;
        }
    }
    return flag;
}


int main(){
    int n;
    int data;
    cin >> n;
    cin.ignore();
    while(n != 0){
        bool flag = true;
        while(flag){
            list<int> tren;
            cin >> data;
            if(data == 0){
                flag = false;
            }
            if(flag){
                tren.push_back(data);
                for (int i = 1; i < n; i++){
                    cin >> data;
                    tren.push_back(data);
                }
                bool both = posibleRail(tren, n);
                if(both)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        }
        cout << endl;
        cin >> n;
        cin.ignore();
    }



    return 0;
}