//FormAI DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {

    char puzzling_email[100];
    printf("Enter a puzzling email address: ");
    scanf("%s", puzzling_email);

    char domain[100];
    int at_symbol_present = 0;
    int domain_start_index = 0;

    for (int i = 0; i < strlen(puzzling_email); i++) {
        if (puzzling_email[i] == '@') {
            at_symbol_present = 1;
            domain_start_index = i + 1;
            break;
        }
    }

    if (at_symbol_present == 1) {

        for (int i = domain_start_index; i < strlen(puzzling_email); i++) {

            if (puzzling_email[i] == '.') {
                domain[i - domain_start_index] = '\0';
                break;
            } else {
                domain[i - domain_start_index] = puzzling_email[i];
            }
        }

        printf("Domain: %s\n", domain);
    } else {
        printf("Invalid email address!\n");
    }

    return 0;
}