//FormAI DATASET v1.0 Category: Recursive ; Style: Cryptic
#include <stdio.h>

int cRyPtic(int a);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = cRyPtic(num);
    printf("The result is %d\n", result);
    return 0;
}

int cRyPtic(int a) {
    if (a == 0) {
        return 0;
    } else if (a == 1) {
        return 1;
    } else {
        int first = cRyPtic(a - 1);
        int second = cRyPtic(a - 2);
        int third = first + second + cRyPtic(a - 3);
        return third;
    }
}