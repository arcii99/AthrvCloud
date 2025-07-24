//FormAI DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_string[100];
    char first_name[50];
    char last_name[50];
    int string_len, i, j, first_name_len, last_name_len;
    
    printf("Please enter your full name: ");
    fgets(input_string, 100, stdin);
    
    string_len = strlen(input_string) - 1;
    for (i = 0; i < string_len; i++) {
        if (input_string[i] == ' ') {
            break;
        } else {
            first_name[i] = input_string[i];
        }
    }
    first_name[i] = '\0';
    
    for (j = i + 1; j < string_len; j++) {
        last_name[j-i-1] = input_string[j];
    }
    last_name[j-i-1] = '\0';
    
    first_name_len = strlen(first_name);
    last_name_len = strlen(last_name);
    
    // Capitalize first name
    for (i = 0; i < first_name_len; i++) {
        if (first_name[i] >= 'a' && first_name[i] <= 'z') {
            first_name[i] -= 32;
        }
    }
    
    // Reverse last name
    char temp;
    for (i = 0; i < last_name_len/2; i++) {
        temp = last_name[i];
        last_name[i] = last_name[last_name_len - i - 1];
        last_name[last_name_len - i - 1] = temp;
    }
    
    printf("Your new name is %s %s\n", first_name, last_name);
    
    return 0;
}