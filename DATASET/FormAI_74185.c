//FormAI DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <string.h>

int main(){
    char file_name[50];
    char *key = "happymenow";
    FILE *fp_in, *fp_out;
    char ch;
    int key_len = strlen(key), i = 0;

    printf("Enter a file name to encrypt (include file extension): ");
    scanf("%s", file_name);
    fp_in = fopen(file_name, "r");

    if(fp_in == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    fp_out = fopen("encrypted.txt", "w");

    while((ch = fgetc(fp_in)) != EOF){
        ch = ch ^ key[i++];
        if(i == key_len){
            i = 0;
        }
        fputc(ch, fp_out);
    }

    printf("File encrypted successfully!\n");
    fclose(fp_in);
    fclose(fp_out);

    return 0;
}