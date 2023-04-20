/*
Nombre: Samuel Francisco Moncayo Moncayo 
Id: 8973440
Grupo: B

Complejidad:
Función: insertarEnListaOrdenada 

R/
  En la función insertarEnListaOrdenada encontramos un ciclo for
  que compila hasta el tamaño total de la lista, por lo que
  empezariamos con una complejidad O(n), sin embargo, encontramos
  un if (Suponiendo que se cumpla siempre) con la función infoLista 
  la cual internamente contiene otro ciclo for que en el peor de los casos 
  recorreria hasta n-1 veces, obteniendo una complejidad O(n^2), 
  asimismo, cabe resaltar el uso de la función .insLista() con una complejidad O(k),
  pero que al final ambas estan anidas al mismo for, entonces mantendriamos una
  complejidad O(n^2).
  Nota: Si tomamos el peor caso posible en el que se cumple el if a n - 1 veces
  el if posterior a eso solo se ejecutaria 1 vez, sin afectar la complejidad O(n^2).
*/

#include "lista.h"
#include <iostream>
void insertarEnListaOrdenada(Lista &l, int v){
  bool flag = true;
  int size = l.longLista();
  for(int i = 1; i < size && flag != false; i++){
    if(v > l.infoLista(i) && v < l.infoLista(i+1)){
      l.insLista(v,i+1);
      flag = false;
    }
  }
  if(flag == true)
    l.anxLista(v);   
}
int main(){
  Lista l;
  l.anxLista(5);
  l.anxLista(10);
  l.anxLista(12);
  l.anxLista(15);
  int i;
  //Ejemplo de la función insertarEnListaOrdenada()
  insertarEnListaOrdenada(l,16);
  cout << "Elementos Lista:" << endl;
  for(i = 1; i <= l.longLista(); i++){
    cout << l.infoLista(i) << " ";
  }
  cout << endl;
  
  return 0;
}
