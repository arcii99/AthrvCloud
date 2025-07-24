//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void generateDNA(char *seq, int len) {
    char bases[] = {'A', 'T', 'C', 'G'};
    int i;
    for(i = 0; i < len; i++) {
        int randIndex = rand() % 4;
        seq[i] = bases[randIndex];
    }
    seq[i] = '\0';
}

void printAlignment(char *seq1, char *seq2, int len) {
    printf("\n");
    for(int i = 0; i < len; i++) {
        printf("%c", seq1[i]);
    }
    printf("\n");
    for(int i = 0; i < len; i++) {
        printf("%c", seq2[i]);
    }
}

void findMutations(char *seq1, char *seq2, int len) {
    printf("\n\nMutations:\n");
    int mismatches = 0, gaps = 0;
    for(int i = 0; i < len; i++) {
        if(seq1[i] != seq2[i]) {
            printf("Mismatch at position %d: %c -> %c\n", i + 1, seq1[i], seq2[i]);
            mismatches++;
        }
        if(seq1[i] == '-' || seq2[i] == '-') {
            printf("Gap at position %d: %c\n", i + 1, seq1[i] == '-' ? seq2[i] : seq1[i]);
            gaps++;
        }
    }
    if(!mismatches && !gaps) {
        printf("No mutations found!\n");
    }
}

int main() {
    srand(time(NULL));
    int len = 50;
    char seq1[len+1], seq2[len+1];
    generateDNA(seq1, len);
    generateDNA(seq2, len);
    printf("Sequence 1:\n");
    printf("%s\n", seq1);
    printf("Sequence 2:\n");
    printf("%s\n", seq2);
    printf("\n\nAligning Sequences...\n\n");
    int score[len+1][len+1];
    memset(score, 0, sizeof(score));
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= len; j++) {
            int match = seq1[i-1] == seq2[j-1] ? 1 : -1;
            int diag = score[i-1][j-1] + match;
            int left = score[i][j-1] - 1;
            int up = score[i-1][j] - 1;
            score[i][j] = diag;
            if(left > score[i][j]) {
                score[i][j] = left;
            }
            if(up > score[i][j]) {
                score[i][j] = up;
            }
        }
    }
    char aln1[len*2+1], aln2[len*2+1];
    memset(aln1, '-', sizeof(aln1));
    memset(aln2, '-', sizeof(aln2));
    int i = len, j = len;
    while(i > 0 || j > 0) {
        if(i > 0 && j > 0 && score[i][j] == score[i-1][j-1] + (seq1[i-1] == seq2[j-1] ? 1 : -1)) {
            aln1[i+j-1] = seq1[i-1];
            aln2[i+j-1] = seq2[j-1];
            i--;
            j--;
        } else if(j > 0 && score[i][j] == score[i][j-1] - 1) {
            aln1[i+j-1] = '-';
            aln2[i+j-1] = seq2[j-1];
            j--;
        } else if(i > 0 && score[i][j] == score[i-1][j] - 1) {
            aln1[i+j-1] = seq1[i-1];
            aln2[i+j-1] = '-';
            i--;
        }
    }
    printf("Score: %d\n", score[len][len]);
    printAlignment(aln1, aln2, len*2);
    findMutations(seq1, seq2, len);
    return 0;
}