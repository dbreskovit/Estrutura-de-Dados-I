#include <stdio.h>
#include <windows.h>

typedef struct class
{
    char name[50];
    int year;
} class;

typedef struct student
{
    char name[50];
    int registration;
    class group;
} student;

void getStudent(student *s)
{
    printf("Nome: ");
    scanf(" %49[^\n]", s->name);
    printf("Matrícula: ");
    scanf("%d", &s->registration);
    printf("Turma: ");
    scanf(" %49[^\n]", s->group.name);
    printf("Ano: ");
    scanf("%d", &s->group.year);
    printf("\n");
}

void printStudentPointer(student *s)
{
    printf("Via ponteiro:\n");
    printf("Nome: %s\n", s->name);
    printf("Matrícula: %d\n", s->registration);
    printf("Turma: %s\n", s->group.name);
    printf("Ano: %d\n", s->group.year);
    printf("\n");
}

void printStudent(student s)
{
    printf("Via struct:\n");
    printf("Nome: %s\n", s.name);
    printf("Matrícula: %d\n", s.registration);
    printf("Turma: %s\n", s.group.name);
    printf("Ano: %d\n", s.group.year);
    printf("\n");
}

int main()
{
    // Configura o terminal para aceitar acentos (No Windows)
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    student s;
    student *p = &s;

    getStudent(p);

    printStudent(s);
    printStudentPointer(p);

    SetConsoleOutputCP(CPAGE_DEFAULT);

    return 1;
}