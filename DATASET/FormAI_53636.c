//FormAI DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100], temp[100], output[200];
    int i, j, k, len, flag;

    printf("Enter a string: ");
    fgets(input, 100, stdin); // gets input from user

    len = strlen(input);

    for(i = 0, j = 0; i < len; i++) {
        flag = 0;
        if(input[i] == 'a' || input[i] == 'A') {
            for(k=i; k < len && input[k] != '\0'; k++) {
                if(input[k] == ' ') {
                    flag = 1;
                    break;
                }
                temp[j++] = input[k];
            }
 
            if(flag == 0) // If word doesn't contain space add blank space
                temp[j++] = ' ';

            temp[j++] = 'A';
            temp[j++] = 't';
            temp[j++] = ',';
            temp[j++] = ' ';

            i = k; // Increment i to the end of the word
        }
        else {
            temp[j++] = input[i];
        }
    }

    temp[j] = '\0';

    printf("\nModified string is: %s\n", temp);

    // reverse the modified string
    len = strlen(temp);
    for(i = len-1, j = 0; i >= 0; i--, j++) {
        output[j] = temp[i];
    }
    output[j] = '\0';

    printf("\nReversed modified string is: %s\n", output);
    
    return 0;
}