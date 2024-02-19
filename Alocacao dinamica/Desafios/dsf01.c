#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Teclas de movimento
#define UP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'

// Variavel de vitoria
bool win = false;

// Layout do labirinto
char layout[5][5] = {
    {'#', '#', '#', 'E', '#'},
    {'#', 'P', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#'}};

// Protótipos
void FindPlayer(char **labirinto, int row, int col, int *dX, int *dY);
bool Collision(char **labirinto, int row, int col, int dX, int dY);
void Move(char **labirinto, int row, int col, int *dX, int *dY);
void AlocateLabirinto(char **labirinto, int row, int col);
void World(char **labirinto, int row, int col);
void Victory(void);

int main(void)
{
    int row = 5, col = 5;
    int dX = 0, dY = 0;

    char **labirinto;
    labirinto = (char **)malloc(row * sizeof(char *));

    AlocateLabirinto(labirinto, row, col);
    FindPlayer(labirinto, row, col, &dX, &dY);
    World(labirinto, row, col);

    while (true)
    {
        Move(labirinto, row, col, &dX, &dY);
        if (win) Victory();
    }

    return 1;
}

void World(char **labirinto, int row, int col)
{
    int i = 0;
    int j = 0;

    system("clear");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%c ", labirinto[i][j]);
        printf("\n");
    }
}

void Move(char **labirinto, int row, int col, int *dX, int *dY)
{
    char key = 0;

    printf("WASD: ");
    scanf(" %c", &key);

    switch (key)
    {
    case UP:
        if (!Collision(labirinto, row, col, *dX - 1, *dY))
        {
            labirinto[*dX][*dY] = ' ';
            *dX -= 1;
            labirinto[*dX][*dY] = 'P';
        }
        break;
    case LEFT:
        if (!Collision(labirinto, row, col, *dX, *dY - 1))
        {
            labirinto[*dX][*dY] = ' ';
            *dY -= 1;
            labirinto[*dX][*dY] = 'P';
        }
        break;
    case RIGHT:
        if (!Collision(labirinto, row, col, *dX, *dY + 1))
        {
            labirinto[*dX][*dY] = ' ';
            *dY += 1;
            labirinto[*dX][*dY] = 'P';
        }
        break;
    case DOWN:
        if (!Collision(labirinto, row, col, *dX + 1, *dY))
        {
            labirinto[*dX][*dY] = ' ';
            *dX += 1;
            labirinto[*dX][*dY] = 'P';
        }
        break;
    default:
        break;
    }

    World(labirinto, row, col);
}

bool Collision(char **labirinto, int row, int col, int dX, int dY)
{
    if (dX < 0 || dX >= row)
        return true;
    if (dY < 0 || dY >= col)
        return true;
    if (labirinto[dX][dY] == '#')
        return true;
    if (labirinto[dX][dY] == 'E')
    {
        win = true;
        return false;
    }

    return false;
}

void FindPlayer(char **labirinto, int row, int col, int *dX, int *dY)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (labirinto[i][j] == 'P')
            {
                *dX = i;
                *dY = j;
            }
}

void AlocateLabirinto(char **labirinto, int row, int col)
{
    for (int i = 0; i < row; i++)
        labirinto[i] = (char *)malloc(col * sizeof(char));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            labirinto[i][j] = layout[i][j];
}

void Victory(void)
{
    printf("Parabens, voce venceu!\n");
    system("pause");
    exit(0);
}