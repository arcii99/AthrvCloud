//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

int main() {

    printf("Let's print a unique C pattern in style!\n\n");

    int i, j, k;

    for (i = 1; i <= 5; i++){

        for (j = 1; j <= i; j++){
            
            if (j == 1 || i == 5 || j == i){
                printf("*");
            }else{
                printf(" ");
            }
        }

        for (k = i + 1; k <= 5; k++){
            printf(" ");
        }

        for (j = 1; j <= i; j++){

            if (j == 1 || i == 5 || j == i){
                printf("*");
            }else{
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 5; i++){

        for (j = 1; j <= i; j++){
            
            if (j == 1 || i == 5 || j == i){
                printf("*");
            }else{
                printf(" ");
            }
        }

        for (k = i + 1; k <= 5; k++){
            printf(" ");
        }

        for (j = 1; j <= i; j++){

            if (j == 1 && i != 1 || i == 5 || j == i){
                printf("*");
            }else{
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 5; i++){

        for (j = 5; j >= i; j--){
            
            if (j == 5 || i == 1 || j == i){
                printf("*");
            }else{
                printf(" ");
            }
        }

        for (k = i + 1; k <= 5; k++){
            printf(" ");
        }

        for (j = 5; j >= i; j--){

            if (j == 5 || i == 1 || j == i){
                printf("*");
            }else{
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= 5; i++){

        for (j = 5; j >= i; j--){
            
            if (j == 5 && i != 1 || i == 5 || j == i){
                printf("*");
            }else{
                printf(" ");
            }
        }

        for (k = i + 1; k <= 5; k++){
            printf(" ");
        }

        for (j = 5; j >= i; j--){

            if (j == 5 && i != 1 || i == 5 || j == i){
                printf("*");
            }else{
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}