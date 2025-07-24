//FormAI DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>

int main() {
    int secret_variable = 0x1234; // secret variable to be protected
    int passcode = 137; // correct passcode to access secret variable
    int user_passcode; // user enters their passcode
    int success = 0; // boolean variable to track successful access
    
    printf("Enter passcode: ");
    scanf("%d", &user_passcode);
    
    // check if user input matches correct passcode
    if (user_passcode == passcode) {
        printf("Access granted.\n");
        success = 1;
    } else {
        printf("Incorrect passcode.\n");
    }
    
    // bomb planted to destroy secret variable if access is unsuccessful
    if (!success) {
        printf("Initiating self-destruct sequence in T-10 seconds.\n");
        fflush(stdout); // flush output stream to ensure prompt is displayed before delay
        
        // delay for 10 seconds
        for (int i = 10; i >= 1; i--) {
            printf("T-%d seconds.\n", i);
            sleep(1); // 1 second delay
        }
        
        secret_variable = 0; // destroy secret variable
        printf("Self-destruct sequence complete. Secret variable destroyed.\n");
    } else {
        printf("Secret variable value: %d\n", secret_variable);
    }

    return 0;
}