//FormAI DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //declaring variables
    char str[100], temp;
    int i, j, len;

    //input string
    printf("Enter a string: ");
    scanf("%s", str);

    //calculating the length of the string
    len = strlen(str);

    //reversing the string
    for(i=0, j=len-1; i<len/2; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    //converting the string to uppercase
    for(i=0; i<len; i++){
        if(str[i]>=97 && str[i]<=122) str[i] -= 32;
    }

    //counting the number of vowels and consonants
    int vowels=0, consonants=0;
    for(i=0; i<len; i++){
        if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') vowels++;
        else if((str[i]>='A'&& str[i]<='Z')) consonants++;
    }

    //displaying the output
    printf("\n\nThe reversed uppercase string is: %s\n", str);
    printf("Number of vowels in the string = %d\n", vowels);
    printf("Number of consonants in the string = %d\n", consonants);

    return 0;
}