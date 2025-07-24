//FormAI DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void myFunction(int num){
    if(num==0){
        perror("Error handling example");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Function executed successfully!\n");
    }
}

int main(){
    int num;
    printf("Enter a non-zero integer value:\n");
    scanf("%d",&num);
    myFunction(num);
    return 0;
}