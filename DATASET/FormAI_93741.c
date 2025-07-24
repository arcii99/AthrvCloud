//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* rainbow = malloc(sizeof(char) * 10);
    if (rainbow == NULL) {
        printf("Uh oh, we ran out of memory :(\n");
        return 1;
    }
    
    printf("Enter your favorite color of the rainbow: ");
    scanf("%s", rainbow);
    printf("Your favorite color of the rainbow is %s!\n", rainbow);
    
    free(rainbow);
    printf("Free at last, free at last, thank C above we're free at last!\n");
    
    return 0;
}