//FormAI DATASET v1.0 Category: Pattern printing ; Style: modular
#include<stdio.h>
void left_half(int h)
{
    int i, j;
    for(i=1; i<=h; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
void right_half(int h)
{
    int i, j, k;
    for(i=h; i>=1; i--)
    {
        for(k=h-i; k>=1; k--)
        {
            printf("  ");
        }
        for(j=1; j<=i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
void print_C(int h)
{
    printf("\n");
    left_half(h-1);
    right_half(h);
}
int main()
{
    int height;
    printf("Enter the height of C: ");
    scanf("%d", &height);
    print_C(height);
    return 0;
}