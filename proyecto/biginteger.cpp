#include "biginteger.h"

/*        Funciones Constructoras        */

list<int>BigInteger::getter(){
    return bigInteger;
}

BigInteger::BigInteger(){
}

BigInteger::BigInteger(const string &num){
    int size = num.size();
    sign = true;
    int numero;
    if(num[0] == '-')
        sign = false;
    else{
        numero = num[0] - 48;
        bigInteger.push_back(numero);
    }
    for(int i = 1; i < size; i++){
        numero = num[i] - 48;
        bigInteger.push_back(numero);
    }
}

BigInteger::BigInteger(const BigInteger &num){
    bigInteger = num.bigInteger;
    sign = num.sign;
}
 

/*        Funciones Modificadoras        */


// Suma (add)
void BigInteger::add(BigInteger &num){
    BigInteger temporal;
    temporal.bigInteger = bigInteger;
    temporal.sign = sign;
    if(sign == num.sign)
        auxAdd(num);
    else{
        if(num > temporal){
            sign = num.sign;
        }
        auxSubstract(num);
    }
}

// Resta (substract)
void BigInteger::substract(BigInteger &num){
    BigInteger temporal;
    temporal.bigInteger = bigInteger;
    temporal.sign = sign;
    if(sign == num.sign){
    if(sign == false && num.sign == false){
        if(num > temporal)
            sign = true;
    } else if(sign == true && num.sign == true){
            if(num > temporal)
            sign = false;
    }   
    auxSubstract(num);

    }else if(sign != num.sign)
        auxAdd(num);

}


// Multiplicación (product)
void BigInteger::product(BigInteger &num){
    int size = bigInteger.size();
    if(sign != num.sign)
        sign = false;
    else if(sign == num.sign)
        sign = true;
    auxProduct(num);
}

// División (quotient)
void BigInteger::quotient(BigInteger &num){
    BigInteger saver;
    saver.bigInteger = bigInteger;
    bool flag = true;
    if(sign != num.sign)
        sign = false;
    else if(sign == num.sign)
        sign = true;
    if(num > saver){
        list<int>zero;
        zero.push_back(0);
        bigInteger = zero;
        flag = false;
    }
    int size = num.bigInteger.size();
    BigInteger tempo;
    BigInteger productNum;
    list<int>::iterator itList = bigInteger.begin();
    list<int>::iterator itTempo = next(itList, size);
    list<int> tempoList(itList, itTempo);
    list<int> solution;
    list<int> productNumList;
    tempo.bigInteger = tempoList;
    --itTempo;
    if(num > tempo && flag){
        ++itTempo;
        tempo.bigInteger.push_back(*itTempo);
    }
    while(itTempo != bigInteger.end() && flag){
        list<int> nothing;
        productNum.bigInteger = nothing;
        int x = tempo.bigInteger.front() / num.bigInteger.front();
        if(x == 0){
            list<int>::iterator itTempo2 = tempo.bigInteger.begin();            
            ++itTempo2;
            int acum = (tempo.bigInteger.front() * 10) + *itTempo2;
            x = acum / num.bigInteger.front();
            if(num > tempo)
                tempo.bigInteger.push_back(*itTempo);
        }
        productNum.bigInteger.push_back(x);     
        productNum.auxProduct(num);
        if(productNum > tempo){
            --x;
            productNum.auxSubstract(num);
        }
        solution.push_back(x);
        tempo.auxSubstract(productNum);
        tempo.eraseZero();
        if(itTempo != bigInteger.end()){
            ++itTempo;
            tempo.bigInteger.push_back(*itTempo);
            while(num > tempo && itTempo != bigInteger.end()){
                ++itTempo;
                tempo.bigInteger.push_back(*itTempo);
                solution.push_back(0);
            }
            } else if( itTempo == bigInteger.end() && num > tempo)
                solution.push_back(0);
    }
    bigInteger = solution;         
}

