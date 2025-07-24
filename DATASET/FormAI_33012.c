//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: medieval
#include <stdio.h>

// function to calculate the checksum
int calculate_checksum(long long num) {
    int sum = 0;
    while(num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(void) {
    long long num;
    printf("Greetings peasant! Welcome to the Checksum Calculator program developed by the Royal Engineers!\n");
    printf("Please enter a number to calculate the checksum: ");
    scanf("%lld", &num);
    int checksum = calculate_checksum(num);
    printf("\nCalculating checksum.. please wait while we consult the almighty wizard..");
    for(int i=0; i<5; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n\nThe checksum of %lld is %d.\n", num, checksum);
    printf("Do not lose your temper if the laws of mathematics seem to defy your intuition, you pathetic peasant!\n");
    printf("May you have a productive day ahead!\n");
    return 0;
}