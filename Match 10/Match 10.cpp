#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int disp[9][9];
int i, j, k, l, c = 0, rr = 3, s = 0;
int score1 = 0, score2 = 0;
int fourplus = 0;
int row1 = 0, row2 = 1, row3 = 2, row4 = 3, row5 = 4, row6 = 5, row7 = 6, row8 = 7, row9 = 8;
void randomFun();
void print_array();
void getpair();
int isempty();
int check(int, int, int, int, int);
void scorebord();
int main()
{
    randomFun();
    int a = 0;
    while (a < 7)
    {
        print_array();
        if (s % 2 == 0)
            cout << "\n<----First Player turn---->" << endl;
        else if (s % 2 != 0)
            cout << "\n<----Second Player turn---->" << endl;
        getpair();
        if (check(i, j, k, l, c) > 0)
        {
            disp[i - 1][j - 1] = 0;
            disp[k - 1][l - 1] = 0;
        }
        scorebord();
        if (isempty() == 0)
        {
            rr++;
        }
        s++;
    }
    return 0;
}
void getpair()
{
    cout << "\nEnter the row and column of first number you want to pair \n";
    cin >> i >> j;
    cout << "\nEnter the row and column of second number you want to pair \n";
    cin >> k >> l;
}
void randomFun()
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            int num = (rand() % (9 - 1 + 1)) + 1;
            disp[i][j] = num;
        }
    }
}
void print_array()
{
    int i, j;
    for (i = 0; i < rr; i++) {
        for (j = 0; j < 9; j++) {
            if (disp[i][j] != 0) {
                cout << "| " << disp[i][j];
            }
            else {
                cout << "|  ";
            }
        }
        cout << endl;
    }
}

