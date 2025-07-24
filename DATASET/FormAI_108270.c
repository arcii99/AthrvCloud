//FormAI DATASET v1.0 Category: Math exercise ; Style: ultraprecise
/*
 * Ultramegacalculatron - A super precise calculator in C
 * 
 * This program is designed to perform mathematical operations at an ultra-precise level
 * using custom data structures to store numbers with unlimited digits.
 * 
 * Author: John Doe
 * Last updated: 05/08/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * Structures for storing numbers
 */

typedef struct {
    int* digits;    // Array of digits
    int size;       // Number of digits
} Number;

/**
 * Function prototypes
 */

Number* from_int(int n);
Number* from_str(char* str);
void print_number(Number* num);
int compare(Number* a, Number* b);
Number* add(Number* a, Number* b);
Number* subtract(Number* a, Number* b);
Number* multiply(Number* a, Number* b);
Number* divide(Number* a, Number* b);

/**
 * Entry point of program
 */

int main() {
    char in1[100];
    char in2[100];
    char op;

    printf("Welcome to Ultramegacalculatron!\n");
    printf("Enter two numbers and an operator (+, -, *, /): ");

    scanf("%s %s %c", in1, in2, &op);

    Number* num1 = from_str(in1);
    Number* num2 = from_str(in2);
    Number* result;

    switch(op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Invalid operator: %c\n", op);
            return 1;
    }

    printf("Result: ");
    print_number(result);
    printf("\n");

    return 0;
}

/**
 * Convert an integer into a Number struct
 */

Number* from_int(int n) {
    Number* num = malloc(sizeof(Number));
    num->size = 0;
    num->digits = NULL;

    do {
        num->digits = realloc(num->digits, (num->size + 1) * sizeof(int));
        num->digits[num->size++] = n % 10;
        n /= 10;
    } while(n > 0);

    return num;
}

/**
 * Convert a string into a Number struct
 */

Number* from_str(char* str) {
    Number* num = malloc(sizeof(Number));
    num->size = strlen(str);
    num->digits = malloc(num->size * sizeof(int));

    for(int i = 0; i < num->size; i++) {
        if(!isdigit(str[i])) {
            printf("Invalid input: %s\n", str);
            exit(1);
        }
        num->digits[i] = str[num->size - i - 1] - '0';
    }

    return num;
}

/**
 * Print a Number struct to stdout
 */

void print_number(Number* num) {
    for(int i = num->size - 1; i >= 0; i--) {
        printf("%d", num->digits[i]);
    }
}

/**
 * Compare two Number structs
 */

int compare(Number* a, Number* b) {
    if(a->size > b->size) return 1;
    if(a->size < b->size) return -1;
    for(int i = a->size - 1; i >= 0; i--) {
        if(a->digits[i] > b->digits[i]) return 1;
        if(a->digits[i] < b->digits[i]) return -1;
    }
    return 0;
}

/**
 * Add two Number structs
 */

Number* add(Number* a, Number* b) {
    Number* result = malloc(sizeof(Number));
    result->size = a->size > b->size ? a->size : b->size;
    result->digits = malloc(result->size * sizeof(int));

    int carry = 0;

    for(int i = 0; i < result->size; i++) {
        int sum = carry;
        if(i < a->size) sum += a->digits[i];
        if(i < b->size) sum += b->digits[i];
        result->digits[i] = sum % 10;
        carry = sum / 10;
    }

    if(carry > 0) {
        result->digits = realloc(result->digits, (result->size + 1) * sizeof(int));
        result->digits[result->size++] = carry;
    }

    return result;
}

/**
 * Subtract two Number structs
 */

Number* subtract(Number* a, Number* b) {
    if(compare(a, b) < 0) {
        printf("Error: cannot perform subtraction with negative result\n");
        exit(1);
    }

    Number* result = malloc(sizeof(Number));
    result->size = a->size;
    result->digits = malloc(result->size * sizeof(int));

    int carry = 0;

    for(int i = 0; i < result->size; i++) {
        int diff = carry + a->digits[i];
        if(i < b->size) diff -= b->digits[i];
        if(diff < 0) {
            diff += 10;
            carry = -1;
        } else {
            carry = 0;
        }
        result->digits[i] = diff;
    }

    while(result->size > 1 && result->digits[result->size - 1] == 0) {
        result->size--;
        result->digits = realloc(result->digits, result->size * sizeof(int));
    }

    return result;
}

/**
 * Multiply two Number structs
 */

Number* multiply(Number* a, Number* b) {
    Number* result = malloc(sizeof(Number));
    result->size = a->size + b->size;
    result->digits = calloc(result->size, sizeof(int));

    for(int i = 0; i < a->size; i++) {
        int carry = 0;
        for(int j = 0; j < b->size; j++) {
            int prod = a->digits[i] * b->digits[j] + carry + result->digits[i+j];
            result->digits[i+j] = prod % 10;
            carry = prod / 10;
        }
        if(carry > 0) {
            result->digits[i + b->size] += carry;
        }
    }

    while(result->size > 1 && result->digits[result->size - 1] == 0) {
        result->size--;
        result->digits = realloc(result->digits, result->size * sizeof(int));
    }

    return result;
}

/**
 * Divide two Number structs
 */

Number* divide(Number* a, Number* b) {
    if(b->size == 1 && b->digits[0] == 0) {
        printf("Error: cannot divide by zero\n");
        exit(1);
    }

    Number* result = malloc(sizeof(Number));
    result->size = a->size;
    result->digits = calloc(result->size, sizeof(int));

    Number* num = malloc(sizeof(Number));
    num->size = 1;
    num->digits = calloc(1, sizeof(int));

    for(int i = a->size - 1; i >= 0; i--) {
        num->digits[0] = a->digits[i];
        int x = 0, y = 9;
        while(x < y) {
            int mid = (x + y + 1) / 2;
            num->digits[0] = mid;
            Number* prod = multiply(b, num);
            if(compare(prod, a) <= 0) {
                x = mid;
            } else {
                y = mid - 1;
            }
            free(prod);
        }
        result->digits[i] = x;
        num->digits[0] = x;
        Number* prod = multiply(b, num);
        Number* sub = subtract(a, prod);
        a->size = sub->size;
        free(a->digits);
        a->digits = sub->digits;
        free(prod);
    }

    while(result->size > 1 && result->digits[result->size - 1] == 0) {
        result->size--;
        result->digits = realloc(result->digits, result->size * sizeof(int));
    }

    return result;
}