//FormAI DATASET v1.0 Category: Benchmarking ; Style: Ada Lovelace
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    printf("The analytical engine has no pretensions to originate anything. It can do whatever we know how to order it to perform.\n");
    start = clock();
    // perform some calculations
    int x = 0;
    for (int i = 0; i < 1000000000; i++) {
        x += i;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Calculation time: %f seconds\n", cpu_time_used);

    printf("A large income is the best recipe for happiness I ever heard of.\n");
    start = clock();
    // perform some file I/O
    FILE *file = fopen("example.txt", "w");
    fputs("Hello, world!", file);
    fclose(file);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("File I/O time: %f seconds\n", cpu_time_used);

    printf("If you can't give me poetry, can't you give me poetical science?\n");
    start = clock();
    // perform some string manipulation
    char str[] = "abcdefg";
    for (int i = 0; i < 1000000000; i++) {
        str[0] = '!';
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("String manipulation time: %f seconds\n", cpu_time_used);

    return 0;
}