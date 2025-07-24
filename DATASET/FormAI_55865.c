//FormAI DATASET v1.0 Category: Funny ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));
    int num, rand_num, freq[11] = {0};
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &num);
    printf("\nGenerating random numbers...\n");
    for(int i = 1; i <= 100; i++) {
        rand_num = rand()%10 + 1;
        freq[rand_num]++;
    }
    printf("\nStats for %d:\n", num);
    printf("Number of times %d was generated: %d\n", num, freq[num]);
    printf("Other numbers generated and their frequencies:\n");
    for(int i = 1; i <= 10; i++) {
        if(i != num)
            printf("%d: %d\n", i, freq[i]);
    }
    float percentage = (float) freq[num] / 100 * 100;
    printf("Percentage of times %d was generated: %.2f%%\n", num, percentage);
    printf("Total number of random numbers generated: %d\n", 100);
    return 0;
}