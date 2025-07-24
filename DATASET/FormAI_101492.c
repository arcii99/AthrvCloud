//FormAI DATASET v1.0 Category: Computer Biology ; Style: lively
#include<stdio.h>

int main(){
    printf("Welcome to the DNA Sequencing Program!\n\n");
    
    //Getting DNA sequence from user
    char dna[100];
    printf("Please enter a DNA sequence (A, T, G, C only): ");
    scanf("%s", &dna);
    
    //Checking if input is valid
    int i;
    for(i=0; i<strlen(dna); i++){
        if(dna[i]!='A' && dna[i]!='T' && dna[i]!='G' && dna[i]!='C'){
            printf("\nInvalid input: %c\n", dna[i]);
            return 0;
        }
    }
    
    printf("\nThe DNA sequence entered is: %s", dna);
    
    //Transcribing DNA sequence to mRNA
    char mrna[100];
    for(i=0; i<strlen(dna); i++){
        if(dna[i]=='A')
            mrna[i]='U';
        else if(dna[i]=='T')
            mrna[i]='A';
        else if(dna[i]=='G')
            mrna[i]='C';
        else if(dna[i]=='C')
            mrna[i]='G';
    }
    printf("\n\nThe mRNA transcribed from the DNA sequence is: %s", mrna);
    
    //Translating mRNA sequence to protein
    char protein[100];
    for(i=0; i<strlen(mrna); i+=3){
        if(mrna[i]=='U'){
            if(mrna[i+1]=='U'){
                if(mrna[i+2]=='U' || mrna[i+2]=='UC')
                    protein[i/3]='F';
                else if(mrna[i+2]=='UU' || mrna[i+2]=='UC')
                    protein[i/3]='L';
            }
            else if(mrna[i+1]=='C'){
                protein[i/3]='S';
            }
            else if(mrna[i+1]=='A'){
                if(mrna[i+2]=='U' || mrna[i+2]=='UC')
                    protein[i/3]='I';
                else if(mrna[i+2]=='AU' || mrna[i+2]=='AC')
                    protein[i/3]='N';
            }
            else if(mrna[i+1]=='G'){
                if(mrna[i+2]=='U' || mrna[i+2]=='UC')
                    protein[i/3]='C';
                else if(mrna[i+2]=='AU' || mrna[i+2]=='AC')
                    protein[i/3]='T';
            }
        }
        else if(mrna[i]=='C'){
            if(mrna[i+1]=='U'){
                protein[i/3]='L';
            }
            else if(mrna[i+1]=='C'){
                protein[i/3]='P';
            }
            else if(mrna[i+1]=='A'){
                if(mrna[i+2]=='U' || mrna[i+2]=='UC')
                    protein[i/3]='H';
                else if(mrna[i+2]=='AU' || mrna[i+2]=='AC')
                    protein[i/3]='Q';
            }
            else if(mrna[i+1]=='G'){
                protein[i/3]='R';
            }
        }
        else if(mrna[i]=='A'){
            if(mrna[i+1]=='U'){
                if(mrna[i+2]=='U' || mrna[i+2]=='UC' || mrna[i+2]=='UA')
                    protein[i/3]='I';
                else if(mrna[i+2]=='AU' || mrna[i+2]=='AC')
                    protein[i/3]='T';
                else if(mrna[i+2]=='UG')
                    protein[i/3]='M';
            }
            else if(mrna[i+1]=='C'){
                protein[i/3]='T';
            }
            else if(mrna[i+1]=='A'){
                if(mrna[i+2]=='UU' || mrna[i+2]=='UC')
                    protein[i/3]='N';
                else if(mrna[i+2]=='AU' || mrna[i+2]=='AC')
                    protein[i/3]='K';
                else if(mrna[i+2]=='UG')
                    protein[i/3]='*';
            }
            else if(mrna[i+1]=='G'){
                if(mrna[i+2]=='UU' || mrna[i+2]=='UC')
                    protein[i/3]='S';
                else if(mrna[i+2]=='CU' || mrna[i+2]=='CC' || mrna[i+2]=='CA' || mrna[i+2]=='CG')
                    protein[i/3]='R';
            }
        }
        else if(mrna[i]=='G'){
            if(mrna[i+1]=='U'){
                protein[i/3]='V';
            }
            else if(mrna[i+1]=='C'){
                protein[i/3]='A';
            }
            else if(mrna[i+1]=='A'){
                if(mrna[i+2]=='UU' || mrna[i+2]=='UC')
                    protein[i/3]='E';
                else if(mrna[i+2]=='AU' || mrna[i+2]=='AC')
                    protein[i/3]='D';
                else if(mrna[i+2]=='UG')
                    protein[i/3]='*';
                else if(mrna[i+2]=='AG')
                    protein[i/3]='*';
            }
            else if(mrna[i+1]=='G'){
                protein[i/3]='G';
            }
        }
        else{
            printf("\nInvalid input: %c\n", mrna[i]);
            return 0;
        }
    }
    printf("\n\nThe protein translated from the mRNA sequence is: %s", protein);
    
    printf("\n\nThank you for using the DNA Sequencing Program!\n");
    return 0;
}