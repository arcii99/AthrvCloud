//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include<stdio.h>

int happyNumber(int number){
    int digits = 0;
    int sum = 0;
    int temp = number;
    while(temp != 0){
        digits = temp % 10;
        sum = sum + digits*digits;
        temp = temp/10;
    }
    if(sum == 1){
        return 1;
    }else if(sum == 4){
        return 0; // unhappy
    }else{
        return happyNumber(sum);
    }
}

int main(){
    int choice;
    printf("Welcome to the Happy Number Checker!\n");
    printf("Enter a number: ");
    scanf("%d", &choice);
    if(happyNumber(choice)){
        printf("%d is a Happy Number!\n", choice);
    }else{
        printf("%d is an Unhappy Number :(\n", choice);
    }
    return 0;
}