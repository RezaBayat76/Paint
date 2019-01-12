#include <iostream.h>
#include <conio.h>
#include <stdio.h>

int far *screen = (int far *)0xb8000000;
int x = 9, y = 40, p = 7 * 16 * 256, flag = 0, color = 7 * 16;

void fill(int x, int y, int c, int tp);

char c;

//***************************************************************************
void init(void) {                           //clear screen
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            screen[i * 80 + j] = p;
        }
    }
    for (int tb = 1; tb < 79; tb++) {         //tp=top border
        screen[tb] = p + 205;
    }
    /////
    for (int cb1 = 0; cb1 < 20; cb1++) {     //cb1=centeral border 1
        screen[18 * 80 + cb1] = p + 205;
    }
    for (int cb2 = 20; cb2 < 58; cb2++) {     //cb2=centeral border 2
        screen[18 * 80 + cb2] = p + 205;
    }
    for (int cb3 = 59; cb3 < 79; cb3++) {     //cb3=centeral border 3
        screen[18 * 80 + cb3] = p + 205;
    }
    /////
    for (int bb1 = 1; bb1 < 20; bb1++) {         //bb1=bottom border 1
        screen[24 * 80 + bb1] = p + 205;
    }
    for (int bb2 = 21; bb2 < 79; bb2++) {        //bb2=bottom border 2
        screen[24 * 80 + bb2] = p + 205;
    }
    /////
    for (int rlb1 = 1; rlb1 < 18; rlb1++) {      //rlb1=right left border 1
        screen[rlb1 * 80] = p + 186;
        screen[rlb1 * 80 + 79] = p + 186;
    }
    for (int rlb2 = 19; rlb2 < 24; rlb2++) {     //rlb2=right left border 2
        screen[rlb2 * 80] = p + 186;
        screen[rlb2 * 80 + 79] = p + 186;
    }
    /////
    for (int ib1 = 19; ib1 < 24; ib1++) {        //ib1=inner border 1
        screen[ib1 * 80 + 58] = p + 186;
        screen[ib1 * 80 + 20] = p + 186;
    }
    screen[0] = p + 201;
    screen[79] = p + 187;

    screen[18 * 80] = p + 204;
    screen[18 * 80 + 79] = p + 185;

    screen[24 * 80] = p + 200;
    screen[24 * 80 + 79] = p + 188;

    screen[18 * 80 + 20] = p + 203;
    screen[18 * 80 + 58] = p + 203;

    screen[24 * 80 + 20] = p + 202;
    screen[24 * 80 + 58] = p + 202;

    screen[19 * 80 + 2] = 1 * 16 * 256;
    screen[19 * 80 + 3] = 1 * 16 * 256;
    screen[19 * 80 + 5] = p + 256 + '1';

    screen[21 * 80 + 2] = 2 * 16 * 256;
    screen[21 * 80 + 3] = 2 * 16 * 256;
    screen[21 * 80 + 5] = p + 2 * 256 + '2';

    screen[23 * 80 + 2] = 3 * 16 * 256;
    screen[23 * 80 + 3] = 3 * 16 * 256;
    screen[23 * 80 + 5] = p + 3 * 256 + '3';

    screen[19 * 80 + 8] = 4 * 16 * 256;
    screen[19 * 80 + 9] = 4 * 16 * 256;
    screen[19 * 80 + 11] = p + 4 * 256 + '4';

    screen[21 * 80 + 8] = 5 * 16 * 256;
    screen[21 * 80 + 9] = 5 * 16 * 256;
    screen[21 * 80 + 11] = p + 5 * 256 + '5';

    screen[23 * 80 + 8] = 6 * 16 * 256;
    screen[23 * 80 + 9] = 6 * 16 * 256;
    screen[23 * 80 + 11] = p + 6 * 256 + '6';

    screen[19 * 80 + 14] = 0 * 16 * 256;
    screen[19 * 80 + 15] = 0 * 16 * 256;
    screen[19 * 80 + 17] = p + 0 * 256 + '0';

    screen[21 * 80 + 14] = p + 176;
    screen[21 * 80 + 15] = p + 176;
    screen[21 * 80 + 17] = p + 0 * 256 + 'e';
    screen[19 * 80 + 60] = p + 8 * 256 + 'S';
    screen[19 * 80 + 61] = p + 8 * 256 + 'e';
    screen[19 * 80 + 62] = p + 8 * 256 + 'l';
    screen[19 * 80 + 63] = p + 8 * 256 + 'e';
    screen[19 * 80 + 64] = p + 8 * 256 + 'c';
    screen[19 * 80 + 65] = p + 8 * 256 + 't';
    screen[19 * 80 + 66] = p + 8 * 256 + 'e';
    screen[19 * 80 + 67] = p + 8 * 256 + 'd';
    screen[19 * 80 + 68] = p + ' ';
    screen[19 * 80 + 69] = p + 8 * 256 + 'C';
    screen[19 * 80 + 70] = p + 8 * 256 + 'o';
    screen[19 * 80 + 71] = p + 8 * 256 + 'l';
    screen[19 * 80 + 72] = p + 8 * 256 + 'o';
    screen[19 * 80 + 73] = p + 8 * 256 + 'r';
    screen[19 * 80 + 74] = p + ' ';
    screen[19 * 80 + 75] = p + 8 * 256 + '=';
    screen[19 * 80 + 76] = p + ' ';

    screen[21 * 80 + 60] = p + 8 * 256 + 'A';
    screen[21 * 80 + 61] = p + 8 * 256 + 'c';
    screen[21 * 80 + 62] = p + 8 * 256 + 't';
    screen[21 * 80 + 63] = p + 8 * 256 + 'i';
    screen[21 * 80 + 64] = p + 8 * 256 + 'v';
    screen[21 * 80 + 65] = p + 8 * 256 + 'e';
    screen[21 * 80 + 66] = p + ' ';
    screen[21 * 80 + 67] = p + 8 * 256 + 'C';
    screen[21 * 80 + 68] = p + 8 * 256 + 'o';
    screen[21 * 80 + 69] = p + 8 * 256 + 'l';
    screen[21 * 80 + 70] = p + 8 * 256 + 'o';
    screen[21 * 80 + 71] = p + 8 * 256 + 'r';
    screen[21 * 80 + 72] = p + 8 * 256 + ' ';
    screen[21 * 80 + 73] = p + 8 * 256 + '=';
    screen[21 * 80 + 74] = p + ' ';

    screen[21 * 80 + 22] = p + 8 * 256 + 'D';
    screen[21 * 80 + 23] = p + 8 * 256 + 'e';
    screen[21 * 80 + 24] = p + 8 * 256 + 'l';
    screen[21 * 80 + 25] = p + 8 * 256 + 'e';
    screen[21 * 80 + 26] = p + 8 * 256 + 't';
    screen[21 * 80 + 27] = p + 8 * 256 + 'e';
    screen[21 * 80 + 28] = p + ' ';
    screen[21 * 80 + 29] = p + 8 * 256 + '=';
    screen[21 * 80 + 30] = p + ' ';
    screen[21 * 80 + 31] = p + 8 * 256 + 'C';
    screen[21 * 80 + 32] = p + 8 * 256 + 'l';
    screen[21 * 80 + 33] = p + 8 * 256 + 'e';
    screen[21 * 80 + 34] = p + 8 * 256 + 'a';
    screen[21 * 80 + 35] = p + 8 * 256 + 'r';

    screen[19 * 80 + 22] = p + 8 * 256 + 'T';
    screen[19 * 80 + 23] = p + 8 * 256 + 'a';
    screen[19 * 80 + 24] = p + 8 * 256 + 'b';
    screen[19 * 80 + 25] = p + ' ';
    screen[19 * 80 + 26] = p + 8 * 256 + '=';
    screen[19 * 80 + 27] = p + ' ';
    screen[19 * 80 + 28] = p + 8 * 256 + 'A';
    screen[19 * 80 + 29] = p + 8 * 256 + 'c';
    screen[19 * 80 + 30] = p + 8 * 256 + 't';
    screen[19 * 80 + 31] = p + 8 * 256 + 'i';
    screen[19 * 80 + 32] = p + 8 * 256 + 'v';
    screen[19 * 80 + 33] = p + 8 * 256 + 'e';
    screen[19 * 80 + 34] = p + ' ';
    screen[19 * 80 + 35] = p + 8 * 256 + 'C';
    screen[19 * 80 + 36] = p + 8 * 256 + 'o';
    screen[19 * 80 + 37] = p + 8 * 256 + 'l';
    screen[19 * 80 + 38] = p + 8 * 256 + 'o';
    screen[19 * 80 + 39] = p + 8 * 256 + 'r';

    screen[23 * 80 + 22] = p + 8 * 256 + '\'';
    screen[23 * 80 + 23] = p + 8 * 256 + 'f';
    screen[23 * 80 + 24] = p + 8 * 256 + '\'';
    screen[23 * 80 + 25] = p + ' ';
    screen[23 * 80 + 26] = p + 8 * 256 + '=';
    screen[23 * 80 + 27] = p + ' ';
    screen[23 * 80 + 28] = p + 8 * 256 + 'F';
    screen[23 * 80 + 29] = p + 8 * 256 + 'i';
    screen[23 * 80 + 30] = p + 8 * 256 + 'l';
    screen[23 * 80 + 31] = p + 8 * 256 + 'l';

    screen[23 * 80 + 60] = p + 8 * 256 + 'e';
    screen[23 * 80 + 61] = p + 8 * 256 + 's';
    screen[23 * 80 + 62] = p + 8 * 256 + 'c';
    screen[23 * 80 + 63] = p + ' ';
    screen[23 * 80 + 64] = p + 8 * 256 + '=';
    screen[23 * 80 + 65] = p + ' ';
    screen[23 * 80 + 66] = p + 4 * 256 + 'e';
    screen[23 * 80 + 67] = p + 4 * 256 + 'x';
    screen[23 * 80 + 68] = p + 4 * 256 + 'i';
    screen[23 * 80 + 69] = p + 4 * 256 + 't';

    screen[19 * 80 + 48] = p + 8 * 256 + 'S';
    screen[19 * 80 + 49] = p + 8 * 256 + 'a';
    screen[19 * 80 + 50] = p + 8 * 256 + 'v';
    screen[19 * 80 + 51] = p + 8 * 256 + 'e';
    screen[19 * 80 + 52] = p + 8 * 256 + ' ';
    screen[19 * 80 + 53] = p + 8 * 256 + '=';
    screen[19 * 80 + 54] = p + 8 * 256 + ' ';
    screen[19 * 80 + 55] = p + 8 * 256 + '\'';
    screen[19 * 80 + 56] = p + 8 * 256 + 's';
    screen[19 * 80 + 57] = p + 8 * 256 + '\'';

    screen[21 * 80 + 48] = p + 8 * 256 + 'L';
    screen[21 * 80 + 49] = p + 8 * 256 + 'o';
    screen[21 * 80 + 50] = p + 8 * 256 + 'a';
    screen[21 * 80 + 51] = p + 8 * 256 + 'd';
    screen[21 * 80 + 52] = p + 8 * 256 + ' ';
    screen[21 * 80 + 53] = p + 8 * 256 + '=';
    screen[21 * 80 + 54] = p + 8 * 256 + ' ';
    screen[21 * 80 + 55] = p + 8 * 256 + '\'';
    screen[21 * 80 + 56] = p + 8 * 256 + 'l';
    screen[21 * 80 + 57] = p + 8 * 256 + '\'';
    screen[21 * 80 + 76] = 7 * 16 * 256 + (4 + 128) * 256 + 'o';
    screen[21 * 80 + 77] = 7 * 16 * 256 + (4 + 128) * 256 + 'f';
    screen[21 * 80 + 78] = 7 * 16 * 256 + (4 + 128) * 256 + 'f';

    screen[x * 80 + y] = 7 * 16 * 256 + '*';
}

