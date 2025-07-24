//FormAI DATASET v1.0 Category: Text processing ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

void reverse(char [], int, int); // function to reverse a string recursively

int main()
{
    char str[100];
    int l = 0, r;

    printf("Enter a string: ");
    fgets(str, 100, stdin); // read input string

    while (str[l] != '\0') // calculate length of string
        l++;
    r = l - 1; // set right index to last character

    printf("Original string: %s", str);

    reverse(str, l, r); // call reverse function

    printf("Reversed string: %s", str);

    return 0;
}

void reverse(char str[], int l, int r)
{
    if (l <= r) // base condition
    {
        char temp = str[l];
        str[l] = str[r];
        str[r] = temp;

        reverse(str, l + 1, r - 1); // recursive call
    }
}