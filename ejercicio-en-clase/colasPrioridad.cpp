#include "colasPrioridad.h"

Colaprio::Colaprio(){

}
/*
Este constructor funciona en el tiempo que tome la operación sort del contenedor lista.
Asumimos que ha de estar implementado en O(n*log n)
*/
Colaprio::Colaprio(list<int> list){
  list.sort();
  cola = list;
}
/*
En el mejor caso, *(cola.begin) >= i, por lo que nunca se entra al ciclo y por esto funciona
  en tiempo constante O(1).
En el peor caso, i es mayor a todos los elementos de cola, por lo que iteramos hasta que
  it == cola.end(). Funciona entonces en O(n).
*/
void Colaprio::enqueue(int i){
  list<int>::iterator it = cola.begin();
  while ( it != cola.end() && *it < i){
    ++it;
  }
  cola.insert(it, i);
}

/*
Deque funciona en el tiempo que toma la operacion pop_front del contenedor lista.
Este funciona en O(1)
  */
void Colaprio::deque(){
  cola.pop_front();
}
/*
Deque funciona en el tiempo que toma la operacion front del contenedor lista.
Este funciona en O(1)
  */
int Colaprio::front(){
  return cola.front();
}
/*
Deque funciona en el tiempo que toma la operacion empty del contenedor lista.
Este funciona en O(1)
  */
bool Colaprio::empty(){
  return cola.empty();
}