//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    srand(time(NULL));
    int length, complexity;
    char password[100];
    printf("Welcome to the Medieval Password Generator!\n");
    printf("-------------------------------------------\n");
    printf("Enter the length of password you want to generate: ");
    scanf("%d", &length);
    printf("Enter the complexity of password you want to generate (1-5): ");
    scanf("%d", &complexity);
    printf("\nGenerating your password...\n");
    int i;

    for(i=0; i<length; i++)
    {
        if(complexity<1 || complexity>5)
        {
            printf("Invalid complexity input!\n");
            printf("Rerun the program and try again.\n");
            return 0;
        }

        int selector=rand()%complexity;

        switch(selector)
        {
            case 0:
            {
                int num=rand()%10;
                password[i]=(char)(num+'0');
                break;
            }

            case 1:
            {
                int lower=rand()%26;
                password[i]=(char)(lower+'a');
                break;
            }

            case 2:
            {
                int upper=rand()%26;
                password[i]=(char)(upper+'A');
                break;
            }

            case 3:
            {
                int symbol=rand()%15;
                char symbols[15]={'!','@','#','$','%','^','&','*','-','_','=','+','/','?','~'};
                password[i]=symbols[symbol];
                break;
            }

            case 4:     //case for medieval touch
            {
                char medieval[]={'E','V','I','L','L','O','R','D','S','A','V','A','G','E','S','F','E','A','R','D','R','E','A','D','Y'};
                int select_med=rand()%25;
                password[i]=medieval[select_med];
                break;
            }
        }
    }

    //checking password strength
    int upper_flag=0, lower_flag=0, num_flag=0, symbol_flag=0, medieval_flag=0;
    for(i=0; i<length; i++)
    {
        if(isupper(password[i]))
        {
            upper_flag=1;
        }
        if(islower(password[i]))
        {
            lower_flag=1;
        }
        if(isdigit(password[i]))
        {
            num_flag=1;
        }
        if(strchr("!@#$%^&*-_+=/?~", password[i]))
        {
            symbol_flag=1;
        }
        if(strchr("EVIL LORD SAVAGES FEARD READY", password[i]))
        {
            medieval_flag=1;
        }
    }

    //if password is weak, regenerate
    while(!(upper_flag && lower_flag && num_flag && symbol_flag && medieval_flag))
    {
        printf("\nGenerated password is weak! Generating new password...");
        for(i=0; i<length; i++)
        {
            int selector=rand()%complexity;
            switch(selector)
            {
                case 0:
                {
                    int num=rand()%10;
                    password[i]=(char)(num+'0');
                    break;
                }

                case 1:
                {
                    int lower=rand()%26;
                    password[i]=(char)(lower+'a');
                    break;
                }

                case 2:
                {
                    int upper=rand()%26;
                    password[i]=(char)(upper+'A');
                    break;
                }

                case 3:
                {
                    int symbol=rand()%15;
                    char symbols[15]={'!','@','#','$','%','^','&','*','-','_','=','+','/','?','~'};
                    password[i]=symbols[symbol];
                    break;
                }

                case 4:
                {
                    char medieval[]={'E','V','I','L','L','O','R','D','S','A','V','A','G','E','S','F','E','A','R','D','R','E','A','D','Y'};
                    int select_med=rand()%25;
                    password[i]=medieval[select_med];
                    break;
                }
            }
        }
        upper_flag=0;
        lower_flag=0;
        num_flag=0;
        symbol_flag=0;
        medieval_flag=0;
        for(i=0; i<length; i++)
        {
            if(isupper(password[i]))
            {
                upper_flag=1;
                continue;
            }
            if(islower(password[i]))
            {
                lower_flag=1;
                continue;
            }
            if(isdigit(password[i]))
            {
                num_flag=1;
                continue;
            }
            if(strchr("!@#$%^&*-_+=/?~", password[i]))
            {
                symbol_flag=1;
                continue;
            }
            if(strchr("EVIL LORD SAVAGES FEARD READY", password[i]))
            {
                medieval_flag=1;
                continue;
            }
        }
    }

    printf("Password generated successfully!\nYour Password is: ");
    for(i=0; i<length; i++)
    {
        printf("%c", password[i]);
    }
    printf("\n");

    return 0;
}