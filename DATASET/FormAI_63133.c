//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_SIZE 5000
#define MAX_SUMMARY_SIZE 1000

// function to remove punctuations from the input text
void remove_punctuations(char *s) 
{
   int i,j;
   for(i=0; s[i]!='\0'; i++)
   {
      while (!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]=='\0'))) 
      {
         for(j=i; s[j]!='\0';j++) 
         {
            s[j]=s[j+1];
         }
         s[j]='\0';
      }
   }
}

// function to convert all the characters in the input text to lower case
void convert_to_lower_case(char *s) 
{
   int i = 0;
   while(s[i]!='\0') 
   {
      if(s[i]>='A'&&s[i]<='Z') 
      {
         s[i]+=32;
      }

      i++;
   }
}

// function to generate a summary of the input text
void generate_summary(char *input_text, char *summary) 
{
   int i,j,count=0,len_input_text,len_summary=0,flag=0;
   char temp[MAX_INPUT_SIZE];
   char *token;
   char *ptr[MAX_INPUT_SIZE];

   // remove punctuations from the input text
   remove_punctuations(input_text);

   // convert all the characters to lower case
   convert_to_lower_case(input_text);

   // make a copy of the input text
   strcpy(temp, input_text);

   // split the input text into sentences using '.' as the delimiter
   token = strtok(temp, ".");

   // iterate over the sentences
   while(token != NULL) 
   {
      // check if the sentence contains some important keywords
      if(strstr(token, "important") != NULL || strstr(token, "key") != NULL || strstr(token, "highlight") != NULL) 
      {
         // if the number of characters in the summary is within the limit
         if(len_summary + strlen(token) < MAX_SUMMARY_SIZE) 
         {
            // add the sentence to the summary
            strcat(summary, token);
            strcat(summary, ". ");

            // set the flag indicating that the input text contains some important sentences
            flag = 1;
         }
      }

      // store the sentence in an array of pointers
      ptr[count++] = token;

      // move to the next sentence
      token = strtok(NULL, ".");
   }

   // if the input text does not contain any important sentences
   if(flag == 0) 
   {
      // if the number of sentences in the input text is less than the limit
      if(count < MAX_SUMMARY_SIZE) 
      {
         // add all the sentences to the summary
         for(i=0;i<count;i++) 
         {
            strcat(summary, ptr[i]);
            strcat(summary, ". ");
         }
      }
      else // if there are more sentences than the limit
      {
         // add the first few sentences to the summary
         for(i=0;i<MAX_SUMMARY_SIZE;i++) 
         {
            strcat(summary, ptr[i]);
            strcat(summary, ". ");
         }
      }
   }
}

int main() 
{
   char input_text[MAX_INPUT_SIZE];
   char summary[MAX_SUMMARY_SIZE];

   printf("\nEnter the input text:\n");
   fgets(input_text,MAX_INPUT_SIZE,stdin);

   // initialize the summary
   strcpy(summary, "");

   // generate the summary
   generate_summary(input_text, summary);

   // display the summary
   printf("\nSummary:\n%s\n",summary);

   return 0;
}