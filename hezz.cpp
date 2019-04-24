#include <conio.h>
#include <cstdio>
#include <cstring>
#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
void scF(FILE* fl);
void printD(char D[][8]);
void zapD(char D[][8]);
void readH(char str1[], int flagH);
void dvijP(char str1[10], int flagH);

char doska[8][8];
int main()
{
    FILE* fl;
    fl = fopen("SAH.txt", "rt");
    if (fl == NULL)
        printf("NE NAYDENO");

    zapD(doska);
    printD(doska);
    getche();
    while (1) {
        printD(doska);
        system("CLS");
        scF(fl);
        if (feof(fl))
            break;
    }
    printf("END.");
    getche();

    //}
}
void printD(char D[][8])
{
    int i, j;
    for (i = 7; i >= 0; i--) {
        printf("\n");
        printf("%d", i + 1);
        for (j = 0; j < 8; j++)
            printf(" %c", D[j][i]);
    }
    printf("\n  a b c d e f g h");
}

void scF(FILE* fl)
{
    char ch;
    int i, flag = 0;
    char str1[10];
    for (i = 0; i <= 10; i++)
        str1[i] = '\0';
    i = 0;
    // printf("bounce");
    while (!feof(fl)) {
        ch = fgetc(fl);
        // printf("%c",ch);
        if (ch == ' ')
            readH(str1, flag), flag = 1, i = -1;
        if (ch == '\n') {
            readH(str1, flag);
            return;
        }

        if (!flag)
            str1[i] = ch;
        if (flag)
            str1[i] = ch;
        i++;
    }
}

void readH(char str1[10], int flagH)
{
    int x;
    x = strlen(str1);
    if ((x > 7) || (x < 5))
        printf("ERROR0"), getche();
    if (x == 5)
        dvijP(str1, flagH);
    // if(x==6) DvijF(str1,flagH);
    // if(x==7) SahMat(str1,flagH);
    // printf("\n%d ",flagH);printf("%s",str1);printf(" %d",x);
}

void dvijP(char str1[10], int flagH)
{
    int x, y, xx, yy, flag = 0;
    switch (str1[0]) {
    case 'a':
        x = 0;
        break;
    case 'b':
        x = 1;
        break;
    case 'c':
        x = 2;
        break;
    case 'd':
        x = 3;
        break;
    case 'e':
        x = 4;
        break;
    case 'f':
        x = 5;
        break;
    case 'g':
        x = 6;
        break;
    case 'h':
        x = 7;
        break;
    default:
        printf("vihod za predeli doski vibor bukva");
        getche();
        break;
    }
    y = atoi(&str1[1]);
    y--;
    if ((y > 7) || (y < 0)) {
        printf("vihod za predeli doski vibor cifra");
        getche();
    }

    switch (str1[3]) {
    case 'a':
        xx = 0;
        break;
    case 'b':
        xx = 1;
        break;
    case 'c':
        xx = 2;
        break;
    case 'd':
        xx = 3;
        break;
    case 'e':
        xx = 4;
        break;
    case 'f':
        xx = 5;
        break;
    case 'g':
        xx = 6;
        break;
    case 'h':
        xx = 7;
        break;
    default:
        printf("vihod za predeli doski hod bukva");
        getche();
        break;
    }

    yy = atoi(&str1[4]);
    yy--;
    if ((y > 7) || (y < 0)) {
        printf("vihod za predeli doski hod cifra");
        getche();
    } // control doski

    if ((flagH) && ('P' == doska[x][y])) {
        printf("seycas hodat` chornie");
        getche();
    }
    if ((!flagH) && ('p' == doska[x][y])) {
        printf("seycas hodat` belie");
        getche();
    }
    // if((yy>=y)&&(flagH)){printf("vi libo hodite nazad libo na meste
    // black");getche();}  //ошибка конкреней описана, можно включить
    // if((yy<=y)&&(!flagH)){printf("vi libo hodite nazad libo na meste
    // white");getche();}

    if ('x' == str1[2]) {
        if (doska[xx][yy] == ' ') {
            printf("EXIT:net vzatiya iz za otsutsviya figuri");
            getche();
        }
    }

    if ('x' == str1[2]) {
        if ((xx == x + 1) && (yy == y + 1) && (!flagH))
            ;
        else if ((xx == x - 1) && (yy == y + 1) && (!flagH))
            ; // white
        else if ((xx == x + 1) && (yy == y - 1) && (flagH))
            ;
        else if ((xx == x - 1) && (yy == y - 1) && (flagH))
            ;
        else {
            printf("net vzatiya nepravilnaya cordinata, %c", doska[x][y]);
            getche();
        }
    }

    if ('-' == str1[2]) {
        if (doska[xx][yy] != ' ') {
            printf("tam stoit figura,%c,nelza postavit tuda,%c",
                   doska[xx][yy],
                   doska[x][y]);
            getche();
        }
    }

    if ('-' == str1[2]) {
        if ((xx == x) && (yy == y + 1) && (!flagH))
            ;
        else if (
                (xx == x) && (yy == y + 2) && (!flagH) && (y == 1)
                && (doska[x][2] == ' '))
            ;
        else if ((xx == x) && (yy == y - 1) && (flagH))
            ;
        else if (
                (xx == x) && (yy == y - 2) && (flagH) && (y == 6)
                && (doska[x][5] == ' '))
            ;
        else {
            printf("tak nelzya hodit` peskoy, libo daliko,lido na puti figura");
            getche();
        }
    }

    // neposredstvenno hod
    if (flagH == 0) {
        printf("%d %d %c", x, y, doska[x][y]);
        if ('P' == doska[x][y]) {
            doska[x][y] = ' ';
            doska[xx][yy] = 'P';
        } else
            printf("net P v kletke, libo drugaya figura"), getche();
    }
    if (flagH == 1) {
        printf("%d %d %c", x, y, doska[x][y]);
        if ('p' == doska[x][y]) {
            doska[x][y] = ' ';
            doska[xx][yy] = 'p';
        } else
            printf("net p v kletke, libo drugaya figura"), getche();
    }
    printD(doska);
    getche();
    system("CLS");
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
    D[4][5] = 'P';
}
