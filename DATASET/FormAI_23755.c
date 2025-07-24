//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    char suspect_virus[100];
    int found_virus = 0;
    
    printf("Greetings, I am Sherlock Holmes, and I am here to assist you in finding any potential viruses on your computer.\n");
    printf("Please enter the filename of the suspected virus:\n");
    scanf("%s", suspect_virus);
    
    FILE *suspect_file = fopen(suspect_virus, "r");
    if(suspect_file == NULL)
    {
        printf("I am afraid I could not locate that file. Please try again.\n");
        return 1;
    }
    
    printf("Let me investigate this file...\n");
    
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), suspect_file) != NULL)
    {
        if(strstr(buffer, "virus") != NULL || strstr(buffer, "malware") != NULL || strstr(buffer, "trojan") != NULL)
        {
            found_virus = 1;
            break;
        }
    }
    
    if(found_virus)
    {
        printf("I have found evidence of a virus in this file. It appears to be dangerous, and I recommend deleting it immediately.\n");
    }
    else
    {
        printf("I have not found any evidence of a virus in this file. However, please be aware that there may still be viruses on your computer.\n");
    }
    
    fclose(suspect_file);
    
    printf("Thank you for using my services. Good day!.\n");
    
    return 0;
}