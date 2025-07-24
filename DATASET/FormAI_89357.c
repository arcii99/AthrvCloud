//FormAI DATASET v1.0 Category: Pattern printing ; Style: high level of detail
#include <stdio.h>

int main() {
    int size, i, j;
    printf("Enter size of C pattern: ");
    scanf("%d", &size);
    
    // top vertical bar
    for(i = 0; i < size; i++) {
        printf("*\n");
    }
    
    // angled line
    for(i = 0; i < size / 2; i++) {
        printf(" ");
    }
    printf("*\n");
    
    // bottom vertical bar
    for(i = 0; i < size / 2; i++) {
        for(j = 0; j < size / 2; j++) {
            printf(" ");
        }
        printf("*\n");
    }
    return 0;
}