#include <vector>
#include <iostream>
#include <list>
#include <string>
using namespace std;
/*  Nombre : Samuel Francisco Moncayo Moncayo
    Código de estudiante: 8973440
   Sección: B
*/
class BigInteger {
    private:

    
    list<int> bigInteger;
    bool sign;
    public:
    /* Constructoras */

    BigInteger(const string &num){
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

    /* Sobrecargas */

bool operator ==(BigInteger &num){
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

bool operator<(BigInteger &num){
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

};



int main(){
    string firstPart;
    int acum = 1;
    while(getline(cin,firstPart)){
        vector<int> fractionPart1;
        vector<int> fractionPart2;
        string number = firstPart;
        string number1;
        string fraction1;
        string number2;
        string fraction2;
        bool flag1 = true;
        bool flag2 = false;
        bool flag3 = false;
        int size = number.size(); 
        for (int i = 0; i < size; i++){
            
            if(number[i] != '.' && flag1 && !flag2){
                number1.push_back(number[i]);
            }else if(number[i] == '.' && !flag2){
                flag1 = false;
            }else if(number[i] != ' ' && !flag1 && !flag2){
                fraction1.push_back(number[i]);
            }else if(number[i] ==' ')
                flag2 = true;
            else if(number[i] != '.' && flag2 && !flag3)
                number2.push_back(number[i]);
            else if(number[i] == '.' && flag2){
                flag3 = true;
            } else if(flag3)
                fraction2.push_back(number[i]);

        }
        BigInteger integerPart1(number1);
        BigInteger integerPart2(number2);
        for(int x = 0; x < fraction1.size(); x++){
            int numero = fraction1[x] - 48;
            fractionPart1.push_back(numero);
        }
        for(int y = 0; y < fraction2.size(); y++){
            int num = fraction2[y] - 48;
            fractionPart2.push_back(num);
        }
        if(integerPart1 < integerPart2){
            cout << "Case " << acum << ": " << "Smaller" << endl;
        } else if(integerPart1 == integerPart2){
            int size1 = fractionPart1.size();
            int size2 = fractionPart2.size();
            int size;
            bool flag = true;
            if(size1 > size2)
                size = size2;
            else
                size = size1;
            bool bandera = true;
            for (int w = 0; w < size1 && bandera; w++){
                if( fractionPart1[w] != 0)
                    bandera = false;
            }
            for (int j = 0; j < size2 && bandera; j++){
                if( fractionPart2[j] != 0)
                    bandera = false;
            }
            
            for(int z = 0; z < size && flag && !bandera; z++){
                cout << fractionPart1[z] << " " << fractionPart2[z] << endl;
                if(fractionPart1[z] < fractionPart2[z]){
                    cout << "Case " << acum << ": " << "Smaller" << endl;
                    flag = false;
                } else if ( fractionPart1[z] > fractionPart2[z]){
                    cout << "Case " << acum << ": " << "Bigger" << endl;
                    flag = false;
                }
            }
            if (flag || bandera){
                cout << "Case " << acum << ": " << "Same" << endl;
            }
        } else 
            cout << "Case " << acum << ": " << "Bigger" << endl;
        ++acum;
    }
    
          
}