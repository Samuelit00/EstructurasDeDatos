/*
Nombre: Samuel Francisco Moncayo Moncayo 
Id: 8973440
Grupo: B

Complejidad:
Sobre carga operador: +

R/
  En la sobre carga del operador + encontramos un ciclo for
  que compila hasta el tamaño total de la lista, por lo que
  empezariamos con una complejidad O(n), sin embargo, encontramos
  internamente el uso de las funciónes anxLista y infoLista, cada 
  una con una complejidad O(n), teniendo así dos ciclos anidados
  en un mismo for por lo tanto obtendriamos una complejidad O(n^2),
  cabe resaltar que repite el mismo proceso para concatenar la otra lista,
  por lo que si hacemos la suma obtendriamos algo aproximado a 2n^2, que 
  al final mantendriamos una comlejidad O(n^2).
*/

#include "lista.h"
#include <iostream>

int main(){
  Lista l;
  l.anxLista(5);
  l.anxLista(10);
  l.anxLista(12);
  l.anxLista(15);

  Lista l2;
  l2.anxLista(6);
  l2.anxLista(5);
  l2.anxLista(64);
  l2.anxLista(1);
  int i;
  Lista l3;
  l3 = l + l2;
  cout << "Elementos Lista:" << endl;
  int size = l3.longLista();
  for(i = 1; i <= size; i++){
    cout << l3.infoLista(i) << " ";
  }
  cout << endl;

  return 0;
}
