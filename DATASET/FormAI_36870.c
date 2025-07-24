//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 1000

typedef struct{
    char ch;
    int weight;
    int parent, lchild, rchild;
}HTNode, *HuffmanTree;

typedef char *HuffmanCode;

void Select(HuffmanTree HT,int *p1,int *p2,int n){
    int min;
    for(int i=1; i<=n; i++){
        if(HT[i].parent == 0){
            *p1 = i;
            break;
        } 
    }
    for(int i=1; i<=n; i++){
        if(HT[i].parent == 0 && HT[i].weight < HT[*p1].weight) *p1 = i;
    }
    for(int i=1; i<=n; i++){
        if(HT[i].parent == 0 && i!=(*p1)){
            *p2 = i;
            break;
        }
    }
    for(int i=1; i<=n; i++){
        if(HT[i].parent == 0 && i!=(*p1)){
            if(HT[i].weight < HT[*p2].weight) *p2 = i;
        }
    }
}

void CreateHuffmanTree(HuffmanTree *HT, int *n){
    char s[MAXLEN];
    printf("Enter string:");
    scanf("%s",s);
    int len = strlen(s);
    int m = len*2-1;
    *HT = (HuffmanTree)malloc(sizeof(HTNode)*(m+1));
    for(int i=1; i<=m; i++){
        if(i<=len){
            (*HT)[i].ch = s[i-1];
        }
        (*HT)[i].weight = 1;
        (*HT)[i].parent = 0;
        (*HT)[i].lchild = 0;
        (*HT)[i].rchild = 0;
    }
    int s1,s2;
    for(int i=len+1; i<=m; i++){
        Select((*HT), &s1, &s2, i-1);
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
    *n = m;
}

void HuffmanCoding(HuffmanTree HT, HuffmanCode *HC, int n){
    char *cd = (char*)malloc(sizeof(char)*(n+1));
    cd[n-1] = '\0';
    for(int i=1; i<=n; i++){
        int start = n-1;
        int c = i;
        int f = HT[i].parent;
        while(f != 0){
            --start;
            if(HT[f].lchild == c) cd[start] = '0';
            else cd[start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HC[i-1] = (char*)malloc(sizeof(char)*(n-start));
        strcpy(HC[i-1], &cd[start]);
    }
    free(cd);
}

void PrintHuffmanCode(HuffmanTree HT, HuffmanCode HC, int n){
    for(int i=1; i<=n; i++){
        printf("'%c': %s\n", HT[i].ch, HC[i-1]);
    }
}

int main(){
    HuffmanTree HT;
    HuffmanCode HC;
    int n;
    CreateHuffmanTree(&HT, &n);
    HC = (HuffmanCode)malloc(sizeof(char*)*(n-1));
    HuffmanCoding(HT, HC, n);
    PrintHuffmanCode(HT, HC, n);
    return 0;
}