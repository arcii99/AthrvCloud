//FormAI DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include<stdio.h>

int main()
{
    FILE *fr; //Pointer to the input file
    FILE *fw; //Pointer to the output file
    char c, d;
    int count = 0; //count the number of spaces/tabs
    int i;

    fr=fopen("input.html", "r"); //Opening the input file
    fw=fopen("output.html", "w"); //Opening the output file

    if(fr==NULL) //Error handling for opening input file
    {
        printf("Cannot open input file \n");
        return 0;
    }

    while((c=fgetc(fr))!=EOF) //Loop to read the input file content
    {
        if(c==' ' || c=='\t') //Checking for space or tab
        {
            count++;
        }
        else
        {
            for(i=0;i<count;i++) //Loop to write the spaces/tabs into output file
            {
                fputc(d, fw);
            }
            fputc(c, fw); //Writing the character into output file
            count=0; //Reset the count
        }
    }

    fclose(fr); //Closing the input file
    fclose(fw); //Closing the output file
    return 0;
}