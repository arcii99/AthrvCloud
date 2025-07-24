//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Romeo and Juliet
/* A Romeo and Juliet-style example program demonstrating bitwise operations in C */

#include <stdio.h>

int main() {
    int romeo = 1; 
    int juliet = 2; 
    int balcony = 3; 

    printf("O Romeo, Romeo, wherefore art thou Romeo? \n"); 
    printf("Deny thy mask, and refuse thy name; \n"); 
    printf("Or, if thou wilt not, be but sworn my love, \n"); 
    printf("And I'll no longer be a Capulet.\n\n"); 

    printf("Ah, my sweet Juliet, \n"); 
    printf("The sun does not rise or set \n"); 
    printf("Without thy eyes upon it. \n"); 
    printf("But what's this? \n"); 
    printf("Thy balcony appears to be numbered %d...\n\n", balcony); 

    printf("Juliet, my love, let us use the power of bitwise operations \n"); 
    printf("To ascend to thy balcony and be together forevermore.\n");

    /* Romeo and Juliet combine their bits */
    int combined = romeo | juliet | balcony;

    /* Romeo and Juliet shift their bits to ascend the balcony */
    combined = combined << 1;

    /* Romeo and Juliet arrive on the balcony, their bits now matching */
    printf("Ah, my love, we have ascended to thy balcony, \n"); 
    printf("Our bits now combined as %d. \n", combined);

    return 0; 
}