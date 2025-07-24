//FormAI DATASET v1.0 Category: QR code generator ; Style: surprised
#include<stdio.h>

int main(){

    printf("Oh my! I can't believe I am generating my very own QR code!\n");

    int array[21][21];

    //Initialize array with zeros
    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            array[i][j] = 0;
        }
    }

    printf("My code array:\n");

    //Fill in the code squares
    for(int i=0; i<7; i++){
        for(int j=0; j<21; j++){
            if(j%2 == 0){
                array[i][j] = 1;
            }
        }
    }

    for(int i=14; i<21; i++){
        for(int j=0; j<21; j++){
            if(j%2 == 0){
                array[i][j] = 1;
            }
        }
    }

    for(int i=0; i<21; i++){
        for(int j=0; j<7; j++){
            if(i%2 == 0){
                array[i][j] = 1;
            }
        }
    }

    for(int i=0; i<21; i++){
        for(int j=14; j<21; j++){
            if(i%2 == 0){
                array[i][j] = 1;
            }
        }
    }

    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    printf("Wow!!! I have successfully generated my very own QR code. This is amazing! :)\n");

    return 0;
}