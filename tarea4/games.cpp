#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
/*  Nombre : Samuel Francisco Moncayo Moncayo
    Código de estudiante: 8973440
   Sección: B
   Complejidad area de solución:
   Función: Comparador nomnres
   R/En esta función encontramos varios condicionales y algunos ciclos dentro de los
   mismos por lo que es necesario obtener mejor y peor caso.

    Si observamos si se cumple alguno de los primeros condicionales sin ciclos
    la complejidad seria O(1), pero si por el contrario no se cumple ninguno una
    complejidad de O(n^3).*/
using namespace std;

void organizarNombres(vector<string>& names){
    for(int i = 0; i < names.size(); i++){
        sort(names.begin(),names.end());
    }
}

string comparadorNombres(vector<string> invitados ,vector<string> abecedario, char* arr){
    string who;
    int nombre1;
    int nombre2;
    bool flag = true;
    if(invitados.size() % 2 == 0){
        nombre1 = (invitados.size() / 2) - 1;
        nombre2 = (invitados.size() / 2) ;
    } else if(invitados.size() % 2 != 0){
        nombre1 = (invitados.size() / 2) ;
        nombre2 = (invitados.size() / 2) + 1;
    }
    string name1 = invitados[nombre1];
    string name2 = invitados[nombre2];
    if(name1 == name2 && flag == true){
        who = name1;
        flag = false;
    }
    if(name2.find(name1) != string :: npos && flag == true){
        if(name1 < name2){
            who = name1;
            flag = false;
        } 
    }
    for(int j = 0; j < 26 && flag == true; j++){
        string letra1 = abecedario[j];
        if(letra1 > name1 && letra1 < name2){
            who.append(letra1);
            flag = false;
            }
        }
    int acum = 0;
    for(int x= 0; x < name1.length() && flag == true;x++){
        bool flag1 = true;
        for(int i = 0; i < 26 && flag1 == true; i++){
            char letra = arr[i];
            int letraINT = arr[i];
            int letra1 = name1[x];
            int letra2 = name2[x];
           if(letra == name1[x] && letra == name2[x]){
                who.push_back(letra);
                flag1 = false;
                acum = x + 1;
            }
            if(letra2 - letra1 == 1){
                if(name2.length() == 1){
                    who.push_back(char(letra1));
                    flag1 = false;
                } else {
                    who.push_back(char(letra2));
                    flag1 = false;
                }
            }
            if(letra == name1[x] && letra > name2[x]){
                if(letra != 'Z'){
                    who.push_back(arr[i+1]);
                    flag = false;
                    } else {
                        who.push_back('Z');
                        flag1 = false;
                    } 
            }
            if(acum != 0){
                for(int z = 0; z < 26 && flag == true; z++){   
                    char let = arr[z];            
                    if(let > name1[acum] && let < name2[acum]){
                        who.push_back(let);
                        flag = false;
                    }
                }
            }
        }
    }

    return who;
}
int main(){
    string arr1[26]={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    char arr2[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int n;
    vector<string> abc(arr1,arr1+26);
    cin >> n;
    cin.ignore();
    while(n != 0){
        string name;
        vector<string> lista;
        for(int i = 0; i < n; i++){
            string nombres;
            getline(cin, nombres);
            lista.push_back(nombres);
        }
        organizarNombres(lista);
        name = comparadorNombres(lista,abc, arr2);
        cout << name << endl;

        cin >> n;
        cin.ignore();
    }
    return 0;
}