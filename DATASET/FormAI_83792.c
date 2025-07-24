//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to store translations
typedef struct alienWords{
    char english[20];
    char alien[20];
}alienWords;

int main(){

    int choice;
    char input[20];
    alienWords dict[5];

    //populate the dictionary
    strcpy(dict[0].english, "hello");
    strcpy(dict[0].alien,"phrry");
    strcpy(dict[1].english, "goodbye");
    strcpy(dict[1].alien,"lomph");
    strcpy(dict[2].english, "thank you");
    strcpy(dict[2].alien,"jeestr");
    strcpy(dict[3].english, "please");
    strcpy(dict[3].alien,"grakk");
    strcpy(dict[4].english, "sorry");
    strcpy(dict[4].alien,"blorsh");

    printf("Welcome to the C Alien Language Translator!\n");

    while(1){
        //take user's choice
        printf("\nPlease select an option:\n");
        printf("1. English to Alien\n");
        printf("2. Alien to English\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        getchar();

        switch(choice){

            case 1: //translate from english to alien

                printf("\nEnter the english word/phrase to be translated:\n");
                fgets(input, 20, stdin);
                input[strcspn(input, "\n")] = '\0';

                for(int i=0; i<strlen(input); i++){
                    for(int j=0; j<5; j++){
                        if(dict[j].english[0] == input[i]){
                            printf("%s ",dict[j].alien);
                        }
                    }
                }

                break;

            case 2: //translate from alien to english

                printf("\nEnter the alien word/phrase to be translated:\n");
                fgets(input, 20, stdin);
                input[strcspn(input, "\n")] = '\0';

                int i=0;
                while(i<strlen(input)){
                    //check for matching alien words
                    for(int j=0; j<5; j++){
                        if(strncmp(dict[j].alien,&input[i],strlen(dict[j].alien))==0){
                            printf("%s", dict[j].english);
                            i+=strlen(dict[j].alien);
                        }
                    }
                    i++;
                }

                break;

            case 3: //exit
                printf("\nThank you for using the C Alien Language Translator!\n");
                exit(0);
                break;

            default: //invalid option
                printf("\nInvalid option! Please select a valid option.\n");
                break;
        }
    }

    return 0;
}