int isempty()//for adding row
{
    int rott = 0;
    for (int ro1 = 0; ro1 < rr; ro1++)
    {
        for (int co1 = 0; co1 < 9; co1++)
        {
            if (ro1 < rr - 1)
            {
                if (disp[ro1][co1] != 0) {
                    if (disp[ro1][co1] == disp[ro1][co1 + 1] || disp[ro1][co1] == disp[ro1 + 1][co1] || disp[ro1][co1] == disp[ro1 + 1][co1 + 1] || disp[ro1][co1] + disp[ro1][co1 + 1] == 10 || disp[ro1][co1] + disp[ro1 + 1][co1] == 10 || disp[ro1][co1] + disp[ro1 + 1][co1 + 1] == 10)
                    {
                        rott++;
                    }
                }
            }
            else
            {
                if (disp[ro1][co1] != 0) {
                    if (disp[ro1][co1] == disp[ro1][co1 + 1] || disp[ro1][co1] + disp[ro1][co1 + 1] == 10)
                    {
                        rott++;
                    }
                }
            }

        }

    }
    return rott;
}
int check(int i, int j, int k, int l, int c)
{
    int co;
    if (i + j == k + l - 1 || k + l == i + j - 1 || j == 9 && l == 1)
    {
        if (disp[i - 1][j - 1] == disp[k - 1][l - 1] || disp[i - 1][j - 1] + disp[k - 1][l - 1] == 10)
        {
            c++;
        }
    }
    if (disp[i - 1][j - 1] == disp[k - 1][l - 1] || disp[i - 1][j - 1] + disp[k - 1][l - 1] == 10)
    {
        for (int lol = j; lol < (l - 1); lol++)
        {
            if (disp[i - 1][lol] != 0)
            {
                co++;
            }
        }
        if (co == 0)
        {
            c++;
            fourplus++;
        }
    }
    if (disp[i - 1][j - 1] == disp[k - 1][l - 1] || disp[i - 1][j - 1] + disp[k - 1][l - 1] == 10)
    {
        if (i + j == k + l - 2 || k + l == i + j + 2) {
            if (disp[k - 2][l - 1] == 0 && disp[i][j - 1] == 0)
            {
                c++;
                fourplus++;
            }
        }
    }
    return c;
}
void scorebord()
{
    int counter = 0, counter1 = 0, counter2 = 0;
    if (fourplus > 0)
    {
        if (i + j == k + l - 2) {
            if (s % 2 == 0) {
                score1 += 4;
            }
            else if (s % 2 != 0) {
                score2 += 4;
            }
        }
    }
    if (isempty() == 0)
    {
        if (s % 2 == 0) {
            score1 += 150;
        }
        else if (s % 2 != 0) {
            score2 += 150;
        }
    }
    if (j == 9 && l == 1) {
        if (disp[i - 1][j - 1] == disp[k - 1][l - 1] || disp[i - 1][j - 1] + disp[k - 1][l - 1] == 10) {
            if (s % 2 == 0) {
                score1 += 2;
            }
            else if (s % 2 != 0) {
                score2 += 2;
            }
        }
    }
    if (i + j == k + l - 1 || k + l == i + j - 1) {
        if (disp[i - 1][j - 1] == disp[k - 1][l - 1] || disp[i - 1][j - 1] + disp[k - 1][l - 1] == 10) {
            if (s % 2 == 0) {
                score1 += 1;
            }
            else if (s % 2 != 0) {
                score2 += 1;
            }
        }
    }

    for (int col = 0; col < 9; col++)
    {
        if (disp[row1][col] != 0)
        {
            counter++;
        }
    }
    if (counter == 0)
    {
        if (s % 2 == 0) {
            score1 += 10;
        }
        else if (s % 2 != 0) {
            score2 += 10;
        }
        row1 = 90;
    }

    for (int col = 0; col < 9; col++)
    {
        if (disp[row2][col] != 0)
        {
            counter1++;
        }
    }
    if (counter1 == 0)
    {
        if (s % 2 == 0) {
            score1 += 10;
        }
        else if (s % 2 != 0) {
            score2 += 10;
        }
        row2 = 90;
    }

    for (int col = 0; col < 9; col++)
    {
        if (disp[row3][col] != 0)
        {
            counter2++;
        }
    }
    if (counter2 == 0)
    {
        if (s % 2 == 0) {
            score1 += 10;
        }
        else if (s % 2 != 0) {
            score2 += 10;
        }
        row3 = 90;
    }
    for (int col = 0; col < 9; col++)
    {
        if (disp[row4][col] != 0)
        {
            counter2++;
        }
    }
    if (counter2 == 0)
    {
        if (s % 2 == 0) {
            score1 += 10;
        }
        else if (s % 2 != 0) {
            score2 += 10;
        }
        row4 = 90;
    }
    for (int col = 0; col < 9; col++)
    {
        if (disp[row5][col] != 0)
        {
            counter2++;
        }
    }
    if (counter2 == 0)
    {
        if (s % 2 == 0) {
            score1 += 10;
        }
        else if (s % 2 != 0) {
            score2 += 10;
        }
        row5 = 90;
    }
    for (int col = 0; col < 9; col++)
    {
        if (disp[row6][col] != 0)
        {
            counter2++;
        }
    }
    if (counter2 == 0)
    {
        if (s % 2 == 0) {
            score1 += 10;
        }
        else if (s % 2 != 0) {
            score2 += 10;
        }
        row6 = 90;
    }
    for (int col = 0; col < 9; col++)
    {
        if (disp[row7][col] != 0)
        {
            counter2++;
        }
    }
    if (counter2 == 0)
    {
        if (s % 2 == 0) {
            score1 += 10;
        }
        else if (s % 2 != 0) {
            score2 += 10;
        }
        row7 = 90;
    }
    for (int col = 0; col < 9; col++)
    {
        if (disp[row8][col] != 0)
        {
            counter2++;
        }
    }
    if (counter2 == 0)
    {
        if (s % 2 == 0) {
            score1 += 10;
        }
        else if (s % 2 != 0) {
            score2 += 10;
        }
        row8 = 90;
    }
    for (int col = 0; col < 9; col++)
    {
        if (disp[row9][col] != 0)
        {
            counter2++;
        }
    }
    if (counter2 == 0)
    {
        if (s % 2 == 0) {
            score1 += 10;
        }
        else if (s % 2 != 0) {
            score2 += 10;
        }
        row9 = 90;
    }

    cout << "\n                    SCOREBOARD" << endl;
    cout << "First Player Points : " << score1 << "     Second Player Points : " << score2 << endl;
    cout << endl;
}
