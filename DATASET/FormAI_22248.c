//FormAI DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>

void reverse(char str[])
{
    int i=0, j=strlen(str)-1;
    char temp;
    while(i<j)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

void concatenate(char str1[], char str2[])
{
    int l=strlen(str1);
    for(int i=0; i<strlen(str2); i++)
    {
        str1[l+i]=str2[i];
    }
}

int main()
{
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%[^\n]s", str1);
    getchar();
    printf("Enter second string: ");
    scanf("%[^\n]s", str2);
    printf("\nOriginal strings:\nString 1: %s\nString 2: %s\n", str1, str2);
    reverse(str1);
    printf("\nAfter reversing first string:\nString 1: %s\n", str1);
    concatenate(str1, str2);
    printf("\nAfter concatenating both strings:\nString 1: %s\nString 2: %s\n", str1, str2);
    
    return 0;
}