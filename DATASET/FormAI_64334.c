//FormAI DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;

    printf("The value of num is %d\n", num);
    printf("The value of ptr is %p\n", ptr);
    printf("The value of *ptr is %d\n", *ptr);
    
    *ptr = 20;
    
    printf("The value of num is now %d\n", num);
    printf("The value of ptr is now %p\n", ptr);
    printf("The value of *ptr is now %d\n", *ptr);

    return 0;
}