/*

 Autor : Samuel Francisco Moncayo Moncayo
 Clase : B
 ID: 8973440
 */
#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

#include <iostream>
#include <vector>
using namespace std;

typedef long Elemento;

class BigInteger {

    public:

    vector<int> bigInteger;
    vector<int> copybigInteger;
    /************************
    * OPERACIONES BIG INTEGERS*
    ************************/

    /* Constructoras */
    BigInteger(Elemento elem);
    BigInteger();

    /* Modificadoras */
    void add(BigInteger &num);
    void product(BigInteger &num);
    void substract(BigInteger &num);
    void quotient(BigInteger &num);
    Elemento remainder(BigInteger &num);
    void pow(BigInteger &num);
    string toString();
    /* Sobrecargas */
    BigInteger operator +(BigInteger &num);
    BigInteger operator -(BigInteger &num);
    BigInteger operator *(BigInteger &num);
    BigInteger operator /(BigInteger &num);
    BigInteger operator %(BigInteger &num);
    BigInteger operator ==(BigInteger &num);
    BigInteger operator <(BigInteger &num);
    BigInteger operator <=(BigInteger &num);
    
};





#endif