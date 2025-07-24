//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Memory Management Circus Show!\n");
    printf("Please hold your allocations as tight as you can, and get ready for the memory ride of your life!\n");
    
    //Step right up and allocate your memory!
    int* numAlloc = (int*)malloc(sizeof(int));
    float* floatAlloc = (float*)calloc(1, sizeof(float));
    char* strAlloc = (char*)malloc(sizeof(char) * 10);
    
    //Watch closely as we perform our first memory illusion
    printf("The Great Memory Illusion:\n");
    printf("Allocated int: %d\n", *numAlloc);
    printf("Allocated float: %f\n", *floatAlloc);
    printf("Allocated string: %s\n", strAlloc);

    //Now for our next act, let's copy some strings!
    char* origString = "Hello World!";
    char* newString = (char*)malloc(sizeof(char) * strlen(origString));
    strcpy(newString, origString);

    //Behold! The defying of the null character!
    printf("Original string: %s\n", origString);
    printf("New string: %s\n", newString);

    //And now, for the grand finale, let's free all the allocated memory! 
    free(numAlloc);
    free(floatAlloc);
    free(strAlloc);
    free(newString);
    
    printf("And that concludes our Memory Management Circus Show!\n");
    printf("We hope you enjoyed your allocation experience, and please return soon!\n");
    
    return 0;
}