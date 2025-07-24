//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mind-bending
#include <stdio.h>
#include <unistd.h>

int main () {
    int loading_percentage[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i;
    printf("Optimizing system boot...\n\n");
    for(i=0; i<10; i++){
        printf("[");
        int j;
        for(j=0; j<=i; j++){
            printf("|");
        }
        int k;
        for(k=0; k<9-i; k++){
            printf(" ");
        }
        printf("] %d%%\r", loading_percentage[i]);
        fflush(stdout);
        usleep(50000);
    }
    printf("\n\nBoot optimization complete!\n");
    return 0;
}