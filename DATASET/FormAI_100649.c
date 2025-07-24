//FormAI DATASET v1.0 Category: Fractal Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int n, i, j, k, max_num;
    float x, y, z, c;

    printf("Enter the number of iterations:");
    scanf("%d", &n);

    printf("Enter the maximum value of the numbers:");
    scanf("%d", &max_num);

    for(i=0; i<=max_num; i++){
        for(j=0; j<=max_num; j++){
            x = y = z = 0;
            c = ((float)i/max_num-0.5)*2;
            x = c;
            c = ((float)j/max_num-0.5)*2;
            y = c;

            for(k=0; k<n; k++){
                c = x*x - y*y;
                y = 2*x*y;
                x = c;
                z = x*x + y*y;
                if(z>4){
                    break;
                }
            }

            if(k==n){
                printf("%c", 'O');
            }else{
                printf("%c", '.');
            }
        }
        printf("\n");
    }

    return 0;
}