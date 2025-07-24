//FormAI DATASET v1.0 Category: String manipulation ; Style: imaginative
#include<stdio.h>
#include<string.h>

int main(){

   char str1[20],str2[20],result[40]; //Declare variables

   printf("Enter first string: ");  //Prompt user to input first string
   scanf("%s",str1);

   printf("Enter second string: "); //Prompt user to input second string
   scanf("%s",str2);

   int len1=strlen(str1); //Find length of first string
   int len2=strlen(str2); //Find length of second string

   int i=0,j=0,k=0;

   while(i<len1 && j<len2){ //Loop until characters are present in both strings 
       result[k]=str1[i];  //Add character from first string to result array
       result[k+1]=str2[j]; //Add character from second string to result array
       k+=2; //increase counter by 2
       i++; //increase first string counter
       j++; //increase second string counter
   }

   if(i<len1){ //If characters remaining in first string, add them to result
      while(i<len1){
         result[k]=str1[i];
         i++;
         k++;
      }
   }

   if(j<len2){ //If characters remaining in second string, add them to result
      while(j<len2){
         result[k]=str2[j];
         j++;
         k++;
      }
   }
   
   printf("The concatenated string is %s",result); //Print result
   
   return 0; //end program
}