//FormAI DATASET v1.0 Category: Arithmetic ; Style: secure
#include<stdio.h>
#include<stdlib.h>

int main() {
    int a, b, result;
    char op;

    printf("Enter arithmetic expression (eg. 2 + 3): ");
    scanf("%d %c %d", &a, &op, &b);

    if(op == '+') { 
        result = a + b;
    } else if(op == '-') { 
        result = a - b; 
    } else if(op == '*') { 
        result = a * b;  
    } else if(op == '/') { 
        if(b == 0) { 
            printf("\n Division by zero is not allowed. Please try again!\n "); 
            return 0;   
        } else { 
            result = a/b; 
        }  
    } else { 
        printf("\nInvalid operator used. Please try again!"); 
        return 0;
    }

    printf("%d %c %d = %d\n", a, op, b, result);

    return 0;
}