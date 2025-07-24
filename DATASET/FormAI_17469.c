//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Romeo and Juliet
/* Romeo and Juliet: A Tale of C RAM Usage Monitor */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int memoryUsage = 0;

    printf("Oh, RAM! Thy memory dost govern all!\n");
    printf("How much art thou used, good memory?\n");
    scanf("%d", &memoryUsage);

    if (memoryUsage >= 90) {
        printf("Alas, my heart doth sink, for memory doth\n");
        printf("run high, and soon our program must depart.\n");
        printf("We must bid adieu, and gracefully exit.\n");
        exit(1);
    } else {
        printf("Oh, sweet relief, our memory usage is low!\n");
        printf("Our program shall continue, and joy shall flow.\n");
        printf("Our journey will be long and fruitful,\n");
        printf("For our memory usage is certainly beautiful.\n");
        return 0;
    }
}