/*
Nombre: Samuel Francisco Moncayo Moncayo 
Id: 8973440
Grupo: B

Complejidad 1:
Función:  contarOcurrencias

R/
  En la función  contarOcurrencias encontramos un ciclo for
  que compila hasta el tamaño total de la lista, por lo que
  empezariamos con una complejidad O(n), sin embargo, encontramos
  un if con la función infoLista la cual internamente contiene otro 
  ciclo for que en el peor de los casos recorreria hasta su ultimo valor(n), 
  obteniendo una complejidad O(n^2) gracias a los 2 ciclos anidados en la misma.


Complejidad 2:
Función:  obtenerMenores

R/
  En la función obtenerMenores encontramos un for que igualmente
  compila hasta el final de la lista obteniendo una complejidad
  O(n), sin embargo, internamente una variable toma el
  valor del retorno de la función infoLista que como ya explique
  anteriormente tendría complejidad O(n) en su peor caso, asimismo,
  encontramos la función anexarLista dentro del if la cual tambien
  tiene complejidad O(n),pero, estas dos funciones no estan anidadas una con
  la otra, por lo que, al final tendriamos unicamente una complejidad
  O(n^2).
*/
#include "lista.h"
#include <iostream>

int contarOcurrencias(Lista list,int v){
  int acum = 0;
  int size = list.longLista();
  for(int i = 1; i <= size; i++){
    if(v == list.infoLista(i))
        acum += 1;
  }
  return acum;
}
Lista obtenerMenores(Lista list, int v){
  Lista l;
  int size = list.longLista();
  for(int i = 1; i <= size; i++){
    int acum = list.infoLista(i);
    if(acum < v)
      l.anxLista(acum); 
  }
  return l;
}
int main(){
  Lista l;
  l.anxLista(5);
  l.anxLista(10);
  l.anxLista(12);
  l.anxLista(15);
  // Ejemplo de la funcion del punto 1) contarOcurrencias
  int num;
  num = contarOcurrencias(l,5);
  cout << num << endl;
  return 0;
  // Ejemplo de la funcion del punto 2) obtenerMenores
  int i;
  Lista acum;
  acum = obtenerMenores(l,10);
  cout << "Elementos Lista:" << endl;
  for(i = 1; i <= acum.longLista(); i++){
    cout << acum.infoLista(i) << " ";
  }
  cout << endl;

}
