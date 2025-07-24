//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
#include<stdio.h> 
#include<stdlib.h> 

int main() 
{ 
    char virus[10]={'a','v','i','r','u','s','\0'}; //Declare the virus to be detected
    char fileName[50]; //Declare the file name
    
    printf("Enter the name of the file to be scanned: "); 
    scanf("%s",&fileName); //Take file name input from user
    
    FILE *fp; 
    fp=fopen(fileName,"r"); //Open the file in reading mode
    
    char ch; 
    int i=0; 
    while((ch=fgetc(fp))!=EOF) //Read each character from the file
    { 
        if(virus[i]==ch) //If virus element matches with file character
        { 
            i++; //Move to the next element
            if(virus[i]=='\0') //If all virus elements matches
            { 
                printf("\n\nFile is infected with the virus 'avir\n\n"); 
                exit(0); //Exit the program
            } 
        } 
        else
        { 
            i=0; //Reset i if the element doesn't match
        } 
    } 
    
    printf("\n\nFile is not infected with the virus 'avir'.\n\n"); //Print if virus not found
    
    fclose(fp); //Close the file
    
    return 0; //End the program
}