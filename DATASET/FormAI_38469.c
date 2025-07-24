//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The prime numbers between 1 and %d are: ", num);
    int i, j, flag;
    for(i = 2; i <= num; i++){
        flag = 0;
        for(j = 2; j < i; j++){
            if(i % j == 0){
                flag = 1;
            }
        }
        if(flag == 0){
            printf("%d ", i);
        }
    }
    return 0;
}