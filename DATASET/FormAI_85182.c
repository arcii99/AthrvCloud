//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char* hidden_message = "The RAM usage is";

    int* ptr = malloc(sizeof(int));
    memset(ptr, 0, sizeof(int));
    
    while(1) {
        
        int ram_usage = rand() % 101;

        if(ram_usage > *ptr) {
            
            printf("%s %d%%\n", hidden_message, ram_usage);
            
            *ptr = ram_usage;
        }
    }

    free(ptr);
    return 0;
}