//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MB 1048576   // 1MB

int main() {
    int i = 1;
    char *a;
    while(1) {
        a = (char*)malloc(i*MB);
        
        if(a == NULL) {
            printf("Error: Insufficient memory!\n");
            exit(1);
        }
        
        printf("Memory allocated for %dMB\n", i);
        
        memset(a, 0, i*MB);
        sleep(1);
        
        i++;
        free(a);
    }
    return 0;
}