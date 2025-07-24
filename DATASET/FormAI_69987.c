//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char tag[20];
    int level;
    int parent;
};

int main(){

    char XML[] = "<book>\n"
                 "   <title>Programming with C</title>\n"
                 "   <author>John Doe</author>\n"
                 "   <price>$25.00</price>\n"
                 "</book>";

    struct node tree[20];       //Array of structures to represent XML tree
    char temp[20];              //Temporary string to store tag
    int ptr = 0, level = 0;     //Pointer and level to traverse tree

    //Parsing the XML
    printf("Parsing XML:\n");
    char *token = strtok(XML,"\n");

    while(token!=NULL){

        //Extracting tag from line
        int i = 0, j = 0;
        while(token[i]!='<')
            i++;
        i++;
        while(token[i]!='>')
            temp[j++] = token[i++];

        temp[j] = '\0';

        //Adding tag to tree
        strcpy(tree[ptr].tag,temp);
        tree[ptr].level = level;
        if(ptr!=0)
            tree[ptr].parent = ptr-1;

        //Printing tag with indentation
        for(int k=0;k<=level;k++)
            printf("    ");
        printf("%s\n",temp);

        //Checking if end tag
        int len = strlen(token);
        if(token[1]=='/'){
            level--;
            ptr--;
        }
        else{
            level++;
            ptr++;
        }

        token = strtok(NULL,"\n"); 
    }

    //Printing XML tree using DFS
    printf("Printing XML Tree:\n");
    for(int i=0;i<=ptr;i++){
        for(int j=0;j<=tree[i].level;j++)
            printf("    ");
        printf("%s\n",tree[i].tag);
    }

    return 0;
}