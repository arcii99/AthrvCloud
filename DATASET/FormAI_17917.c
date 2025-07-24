//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Romeo and Juliet
/* Romeo and Juliet C Website Uptime Monitor */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEBSITE_URL "https://example.com"
#define MAX_CHECKS 5
#define CHECK_INTERVAL 10

int main() {
    int checks = 0;
    time_t last_check_time = time(NULL);

    printf("Oh website, thou art the light of my screen,\n");
    printf("But in case thou art gone, I'll make thee seen.\n\n");

    while (checks < MAX_CHECKS) {
        time_t now = time(NULL);

        if (difftime(now, last_check_time) >= CHECK_INTERVAL) {
            printf("Oh website, I shall check on thee once more,\n");
            printf("And make sure thou art still there to adore.\n\n");

            int response_code = system("curl --silent --head " WEBSITE_URL " | head -n 1 | cut -d \" \" -f 2");

            if (response_code == 200) {
                printf("Oh website, thy beauty still shines bright,\n");
                printf("And this is all that I need to know tonight.\n\n");
            } else {
                printf("Alas, oh website, thou art not found,\n");
                printf("And I am lost in this world without a sound.\n\n");
            }

            checks++;
            last_check_time = now;
        }
    }

    printf("Oh website, I must say goodbye for now,\n");
    printf("But I promise to come back and make thou proud somehow.\n\n");

    return 0;
}