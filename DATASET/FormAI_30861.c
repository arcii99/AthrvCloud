//FormAI DATASET v1.0 Category: QR code reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int case_number;
    char victim_name[50];
    char qr_code[100];
} Case;

int main() {
    Case current_case;

    printf("Please enter the case number: ");
    scanf("%d", &current_case.case_number);

    printf("What is the victim's name? ");
    fgets(current_case.victim_name, 50, stdin);

    printf("Please scan the QR code: ");
    fgets(current_case.qr_code, 100, stdin);
    
    // Check QR code
    if (strcmp(current_case.qr_code, "Moriarty") == 0) {
        printf("This code leads to Moriarty. This case is closed.");
    } else {
        printf("This code does not match our records. Further investigation is required.");
    }
    
    return 0;
}