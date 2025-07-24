//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int downloadSpeed, uploadSpeed;
    char buffer[1024];

    printf("Oh, dear user, what a joy to see thee!\n");
    printf("Pray, tell me, dost thou wish to test thine internet speed today?\n");

    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    if(strcmp(buffer, "yes") == 0) {
        printf("Verily, thou art wise!\n");
    } else if(strcmp(buffer, "no") == 0) {
        printf("Alas, I wish thou hadst chosen otherwise.\n");
        return 0;
    } else {
        printf("Prithee, answerest yea or nay.\n");
        return 0;
    }

    printf("Let us begin the test, anon.\n");

    srand(time(NULL));
    downloadSpeed = rand() % 101 + 50;
    printf("Thy download speed is %d mbps, my sweet.\n", downloadSpeed);

    srand(time(NULL));
    uploadSpeed = rand() % 51 + 10;
    printf("Thy upload speed is %d mbps.\n", uploadSpeed);

    printf("Farewell, dearest user! I hope thy internet is fast and true,\n");
    printf("Until we meet again, adieu!\n");

    return 0;
}