// Residuo División (remainder)
void BigInteger::remainder(BigInteger &num){
    BigInteger saver;
    saver.bigInteger = bigInteger;
    bool flag = true;
    sign = true;
    if(num > saver){
        list<int>zero;
        zero.push_back(0);
        bigInteger = zero;
        flag = false;
    }
    int size = num.bigInteger.size();
    BigInteger tempo;
    BigInteger productNum;
    list<int>::iterator itList = bigInteger.begin();
    list<int>::iterator itTempo = next(itList, size);
    list<int> tempoList(itList, itTempo);
    list<int> solution;
    list<int> productNumList;
    tempo.bigInteger = tempoList;
    --itTempo;
    if(num > tempo && flag){
        ++itTempo;
        tempo.bigInteger.push_back(*itTempo);
    }
    while(itTempo != bigInteger.end() && flag){
        list<int> nothing;
        productNum.bigInteger = nothing;
        int x = tempo.bigInteger.front() / num.bigInteger.front();
        if(x == 0){
            list<int>::iterator itTempo2 = tempo.bigInteger.begin();            
            ++itTempo2;
            int acum = (tempo.bigInteger.front() * 10) + *itTempo2;
            x = acum / num.bigInteger.front();
            if(num > tempo)
                tempo.bigInteger.push_back(*itTempo);
        }
        productNum.bigInteger.push_back(x);     
        productNum.auxProduct(num);
        if(productNum > tempo){
            --x;
            productNum.auxSubstract(num);
        }
        solution.push_back(x);
        tempo.auxSubstract(productNum);
        tempo.eraseZero();
        if(itTempo != bigInteger.end()){
            ++itTempo;
            tempo.bigInteger.push_back(*itTempo);
            while(num > tempo && itTempo != bigInteger.end()){
                ++itTempo;
                tempo.bigInteger.push_back(*itTempo);
                solution.push_back(0);
            }
            } else if( itTempo == bigInteger.end() && num > tempo)
                solution.push_back(0);
    }
    if(flag){
    tempo.bigInteger.pop_back();
    bigInteger = tempo.bigInteger;  
    }
}    


// Potencia (pow)
void BigInteger::pow(int num){
    BigInteger copy;
    copy.bigInteger = bigInteger;
    if(sign == false && num % 2 == 0){
        sign = true;
    }
    for(int i = 1; i < num; i++)
        auxProduct(copy);
}

// Lista a String (toString)
string BigInteger::toString(){
    string bigIntegerCadena;
    list<int>::iterator it = bigInteger.begin();
    if(sign == false)
        bigIntegerCadena.push_back('-');
    while(it != bigInteger.end()){
        int num = *it + 48;
        bigIntegerCadena.push_back(num);
        it++;
    }
    return bigIntegerCadena;
}

/*        Funciones Analizadoras         */

int BigInteger::sizeInteger(){
    return bigInteger.size();
}






/*        Sobre cargas de operadores     */

BigInteger BigInteger::operator +(BigInteger &num){
    BigInteger temporal;
    BigInteger saverResult;
    temporal.bigInteger = bigInteger;
    temporal.sign = sign;
    if(sign == num.sign)
        auxAdd(num);
    else{
        if(num > temporal){
            sign = num.sign;
        }
        auxSubstract(num);
    }
    saverResult.bigInteger = bigInteger;
    saverResult.sign = sign;
    bigInteger = temporal.bigInteger;
    sign = temporal.sign;
    return saverResult;
}
BigInteger BigInteger::operator -(BigInteger &num){
    BigInteger temporal;
    BigInteger saverResult;
    temporal.bigInteger = bigInteger;
    temporal.sign = sign;

    if(sign == num.sign){
    if(sign == false && num.sign == false){
        if(num > temporal)
            sign = true;
    } else if(sign == true && num.sign == true){
            if(num > temporal)
            sign = false;
    }   
    auxSubstract(num);

    }else if(sign != num.sign)
        auxAdd(num);
    saverResult.bigInteger = bigInteger;
    saverResult.sign = sign;
    bigInteger = temporal.bigInteger;
    sign = temporal.sign;
    return saverResult;


}
bool BigInteger::operator >(BigInteger &num){

    list<int>::iterator t1 = bigInteger.begin();
    list<int>::iterator t2 = num.bigInteger.begin();
    int size1 = bigInteger.size();
    int size2 = num.bigInteger.size();
    bool flag = true;
    bool flag1 = true;
    if(size1 < size2)
        flag = false;
    else if(size1 == size2){
        while(t1 != bigInteger.end() && flag && flag1){
            if(*t1 > *t2)
                flag1 = false;                
            else if(*t1 < *t2)
                flag = false;
            ++t1;
            ++t2;
        }
    }
    return flag;    
}

