#include <stdio.h>
#include <string.h>

void gameUI(char mat[][3]);
int foundWinner(char mat[][3]);
int choicePos(int a);
void winPlayer(char a);

int main()
{
    char mat[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int choice, row, col, pos, arr[9];
    gameUI(mat);
    for (int i = 0; i < 9; i++)
    {
    restart:
        if (i % 2 == 0)
            printf("Player-1 enter position: ");
        else
            printf("Player-2 enter position: ");

        scanf("%d", &choice);
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == choice)
            {
                printf("This position is taken.\n\n");
                goto restart;
            }
        }
        arr[i] = choice;
        pos = choicePos(choice);
        col = pos % 10;
        row = pos / 10;

        if (i % 2 == 0)
            mat[row - 1][col - 1] = 'x';
        else
            mat[row - 1][col - 1] = '0';

        gameUI(mat);
        if (i >= 4)
        {
            int chk = 0;
            chk = foundWinner(mat);
            if (chk == 1)
                break;
            else if (i == 8)
                printf("Match tie...\n\n");
        }
    }
}

void gameUI(char mat[][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", mat[i][j]);
            if (j < 2)
                printf(" | ");
        }
        if (i < 2)
            printf("\n---------\n");
    }
    printf("\n\n");
}

int foundWinner(char mat[][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (mat[i][0] == mat[i][1])
        {
            if (mat[i][0] == mat[i][2])
            {
                winPlayer(mat[i][0]);
                return 1;
                break;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (mat[0][i] == mat[1][i])
        {
            if (mat[0][i] == mat[2][i])
            {
                winPlayer(mat[0][i]);
                return 1;
                break;
            }
        }
    }

    if (mat[0][0] == mat[1][1])
    {
        if (mat[0][0] == mat[2][2])
        {
            winPlayer(mat[0][0]);
            return 1;
        }
    }

    if (mat[0][2] == mat[1][1])
    {
        if (mat[0][2] == mat[2][0])
        {
            winPlayer(mat[0][2]);
            return 1;
        }
    }
}

void winPlayer(char a)
{
    if (a == 'x')
        printf("Player-1 Wins..\n\n");
    else
        printf("Player-2 Wins..\n\n");
}

int choicePos(int a)
{

    switch (a)
    {
    case 1:
        return 11;
        break;
    case 2:
        return 12;
        break;
    case 3:
        return 13;
        break;
    case 4:
        return 21;
        break;
    case 5:
        return 22;
        break;
    case 6:
        return 23;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 32;
        break;
    case 9:
        return 33;
        break;

    default:
        break;
    }
}