//FormAI DATASET v1.0 Category: Fractal Generation ; Style: puzzling
#include <stdio.h>

int main()
{
    int i, j, k;
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            k = ((i*i)-(j*j));
            if(k < 0) k *= -1;
            if(k % 7 == 0) printf("*");
            else if(k % 5 == 0) printf("=");
            else if(k % 3 == 0) printf("+");
            else printf("-");
        }
        printf("\n");
    }
    return 0;
}