BigInteger BigInteger::operator *(BigInteger &num){
    BigInteger temporal;
    BigInteger saverResult;
    temporal.bigInteger = bigInteger;
    temporal.sign = sign;

    int size = bigInteger.size();
    if(sign != num.sign)
        sign = false;
    else if(sign == num.sign)
        sign = true;
    auxProduct(num);
    saverResult.bigInteger = bigInteger;
    saverResult.sign = sign;
    bigInteger = temporal.bigInteger;
    sign = temporal.sign;

    return saverResult;
}


BigInteger BigInteger::operator /(BigInteger &num){
    BigInteger temporal;
    BigInteger saverResult;
    temporal.bigInteger = bigInteger;
    temporal.sign = sign;
    quotient(num);
    saverResult.bigInteger = bigInteger;
    saverResult.sign = sign;
    bigInteger = temporal.bigInteger;
    sign = temporal.sign;

    return saverResult;
}



BigInteger BigInteger::operator %(BigInteger &num){
    BigInteger temporal;
    BigInteger saverResult;
    temporal.bigInteger = bigInteger;
    temporal.sign = sign;
    remainder(num);
    saverResult.bigInteger = bigInteger;
    saverResult.sign = sign;
    bigInteger = temporal.bigInteger;
    sign = temporal.sign;

    return saverResult;
}

bool BigInteger::operator ==(BigInteger &num){
    list<int>::iterator t1 = bigInteger.begin();
    list<int>::iterator t2 = num.bigInteger.begin();
    int size1 = bigInteger.size();
    int size2 = num.bigInteger.size();
    bool flag = true;
    if(sign != num.sign){
        flag = false;
    } else if(sign == num.sign){
        if(size1 != size2)
            flag = false;
        else if(size1 == size2){
            while(t1 != bigInteger.end() && flag){
                if(*t1 != *t2)
                    flag = false;                         
            ++t1;
            ++t2;
            }

        }
    }
    return flag;   
}

bool BigInteger::operator<(BigInteger &num){
    list<int>::iterator t1 = bigInteger.begin();
    list<int>::iterator t2 = num.bigInteger.begin();
    int acum = 0;
    int size1 = bigInteger.size();
    int size2 = num.bigInteger.size();
    bool flag = true;
    if(sign == true && num.sign == false){
        flag = false;
    } else if(sign == num.sign){
        if(size1 > size2)
            flag = false;
        else if(size1 == size2){
            bool flag1 = true;
            while(t1 != bigInteger.end() && flag && flag1){
                if(*t1 < *t2){
                    flag1 = false;
                }
                else if(*t1 > *t2)
                    flag = false;   
                else if(*t1 == *t2)
                    acum++;                 
                ++t1;
                ++t2;
            }

        }
    }
    if(acum == size1)
        flag = false;
    return flag;
}

bool BigInteger::operator <=(BigInteger &num){
    list<int>::iterator t1 = bigInteger.begin();
    list<int>::iterator t2 = num.bigInteger.begin();
    int size1 = bigInteger.size();
    int size2 = num.bigInteger.size();
    bool flag = true;
    if(sign == true && num.sign == false){
        flag = false;
    } else if(sign == num.sign){
        if(size1 > size2)
            flag = false;
        else if(size1 == size2){
            bool flag1 = true;
            while(t1 != bigInteger.end() && flag && flag1){
              if(*t1 < *t2)
                flag1 = false;
            else if(*t1 > *t2)
                    flag = false;                           
                ++t1;
                ++t2;
            }

        }
    }
    return flag;
}

/*        Funciones Auxiliares           */

// Auxiliar (eliminar)
void BigInteger::eraseZero(){
    list<int>::iterator it = bigInteger.begin();
    bool flag = true;
    while(it != bigInteger.end() && flag){
        if(*it == 0)
            bigInteger.pop_front();
        else
            flag = false;
        ++it;
    } 
}

// Auxiliar (substract)

