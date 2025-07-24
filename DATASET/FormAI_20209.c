//FormAI DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char temp1[150], temp2[150], temp3[150];
    int i, count1 = 0, count2 = 0, count3 = 0;

    fp = fopen("system.log", "r"); //open the log file

    if (fp == NULL)
    {
        printf("Error opening file\n"); //display an error message if unable to open the file
        exit(1);
    }

    while (fgets(temp1, 150, fp) != NULL) //read each line of the file
    {
        if (strstr(temp1, "ERROR") != NULL) //look for the keyword ERROR
        {
            count1++; //increment the count if keyword is found
        }
        if (strstr(temp1, "WARNING") != NULL) //look for the keyword WARNING
        {
            count2++; //increment the count if keyword is found
        }
        if (strstr(temp1, "INFO") != NULL) //look for the keyword INFO
        {
            count3++; //increment the count if keyword is found
        }
    }

    //display the results
    printf("\nNumber of ERROR messages: %d\n", count1);
    printf("Number of WARNING messages: %d\n", count2);
    printf("Number of INFO messages: %d\n\n", count3);

    rewind(fp); //reset the file pointer to the beginning of the file

    //display all ERROR messages
    printf("ERROR messages: \n\n");

    while (fgets(temp2, 150, fp) != NULL) //read each line of the file
    {
        if (strstr(temp2, "ERROR") != NULL) //look for the keyword ERROR
        {
            printf("%s", temp2); //display the line if keyword is found
        }
    }

    rewind(fp); //reset the file pointer to the beginning of the file

    //display all WARNING messages
    printf("\nWARNING messages: \n\n");

    while (fgets(temp3, 150, fp) != NULL) //read each line of the file
    {
        if (strstr(temp3, "WARNING") != NULL) //look for the keyword WARNING
        {
            printf("%s", temp3); //display the line if keyword is found
        }
    }

    fclose(fp); //close the file
    return 0;
}