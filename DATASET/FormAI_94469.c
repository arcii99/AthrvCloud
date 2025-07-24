//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include<stdio.h>

// Function to calculate C checksum
void calculateChecksum(char fileName[])
{
    FILE *fp;
    int i=0, sum=0, flag=0;
    fp=fopen(fileName,"r");

    // Check if file exists
    if(fp==NULL)
    {
        printf("The file %s does not exist!", fileName);
        return;
    }

    // Read file contents
    while(!feof(fp))
    {
        char c=fgetc(fp);
        if(c!=EOF)
        {
            if(flag==0)
            {
                i=c;
                flag=1;
            }
            else
            {
                sum+=i*c;
                flag=0;
            }
        }
    }

    // Close file
    fclose(fp);

    // Calculate checksum
    int checksum = ~(sum) + 1;

    // Print checksum
    printf("The C checksum of file %s is: %d", fileName, checksum);
}

int main()
{
    char fileName[]="example.txt";

    // Call function to calculate checksum
    calculateChecksum(fileName);

    return 0;
}