//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH 1000

char c_alien_language[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

char english_language[] = {'E', 'N', 'O', 'S', 'T', 'Z', 'B', 'L', 'X', 'K', 'D', 'C', 'M', 'J', 'W', 'P', 'R', 'F', 'G', 'U', 'I', 'V', 'Y', 'H', 'A', 'Q', '_'};

int find_index(char *arr, char item) {
    int i;
    for(i = 0; i < strlen(arr); i++) {
        if(arr[i] == item) return i;
    }
    return -1;
}

int main() {
    char input[MAX_INPUT_LENGTH], output[MAX_OUTPUT_LENGTH];
    int i, j, index;
    
    printf("Enter the input text: ");
    scanf("%[^\n]", input);
    
    for(i = 0; i < strlen(input); i++) {
        index = find_index(c_alien_language, input[i]);
        if(index != -1) {
            output[i] = english_language[index];
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';
    
    printf("The translated text is: %s\n", output);
    return 0;
}