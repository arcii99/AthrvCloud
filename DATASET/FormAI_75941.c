//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char email[100];
    printf("Enter email address to check: ");
    scanf("%s", email);

    int i, j;
    int at = 0, period = 0, space = 0;
    for(i=0; i<strlen(email); i++) {
        if(email[i] == '@') {
            at++;
        }
        if(email[i] == '.') {
            period++;
        }
        if(email[i] == ' ') {
            space++;
        }
    }

    if(at != 1 || period < 1 || space > 0) {
        printf("Invalid email address.\n");
    } else {
        printf("Valid email address.\n");
    }

    return 0;
}