//FormAI DATASET v1.0 Category: Educational ; Style: introspective
#include <stdio.h>

int main() {
    printf("I am a C program that counts from 1 to 10!\n");
    
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }
    
    printf("Did you enjoy counting with me? (y/n)\n");
    
    char answer;
    scanf("%c", &answer);
    
    if (answer == 'y') {
        printf("Yay! Thank you for counting with me!\n");
    } else {
        printf("Aww, well maybe we can count together another time.\n");
    }
    
    return 0;
}