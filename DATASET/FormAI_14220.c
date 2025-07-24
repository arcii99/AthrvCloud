//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surprised
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Function to convert the string to uppercase
char *string_to_uppercase(char *string){
    int i = 0;
    while(string[i]){
        string[i] = toupper(string[i]);
        i++;
    }
    return string;
}

//Main function to demonstrate the plugin
int main(){
    printf("Welcome to the C Browser Plugin Example Program\n");

    //Get user input for the URL
    char url[100];
    printf("Enter the URL to load: ");
    scanf("%s", url);

    //Show the input URL and convert it to uppercase
    printf("URL: %s\n", url);
    printf("Uppercase URL: %s\n", string_to_uppercase(url));

    //Generate some sample HTML content
    char html[1000];
    strcpy(html, "<html><head><title>C Plugin Demo</title></head><body>");
    strcat(html, "<h1>Welcome to the C Plugin Demo</h1>");
    strcat(html, "<p>The uppercase URL is ");
    strcat(html, string_to_uppercase(url));
    strcat(html, "</p></body></html>");

    //Display the generated HTML content
    printf("Generated HTML Content:\n%s\n", html);

    //Exit the program
    printf("Exiting the program...");
    return 0;
}