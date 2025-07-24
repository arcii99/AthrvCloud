//FormAI DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[1000];
    int count = 0;
    printf("Enter the string: ");
    fgets(input, 1000, stdin);

    for(int i=0; i<strlen(input); i++) {
        if(isalpha(input[i])) {
            count++;
            while(isalpha(input[i])){
                i++;
            }
        }
    }

    printf("The word count of the given string is: %d", count);

    return 0;
}