//***************************************************************************
void docommand(int t, char c) {
    if (flag == 0) {
        screen[(x * 80) + y] = p;
    } else {
        screen[x * 80 + y] = color * 256;
    }
    if (t == 1) {
        switch (c) {
            case 'P':
                if (x < 17)
                    x++;
                break;

            case 'H':
                if (x > 1)
                    x--;
                break;

            case 'M':
                if (y < 78)
                    y++;
                break;

            case 'K':
                if (y > 1)
                    y--;
                break;
        }

    } else {
        switch (c) {
            case '0':
                color = 0;
                break;

            case '1':
                color = 1 * 16;
                break;

            case '2':
                color = 2 * 16;
                break;

            case '3':
                color = 3 * 16;
                break;

            case '4':
                color = 4 * 16;
                break;

            case '5':
                color = 5 * 16;
                break;

            case '6':
                color = 6 * 16;
                break;

            case 'e':
                color = 7 * 16;     //e=erase clear
                break;

            case 9 :
                flag = !flag;    //9=tab
                if (flag == 0) {
                    screen[21 * 80 + 76] = 7 * 16 * 256 + (4 + 128) * 256 + 'o';
                    screen[21 * 80 + 77] = 7 * 16 * 256 + (4 + 128) * 256 + 'f';
                    screen[21 * 80 + 78] = 7 * 16 * 256 + (4 + 128) * 256 + 'f';
                } else {
                    screen[21 * 80 + 76] = 7 * 16 * 256 + (2 + 128) * 256 + 'o';
                    screen[21 * 80 + 77] = 7 * 16 * 256 + (2 + 128) * 256 + 'n';
                    screen[21 * 80 + 78] = 7 * 16 * 256;
                }
                break;

            case 8 : {
                for (int i = 1; i < 18; i++) {
                    for (int j = 1; j < 79; j++) {
                        screen[i * 80 + j] = 7 * 16 * 256;
                    }
                }
            }
                break;

            case 'f':
                if (p != color * 256) {
                    fill(x, y, color, p);
                    p = color * 256;
                }
                break;

            case 's':
                int a[2000];
                for (int fi = 0; fi < 18 * 80; fi++) {
                    a[fi] = screen[fi];
                }
                FILE *file1;
                file1 = fopen("paint.txt", "w");
                for (int fi1 = 0; fi1 < 18 * 80; fi1++) {
                    fprintf(file1, "%d ", a[fi1]);
                }
                fclose(file1);
                break;

            case 'l':
                FILE *file2;
                file2 = fopen("paint.txt", "r");
                for (int fi2 = 0; fi2 < 18 * 80; fi2++) {
                    fscanf(file2, "%d", a[fi2]);
                }
                for (int fi3 = 0; fi3 < 18 * 80; fi3++) {
                    screen[fi3] = a[fi3];
                }

                fclose(file2);
        }
        screen[19 * 80 + 77] = (color) * 256;//selected color
        screen[19 * 80 + 78] = (color) * 256;//selected color
    }
    p = screen[(x * 80) + y];
    if (color == 0) {
        screen[x * 80 + y] = color * 256 + 7 * 256 + '*';
    } else {
        screen[(x * 80) + y] = color * 256 + '*';
    }
}

//***************************************************************************
int funckey(char &c) {
    int t = 0;
    c = getch();
    if (c == 0) {
        t = 1;
        c = getch();
    }
    return t;
}

//**************************************************************************
void fill(int x, int y, int c, int tp) {
    if (screen[x * 80 + y] == p) {
    }
    screen[x * 80 + y] = c * 256;
    if (y > 1 && screen[x * 80 + y - 1] == p) {
        fill(x, y - 1, c, p);
    }
    if (x > 1 && screen[(x - 1) * 80 + y] == p) {
        fill(x - 1, y, c, p);
    }
    if (x < 18 && screen[(x + 1) * 80 + y] == p) {
        fill(x + 1, y, c, p);
    }
    if (y < 79 && screen[x * 80 + y + 1] == p) {
        fill(x, y + 1, c, p);
    }
}

//***************************************************************************
void main() {
    init();
    int t = funckey(c);
    while (c != 27 || (c == 27 && t != 0)) {
        docommand(t, c);
        t = funckey(c);
    }
}
