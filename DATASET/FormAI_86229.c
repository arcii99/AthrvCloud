//FormAI DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

//Function prototype
void send_email(char *from, char *to, char *subject, char *body);

int main(){
    char email_from[50], email_to[50], email_subject[100], email_body[500];

    //Prompt user for email details
    printf("Enter your email address: ");
    scanf("%s", email_from);
    printf("Enter the recipient's email address: ");
    scanf("%s", email_to);
    printf("Enter the subject of the email: ");
    getchar();//Clear input buffer
    fgets(email_subject, 100, stdin);
    printf("Enter the body of the email: ");
    fgets(email_body, 500, stdin);

    //Call send_email() function
    send_email(email_from, email_to, email_subject, email_body);

    printf("\nEmail sent successfully!\n");

    return 0;
}

//Function definition
void send_email(char *from, char *to, char *subject, char *body){
    printf("\nFrom: <%s>\n", from);
    printf("To: <%s>\n", to);
    printf("Subject: %s\n", subject);
    printf("Body:\n%s", body);
}