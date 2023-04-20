/*
Nombre: Samuel Francisco Moncayo Moncayo 
Id: 8973440
Grupo: B

Complejidad:
Función del TAD : insListaOrdenada 

R/
  En la función insListaOrdenada, encontramos varios ciclos anidados
  que en el mejor caso tendriamos una complejidad O(1), sin embargo,
  si tomamos el peor caso de cada uno y con el while que recorreria hasta
  el final de la lista la mayor complejidad que obtendriamos es O(n).
*/
#include "lista.h"
#include <iostream>

int main(){
  Lista l;
  cout << 1 << endl;
  // Insertamos los datos de entrada en cualquier orden
  l.insListaOrdenada(12);
  l.insListaOrdenada(10);
  l.insListaOrdenada(5);
  l.insListaOrdenada(15);

  //Imprime de manera ordenada de menor a mayor la lista
  cout << "Valor posición 1: " << l.infoLista(1) << endl;
  cout << "Valor posición 2: " << l.infoLista(2) << endl;
  cout << "Valor posición 3: " << l.infoLista(3) << endl;
  cout << "Valor posición 4: " << l.infoLista(4) << endl;

  int i;
  int size = l.longLista();
  for(i = 1; i <= size; i++){
    cout << l.infoLista(i) << " ";
  }
  cout << endl;
}
