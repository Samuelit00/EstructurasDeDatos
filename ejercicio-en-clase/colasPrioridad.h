/*
Autores :

Oscar Vargas Pabon
Samuel Francisco Moncayo Moncayo

Grupo B

*/
#ifndef COLA_PRIO
#define COLA_PRIO

#include <iostream>
#include <list>

using namespace std;

class Colaprio {
  private:

  list<int> cola;

  public:

  Colaprio();
  Colaprio(list<int> list);

  void enqueue(int i);
  void deque(); 
  int front();
  bool empty();

};



#endif
