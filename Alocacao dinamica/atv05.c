#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int registration;
    char name[50];
    int birthYear;
} Student;

int main(void)
{
    Student *students = NULL;
    int size = 0;
    int i = 0;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    students = (Student *)malloc(size * sizeof(Student));

    if (students == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }

    for (i = 0; i < size; i++)
    {
        printf("Enter the registration of student %d: ", i + 1);
        scanf("%d", &students[i].registration);

        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the birth year of student %d: ", i + 1);
        scanf("%d", &students[i].birthYear);
    }

    printf("\n");
    printf("Students:\n");
    for (i = 0; i < size; i++)
    {
        printf("Registration: %d\n", students[i].registration);
        printf("Name: %s\n", students[i].name);
        printf("Birth year: %d\n", students[i].birthYear);
        printf("\n");
    }

    free(students);
    students = NULL;

    return 1;
}