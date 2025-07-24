//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char name[100], profession[100], message[1000];

    printf("Welcome to the Grateful Message Generator!\n\n");

    // Collect user input for name and profession
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Please enter your profession: ");
    fgets(profession, sizeof(profession), stdin);
    profession[strcspn(profession, "\n")] = 0;

    // Create the message
    strcpy(message, "Dear ");
    strcat(message, name);
    strcat(message, ",\n\n");
    strcat(message, "I am forever grateful for the hard work and dedication you put into your profession as a ");
    strcat(message, profession);
    strcat(message, ". Your unwavering commitment to excellence and your passion for what you do is truly inspiring.\n\n");
    strcat(message, "Every day, you give your all to make the world a better place, and for that, I am thankful. Your work has touched the lives of so many people, and your positive impact will be felt for generations to come.\n\n");
    strcat(message, "I hope that this message finds you well and that it brings a smile to your face. You are appreciated more than you know, and I feel lucky to know you.\n\n");
    strcat(message, "Thank you again for all that you do. Your hard work and dedication do not go unnoticed, and you truly make a difference in the world.\n\n");
    strcat(message, "With gratitude,\n");
    strcat(message, "Your friend");

    // Print the message
    printf("\n************************************************************\n\n");
    printf("%s", message);
    printf("\n\n************************************************************\n");

    return 0;
}