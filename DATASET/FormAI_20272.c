//FormAI DATASET v1.0 Category: Error handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &num);

    if(num < 1 || num > 10) {
        perror("\x45\x52\x52\x4F\x52\x3A Invalid input. ");
        exit(1);
    }

    int arr[num];
    int i;

    for(i = 0; i < num; i++) {
        printf("Enter a number: ");
        if(scanf("%d", &arr[i]) != 1) {
            perror("\x45\x52\x52\x4F\x52\x3A Invalid input. ");
            exit(1);
        }
    }

    printf("The numbers you entered are: ");
    for(i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}