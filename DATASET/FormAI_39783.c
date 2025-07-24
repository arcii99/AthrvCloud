//FormAI DATASET v1.0 Category: Recursive ; Style: lively
#include<stdio.h>

void printDiamond(int num, int i, int j){
    if(i == num && j == 1){
        return;
    }
    else if(i <= num && j <= i){
        printf("*");
        j++;
        if(j > i){
            i++;
            j = 1;
            printf("\n");
        }
        printDiamond(num, i, j);
    }
    else if(i > num && j <= (2*num-i)){
        printf("*");
        j++;
        if(j > (2*num-i)){
            i++;
            j = 1;
            printf("\n");
        }
        printDiamond(num, i, j);
    }
}

int main(){
    int num;
    printf("Enter the number of lines for the diamond pattern: ");
    scanf("%d", &num);
    if(num%2 == 0){
        num = num + 1;
    }
    printDiamond(num, 1, 1);
    return 0;
}