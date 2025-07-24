//FormAI DATASET v1.0 Category: Educational ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // surreal setup
    srand(time(NULL));
    int x = rand() % 100 + 1;
    int y = rand() % 100 + 1;
    int z = rand() % 100 + 1;
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;

    // surreal code
    int foo = x;
    int bar = y;
    int baz = z;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (foo < bar && foo < baz) {
                foo += x;
            } else if (bar < foo && bar < baz) {
                bar += y;
            } else {
                baz += z;
            }
        }
    }

    printf("The final values are:\n");
    printf("foo: %d\n", foo);
    printf("bar: %d\n", bar);
    printf("baz: %d\n", baz);

    return 0;
}