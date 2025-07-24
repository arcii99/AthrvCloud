//FormAI DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    char sender[50];
    char recipient[50];
    char subject[50];
    char message[1000];
} email;

int main() {
    email myEmail;
    printf("Welcome to the most rattle-tastic Email Client you will ever come across!\n");
    printf("Please enter your Email Address: \n");
    scanf("%s", myEmail.sender);
    printf("Perfect, now who would you like to send this beautiful Email to?: \n");
    scanf("%s", myEmail.recipient);
    printf("Great! Let's give your Email a catchy subject. What's on your mind?: \n");
    scanf("%s", myEmail.subject);
    printf("\nNow let's add some humor to your Email. Write away!:\n");
    scanf("%s", myEmail.message);
    printf("Haha! That's hilarious. I'm adding that to your Email right now.\n");
    printf("Confirm that you want to send the following Email:\n");
    printf("To: %s\nFrom: %s\nSubject: %s\nMessage: %s\n", myEmail.recipient, myEmail.sender, myEmail.subject, myEmail.message);

    char confirmationOption[5];
    printf("Are you sure you want to send this Email? (yes/no):\n");
    scanf("%s", confirmationOption);
    if(strcmp(confirmationOption,"yes")==0)
    {
        printf("Congrats! Your Email has been delivered successfully. Check your sent folder for confirmation!\n");
        printf("Tip: Don't forget to check your SPAM folder, just in case.\n");
    }
    else if(strcmp(confirmationOption,"no")==0)
    {
        printf("Not cool! Let's try that again. Your Email has not been sent.\n");
    }
    else
    {
        printf("Oops, wrong input! Please enter 'yes' or 'no' next time. And don't worry, we won't tell anyone about this.\n");
    }
    return 0;
}