#include <stdio.h>
/* Código de estudiante: 8973440
   Sección: B */
int main(){
    int n, i, j ;
    while(scanf("%d", &n) != EOF){
        int suma = 0, diff = 0;
        int arr[n];
        scanf("%d", &arr[0]);
        scanf("%d", &arr[1]);
        for(j=1; j < n; j++){
        suma += j;
        }
        diff =+ (arr[0]-arr[1]);
        if(diff< 0){
            diff = (arr[0]-arr[1])*-1;
        } 
        for(i = 2; i < n; i++){
            int diff2 = 0;
            scanf("%d", &arr[i]);
            diff2 = (arr[i-1]-arr[i]);
            if(diff2 < 0){
                diff2 = (arr[i-1]-arr[i])*-1;
            }      
            diff += diff2;
        }
        if(suma == diff){
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
    return 0;
}