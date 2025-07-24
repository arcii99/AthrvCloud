//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: surrealist
#include<stdlib.h>
#include<stdio.h>

int main(){
    int eyes = 2, noses = 1, mouths = 3;
    char* xml = "<person>\n"
                "   <features>\n"
                "       <eyes>%d</eyes>\n"
                "       <noses>%d</noses>\n"
                "       <mouths>%d</mouths>\n"
                "   </features>\n"
                "</person>";

    printf(xml, eyes, noses, mouths);
    printf("\n");

    printf("Suddenly, a wild XML parser appears!\n");
    printf("It starts analyzing the XML code...\n");

    // XML parsing logic
    if(eyes == 2 && noses == 1 && mouths == 3){
        printf("The XML code is valid!\n");
        printf("The person has normal facial features\n");
    } else{
        printf("Invalid XML code. The person is deformed.\n");
        printf("Aborting program...\n");
        exit(1);
    }

    printf("The XML parser disappears into the void.\n");
    printf("Program execution complete!\n");

    return 0;
}