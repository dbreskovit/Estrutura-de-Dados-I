#include <stdio.h>
#include <string.h>
#include <windows.h>

void cls()
{
    system("cls");
}

typedef struct player
{
    char position[50];
    char name[50];
    int age;
    int number;
} player;

typedef struct team
{
    player starting[6];
    player reserve[4];
} team;

void getPlayer(player *p)
{
    printf("Nome: ");
    scanf(" %49[^\n]", p->name);
    printf("Idade: ");
    scanf("%d", &p->age);
    printf("Posição: ");
    scanf(" %49[^\n]", p->position);
    printf("Número da Camisa: ");
    scanf("%d", &p->number);
    printf("\n");
}

void getTeam(team *t)
{
    cls();

    for (int i = 0; i < 6; i++)
    {
        printf("Digite os dados do jogador titular %d\n", i + 1);
        getPlayer(&t->starting[i]);
    }
    cls();
    for (int i = 0; i < 4; i++)
    {
        printf("Digite os dados do jogador reserva %d\n", i + 1);
        getPlayer(&t->reserve[i]);
    }
    cls();
}

void printPlayer(player *p)
{
    printf("Nome: %s\n", p->name);
    printf("Idade: %d\n", p->age);
    printf("Posição: %s\n", p->position);
    printf("Número da camisa: %d\n", p->number);
    printf("\n");
}

void printTeam(team *t)
{
    printf("--------------------\n");
    printf("Titulares:\n");
    printf("--------------------\n");
    for (int i = 0; i < 6; i++)
    {
        printPlayer(&t->starting[i]);
    }
    printf("--------------------\n");
    printf("Reservas:\n");
    printf("--------------------\n");
    for (int i = 0; i < 4; i++)
    {
        printPlayer(&t->reserve[i]);
    }
}

int main(void)
{
    // Configura o terminal para aceitar acentos (No Windows)
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    team t;
    getTeam(&t);
    printTeam(&t);

    SetConsoleOutputCP(CPAGE_DEFAULT);

    return 1;
}
