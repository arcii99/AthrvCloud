//FormAI DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char filename[100], ch;

    printf("Enter the file name for recovery: ");
    scanf("%s", filename);

    fp1 = fopen(filename, "rb");  //open source file in binary mode

    if (fp1 == NULL)
    {
        printf("File does not exist.");
        return 0;
    }

    fp2 = fopen("recovered.txt", "wb"); //create a new file in write-binary mode

    while (1)
    {
        ch = fgetc(fp1);  //read a character from source file

        if (ch == EOF) //EOF is a constant representing end-of-file
        {
            break;  //break the loop if end-of-file is encountered
        }

        fputc(ch, fp2);  //write the character into the new file
    }

    printf("File recovered successfully.");

    fclose(fp1);  //close the source file
    fclose(fp2);  //close the new file

    return 0;
}