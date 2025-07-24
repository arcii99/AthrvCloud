//FormAI DATASET v1.0 Category: Email Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//A struct to hold email information
struct Email{
    char from[50];
    char to[50];
    char subject[100];
    char message[500];
};

//Function declarations
int menu();
void sendEmail();
void viewInbox();
void viewSent();
void saveEmail(struct Email e, char filename[]);
struct Email parseEmail(char filename[]);
void printEmail(struct Email e);

//Main function
int main(){
    int choice;
    do{
        choice = menu(); //Display menu and get user choice
        switch(choice){
            case 1:
                sendEmail(); //Send an email
                break;
            case 2:
                viewInbox(); //View inbox
                break;
            case 3:
                viewSent(); //View sent emails
                break;
            case 4:
                printf("Exiting Email Client...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 4);
    return 0;
}

//Display menu options and get user choice
int menu(){
    int choice;
    printf("--------------\n");
    printf("Email Client\n");
    printf("--------------\n");
    printf("1. Send Email\n");
    printf("2. View Inbox\n");
    printf("3. View Sent Emails\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

//Function to send an email
void sendEmail(){
    char filename[20];
    struct Email e;
    printf("To: ");
    scanf("%s", e.to);
    printf("From: ");
    scanf("%s", e.from);
    printf("Subject: ");
    getchar(); //Clear input buffer
    fgets(e.subject, 100, stdin);
    printf("Message: ");
    fgets(e.message, 500, stdin);
    sprintf(filename, "%s-%s-%d.txt", e.to, e.from, rand()%1000); //Generate filename
    saveEmail(e, filename); //Save email to file
    printf("Email sent successfully!\n");
}

//Function to view inbox
void viewInbox(){
    char emailFiles[50][20];
    int numEmails = 0;
    struct Email e;
    FILE *fp;
    system("ls inbox/ > inbox/emails.txt"); //Get list of email files
    fp = fopen("inbox/emails.txt", "r");
    while(fscanf(fp, "%s", emailFiles[numEmails]) != EOF){
        numEmails++;
    }
    fclose(fp);
    if(numEmails == 0){
        printf("Inbox is empty.\n");
    }
    else{
        printf("Inbox:\n");
        for(int i=0; i<numEmails; i++){
            e = parseEmail(emailFiles[i]); //Parse email from file
            printf("%d. From: %s, Subject: %s\n", i+1, e.from, e.subject);
        }
        int choice;
        printf("Enter number of email to view: ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= numEmails){
            e = parseEmail(emailFiles[choice-1]); //Parse email from file
            printf("\n--------------------------\n");
            printEmail(e); //Print email to console
            printf("--------------------------\n");
            printf("End of email.\n");
        }
        else{
            printf("Invalid choice.\n");
        }
    }
}

//Function to view sent emails
void viewSent(){
    char emailFiles[50][20];
    int numEmails = 0;
    struct Email e;
    FILE *fp;
    system("ls sent/ > sent/emails.txt"); //Get list of email files
    fp = fopen("sent/emails.txt", "r");
    while(fscanf(fp, "%s", emailFiles[numEmails]) != EOF){
        numEmails++;
    }
    fclose(fp);
    if(numEmails == 0){
        printf("Sent folder is empty.\n");
    }
    else{
        printf("Sent emails:\n");
        for(int i=0; i<numEmails; i++){
            e = parseEmail(emailFiles[i]); //Parse email from file
            printf("%d. To: %s, Subject: %s\n", i+1, e.to, e.subject);
        }
        int choice;
        printf("Enter number of email to view: ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= numEmails){
            e = parseEmail(emailFiles[choice-1]); //Parse email from file
            printf("\n--------------------------\n");
            printEmail(e); //Print email to console
            printf("--------------------------\n");
            printf("End of email.\n");
        }
        else{
            printf("Invalid choice.\n");
        }
    }
}

//Function to save an email to file
void saveEmail(struct Email e, char filename[]){
    FILE *fp;
    fp = fopen("sent/emails.txt", "a");
    fprintf(fp, "%s\n", filename); //Add filename to list of sent emails
    fclose(fp);
    fp = fopen(filename, "w");
    fprintf(fp, "From: %s\n", e.from);
    fprintf(fp, "To: %s\n", e.to);
    fprintf(fp, "Subject: %s", e.subject);
    fprintf(fp, "Message: %s", e.message);
    fclose(fp);
}

//Function to parse an email from file
struct Email parseEmail(char filename[]){
    struct Email e;
    char line[100];
    FILE *fp;
    fp = fopen(filename, "r");
    fgets(line, 100, fp);
    sscanf(line, "From: %s", e.from);
    fgets(line, 100, fp);
    sscanf(line, "To: %s", e.to);
    fgets(line, 100, fp);
    strcpy(e.subject, line);
    while(fgets(line, 100, fp) != NULL){
        strcat(e.message, line);
    }
    fclose(fp);
    return e;
}

//Function to print an email to console
void printEmail(struct Email e){
    printf("From: %s\n", e.from);
    printf("To: %s\n", e.to);
    printf("Subject: %s", e.subject);
    printf("Message: %s", e.message);
}