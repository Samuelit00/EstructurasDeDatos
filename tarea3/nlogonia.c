#include <stdio.h>
/* Código de estudiante: 8973440
   Sección: B */
int main(){
    int k;
    scanf("%d", &k);
    while(k != 0){
        int n, m, i;
        scanf("%d", &n);
        scanf("%d", &m);
        for(i = 0; i < k ;i++){
            int x, y;
            scanf("%d", &x);
            scanf("%d", &y);
            if(x > n && y > m){
                printf("NE\n");
            }else if(x > n && y < m){
                printf("SE\n");
            }else if(x < n && y < m){
                printf("SO\n");
            }else if(x < n && y > m){
                printf("NO\n");
            }else if(x == n || y == m){
                printf("divisa\n");
        }
        }
        scanf("%d", &k);
    }
    return 0;
}