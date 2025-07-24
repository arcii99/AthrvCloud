//FormAI DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
// Romeo and Juliet: A Tale of Memory Management in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
} Person;

int main() {
    // Act 1
    Person* romeo = malloc(sizeof(Person));
    romeo->name = strdup("Romeo");
    romeo->age = 18;
    
    // Act 2
    Person* juliet = malloc(sizeof(Person));
    juliet->name = strdup("Juliet");
    juliet->age = 18;
    
    // Act 3
    printf("%s and %s meet for the first time.\n", romeo->name, juliet->name);
    
    // Act 4
    free(romeo);
    free(juliet->name);
    free(juliet);
    
    // Epilogue
    printf("%s and %s were and always will be in our memories.\n", romeo->name, juliet->name);
    
    return 0;
}