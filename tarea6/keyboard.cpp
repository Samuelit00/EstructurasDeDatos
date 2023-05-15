#include <iostream>
#include <list>
#include <string>
/*  Nombre : Samuel Francisco Moncayo Moncayo
    Código de estudiante: 8973440
   Sección: B
   Complejidad area de solución función beijuText()
    R/ 
    En este bloque, encontramos un "for" que itera hasta el tamaño total del string 
    recibido, por lo cual, sería hasta "n" veces, siendo este el tamaño de la lista. 
    Dentro del ciclo, encontramos varios condicionales que, en el peor caso, alguno de 
    ellos se iterará "n" veces.

    Es necesario tener en cuenta que se hace uso de varias operaciones, como "push_back", 
    "begin", y "insert". "Push_back" y "begin" tienen una complejidad constante, sin embargo, 
    es necesario tener en cuenta que "insert" tiene complejidad lineal en sus peores casos, pero 
    aquí es utilizado con un iterador para en todo momento insertar en la primera posición de la lista, 
    obteniendo una complejidad constante.

    Al hacer las respectivas operaciones, encontramos que, en el peor y mejor caso, la complejidad será O(n).
    */
using namespace std;



list<char> beijuText(string msg){
    list<char> beiju;
    bool flag = true;
    int size = msg.size();
    list<char>::iterator it;
    for (int i = 0; i < size; i++){
        char x = msg[i];
        if(x == '['){
            it = beiju.begin();
            flag = false;
        } else if(x == ']'){
            flag = true;
        }
        if(flag && x != ']'){
            beiju.push_back(x);
        }
        else if(!flag && x != '[')    
            beiju.insert(it, x);          
    }
    return beiju;
}



int main(){
    list<char> beiju;
    string msg;
    while(getline(cin, msg)){
        beiju = beijuText(msg);
        for (list<char>::iterator it = beiju.begin(); it != beiju.end(); ++it) 
            cout << *it;
        cout << endl;
    }
}