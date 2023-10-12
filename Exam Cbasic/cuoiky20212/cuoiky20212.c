//------LuvU------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX 1000
#define forr(i, a, b) for(int i = a; i <= b; i++)

typedef struct{
    char name[5];
    double dientich;
    int dieuhoa;
} Room;

    int totalroom;
    Room a[MAX];
    int airtype[5];

void Menu();
void printfMenu();
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Clear(){
    while(getchar() != '\n');
}

int main(){
    Menu();
    return 0;
}

void printMenu(){
    printf("\n\n\t\tMENU\n");
    printf("1. Nhap thong tin phong to\n");
    printf("2. In thong tin cac nha hang\n");
    printf("3. Tim kiem theo dien tich\n");
    printf("4. Sap xep\n");
    printf("5. Thong ke so luong dieu hoa can bo sung\n");
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
        case 5: Task5(); break;
        case 6: return;
        default: printf("Vui long nhap tu 1 den 6.\n");
    }
    Menu();
    return;
}

void Task1(){
    int n;
    int check =1;
    do{
        printf("Nhap vao so phong muon nhap them: ");
        scanf("%d", &n);
    } while(n<0);
    for(int i=1; i<=n; i++){
        int cur = totalroom + i;
        do{
            check = 1;
            printf("Nhap ten phong tro: ");
            strncpy(a[cur].name,"",strlen(a[cur].name));
            scanf("%s", a[cur].name);
            if(strlen(a[cur].name) != 4) check = 0;
            for(int j=0; j< 4; j++)
                if(isalpha(a[cur].name[j]) == 0) check=0;
            Clear();
        } while(check == 0);

        do{
            printf("Nhap dien tich phong: ");
            scanf("%lf", &a[cur].dientich);
        } while (a[cur].dientich < 10 || a[cur].dientich > 40);

        do{
            printf("Nhap trang thai dieu hoa, 0 la chua lap, 1 la da lap: ");
            scanf("%d", &a[cur].dieuhoa);
        } while(a[cur].dieuhoa != 1 && a[cur].dieuhoa != 0);
        printf("\n--------------\n");
    }
    totalroom += n;
    return;
}

void Task2(){
    printf("%-20s%-20s%-20s\n", "Ten phong", "Dien tich", "Dieu hoa");
    for(int i=1; i<= totalroom; i++){
        printf("%-20s%-20lf%-20d\n", a[i].name, a[i].dientich, a[i].dieuhoa);
    }
    printf("%-20s%-20s%-20s\n", "------", "------", "------");
    return;
}

void Task3(){
    double area;
    int dem = 0;
    printf("Nhap dien tich phong ban muon tim: ");
    scanf("%lf", &area);
    for(int i=1; i<= totalroom; i++){
        if(abs(a[i].dientich-area) <= 5)
            dem++;
    }
    if(dem == 0) 
    {
        printf("Khong tim duoc phong hop le.\n");
        return;
    }
    printf("Co %d phong hop le.\n", dem );
    printf("%-20s%-20s%-20s\n", "Ten phong", "Dien tich", "Dieu hoa");
    for(int i=1; i<= totalroom; i++){
        if(abs(a[i].dientich-area) <= 5)
            printf("%-20s%-20lf%-20d\n", a[i].name, a[i].dientich, a[i].dieuhoa);
    }
    printf("%-20s%-20s%-20s\n", "------", "------", "------");
    return;
}

void Task4(){
    for(int i=1; i<= totalroom; i++){
        for(int j=i+1; j<= totalroom; j++){
            if(a[i].dientich < a[j].dientich)
            {
                Room temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    Task2();
    return;
}

void Task5(){
    for(int i=1; i<= 5; i++)
        airtype[i] = 0;
    for(int i=1; i<= totalroom; i++)
    {
        if(a[i].dieuhoa == 1) continue;
        if(a[i].dientich < 15) airtype[1]++;
        else{
            if(a[i].dientich < 22) airtype[2]++;
            else{
                if(a[i].dientich < 30) airtype[3]++;
                else
                    airtype[4]++;
            }
        }
    }
    printf("Luong dieu hoa can lap them la: \n");
    printf("%dBTU: %d chiec\n", 9000, airtype[1]);
    printf("%dBTU: %d chiec\n", 12000, airtype[2]);
    printf("%dBTU: %d chiec\n", 18000, airtype[3]);
    printf("%dBTU: %d chiec\n", 21000, airtype[4]);
    return;
}