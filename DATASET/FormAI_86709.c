//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include<stdio.h>
void recursive(int num);
int main(){
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Recursive sequence: ");
    recursive(num);

    return 0;
}

void recursive(int num){
    if (num == 1){
        printf("%d ", num);
        return;
    }

    printf("%d ", num);
    if (num % 2 == 0){
        recursive(num/2);
    }
    else {
        recursive(3*num + 1);
    }
}