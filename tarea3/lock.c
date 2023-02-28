#include <stdio.h>
/* Código de estudiante: 8973440
   Sección: B */
int main(){
    int initial, digit1, digit2, digit3;
    scanf("%d", &initial);
    scanf("%d", &digit1);
    scanf("%d", &digit2);
    scanf("%d", &digit3);
    while(initial != 0 || digit1 != 0 || digit2 !=0 || digit3 !=0){
        int deagrees = 1080;
        if(digit1 <= initial){
            deagrees+=(initial-digit1)*9;
        } else {
            deagrees += ((40-digit1)+initial)*9;            
        }
        if(digit1 <= digit2){
            deagrees += (digit2-digit1)*9;

        } else {
            deagrees += ((40-digit1)+digit2)*9;
        }
        if(digit2 >= digit3){
            deagrees += (digit2-digit3)*9;
        } else {
        deagrees += ((40-digit3)+digit2)*9;
        }
        printf("%d\n", deagrees);

        scanf("%d", &initial);
        scanf("%d", &digit1);
        scanf("%d", &digit2);
        scanf("%d", &digit3);
    }

    return 0;

}