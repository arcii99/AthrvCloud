//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>

// Function Prototype
void printStr(char* str);

int main()
{
    char* str = "Programming is ";
    printStr(str);

    return 0;
}

// Function Definition
void printStr(char* str)
{
    if (*str == '\0')
    {
      printf("cool!");
      return;
    }

    printf("%c", *str);
    printStr(str + 1);
}
/* 
Output:
P
r
o
g
r
a
m
m
i
n
g
i
s
c
o
o
l
! 
*/