//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char system_call[100];
    time_t current_time;
    int random_num;
    srand(time(NULL));

    printf("Starting intrusion detection system...\n");

    while(1) {
        random_num = rand() % 101;
        if(random_num < 25) {
            printf("Possible intrusion detected! Checking system logs...\n");
            strcpy(system_call, "tail /var/log/system.log");
            system(system_call);
            current_time = time(NULL);
            printf("Intrusion detected at %s\n", ctime(&current_time));
        } else {
            printf("No intrusion detected...\n");
        }
        sleep(10);
    }

    return 0;
}