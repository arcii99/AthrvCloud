//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>

int main(){
    int num_discs = 4;
    int moves = 0;
    int source[] = {4,3,2,1};
    int aux[] = {0,0,0,0};
    int dest[] = {0,0,0,0};

    printf("Current position:\n");
    printf("Source: ");
    for(int i=0; i<num_discs; i++)
        printf("%d ", source[i]);
    printf("\nAuxiliary: ");
    for(int i=0; i<num_discs; i++)
        printf("%d ", aux[i]);
    printf("\nDestination: ");
    for(int i=0; i<num_discs; i++)
        printf("%d ", dest[i]);
    printf("\n\n");

    while(dest[num_discs-1] != 4){
        if(num_discs%2 == 0){
            if(source[num_discs-1] == 4){
                source[num_discs-1] = 0;
                dest[3] = 4;
                moves++;
            }
            else if(aux[num_discs-1] == 4){
                aux[num_discs-1] = 0;
                dest[3] = 4;
                moves++;
            }
            else if(dest[num_discs-1] == 4){
                dest[num_discs-1] = 0;
                source[3] = 4;
                moves++;
            }
            if(source[num_discs-2] == 3){
                source[num_discs-2] = 0;
                aux[3] = 3;
                moves++;
            }
            else if(aux[num_discs-2] == 3){
                aux[num_discs-2] = 0;
                source[3] = 3;
                moves++;
            }
            else if(dest[num_discs-2] == 3){
                dest[num_discs-2] = 0;
                source[3] = 3;
                moves++;
            }
            if(source[num_discs-3] == 2){
                source[num_discs-3] = 0;
                dest[2] = 2;
                moves++;
            }
            else if(aux[num_discs-3] == 2){
                aux[num_discs-3] = 0;
                dest[2] = 2;
                moves++;
            }
            else if(dest[num_discs-3] == 2){
                dest[num_discs-3] = 0;
                aux[2] = 2;
                moves++;
            }
            if(source[num_discs-4] == 1){
                source[num_discs-4] = 0;
                aux[1] = 1;
                moves++;
            }
            else if(aux[num_discs-4] == 1){
                aux[num_discs-4] = 0;
                source[1] = 1;
                moves++;
            }
            else if(dest[num_discs-4] == 1){
                dest[num_discs-4] = 0;
                source[1] = 1;
                moves++;
            }
        }
        else{
            if(source[num_discs-1] == 4){
                source[num_discs-1] = 0;
                aux[3] = 4;
                moves++;
            }
            else if(aux[num_discs-1] == 4){
                aux[num_discs-1] = 0;
                source[3] = 4;
                moves++;
            }
            else if(dest[num_discs-1] == 4){
                dest[num_discs-1] = 0;
                source[3] = 4;
                moves++;
            }
            if(source[num_discs-2] == 3){
                source[num_discs-2] = 0;
                dest[3] = 3;
                moves++;
            }
            else if(aux[num_discs-2] == 3){
                aux[num_discs-2] = 0;
                dest[3] = 3;
                moves++;
            }
            else if(dest[num_discs-2] == 3){
                dest[num_discs-2] = 0;
                source[2] = 3;
                moves++;
            }
            if(source[num_discs-3] == 2){
                source[num_discs-3] = 0;
                aux[2] = 2;
                moves++;
            }
            else if(aux[num_discs-3] == 2){
                aux[num_discs-3] = 0;
                source[2] = 2;
                moves++;
            }
            else if(dest[num_discs-3] == 2){
                dest[num_discs-3] = 0;
                source[2] = 2;
                moves++;
            }
            if(source[num_discs-4] == 1){
                source[num_discs-4] = 0;
                dest[1] = 1;
                moves++;
            }
            else if(aux[num_discs-4] == 1){
                aux[num_discs-4] = 0;
                dest[1] = 1;
                moves++;
            }
            else if(dest[num_discs-4] == 1){
                dest[num_discs-4] = 0;
                aux[1] = 1;
                moves++;
            }
        }

        printf("Move #%d:\n", moves);
        printf("Source: ");
        for(int i=0; i<num_discs; i++)
            printf("%d ", source[i]);
        printf("\nAuxiliary: ");
        for(int i=0; i<num_discs; i++)
            printf("%d ", aux[i]);
        printf("\nDestination: ");
        for(int i=0; i<num_discs; i++)
            printf("%d ", dest[i]);
        printf("\n\n");
    }
    printf("Total moves: %d\n", moves);
    return 0;
}