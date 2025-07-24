//FormAI DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

// Forward declarations
void convert_to_binary(int n, bool* result);
void print_binary(bool* binary);
void print_error(char* format, ...);
void process_input(char* input);

// Constants
const int MAX_INPUT = 100;

int main()
{
    char input[MAX_INPUT];
    
    while(true)
    {
        printf("Enter a number to convert to binary (or 'exit' to quit): ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character
        
        if(strcmp(input, "exit") == 0)
        {
            printf("Exiting...\n");
            break;
        }
        
        process_input(input);
    }
    
    return 0;
}

void process_input(char* input)
{
    int n = atoi(input);
    
    if(n == 0 && strcmp(input, "0") != 0)
    {
        print_error("Invalid input: '%s' is not a number\n", input);
        return;
    }
    
    bool binary[32] = {0};
    convert_to_binary(n, binary);
    print_binary(binary);
}

void convert_to_binary(int n, bool* result)
{
    int i = 0;
    
    while(n > 0)
    {
        result[i] = n % 2;
        n /= 2;
        i++;
    }
}

void print_binary(bool* binary)
{
    printf("Binary representation: ");
    
    for(int i = 31; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    
    printf("\n");
}

void print_error(char* format, ...)
{
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
}