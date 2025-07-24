//FormAI DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>

int main() {
    int count;
    printf("How many smiley faces do you want to print? ");
    scanf("%d", &count);
    
    for (int i = 0; i < count; i++) {
        printf(":)");
    }
    printf("\n");
    
    if (count > 5) {
        printf(">5 :D\n");
    } else if (count > 3) {
        printf("3-5 :)\n");
    } else if (count > 1) {
        printf("2 :)\n");
    } else {
        printf("1 :(\n");
    }
    
    return 0;
}