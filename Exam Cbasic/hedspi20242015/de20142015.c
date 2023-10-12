#include<stdio.h>
#include<string.h>

#define db double

#define forr(i,a,b) for(int i=a; i<=b; i++)

typedef struct{
    int id;
    char name[35];
    db insPoint;
    db ansPoint;
    db lastPoint[5];
    db ck, gk;
} Infor;

Infor sv[25];
int yeucau, allsv;

void Menu();
void Add();
// void List();
// void Sorted();
int checkPoint(double i)
{
    if(i > 10 || i< 0) 
        return 0;
    return 1;
}

int main()
{
    
    allsv = 0;
    Menu();
    return 0;
}

void Menu()
{
    printf("\tMenu\n\n");
    printf("1\\Bo sung sinh vien\n2\\Danh sach sinh vien bao ve thanh cong\n3\\Sap xep theo ten sinh vien\n4\\Thoat chuong trinh\n");
    scanf("%d",&yeucau);
    if(yeucau == 1)
        Add();
    // else if(yeucau == 2)
    //     List();
    // else if(yeucau == 3)
    //     Sorted();
    return ;
}

void Add(){
    int n;
    do
    {
        printf("Nhap so sinh vien them vao: ");
        scanf("%d", &n);
        printf("\n");
    }
    while(allsv + n > 20);
    forr(i, 1, n)
    {
        int check = 0;
        int cur = i + allsv;
        do{
            printf("Nhap MSSV: ");
            scanf("%d", &sv[cur].id);
            check = 1;
            forr(j, 1, cur -1)
            {
                if(sv[j].id == sv[cur].id)
                    check = 0;
            }
        }
        while(check == 0);

        do{
            printf("Nhap Ho va ten sinh vien: ");
            scanf("%*c%[^\n]%*c", sv[cur].name);
            printf("%s\n", sv[cur].name);
            check = 1;
            if(strlen(sv[i].name) > 30) check = 1 ;
            if(sv[i].name[strlen(sv[i].name)-1] == ' ') 
                check = 0 ;
        }
        while(check == 0);

        do{
            printf("Nhap diem huong' dan~: ");
            scanf("%lf", &sv[cur].insPoint);
        }
        while(checkPoint(sv[cur].insPoint) == 0);

        do{
            printf("Nhap diem phan bien: ");
            scanf("%lf", &sv[cur].ansPoint);
        }
        while(checkPoint(sv[cur].ansPoint) == 0);
        forr(j,1,3)
        {
            do{
                printf("Nhap diem hoi dong %d: ", j);
                scanf("%lf", &sv[cur].lastPoint[j]);
            }
            while(checkPoint(sv[cur].lastPoint[j]) == 0);
            sv[cur].ck += sv[cur].lastPoint[j];
        }
        sv[cur].gk = (sv[cur].insPoint + sv[cur].ansPoint) / 2;
        sv[cur].ck /= 3;
    }
    allsv += n;
    printf("MSSV\tHo va ten\tHD\tPB\tHD1\tHD2\tHD3\tGiuaKy\tCuoiky\n");
    forr(i, 1, allsv)
    {
        printf("%d\t%s\t\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",sv[i].id, sv[i].name, sv[i].insPoint, sv[i].ansPoint, sv[i].lastPoint[1],sv[i].lastPoint[2], sv[i].lastPoint[3], sv[i].gk, sv[i].ck);
    }
    printf("\n");
    Menu();
    return;
}

void List()
{
    forr(i, 1, allsv)
    {
        if()
        printf("%d\t%s\t\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",sv[i].id, sv[i].name, sv[i].insPoint, sv[i].ansPoint, sv[i].lastPoint[1],sv[i].lastPoint[2], sv[i].lastPoint[3], sv[i].gk, sv[i].ck);
    }
    printf("\n");   
}