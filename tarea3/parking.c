#include <stdio.h>
/* Código de estudiante: 8973440
   Sección: B */
int main(){
    int positionStores,cases, stores,x,j;
    scanf("%d", &cases);
    for(x=0 ; x < cases; x++){
        int max = 0;
        int min = 100;
        scanf("%d", &stores);
        for(j=0; j < stores; j++){
           scanf("%d", &positionStores);
            if (max < positionStores){
                max = positionStores;
                }
            if(min>positionStores){
                min =positionStores;
                }
        }
        printf("%d\n", (max-min)*2);          
    }
    return 0;
}