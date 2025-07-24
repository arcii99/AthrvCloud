//FormAI DATASET v1.0 Category: Pattern printing ; Style: funny
#include<stdio.h>
#include<stdlib.h>
int main(){
    int count = 20; // Change this number to change the size of pattern
    printf("HaHaHa! Welcome to the unique C pattern printing program!!\n\n");
    for(int i=0; i<count; i++){
        printf("*");
        if(i>count/3 && i<count/2){
            for(int j=0; j<(count-i)*2; j++){
                printf(" ");
            }
            printf("*");
        }
        if(i>count/2){
            for(int j=0; j<(i-count/2)*2; j++){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    for(int i=0; i<count; i++){
        printf("*");
        if(i<count/3){
            for(int j=0; j<i*2; j++){
                printf(" ");
            }
            printf("*");
        }
        if(i>count/3 && i<count/2){
            for(int j=0; j<(count-i)*2; j++){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    printf("TADAAA!!! The pattern is ready! :)\n\n");
    return 0;
}