void BigInteger::auxSubstract(BigInteger &num){
        list<int> tmp;
        int sizeNum = num.bigInteger.size();
        int sizeList = bigInteger.size();
        int acum = 0;
        int size;
        if(sizeList < sizeNum){
            size = sizeNum - sizeList;
            for(int i = 0; i < size; i++)
                bigInteger.push_front(0);
            tmp = num.bigInteger;
            num.bigInteger = bigInteger;
            bigInteger = tmp;
        } else if(sizeList > sizeNum){
            size = sizeList - sizeNum;
            for(int i = 0; i < size; i++)
                num.bigInteger.push_front(0);
        } else if(sizeList == sizeNum){
            list<int>::iterator t1 = bigInteger.begin();
            list<int>::iterator t2 = num.bigInteger.begin();
            bool flag = true;
            while(t1 != bigInteger.end() && flag){
                if(*t1 < *t2){
                    tmp = num.bigInteger;
                    num.bigInteger = bigInteger;
                    bigInteger = tmp;
                    flag = false;                
                } else if(*t1 > *t2){
                    flag = false;
                }
                ++t1;
                ++t2;
            }
        }
        list<int>::reverse_iterator it1 = bigInteger.rbegin();
        list<int>::reverse_iterator it2 = num.bigInteger.rbegin();
        list<int>::reverse_iterator fin1 = bigInteger.rend();
        while(it1 != fin1){
            *it1 = *it1 - acum;
            if(*it1 < *it2){
                *it1 += 10;
                *it1 = *it1 - *it2;
                acum = 1;

            } else {
                *it1 = *it1 - *it2;
                acum = 0;
            }
            ++it1;
            ++it2;
        }  
        if(acum == 1)
            bigInteger.front() -= 1;
        if(!tmp.empty())
            num.bigInteger = tmp;
    eraseZero();
    num.eraseZero();
}


// Auxiliar (add)

void BigInteger::auxAdd(BigInteger &num){
        int extra = 0;
        int x = num.bigInteger.size();
        int y = bigInteger.size();
        int size;
        if(y < x){
            size = x - y;
            for(int i = 0; i < size; i++)
                bigInteger.push_front(0);
        } else {
            size = y - x;
            for(int i = 0; i < size; i++)
                num.bigInteger.push_front(0);
        }
        list<int>::reverse_iterator it1 = bigInteger.rbegin();
        list<int>::reverse_iterator it2 = num.bigInteger.rbegin();
        list<int>::reverse_iterator fin1 = bigInteger.rend();
        while(it1 != fin1){
            int acum = *it1 + *it2 + extra;
            if(acum >= 10){
                *it1 = acum % 10;
                extra = 1;
            } else {
                *it1 = acum;
                extra = 0;
            }
            ++it1;
            ++it2;
        }
        if(extra > 0)
            bigInteger.push_front(1);
    eraseZero();
    num.eraseZero();
}

// Auxiliar (Product)

void BigInteger::auxProduct(BigInteger &num){
    list<int> temporal;
    int size = bigInteger.size(); 
    for(int i = 0; i < size;i++)
        temporal.push_back(0);
    int add = 0;
    list<int>::reverse_iterator itnum = num.bigInteger.rbegin();
    while(itnum != num.bigInteger.rend()){
        int acum = 0;
        list<int>::reverse_iterator itmp = next(temporal.rbegin(),add);
        list<int>::reverse_iterator it = bigInteger.rbegin();
        while(it != bigInteger.rend()){
            int x = *itmp;
            *itmp = (*itmp + (*it * *itnum + acum))%10;
            acum = (x + (*it * *itnum + acum))/10;
            ++it;
            ++itmp;
        }
        if(acum > 0)
            temporal.push_front(acum);
        else 
            temporal.push_front(0);
        ++add;
        ++itnum;
    }
    list<int>::iterator it2 = temporal.begin();
    if(*it2 == 0)
        temporal.pop_front();
    bigInteger = temporal;
    eraseZero();
}

/*        Operaciones Estaticas          */

BigInteger BigInteger::sumarListaValores(list<BigInteger> &bigList){
    list<BigInteger>::iterator it = bigList.begin();
    BigInteger result;
    result = *it;
    ++it;
    while (it != bigList.end()){
        result = result + *it;
        ++it;
    }
    return result;
}

BigInteger BigInteger::multiplicarListaValores(list<BigInteger> &bigList){
    list<BigInteger>::iterator it = bigList.begin();
    BigInteger result;
    result = *it;
    ++it;
    while (it != bigList.end()){
        result = result * (*it);
        ++it;
    }
    return result;
}