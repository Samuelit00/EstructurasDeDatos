/*

 Autor : Samuel Francisco Moncayo Moncayo
 Clase : B
 ID: 8973440
 */
#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

#include <iostream>
#include <list>
#include <string>
using namespace std;


class BigInteger {
    private:

    
    list<int> bigInteger;
    bool sign;

    /* Auxiliares */
    
    void auxAdd(BigInteger &num);
    void auxSubstract(BigInteger &num);
    void eraseZero();
    void auxProduct(BigInteger &num);
    bool operator>(BigInteger &num);

    public:



    /*Getter*/
    list<int> getter();
    /************************
    * OPERACIONES BIG INTEGERS*
    ************************/


    /* Constructoras */
    BigInteger();
    BigInteger(const string &num);
    BigInteger(const BigInteger &num);

    /* Modificadoras */

    void add(BigInteger &num);
    void product(BigInteger &num);
    void substract(BigInteger &num);
    void quotient(BigInteger &num);
    void remainder(BigInteger &num);
    void pow(int num);
    string toString();

    /* Sobrecargas */

    BigInteger operator +(BigInteger &num);
    BigInteger operator -(BigInteger &num);
    BigInteger operator *(BigInteger &num);
    BigInteger operator /(BigInteger &num);
    BigInteger operator %(BigInteger &num);
    bool operator ==(BigInteger &num);
    bool operator <(BigInteger &num);
    bool operator <=(BigInteger &num);


    /* Analizadoras */

    int sizeInteger();

    /*Operaciones Estaticas */
    
    static BigInteger sumarListaValores(list<BigInteger> &bigList);
    static BigInteger multiplicarListaValores(list<BigInteger> &bigList);

};





#endif