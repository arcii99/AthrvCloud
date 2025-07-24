//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    char f_name[50],str[100];
    int i,j,k,str_len,key;
    FILE *fp,*fp1,*fp2;
    printf("Enter the file name: ");
    fgets(f_name,50,stdin); /* Takes input from the user */
    f_name[strcspn(f_name,"\n")]='\0'; /* Removes the newline character from the input */
    fp=fopen(f_name,"rb"); /* Opens the file in read binary mode */
    printf("Enter the key: ");
    scanf("%d",&key);
    sprintf(str,"%d",key); /* Converts the key to a string */
    str_len=strlen(str); /* Finds the length of the key */
    fp1=fopen("out_file.txt","wb"); /* Opens a new file in write binary mode */
    while(fread(&i,sizeof(int),1,fp)) /* Loops through the file */
    {
        j=i+key; /* Adds the key to the integer i */
        fwrite(&j,sizeof(int),1,fp1); /* Writes the new integer j to the new file */
    }
    fclose(fp); /* Closes the file */
    fclose(fp1); /* Closes the new file */
    fp1=fopen("out_file.txt","rb"); /* Opens the new file in read binary mode */
    fp2=fopen("out_file_steg.txt","wb"); /* Opens another new file in write binary mode */
    fwrite(str,sizeof(char),str_len,fp2); /* Writes the string representation of the key to the new file */
    while(fread(&i,sizeof(int),1,fp1)) /* Loops through the new file */
    {
        j=i-key; /* Subtracts the key from the integer i */
        fwrite(&j,sizeof(int),1,fp2); /* Writes the new integer j to the new file */
    }
    fclose(fp1); /* Closes the new file */
    fclose(fp2); /* Closes the other new file */
    remove("out_file.txt"); /* Deletes the temporary file */
    printf("Done!");
    return 0;
}