//FormAI DATASET v1.0 Category: String manipulation ; Style: romantic
#include<stdio.h>
#include<string.h>

int main()
{
    char message[100], name[20], romanticMessage[200]; //initialize variables
    
    printf("Enter your romantic message: ");
    fgets(message, 100, stdin); //get input from user
    
    printf("Enter your lover's name: ");
    scanf("%s", name); //get input from user

    strcat(romanticMessage, "My beloved "); //using the string function strcat to join strings
    strcat(romanticMessage, name);
    strcat(romanticMessage, ",\n\n");

    int length = strlen(message);
    int i;

    for (i = 0; i < length; i++) { //iterate through the string
        if (i == 0) {
            strcat(romanticMessage, "Your eyes, like ");
        }
        if (message[i] == ' ' && message[i+1] != '\0') { //if there is a space between two words
            strcat(romanticMessage, ", like ");
        } else if (message[i] != ' ' && message[i+1] != '\0') {
            strcat(romanticMessage, &message[i]);
        }
        if (message[i+1] == '\0') { //end of the string
            if (message[i] == '\n') {
                strcat(romanticMessage, " my heart, have captured.\n"); 
            } else {
                strcat(romanticMessage, " my heart, have captured.\n\n");
            }
        }
    }

    printf("%s", romanticMessage); //print output

    return 0;
}