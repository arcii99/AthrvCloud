//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: recursive
// C Levenshtein Distance Calculator using recursive style

#include<stdio.h>
#include<string.h>

//Recursive function for finding Levenshtein Distance
int levDist(char str1[], char str2[], int l1, int l2){
    //If 1st string is empty then distance is length of 2nd string
    if(l1 == 0){
        return l2;
    }
    //If 2nd string is empty then distance is length of 1st string
    if(l2 == 0){
        return l1;
    }
    //If last characters of both strings are same then nothing to do
    if(str1[l1-1] == str2[l2-1]){
        return levDist(str1, str2, l1-1, l2-1);
    }
    //Find minimum distance after insert, delete and replace operation
    int minDist = levDist(str1, str2, l1-1, l2) + 1; //Deletion
    int distByInsert = levDist(str1, str2, l1, l2-1) + 1; //Insertion
    int distByReplace = levDist(str1, str2, l1-1, l2-1) + 1; //Replace
    //Return the minimum distance 
    return minDist > distByInsert ? (distByInsert > distByReplace ? distByReplace : distByInsert) : (minDist > distByReplace ? distByReplace : minDist);
}

int main(){
    char str1[100], str2[100];
    int l1, l2;
    printf("Enter 1st string: ");
    scanf("%s", str1);
    printf("Enter 2nd string: ");
    scanf("%s", str2);
    l1 = strlen(str1);
    l2 = strlen(str2);
    printf("Minimum Levenshtein Distance between %s and %s is %d\n", str1, str2, levDist(str1, str2, l1, l2));
    return 0;
}