//FormAI DATASET v1.0 Category: Recursive ; Style: retro
#include<stdio.h>

void retro_print(int n)
{
    if(n == 0)
        return;
    retro_print(n-1);
    printf("%d\n", n);
    return;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    retro_print(n);
    return 0;
}