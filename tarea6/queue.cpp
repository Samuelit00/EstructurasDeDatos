#include <iostream>
#include <map>
#include <list>
#include <queue>
/*  Nombre : Samuel Francisco Moncayo Moncayo
    Código de estudiante: 8973440
   Sección: B
   Complejidad area de solución función peopleRow()
    R/ 

    En este bloque de código, hay un bucle que itera hasta un número 'n', 
    que representa el número de instrucciones que se ejecutarán. Al comienzo, 
    hay una condición 'if' que evalúa un dato de entrada. En el peor de los casos, 
    esta condición se evaluará 'n' veces. Dentro del primer condicional, se realizan 
    varias operaciones como "front()", "push_back()" y "pop_front()", todas con complejidad 
    lineal. En el caso contrario, se depende de otro dato de entrada llamado 'E', que se encuentra 
    en la línea 53. En esta línea, se realiza una condición que verifica si el dato de entrada 
    existe en el mapa utilizando la función "find()". Esta función tiene una complejidad de O(log(n)). 
    Luego, se utilizan otras funciones como ".insert()", que tienen complejidad O(log(n)). 
    Sumando estas funciones a las anteriores, las demás funciones tienen complejidad constante.

    En la línea 47, encontramos un caso especial donde se revisa hasta cierto número, 
    verificando una clave hasta que sea igual. Puede parecer que tiene una complejidad lineal, 
    sin embargo, esto depende del valor de 'E', que es el dato de entrada. Es importante destacar 
    que si se coloca siempre el mismo valor para 'E', inicialmente se llegaría al 'else' de la línea
    53 para todos los valores, y luego, en la segunda mitad de 'E', se ingresaría al bucle 'while' de la 
    última línea. Como solo la mitad de 'E' entra en el ciclo de la línea 47, tiene una complejidad de O(log(n)). 
    Si sumamos todo y lo multiplicamos, obtenemos una complejidad de O(n*log(n)).
    */
using namespace std;

struct Persona {
    int posicion;
    int id;
};

void peopleRow(int num, map<int,int>& row,list<Persona>& keys){
    for(int i = 0; i < num; i++){
        char x;
        cin >> x;
        if (x == 'N'){
            if(keys.front().id == row[keys.front().posicion]){
                cout << keys.front().posicion  << endl;
                keys.push_back(keys.front());
                keys.pop_front();
            } else{
                while(keys.front().id != row[keys.front().posicion])
                    keys.pop_front();
                cout << keys.front().posicion << endl;
                keys.push_back(keys.front());
                keys.pop_front();
            }
        } else {
            int j;
            cin >> j;
            if(row.find(j) != row.end()){
                row[j]++;
                keys.push_front({j,row[j]});
            } else {
                row.insert(make_pair(j, 0));
                keys.push_front({j,0});
            }
        }        
    }

}


int main(){
    int p, c, size, acum = 1;
    cin >> p;
    cin.ignore();
    cin >> c;
    cin.ignore();    
    while(c != 0 && p != 0){
        map<int,int> row;
        list<Persona> keys;
        int size;
        if(p < c)
            size = p;
        else 
            size = c;
        cout << "Case " << acum << ":" << endl;
        for(int i = 1; i <= size; i++){
            keys.push_back({i,0});
            row.insert(make_pair(i, 0)) ;
        }
        peopleRow(c,row,keys);

        cin >> p;
        cin.ignore();
        cin >> c;
        cin.ignore();
        acum++;
    }
    
    return 0;
}