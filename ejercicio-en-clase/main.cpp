/*
Autores :

Oscar Vargas Pabon
Samuel Francisco Moncayo Moncayo

Grupo B

Implementacion Cola Prioridad
*/

#include "colasPrioridad.h"


int main(){
  int arr[] = {5,3,2,87,31,54,7,4};
  list<int> list (arr,arr + 8);
  // Utilizar el constructor
  Colaprio colador(list);
  // Imprimir los elementos de la cola
  while(!list.empty()){
    cout << colador.front() << endl;
    colador.deque();
  }
  





  return 0;
}