//FormAI DATASET v1.0 Category: System boot optimizer ; Style: medieval
#include <stdio.h>
#include <string.h>

char* weakness = "dragonfire";
char* optimizationStatus[] = {
    "Optimizing your system for the battle ahead...",
    "Preparing your system for the coming siege...",
    "Honing your system's performance for the task ahead...",
    "Boosting your system's speed and power for the battle..."
};

void optimizeBoot() {
    int statusIndex = 0;
    char password[20];
    printf("\nHold on... Before we begin, what is the password?\n");
    scanf("%s", password);

    if (strcmp(password, weakness) != 0) {
        printf("Invalid password! Aborting optimization...\n");
        return;
    }

    printf("Valid password detected. Initiating boot optimization:\n\n");
    for (int i = 0; i < 50; i++) {
        printf("%s\n", optimizationStatus[statusIndex]);
        statusIndex = (statusIndex + 1) % 4;
    }

    printf("\nBoot optimization complete. Your system is now ready for battle.\n");
}

int main() {
    optimizeBoot();
    return 0;
}