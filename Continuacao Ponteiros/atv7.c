#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "lib.h"

typedef struct Time
{
    int hour;
    int minute;
} Time;

typedef struct Car
{
    char plate[50];
    char model[50];
} Car;

typedef struct Parking
{
    Car car;
    Time entry;
    Time exit;
    float price;
} Parking;

void printCar(Car *car)
{
    printf("Plate: %s\n", car->plate);
    printf("Model: %s\n", car->model);
}

void printTime(Time *time)
{
    printf("%02d:%02d\n", time->hour, time->minute);
}

int readTime(Time *time)
{
    int hour, minute;
    printf("Enter the hour: ");
    hour = readInt();
    printf("Enter the minutes: ");
    minute = readInt();
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
    {
        printf("Invalid time!\n");
        return 0;
    }
    time->hour = hour;
    time->minute = minute;
    return 1;
}

int readCar(Car *car)
{
    printf("Enter the plate: ");
    scanf(" %49[^\n]", car->plate);
    printf("Enter the model: ");
    scanf(" %49[^\n]", car->model);

    return 1;
}

int readParking(Parking *parking)
{
    if (!readCar(&parking->car))
    {
        printf("Error reading car!\n");
        return 0;
    }

    if (!readTime(&parking->entry))
    {
        printf("Error reading entry time!\n");
        return 0;
    }

    if (!readTime(&parking->exit))
    {
        printf("Error reading exit time!\n");
        return 0;
    }

    return 1;
}

void calculatePrice(Parking *parking)
{
    int entry = parking->entry.hour * 60 + parking->entry.minute;
    int exit = parking->exit.hour * 60 + parking->exit.minute;
    int time = exit - entry;

    if (time <= 60)
        parking->price = 5;
    else
        parking->price = 5 + ((time - 60) / 60) * 2;
}

void printParking(Parking *parking)
{
    printf("Car:\n");
    printCar(&parking->car);
    printf("Entry time: ");
    printTime(&parking->entry);
    printf("Exit time: ");
    printTime(&parking->exit);
    calculatePrice(parking);
    printf("Price: R$ %.2f\n", parking->price);
}

int main()
{

    // Configura o terminal para aceitar acentos (No Windows)
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    Parking parking;
    readParking(&parking);
    printParking(&parking);

    SetConsoleOutputCP(CPAGE_DEFAULT);

    return 1;
}