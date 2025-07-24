//FormAI DATASET v1.0 Category: Educational ; Style: imaginative
#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    if(age < 18) {
        printf("Sorry, you are not old enough to access this program.\n");
    } else {
        printf("Welcome to the 'C' Educational Example Program!\n");
        printf("In this program, we will demonstrate the use of pointers in C.\n");

        int num = 7;
        int *ptr;

        ptr = &num;

        printf("The value of 'num' is %d.\n", num);
        printf("The value of 'ptr' is %p, pointing to the value %d.\n", ptr, *ptr);

        *ptr = 10;

        printf("The value of 'num' is now %d.\n", num);
        printf("The value of 'ptr' is still %p, pointing to the value %d.\n", ptr, *ptr);

        printf("Thanks for using the 'C' Educational Example Program!\n");
    }

    return 0;
}