//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main() {

    char buffer[1024];
    char attack[7] = "attack";

    printf("Enter your message: ");
    fgets(buffer, 1024, stdin);

    if(strstr(buffer, attack) != NULL) {
        printf("ALERT: Intrusion detected!\n");
    }

    return 0;
}