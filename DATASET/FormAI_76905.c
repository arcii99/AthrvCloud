//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: random
/*
* Building a Simple XML Parser
*
* This program reads an XML file, extracts the element tags and prints them
* to the console.
*
*/

#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_TAG_SIZE 50

int main(int argc, char* argv[])
{
   FILE* xml_file;
   char line[MAX_LINE_SIZE];
   char curr_tag[MAX_TAG_SIZE];
   int i, j, tag_index;

   //check if the xml file has been specified as the command line argument
   if(argc != 2)
   {
      printf("Please specify the xml file to parse as the command line argument.\n");
      return -1;
   }

   //open the xml file
   xml_file = fopen(argv[1], "r");

   //check if the file exists
   if(xml_file == NULL)
   {
      printf("The xml file does not exist.\n");
      return -1;
   }

   //read through the file line by line
   while(fgets(line, MAX_LINE_SIZE, xml_file) != NULL)
   {
      //check if the line contains a tag
      if(line[0] == '<')
      {
         //initialize the tag string
         memset(curr_tag, '\0', MAX_TAG_SIZE*sizeof(char));

         //extract the tag from the line
         tag_index = 0;
         for(i=1; i<MAX_LINE_SIZE && line[i]!='\0'; i++)
         {
            if(line[i] == '>') break;
            curr_tag[tag_index++] = line[i];
         }

         //print the tag to the console
         printf("%s\n", curr_tag);
      }
   }

   //close the xml file
   fclose(xml_file);

   return 0;
}