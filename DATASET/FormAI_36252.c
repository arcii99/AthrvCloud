//FormAI DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
#include<stdio.h>

int romeo(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return romeo(y, x % y);
    }
}

int juliet(int x, int y) {
    if (x == 0) {
        return y;
    } else {
        return romeo(y % x, x);
    }
}

int main() {
    int a, b, gcd;
    printf("O Romeo, what number would thou like?\nO Juliet, what number would thee desire?\n");
    scanf("%d %d", &a, &b);
    gcd = romeo(a, b);
    printf("Speak, my dear, what is the hallowed GCD?\n%d\n", gcd);
    return 0;
}