//------LuvU------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<math.h>

#define MAX 105
#define NAMEMAX 25
#define forr(i, a, b) for(int i = a; i <= b; i++)

typedef struct{
    char name[NAMEMAX];
    double l,w,h;
    double weight;
    double afterweight;
    int type;
    int typeoferror;
    int cost;
} delivery;

    int n;
    delivery a[MAX];

void Menu();
void printfMenu();
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Task6();
double OwnRoundUp(double a){
    int b = a/1;
    if(a-b < 0.5)
        return (b*1.0 + 0.5);
    return (b*1.0 + 1.0);
}

void PrintMoney(int num)
{
    char money[10];
    strncpy(money,"",strlen(money));
    itoa(num, money, 10);
    for(int i=0; i< strlen(money); i++){
        if(strlen(money) % 3 == i % 3 && i!=0)
            printf(",");
        printf("%c", money[i]);
    }
    printf("\n");
}

void Clear(){
    while(getchar() != '\n');
}

int main(){
    //PrintMoney(100);
    Menu();
    return 0;
}

void printMenu(){
    printf("\n\t\tMENU\n");
    printf("1. Nhap thong tin kien hang\n");
    printf("2. Chi tiet kien hang bi tu choi\n");
    printf("3. Chiet tiet kien hang hop le\n");
    printf("4. Tinh phi van chuyen\n");
    printf("5. Thoat\n");
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
        case 3: Task5(); break;
        case 4: Task6(); break;
        case 5: return;
        default: printf("Vui long nhap tu 1 den 5.\n");
    }
    Menu();
    return;
}

void Task1(){
    do{
        printf("Nhap so kien hang yeu cau nhap vao: ");
        scanf("%d", &n);
    } while(n<1 || n>100);
    int check = 1;
    for(int i=1; i<=n; i++){
        do{
            check = 0;
            printf("Nhap ma kien hang %d: ", i);
            strncpy(a[i].name,"",strlen(a[i].name));
            scanf("%s", a[i]. name);
            for(int j=0; j< strlen(a[i].name); j++){
                if(isdigit(a[i].name[j]) == 0 && isalpha(a[i].name[j]) == 0)
                    check =1;
            }
            if(strlen(a[i].name) < 8 || strlen(a[i].name) >20) check =1;
        }while(check == 1);
        printf("Nhap 3 chieu cua kien hang cach nhau boi dau cach: ");
        scanf("%lf %lf %lf", &a[i].l, &a[i].w, &a[i].h);
        printf("Nhap trong luong tinh cua kien hang: ");
        scanf("%lf", &a[i].weight);
        a[i].weight = OwnRoundUp(a[i].weight);
        printf("Nhap loai van chuyen cua kien hang: ");
        scanf("%d", &a[i].type);
        a[i].typeoferror = 0;
        if(a[i].l<10 || a[i].h<10 || a[i].w<10)
            a[i].typeoferror = 1;
        if(a[i].l > 150 || a[i].h > 150 || a[i].w > 150)
            a[i].typeoferror = 2;
        if(a[i].weight > 30)
            a[i].typeoferror = 3;
    }
    return;
}

void Task2(){
    int dem = 0;
    printf("Chi tiet kien hang bi tu choi\n==================\n");
    printf("%-20s%-40s\n","Ma kien", "Ly do bi tu choi");
    for(int i=1; i<=n; i++)
    {
        if(a[i]. typeoferror == 0) continue;
        printf("%-20s%-2s%d\n", a[i].name, "ER", a[i].typeoferror);
        dem++;
    }
    printf("Tong so: %d", dem);
    return;
}

void Task3(){
    for(int i=1; i<=n;  i++){
        if(a[i].typeoferror != 0) continue;
        if(a[i].l + a[i].w + a[i].h < 80){
            a[i].afterweight = a[i].weight;
            continue;
        }
        if(a[i].type == 1){
            a[i].afterweight = a[i].l * a[i].w * a[i].h / 6000;
            a[i].afterweight = OwnRoundUp(a[i].afterweight);
            continue;
        }
        a[i].afterweight = a[i].l * a[i].w * a[i].h /4000;
        a[i].afterweight = OwnRoundUp(a[i].afterweight);
    }
    return;
}

void Task4(){
    Task3();
    for(int i=1; i<=n; i++){
        if(a[i].typeoferror != 0) continue;
        if(a[i].type == 1){
            if(a[i].afterweight <= 3) a[i].cost = 16500;
            else
                a[i].cost = 16500 + ((a[i].afterweight-3.0)/0.5) * 2500;
        }
        else
            if(a[i].afterweight <= 3) a[i].cost = 22000;
            else
                a[i].cost = 22000 + ((a[i].afterweight-3.0)/0.5) * 2500;
    }
}

void Task5(){
    Task4();
    int validcount = 0;
    printf("Chi tiet kien hang hop le\n====================\n");
    printf("%-20s%-20s%-40s%-20s\n", "Ma kien", "Can tang tinh phi", "Hinh thuc van chuyen", "Cuoc phi");
    for(int i=1; i<=n; i++){
        if(a[i].typeoferror != 0) continue;
        printf("%-20s%-20.2lf", a[i].name, a[i]. afterweight);
        if(a[i]. type ==1)
            {printf("%-40s", "Chuyen nhanh");
            PrintMoney(a[i].cost);}
        else
            {printf("%-40s", "Chuyen thuong");
            PrintMoney(a[i].cost);}
        validcount++;
    }
    printf("Tong so: %d", validcount);
}

void Task6(){
    Task4();
    int sumcost = 0;
    int validcount = 0;
    printf("Chi phi van chuyen\n====================\n");
    for(int i=1; i<=n; i++){
        if(a[i].typeoferror != 0) continue;
        sumcost += a[i].cost;
        validcount++;
    }
    printf("So luong kien da nha: %d\n", validcount);
    printf("Tong tien cuoc:");
    PrintMoney(sumcost);
    printf("VAT: ");
    PrintMoney(sumcost * 8 / 100);
    printf("Tong chi phi: ");
    PrintMoney(sumcost * 108 / 100);
    return;
}