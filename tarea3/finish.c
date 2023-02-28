#include <stdio.h>
/* Código de estudiante: 8973440
   Sección: B */
int main(){
    int t, c;
    scanf("%d", &t);
    for(c = 1; c <= t; c++){
        int n, i, j, x;
        int station = 0, need = 0, gasolina = 0;
        scanf("%d", &n);
        int needgaso[n];
        n = n+1;
        int gasodispo[n];
        gasodispo[n-1] = 0;
        for(i = 0 ;i < n-1; i++){
            scanf("%d", &gasodispo[i]);
        }
        for(j = 0; j < n-1; j++){
            scanf("%d", &needgaso[j]);
        }
        for(x = 0; x < n-1; x++){
            if(gasodispo[x] >= needgaso[x]){
                gasodispo [x+1] += gasodispo[x]-needgaso[x];
                if (station == -1) {
                    station = x;
                }
            }else {
                gasolina += gasodispo[x];
                need += needgaso[x];
                station = -1;
            }
        }
        station += 1;
        gasodispo[n-1] += gasolina;
        gasodispo[n-1] -= need;
        if(gasodispo[n-1] >= 0){
            printf("Case %d: Possible from station %d\n", c, station);
        } else {
            printf("Case %d: Not possible\n", c);
        }

    }
    return 0;
}