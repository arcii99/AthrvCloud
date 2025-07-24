//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

int main(){
    char sequence[MAX_LENGTH];
    int seqLength, i, j, k, temp;
    int gcCount, atCount;
    float gcPercentage, atPercentage;

    printf("Enter a DNA sequence (max length - 1000):\n");
    fgets(sequence, MAX_LENGTH, stdin);
    seqLength = strlen(sequence)-1;

    // Check if the sequence contains only valid nucleotides
    for(i=0;i<seqLength;i++){
        if(sequence[i]!='A'&&sequence[i]!='C'&&sequence[i]!='G'&&sequence[i]!='T'){
            printf("Invalid sequence! Contains non-nucleotide character(s)\n");
            return 0;
        }
    }

    // Convert to upper case
    for(i=0;i<seqLength;i++){
        if(sequence[i]>='a'&&sequence[i]<='z'){
            sequence[i] -= ('a'-'A');
        }
    }

    // Reverse complement
    for(i=0,j=seqLength-1;i<j;i++,j--){
        temp = sequence[i];
        sequence[i] = sequence[j];
        sequence[j] = temp;

        if(sequence[i]=='A'){
            sequence[i] = 'T';
        }else if(sequence[i]=='T'){
            sequence[i] = 'A';
        }else if(sequence[i]=='C'){
            sequence[i] = 'G';
        }else if(sequence[i]=='G'){
            sequence[i] = 'C';
        }

        if(sequence[j]=='A'){
            sequence[j] = 'T';
        }else if(sequence[j]=='T'){
            sequence[j] = 'A';
        }else if(sequence[j]=='C'){
            sequence[j] = 'G';
        }else if(sequence[j]=='G'){
            sequence[j] = 'C';
        }
    }

    // Calculate GC percentage
    gcCount = 0;
    for(i=0;i<seqLength;i++){
        if(sequence[i]=='G'||sequence[i]=='C'){
            gcCount++;
        }
    }
    gcPercentage = ((float)gcCount/seqLength)*100;

    // Calculate AT percentage
    atCount = 0;
    for(i=0;i<seqLength;i++){
        if(sequence[i]=='A'||sequence[i]=='T'){
            atCount++;
        }
    }
    atPercentage = ((float)atCount/seqLength)*100;

    // Print results
    printf("Reverse complement: %s\n", sequence);
    printf("GC percentage: %.2f%%\n", gcPercentage);
    printf("AT percentage: %.2f%%\n", atPercentage);

    return 0;
}