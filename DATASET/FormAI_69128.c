//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>

void output(int num, int count) {
    if(count == 0)
        return;

    int i;
    for(i = 0; i < count - 1; i++) {
        printf("%d + ", num);
    }
    printf("%d = %d\n", num, num * count);

    output(num + 1, count - 1);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    output(1, n);

    return 0;
}