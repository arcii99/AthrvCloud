//FormAI DATASET v1.0 Category: Spell checking ; Style: random
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char input_word[50],dict_word[50],ch=0;
    int i,j,length_input_word,len_dict_word,f=0;

    printf("Enter the word to check for spelling: ");
    scanf("%s",input_word);

    length_input_word=strlen(input_word);

    FILE *fp;

    fp=fopen("dictionary.txt","r");

    if(fp==NULL)
    {
        printf("Dictionary not found.\n");
        return 0;
    }

    printf("Possible corrections for the word %s are:\n",input_word);
    printf("--------------------------------------------------------\n");

    while(ch!=EOF)
    {
        len_dict_word=0;
        while((ch=fgetc(fp))!='\n' && ch!=EOF)
        {
            dict_word[len_dict_word++]=ch;
        }
        dict_word[len_dict_word]='\0';

        for(i=0;i<strlen(input_word);i++)
        {
            input_word[i]=tolower(input_word[i]);
        }

        for(i=0;i<strlen(dict_word);i++)
        {
            dict_word[i]=tolower(dict_word[i]);
        }

        if(strcmp(input_word,dict_word)==0)
        {
            f=1;
            break;
        }

        if(length_input_word==len_dict_word || length_input_word==(len_dict_word+1))
        {
            int flag=0,flag1=0,k=0;
            for(i=0,j=0;i<strlen(input_word);i++,j++)
            {
                if(input_word[i]!=dict_word[j])
                {
                    k++;
                    if(input_word[i]==dict_word[j+1] && flag==0 && (strlen(input_word)+1)==strlen(dict_word))
                    {
                        j++;
                        flag=1;
                    }
                    else if(input_word[i+1]==dict_word[j+1] && flag1==0 && strlen(input_word)==strlen(dict_word))
                    {
                        flag1=1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(i==strlen(input_word) && k<=1 && flag==1 || flag1==1)
            {
                printf("%s\n",dict_word);
            }
        }
    }

    if(f==0)
    {
        printf("\n\n%s is not a valid word.",input_word);
    }

    fclose(fp);

    return 0;
}