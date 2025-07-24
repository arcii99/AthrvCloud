//FormAI DATASET v1.0 Category: Recursive ; Style: Cyberpunk
#include <stdio.h>

int hacker(int n)
{
    if (n == 0)
    {
        return 1; //base case
    }
    else
    {
        int x = hacker(n - 1);
        printf("%d yB", x); //cyberpunk print statement
        return x + 1;
    }
}

int main()
{
    int n;
    printf("Enter a number to hack: ");
    scanf("%d", &n); //input cybercode from user
    int result = hacker(n); //enter the cyberworld of recursion
    printf("\nYour system has been hacked! Access granted.");
    return 0;
}