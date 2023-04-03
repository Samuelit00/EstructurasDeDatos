#include <iostream>
#include <vector>
#include <string>
/*  Nombre : Samuel Francisco Moncayo Moncayo
    Código de estudiante: 8973440
   Sección: B
   Complejidad area de solución:
    Bloque de código:
     for(int j = 0; j < code.length(); j++){
             if (code[j] == ' '){
                bool flag = true;
                acum = code.substr(x, j - x);
			    for(int z = 0 ; z != abcMorse.size() && flag != false; z++){
                    if(acum == abcMorse[z]){
                    fin += abecedario[z];
                    flag = false;
                    x = j+1;
    R/ En este bloque encontramos 2 ciclos, sin embargo, uno depende de una condición
        por lo tanto es necesario separar la complejidad en peor y mejor caso, 1 en el
        que siempre se cumpla la condición y el otro en que nunca.

        Si observamos ambos ciclos recorren un vector o una cadena dependiendo del tamaño del
        mismo.
        
        En el mejor caso vemos que solo se iteraria el for externo por lo que daría una complejidad O(n)
        En el peor caso vemos que dentro del condicional iteraria otro for por lo que dará una complejidad O(n^2) */
using namespace std;

int main(){
    string arr1[54]={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5","6", "7", "8", "9", ".", ",", "?","'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "@"," "};
    string arr2[54]={".-", "-...", "-.-.", "-..", ".", "..-.","--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--","-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-.","_"};
    int num;
    vector<string> abecedario(arr1,arr1+54); 
    vector<string> abcMorse(arr2,arr2+54);
    cin >> num;
    cin.ignore();
    for(int i = 0; i < num; i++){
        string code, acum, fin;
        int x = 0;
        getline(cin,code);
        code.push_back(' ');
        for(int j = 0; j < code.length(); j++){
             if (code[j] == ' '){
                bool flag = true;
                acum = code.substr(x, j - x);
			    for(int z = 0 ; z != abcMorse.size() && flag != false; z++){
                    if(acum == abcMorse[z]){
                    fin += abecedario[z];
                    flag = false;
                    x = j+1;
                }
                }
            } if (code[j] == ' ' && code[j+1] == ' '){
                fin.append(" ");
                j += 2;
                x = j;;
            } 
        }
        cout << "Message #" << i+1 << endl; 
        cout << fin << endl;
        if (i < num-1){
            cout << endl;
        }
    }

    return 0;
}