//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

#define NUM_USERS 3
#define NUM_ENTRIES 5

// Example user database
char user_db[NUM_USERS][20] = {"Alice", "Bob", "Charlie"};

// Example login attempts
char login_attempts[NUM_ENTRIES][20] = {"Alice", "password123",
                                        "Bob", "letmein",
                                        "Eve", "hackme",
                                        "Charlie", "admin123",
                                        "Mallory", "password"};

int main() {
    // Flag to track if intrusion detected
    bool intrusion_detected = false;
    
    // Iterate through all login attempts
    for (int i = 0; i < NUM_ENTRIES; i += 2) {
        bool user_found = false;
        // Iterate through user database to validate login
        for (int j = 0; j < NUM_USERS; j++) {
            if (strcmp(login_attempts[i], user_db[j]) == 0) {
                user_found = true;
                printf("Username found: %s\n", user_db[j]);
                if (strcmp(login_attempts[i+1], "password123") == 0) {
                    // Password is weak, potential intrusion attempt
                    intrusion_detected = true;
                    printf("Weak password detected! Intrusion attempt may be in progress.\n");
                } else {
                    printf("Password validated.\n");
                }
            }
        }
        if (!user_found) {
            printf("Username %s not found in database. Intrusion attempt may be in progress.\n", login_attempts[i]);
            intrusion_detected = true;
        }
    }
    if (intrusion_detected) {
        printf("Intrusion detected. Alert authorities.\n");
    } else {
        printf("No intrusion detected. All login attempts valid.\n");
    }
    return 0;
}