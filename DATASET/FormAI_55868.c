//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

void translateAlienLanguage(char str[])
{
    int len = strlen(str);
    int i,j=-1;
    for(i=0;i<len;i++)
    {
        if(str[i]=='1')       //Alternate between the two vowels
        {
            if(j==0) 
                printf("i");
            else 
                printf("e");
            j=1-j;    //update the value of j
        }
        else if(str[i]=='2'||str[i]=='3')   //Map consonants accordingly
            printf("k");
        else if(str[i]=='4'||str[i]=='5')
            printf("r");
        else if(str[i]=='6'||str[i]=='7')
            printf("t");
        else if(str[i]=='8')
            printf("s");
        else if(str[i]=='9')
            printf("n");
    }
}

int main()
{
    char str[100];
    printf("Enter the alien language string: ");
    scanf("%s", str);
    printf("The translated string is: ");
    translateAlienLanguage(str);
    return 0;
}