//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>

int detectIntrusion(int levels, int attempts) {
    if(levels > 10 || attempts > 5) {
        return 1; // Intrusion detected
    }
    printf("Enter authorization code:\n");
    int authCode;
    scanf("%d", &authCode);
    if(authCode == 1234) {
        printf("Access granted.\n");
        return 0; // No intrusion detected
    }
    else {
        printf("Access denied.\n");
        return detectIntrusion(levels+1, attempts+1); // Recursive call
    }
}

int main() {
    printf("Welcome to the Intrusion Detection System.\n");
    int intrusionDetected = detectIntrusion(1, 1);
    if(intrusionDetected) {
        printf("Intrusion detected! Alert the authorities.\n");
    }
    else {
        printf("No intrusion detected.\n");
    }
    return 0;
}