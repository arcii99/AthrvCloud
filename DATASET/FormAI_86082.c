//FormAI DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char recipient[100];
    char subject[100];
    char message[500];

    printf("Enter recipient's email address: ");
    scanf("%s", recipient);

    printf("Enter subject of email: ");
    scanf("%s", subject);

    printf("Enter message of email: ");
    scanf("%s", message);

    FILE *fp;

    fp = fopen("email.txt", "w");

    fprintf(fp, "To: %s\n", recipient);
    fprintf(fp, "Subject: %s\n", subject);
    fprintf(fp, "Message: %s\n", message);

    fclose(fp);

    printf("\nEmail sent successfully\n");

    return 0;
}