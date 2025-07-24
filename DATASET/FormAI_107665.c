//FormAI DATASET v1.0 Category: Educational ; Style: light-weight
#include<stdio.h>

int main(){
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    if(age>=18){
        printf("You are eligible to vote!\n");
    }
    else{
        printf("Sorry, you are not eligible to vote yet.\n");
    }

    return 0;
}