//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void generate_password(int len);

int main()
{
    int len;
    printf("Enter the length of password to generate: ");
    scanf("%d",&len);
    generate_password(len);
    return 0;
}

void generate_password(int len)
{
    char password[len+1];
    srand(time(NULL));
    
    for(int i=0;i<len;i++)
    {
        int r = rand() % 3;
        
        if(r == 0)
            password[i] = '0' + (rand() % 10);
        else if(r == 1)
            password[i] = 'a' + (rand() % 26);
        else
            password[i] = 'A' + (rand() % 26);
    }
    
    password[len] = '\0';
    printf("Generated password is: %s",password);
}