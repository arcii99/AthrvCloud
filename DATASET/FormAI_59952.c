//FormAI DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include<stdio.h> 
#include<string.h>

//function to check if message contains spam words
int check_spam(char message[])
{
    char spam_words[7][20]={"offer","win","earn","prize","discount","cash","urgent"}; //spam words
    char *token;
    int count=0,i=0;
 
    //get first token from message
    token = strtok(message," \t\n");
   
    while( token != NULL ) 
    {
        for(i=0;i<7;i++)
        {
            if(strcmp(token,spam_words[i])==0) //if token matches one of the spam words
            {
                count++;
            }
        }
        token = strtok(NULL," \t\n"); //get next token
    }
   
    if(count>=2) //if message contains more than or equal to 2 spam words
    {
        return 1; //spam message
    }
    else
    {
        return 0; //not a spam message
    }
 }

int main()
{
    char message[200];
    int is_spam=0;
   
    printf("Enter the message: ");
    fflush(stdin); //flush input buffer to avoid issues with fgets or gets function
    fgets(message,200,stdin); //get message from user
    is_spam = check_spam(message); //check if message is spam
   
    if(is_spam==1)
    {
        printf("This message is a spam.\n");
    }
    else
    {
        printf("This message is not a spam.\n");
    }
   
    return 0;
}