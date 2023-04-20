/*
Nombre: Samuel Francisco Moncayo Moncayo 
Id: 8973440
Grupo: B

Complejidad:
Función: concatenarListas

R/
  En la función  concatenarListas encontramos un ciclo for
  que compila hasta el tamaño total de la lista, por lo que
  empezariamos con una complejidad O(n), sin embargo, encontramos
  internamente el uso de las funciónes anxLista y infoLista, cada 
  una con una complejidad O(n), teniendo así dos ciclos anidados
  en un mismo for por lo tanto obtendriamos una complejidad O(n^2),
  ya que, a pesar de que ambas funciónes tengan una complejidad O(n),
  no estan anidadas una con la otra, si no, que ambas dependen del mismo for
  externo resultando en esta complejidad.

*/

#include "lista.h"
#include <iostream>


void concatenarListas(Lista &l1, Lista l2){
    int size = l2.longLista();
    for(int i = 1; i <= size;i++)
      l1.anxLista(l2.infoLista(i));
}
int main(){
  Lista l1;
  l1.anxLista(5);
  l1.anxLista(10);
  l1.anxLista(12);
  l1.anxLista(15);
  Lista l2;
  l2.anxLista(6);
  l2.anxLista(5);
  l2.anxLista(64);
  l2.anxLista(1);
  //Ejemplo del funcionamiento de la función
  concatenarListas(l1,l2);
  int i;
  cout << "Elementos Lista:" << endl;
  int size = l1.longLista();
  for(i = 1; i <= size; i++){
    cout << l1.infoLista(i) << " ";
  }
  cout << endl;

  return 0;
}
