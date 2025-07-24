//FormAI DATASET v1.0 Category: Pattern printing ; Style: secure
#include<stdio.h>
#include<string.h>

int main(){

    char username[50]; 
    int length,i,j,k;
   
    printf("Enter your username: ");
    scanf("%s", username);

    // determine length of username
    length = strlen(username);

    // printing C pattern
    for(i=0; i<length; i++){
        printf("*");
    } 

    printf("\n");

    for(j=length-2; j>=0; j--){
        for(k=0; k<=length-1; k++){
            if(k==j || k==length-1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    for(i=0; i<length; i++){
        printf("*");
    }

    printf("\n");

    return 0;
}