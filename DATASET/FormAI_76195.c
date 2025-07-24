//FormAI DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // read user input
    str[strcspn(str, "\n")] = 0; // remove newline character from input
    
    int len = strlen(str);
    char new_str[100];
    
    for(int i=0; i<len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') { // if lowercase character
            new_str[i] = 'A' + (str[i] - 'a'); // convert to uppercase
        } else if(str[i] >= 'A' && str[i] <= 'Z') { // if uppercase character
            new_str[i] = 'a' + (str[i] - 'A'); // convert to lowercase
        } else { // if not a letter, leave as is
            new_str[i] = str[i];
        }
    }
    
    printf("Original string: %s\n", str);
    printf("Processed string: %s\n", new_str);
    
    return 0;
}