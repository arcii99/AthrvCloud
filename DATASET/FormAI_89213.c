//FormAI DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>

// A program that calculates the sum of the first 100 odd numbers
// in an artistic and unique way.

int main() {

    printf("Welcome to the Odd Art Arithmetic program!\n\n");
    
    int sum = 0;
    
    for(int i=1; i<=200; i++) {
        
        if(i % 2 == 0) {
            printf("                    i=%d                           \n", i);
            printf("                 /         \\                        \n");
            printf("             __/           \\__                     \n");
            printf("         ___/                 \\___                 \n");
            printf("       __/                       \\__               \n");
            printf("     _/                             \\_             \n");
            printf("   _/                                  \\_          \n");
            printf(" _/                                       \\_       \n");
            printf(" \\                                          /    \n");
            printf("   \\                                      /       \n");
            printf("     \\                                  /         \n");
            printf("         \\ ___                      ___/         \n");
            printf("               \\_                  _/             \n");
            printf("                 \\__            __/               \n");
            printf("                    \\__________/                  \n");
            printf("\n");
        } else {
            sum += i;
            
            printf("Summing the odd number %d...\n", i);
            
            printf("     /\\                                    /\\             \n");
            printf("    /  \\                                  /  \\            \n");
            printf("   /    \\                                /    \\           \n");
            printf("  /      \\                              /      \\          \n");
            printf(" /        \\_______________c_             /        \\   sum=%d\n", sum);
            printf(" \\        /               | |           \\        /        \n");
            printf("  \\      /                |_|            \\      /         \n");
            printf("   \\    /                                 \\    /          \n");
            printf("    \\  /                                   \\  /           \n");
            printf("     \\/                                     \\/            \n");
            printf("\n");
        }
    }
    
    printf("\n\n");
    printf("Done! The sum of the first 100 odd numbers is %d.\n", sum);
    
    return 0;
}