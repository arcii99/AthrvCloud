//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void fun1()
{
    FILE *fp= fopen("file.txt", "r");
    if(fp==NULL)
    {
        perror("Error Occurred");
        exit(EXIT_FAILURE);
    }
    printf("File opened successfully\n");
}

void fun2()
{
    int a=5, b=0, result;
    if(b==0)
    {
        errno=EINVAL;
        perror("Error Occurred");
        exit(EXIT_FAILURE);
    }
    result= a/b;
    printf("Result: %d", result);
}

void fun3()
{
    char *ptr= malloc(sizeof(char)*10);
    if(ptr==NULL)
    {
        perror("Error Occurred");
        exit(EXIT_FAILURE);
    }
    printf("Memory allocated successfully\n");
    free(ptr);
}

int main()
{
    fun1();
    fun2();
    fun3();
    return 0;
}