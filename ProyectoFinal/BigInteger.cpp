#include <BigInteger.h>

BigInteger::BigInteger(Elemento elem){

    while (elem > 0) {
        int digito = elem % 10;
        bigInteger.push_back(digito);
        elem /= 10;
    }    
    if(elem < 0)
        bigInteger.push_back(1);
    else
        bigInteger.push_back(0);
}

BigInteger::BigInteger(){
    copybigInteger = bigInteger;
}

void BigInteger::add(BigInteger &num){
    int size = bigInteger.size();
    for (int i = -2; i > 0; i++){
        int acum = bigInteger[i] + num.bigInteger[i];
        if(acum > 10){
            bigInteger[i] = acum % 10;
            bigInteger[i-1]++;
        } else {
            bigInteger[i] = acum;
        }
    }
    int acum2 = bigInteger[0] + num.bigInteger[0];
    if(acum2 > 10){
        bigInteger[0] = acum2 % 10;
        bigInteger.insert(bigInteger.begin(),1);
    } else {
        bigInteger[0] = acum2;
    }
}
void BigInteger::substract(BigInteger &num){
    int size = bigInteger.size();

    if(bigInteger[bigInteger.size()] == 0 && num.bigInteger[num.bigInteger.size()] == 1)
        add(num);
    else if(bigInteger[bigInteger.size()] == 1 && num.bigInteger[num.bigInteger.size()] == 0)
        add(num);
    else{
        for (int i = -2; i > 0; i++){
            if(bigInteger[i] < num.bigInteger[i]){
                bigInteger[i] += 10;
                bigInteger[i] - num.bigInteger[i];

            } else {
                bigInteger[i] - num.bigInteger[i];
            }
        }        
}
