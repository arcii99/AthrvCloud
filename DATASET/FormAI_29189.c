//FormAI DATASET v1.0 Category: Firewall ; Style: surrealist
#include <stdio.h>
int main() {
    // Welcome Message
    printf("Welcome to the Surrealist Firewall Example Program!\n");

    // Firewall Activation
    int activate_firewall = 1;

    // Surreal Defense Mechanism
    while (activate_firewall) {
        char * firewall_codes = "#^}<]+!]%!]{[>+>@"; // Surreal Codes
        char user_input[50]; // Input Buffer
        printf("Enter the Activation Code: ");
        fgets(user_input, sizeof(user_input), stdin); // Accept User Input

        // Firewall Validation Algorithm
        int validation_code = 0;
        int i = 0;
        while (user_input[i] != '\0') {
            validation_code += (int)user_input[i];
            i++;
        }
        validation_code *= 2;

        // Surreal Comparison
        int compare_codes = 1;
        for (i = 0; i < 12; i++) {
            if (validation_code != (int)firewall_codes[i]) {
                compare_codes = 0;
                break;
            }
        }

        // Surreal Defense
        if (compare_codes) { // Firewall Activation Successful
            printf("Firewall Activated!\n");
            printf("All external connections terminated!\n");
            printf("The Surrealist Firewall is now protecting your system!\n");
            activate_firewall = 0; // Deactivate Firewall Loop
        } else { // Firewall Activation Failed
            printf("Firewall Activation Failed!\n");
            printf("Please try again with another set of surreal activation codes.\n");
        }
    }

    return 0;
}