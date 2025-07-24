//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include<stdio.h>
#include<string.h>

void watermark(char input[], char output[])
{
    char watermark[] = "This File is Watermarked!"; //Define the watermark as a string
    int i, j, k = 0;
    for(i=0;i<strlen(input);i++)
    {
        //Add watermark after every 5th character in the input string
        if(i%5 == 0)
        {
            for(j=0;j<strlen(watermark);j++)
            {
                output[k] = watermark[j];
                k++;
            }
        }
        //Add character of input string to output string
        output[k] = input[i];
        k++;
    }
    output[k]='\0'; //Add null terminator at the end of the output string
}

int main()
{
    char input[100], output[200];
    printf("Enter the text to watermark: ");
    gets(input); //User input as the string to be watermarked
    watermark(input, output); //Watermark the input string and store in output string
    printf("\nWatermarked Text: %s\n", output); //Print the watermarked text
    return 0;
}