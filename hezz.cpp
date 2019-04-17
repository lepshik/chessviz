
#include <cstdio>
#include <iostream>

void printD(char D[][8])
{
    int i, j;
    for (i = 7; i >= 0; i--) {
        printf("\n");
        for (j = 0; j < 8; j++)
            printf(" %c", D[j][i]);
    }
}

void zapD(char D[][8])
{
    D[0][7] = 'r';
    D[1][7] = 'n';
    D[2][7] = 'k';
    D[3][7] = 'q';
    D[4][7] = 'k';
    D[5][7] = 'b';
    D[6][7] = 'n';
    D[7][7] = 'r';
    D[0][6] = 'p';
    D[1][6] = 'p';
    D[2][6] = 'p';
    D[3][6] = 'p';
    D[4][6] = 'p';
    D[5][6] = 'p';
    D[6][6] = 'p';
    D[7][6] = 'p';
    for (int i = 2; i <= 5; i++) {
        for (int j = 0; j <= 7; j++) {
            D[j][i] = ' ';
        }
    }
    D[0][1] = 'P';
    D[1][1] = 'P';
    D[2][1] = 'P';
    D[3][1] = 'P';
    D[4][1] = 'P';
    D[5][1] = 'P';
    D[6][1] = 'P';
    D[7][1] = 'P';
    D[0][0] = 'R';
    D[1][0] = 'N';
    D[2][0] = 'K';
    D[3][0] = 'Q';
    D[4][0] = 'K';
    D[5][0] = 'B';
    D[6][0] = 'N';
    D[7][0] = 'R';
}

int main()
{
    char doska[8][8];
    zapD(doska);
    printD(doska);
}

