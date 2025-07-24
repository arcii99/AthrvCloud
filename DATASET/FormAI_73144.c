//FormAI DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <string.h>
#define MAX_EMAIL_LENGTH 1000
#define MAX_SPAM_KEYWORDS 10

/* Function to check if a given email contains spam keywords */
int check_spam(char email[], char spam_keywords[][20], int num_keywords)
{
    // Convert the email to lowercase for easier comparison
    for(int i=0; email[i]; i++){
        email[i] = tolower(email[i]);
    }
    // Check if any of the spam keywords are present in the email
    for(int i=0; i<num_keywords; i++){
        if(strstr(email, spam_keywords[i])){
            return 1; // Spam keyword found
        }
    }
    return 0; // No spam keywords found
}

int main()
{
    char email[MAX_EMAIL_LENGTH]; // Variable to store the user's email
    char spam_keywords[MAX_SPAM_KEYWORDS][20] = {"viagra", "lottery", "nigeria", "spam"}; // Array of common spam keywords
    int num_keywords = 4; // Number of keywords in the array
    printf("Enter your email address: ");
    scanf("%s", email);
    // Check if the email contains any spam keywords
    if(check_spam(email, spam_keywords, num_keywords)){
        printf("The email you entered contains spam.\n");
    }
    else{
        printf("The email you entered is spam-free.\n");
    }
    return 0;
}