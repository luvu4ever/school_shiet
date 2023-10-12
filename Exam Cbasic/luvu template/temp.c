//------LuvU------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctime.h>

#define MAX 1000
#define forr(i, a, b) for(int i = a; i <= b; i++)

typedef struct{

} ;

    int n;


void Menu();
void printfMenu();
// void Task1();
// void Task2();
// void Task3();
// void Task4();
// void Task5();
void Clear(){
    while(getchar() != '\n');
}

int main(){
    Menu();
    return 0;
}

void printMenu(){
    printf("\n\t\tMENU\n");
    printf("1. \n");
    printf("2. \n");
    printf("3. \n");
    printf("4. \n");
    printf("5. \n");
    printf("\n");
}

void Menu()
{
    int choice;
    printMenu();
    scanf("%d", &choice);
    switch(choice){
        case 1: Task1(); break;
        case 2: Task2(); break;
        case 3: Task3(); break;
        case 4: Task4(); break;
        case 5: return;
        default: printf("Vui long nhap tu 1 den 5.\n");
    }
    Menu();
    return;
}

void Task1(){
    return;
}

void Task2(){
    return;
}

void Task3(){
    return;
}