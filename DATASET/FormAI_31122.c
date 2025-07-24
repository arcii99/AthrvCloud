//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: creative
#include <stdio.h>
#include <string.h>

// Function to check if there is any intrusion or not
void checkIntrusion(char* str)
{
    int count = 0;
    char* keywords[7] = {"hack", "malware", "virus", "attack", "exploit", "backdoor", "trojan"};

    // Loop through the string to check if any keyword is present or not
    for(int i=0; i<strlen(str); i++)
    {
        // If a keyword is found, increase the count and print a warning message
        for(int j=0; j<7; j++)
        {
            if (strstr(str+i, keywords[j]) == str+i)    // If keyword is found
            {
                count++;
                printf("WARNING: Intrusion detected - %s\n", keywords[j]);
            }
        }
    }

    // If no intrusion is detected, print a success message
    if(count == 0)
    {
        printf("No intrusion detected..\n");
    }
}

// Main function to test the Intrusion detection system
int main()
{
    printf("\n\n\t********* Intrusion Detection System *********\n\n");

    char str[200];

    // Get input from the user
    printf("Enter the text to be checked: ");
    fgets(str, 200, stdin);

    // Remove the newline character from the input string
    str[strcspn(str, "\n")] = 0;

    // Check for intrusion
    checkIntrusion(str);

    return 0;
}