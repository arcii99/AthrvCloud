//FormAI DATASET v1.0 Category: Data mining ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create an array of strings containing sample data
    char* data[] = {
        "John Smith,25,Male,Engineer",
        "Jane Doe,30,Female,Doctor",
        "Bob Johnson,40,Male,Lawyer",
        "Alice Brown,33,Female,Teacher",
        "Mike Davis,28,Male,IT Specialist"
    };

    // Determine the size of the dataset
    int size = sizeof(data) / sizeof(data[0]);

    // Initialize an empty dictionary to store the mined data
    char* dict[100];
    int num_dict_entries = 0;

    // Loop through each entry in the dataset
    for(int i = 0; i < size; i++)
    {
        // Parse each entry to extract the necessary information
        char* name = strtok(data[i], ",");
        char* age = strtok(NULL, ",");
        char* gender = strtok(NULL, ",");
        char* occupation = strtok(NULL, ",");

        // Determine if the occupation has already been added to the dictionary
        int entry_found = 0;
        for(int j = 0; j < num_dict_entries; j++)
        {
            if(strcmp(dict[j], occupation) == 0)
            {
                // If the occupation is already in the dictionary, increment its count
                entry_found = 1;
                char temp[100];
                sprintf(temp, "%s,%d", occupation, atoi(dict[j]+strlen(occupation)+1)+1);
                dict[j] = (char*) realloc(dict[j], strlen(temp) + 1);
                strcpy(dict[j], temp);
                break;
            }
        }

        // If the occupation is not in the dictionary, add it with a count of 1
        if(!entry_found)
        {
            dict[num_dict_entries] = (char*) malloc(100);
            sprintf(dict[num_dict_entries], "%s,%d", occupation, 1);
            num_dict_entries++;
        }
    }

    // Print out the mined data
    printf("Occupation\tCount\n");
    for(int i = 0; i < num_dict_entries; i++)
    {
        printf("%s\n", dict[i]);
    }

    // Free the memory used for the dictionary
    for(int i = 0; i < num_dict_entries; i++)
    {
        free(dict[i]);
    }

    return 0;
}