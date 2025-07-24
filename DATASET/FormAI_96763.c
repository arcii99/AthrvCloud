//FormAI DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
// Romeo and Juliet: A Memory Management Tragedy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Our tale begins with two lovers, Romeo and Juliet
    char* romeo = malloc(50);
    char* juliet = malloc(50);

    // Romeo writes a love letter to his beloved Juliet
    strncpy(romeo, "My dearest Juliet, my heart belongs to you", 50);

    // But tragedy strikes as Romeo forgets to allocate enough memory for his message
    romeo = realloc(romeo, 25);

    // When he attempts to continue his message, he accidentally overwrites the heap with gibberish
    strncpy(romeo, "Forsooth! Verily I say unto thee, thy love doth fill me with much rejoice", 25);

    // Meanwhile, Juliet receives the message and attempts to read it
    printf("%s\n", juliet); // But the message never reaches her, as Romeo's mistake causes a segmentation fault

    // As Romeo mourns his error, he realizes the only way to prevent such tragedies in the future is to always check the return values of memory allocation functions
    free(romeo);
    free(juliet);
    
    return 0;
}