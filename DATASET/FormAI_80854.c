//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Helper function to randomly generate true or false boolean values
bool random_boolean() {
    return rand() % 2 == 0;
}

// Asynchronous function to print the first part of the pattern
void print_pattern_top() {
    printf("***********\n");
    printf(" *********\n");
    printf("  *******\n");
    printf("   *****\n");
    printf("    ***\n");
    printf("     *\n");
}

// Asynchronous function to print the second part of the pattern
void print_pattern_bottom() {
    printf("     *\n");
    printf("    ***\n");
    printf("   *****\n");
    printf("  *******\n");
    printf(" *********\n");
    printf("***********\n");
}

// Asynchronous function to print the middle of the pattern
void print_pattern_middle() {
    bool should_print_top = random_boolean();
    if (should_print_top) {
        print_pattern_top();
    } else {
        print_pattern_bottom();
    }
}

int main() {
    srand(time(NULL));
    
    // Print the top part of the pattern
    print_pattern_top();
    
    // Spawn a new thread to print the middle part of the pattern asynchronously
    #pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        print_pattern_middle();
    }
    
    // Print the bottom part of the pattern
    print_pattern_bottom();
    
    return 0;
}