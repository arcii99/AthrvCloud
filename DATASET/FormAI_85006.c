//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// Structure to store the information about the attacker
struct attacker_info {
    char attacker_ip[20];
    char attacker_location[30];
    int attack_attempts;
};

// Function to print the log of attack attempts
void print_log(struct attacker_info attacker)
{
    printf("===========================\n");
    printf("INTRUSION DETECTED!\n");
    printf("Attacker IP: %s\n", attacker.attacker_ip);
    printf("Attacker Location: %s\n", attacker.attacker_location);
    printf("Number of Attack Attempts: %d\n", attacker.attack_attempts);
    printf("===========================\n\n");
}

int main()
{
    // Initialize the attacker info to zero
    struct attacker_info attacker = {"", "", 0};
    
    // Use loop to run the program indefinitely
    while(1)
    {
        // Wait for random time between 10 to 30 seconds
        int wait_time = (rand() % 21) + 10;
        sleep(wait_time);
        
        // Randomly generate whether an attack has been attempted or not
        int attack_attempted = rand() % 2;
        
        // If attack has been attempted
        if(attack_attempted)
        {
            // Increase the attack attempts counter by 1
            attacker.attack_attempts++;
            
            // If the attacker info has not been filled yet
            if(attacker.attacker_ip[0] == '\0')
            {
                // Randomly generate the IP and location of the attacker
                sprintf(attacker.attacker_ip, "%d.%d.%d.%d", (rand() % 256), (rand() % 256), (rand() % 256), (rand() % 256));
                sprintf(attacker.attacker_location, "Castle %c", (rand() % 26) + 65);
            }
            
            // If the attack attempts is more than 3, log the attack and reset the counter and attacker info
            if(attacker.attack_attempts >= 3)
            {
                print_log(attacker);
                attacker = (struct attacker_info){"", "", 0};
            }
        }
    }
    
    return 0;
}