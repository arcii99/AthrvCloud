//FormAI DATASET v1.0 Category: Password management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(){
    char password[MAX], confirm[MAX];
    int match;
    
    printf("Please enter your desired password:\n");
    scanf("%s", password);
    
    do{
        printf("Please re-enter your password:\n");
        scanf("%s", confirm);
        match = strcmp(password, confirm);
        if(match != 0){
            printf("The passwords do not match. Please try again.\n");
        }
    }while(match != 0);
    
    printf("Password successfully set as: %s", password);
    
    return 0;
}