//FormAI DATASET v1.0 Category: Computer Biology ; Style: creative
#include <stdio.h>
#include <string.h>

int main(){
   char dna[100], rna[100], aminoAcids[21][4] = {"ALA","CYS","ASP","GLU","PHE","GLY","HIS","ILE","LYS","LEU",
                                                    "MET","ASN","PRO","GLN","ARG","SER","THR","VAL","TRP","TYR","**"};   
   printf("Enter the DNA sequence: ");
   scanf("%s",dna);
   
   // Step 1: Convert DNA to RNA
   int i;
   for(i=0; i<strlen(dna); i++){
       if(dna[i]=='T')
           rna[i]='U';
       else
           rna[i]=dna[i];
   }
   rna[strlen(dna)]='\0'; // Adding null terminator to rna
   
   // Step 2: Translate RNA to Protein
   int codonStart=0, aminoAcidIndex=0, codonIndex=0;
   char codon[4];
   while(codonStart<strlen(rna)){
       codon[0]=rna[codonStart];
       codon[1]=rna[codonStart+1];
       codon[2]=rna[codonStart+2];
       codon[3]='\0'; // Adding null terminator to codon
       
       for(i=0; i<21; i++){
           if(strcmp(codon,aminoAcids[i])==0){
               aminoAcidIndex=i;
               break;
           }
       }
       codonIndex+=3;
       printf("%s ",aminoAcids[aminoAcidIndex]);
   }
   printf("**\n"); // Adding stop codon
   
   return 0;
}