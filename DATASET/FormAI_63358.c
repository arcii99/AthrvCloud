//FormAI DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char str[100], temp;
    int i, j, len;
    
    // Get user input for string
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    // Find the length of the string
    len = strlen(str) - 1;
    
    // Reverse the string
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Display the reversed string
    printf("Reversed string: %s\n", str);
    
    // Count the number of vowels in the string
    int count = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
                || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            count++;
    }

    // Display the number of vowels
    printf("Number of vowels in the string: %d\n", count);

    // Convert the string to all uppercase letters
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }

    // Display the uppercase string
    printf("Uppercase string: %s\n", str);

    // Remove all spaces from the string
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            j = i;
            do {
                str[j] = str[j+1];
                j++;
            } while(str[j] != '\0');
        }
    }

    // Display the string without spaces
    printf("String without spaces: %s\n", str);

    return EXIT_SUCCESS;
}