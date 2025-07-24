//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <pthread.h>

#define BUFFER_SIZE 256      /* Maximum size of input buffer */

char *hex_table = "0123456789ABCDEF";         /* Char array for Hexadecimal conversion */

/* Function prototype declarations */
void *convert(void *str);
bool is_hexadecimal(char *str);

/* Main function */
int main() {
    char input[BUFFER_SIZE];        /* Input buffer */
    pthread_t thread;               /* Thread object */
    
    while (true) {
        printf("Enter a hexadecimal number (type \"exit\" to terminate): ");
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';      /* Remove trailing newline */
        
        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        if (is_hexadecimal(input)) {
            pthread_create(&thread, NULL, convert, (void *) input);
            pthread_join(thread, NULL);             /* Wait for the thread to finish executing */
        }
        else {
            printf("Invalid input. Please enter a hexadecimal number.\n");
        }
    }
    return 0;
}

/* Function to convert Hexadecimal input to Decimal */
void *convert(void *str) {
    char *hex_str = (char *) str;
    int len = strlen(hex_str);
    int i, dec = 0, base = 1;
    
    for (i = len - 1; i >= 0; i--) {
        int j;
        char c = toupper(hex_str[i]);
        
        for (j = 0; j < 16; j++) {
            if (c == hex_table[j]) {
                dec += j * base;
                break;
            }
        }
        base *= 16;
    }
    printf("Hexadecimal: %s\nDecimal: %d\n", hex_str, dec);
    pthread_exit(NULL);         /* Exit the thread */
}

/* Function to validate Hexadecimal input */
bool is_hexadecimal(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isxdigit(str[i])) {
            return false;
        }
    }
    return true;
}