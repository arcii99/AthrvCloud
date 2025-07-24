//FormAI DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[30]="Coding with";
    char str2[10]="bot";
    char str3[30];
    int i,j,n,k;

    printf("Original string: %s\n", str1);
    printf("String to concatenate : %s\n", str2);

    // String concatenation
    for(i=0; str1[i]!='\0'; i++)
        str3[i]=str1[i];
    for(j=0; str2[j]!='\0'; j++)
        str3[i+j]=str2[j];
    str3[i+j]='\0';
    printf("Concatenated string: %s\n", str3);

    // String reversal
    n=strlen(str3);
    for(k=n-1; k>=0; k--)
        printf("%c", str3[k]);
    printf("\n");

    // String copying
    char str4[10];
    strcpy(str4,"Hello");
    printf("Copied string: %s\n", str4);

    // String comparison
    char str5[10]="hello";
    int cmp;
    cmp=strcmp(str4, str5);
    if(cmp==0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");

    return 0;
}