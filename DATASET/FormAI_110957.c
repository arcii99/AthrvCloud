//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c){
    if(a<b && a<c){
        return a;
    }else if(b<a && b<c){
        return b;
    }else{
        return c;
    }
}

int levenshtein(char*str1,char*str2,int len1,int len2){
    int matrix[len1+1][len2+1];
    int i,j,sub;
    for(i=0;i<=len1;i++){
        matrix[i][0]=i;
    }
    for(j=0;j<=len2;j++){
        matrix[0][j]=j;
    }
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(str1[i-1]==str2[j-1]){
                sub=0;
            }else{
                sub=1;
            }
            matrix[i][j]=minimum(matrix[i-1][j]+1,matrix[i][j-1]+1,matrix[i-1][j-1]+sub);
        }
    }
    return matrix[len1][len2];
}

int main()
{
    char str1[10],str2[10];
    printf("Enter the first string:\n");
    scanf("%s",str1);
    printf("Enter the second string:\n");
    scanf("%s",str2);
    int len1=strlen(str1);
    int len2=strlen(str2);
    printf("The Levenshtein Distance between the strings %s and %s is %i\n",str1,str2,levenshtein(str1,str2,len1,len2));
    return 0;
}