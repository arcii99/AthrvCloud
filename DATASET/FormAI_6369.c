//FormAI DATASET v1.0 Category: System administration ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    char flag[25] = "santaclausiscomingto";
    char input[25];
    int i, match = 0;
    
    printf("Enter the secret passphrase: ");
    scanf("%s", input);

    for(i=0; i<25; i++){
        if(input[i] == flag[i]){
            match++;
        }
    }

    if(match == 25){
        printf("Congratulations! You have unlocked the system administration program.\n");
        printf("Accessing sensitive files....\n");
        sleep(2);
        printf("Sorry, we cannot show you the sensitive files without proper authorization.\n");
        printf("Please enter the superuser password: ");
        scanf("%s", input);

        if(strcmp(input, "3Rq#p7K@9Xm") == 0){
            printf("Superuser access granted. Proceeding with sensitive files...");
            //Insert code to display sensitive files here
        }
        else{
            printf("Superuser access denied. Program terminated.\n");
            exit(0);
        }
    }
    else{
        printf("Wrong passphrase entered. Program terminated.\n");
        exit(0);
    }

    return 0;
}