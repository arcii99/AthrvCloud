//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>

int main() {
    char str[1000];
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Counting number of vowels, consonants and spaces in the given string
    for(int i=0; str[i]!='\0'; i++) {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
           str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
            count++;
        }
    }

    printf("\nNumber of vowels in the string: %d", count);

    count = 0;

    for(int i=0; str[i]!='\0'; i++) {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
            if(!(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
               str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')) {

                count++;
            }
        }
    }

    printf("\nNumber of consonants in the string: %d", count);

    count = 0;

    for(int i=0; str[i]!='\0'; i++) {
        if(str[i]==' ') {
            count++;
        }
    }

    printf("\nNumber of spaces in the string: %d", count);

    return 0;
}