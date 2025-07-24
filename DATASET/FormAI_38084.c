//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include<stdio.h>
#include<string.h>

int main(){
    int i, j, k;
    char virus[5][10] = {"trojan", "worm", "malware", "spyware", "ransomware"};
    char filename[20], ext[5], *ptr;

    printf("Welcome to the C Antivirus scanner! \n");

    printf("\nEnter the filename with extension (.exe, .dll, .doc, .txt): ");
    scanf("%s", filename);

    ptr = strchr(filename, '.');
    strcpy(ext, ptr+1);

    if(strcmp(ext, "exe")==0 || strcmp(ext, "dll")==0) {
        printf("Scanning for viruses... \n");

        for(i=0; i<5; i++) {
            for(j=0; j<strlen(filename); j++) {
                if(filename[j] == virus[i][0]) {
                    k=1;
                    while(k<strlen(virus[i]) && filename[j+k] == virus[i][k])
                        k++;
                    if(k == strlen(virus[i])) {
                        printf("\nVirus detected: %s", virus[i]);
                        printf("\nQuarantine %s file!", ext);
                        return 0;
                    }
                }
            }
        }
        
        printf("\nCongratulations! No viruses have been found.\n");
    }

    else {
        printf("\nInvalid file extension. C Antivirus scanner supports only .exe and .dll files. \n");
    }
    
    return 0;
}