//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int fubar = rand() % 100;
    int snafu = fubar + rand() % 10;
    while (1) {
        int tarfu = rand() % 100;
        if (tarfu == fubar) {
            continue;
        } else if (tarfu == snafu) {
            printf("Intrusion detected! Initiating lockdown...");
            break;
        } else {
            printf("All systems normal.\n");
        }
    }
    return 0;
}