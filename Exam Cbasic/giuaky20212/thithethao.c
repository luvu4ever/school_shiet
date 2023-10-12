//LuvU4ever

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#define

struct athlete{
    char name[50];
    char nation[50];
    int dky[3];
    short pass[3];
    int final;
    char medal;
};

int n;
struct athlete vdv[105];

void Menu();
void Input();
void Process();
void Sort();
void Update();
void Clear()
{
    while(getchar() != '\n');
}

void main()
{
    Menu();
    return;
}


void Menu()
{
    int choice;
    printf("----------Menu ----------\n\n");
    printf("\n1.\tNhap\n2.\tTinh diem\n3.\tSap xep theo diem\n4.\tCap nhat lai thanh tich\n5.\tThoat\n");
    printf("Nhap lua chon cua ban");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: Input(); break;
        case 2: Process(); break;
        case 3: Sort(); break;
        case 4: Update(); break;
        case 5: return;
        default: printf("Vui long nhap tu 1 den 5.\n");
    }
    Menu();
    return;
}

void Input()
{
    int invalid;
    do{
        printf("Nhap so van dong vien: "); scanf("%d", &n);
        invalid = (n<3 || n>100);
        if (invalid)
            printf("Gia tri cua n khong hop ly\n");
    } while (invalid);
    printf("%d", n);
    for(int i=1; i<=n; i++)
    {
        scanf("%s %s", vdv[i].name, vdv[i].nation);
        for(int j = 0; j<3; j++)
            scanf("%d", &vdv[i].dky[j]);
        for(int j = 0; j<3; j++)
            scanf("%d", &vdv[i].pass[j]);
    }
    printf("\n\nName\t\t\tNation\t\t\tR1\tR2\tR3\tP1\tP2\tP3\n");
    for(int i=1; i<=n; i++)
    {
        printf("%-32s%-32s%d\t%d\t%d\t%d\t%d\t%d\n", vdv[i].name, vdv[i].nation, vdv[i].dky[0], vdv[i].dky[1],vdv[i].dky[2], vdv[i].pass[0], vdv[i].pass[1], vdv[i].pass[2]);
    }
    return;
}

void Process()
{
    for(int i=1; i<=n; i++)
    {
        vdv[i].final = 0;
        for(int j=0; j<3; j++)
        {
            if(vdv[i].pass[j] && vdv[i].final < vdv[i].dky[j])
                vdv[i].final = vdv[i]. dky[j];
        }
    }
    printf("\n\nName\t\t\tNation\t\t\tR1\tR2\tR3\tP1\tP2\tP3\tFinal\n");
    for(int i=1; i<=n; i++)
    {
        printf("%-32s%-32s%d\t%d\t%d\t%d\t%d\t%d\t%d\n", vdv[i].name, vdv[i].nation, vdv[i].dky[0], vdv[i].dky[1],vdv[i].dky[2], vdv[i].pass[0], vdv[i].pass[1], vdv[i].pass[2], vdv[i]. final);
    }
}

void Sort()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(vdv[i].final < vdv[j]. final)
            {
                struct athlete Temp = vdv[i];
                vdv[i] = vdv[j];
                vdv[j] = Temp;
                //Swap
            }
        }
    }
    vdv[1].medal = 'G';
    vdv[2].medal = 'S';
    vdv[3].medal = 'B';
    for(int i=4; i<=n; i++)
    {
        vdv[i].medal = 'N';
    }
    printf("\n\nName\t\t\tNation\t\t\tR1\tR2\tR3\tP1\tP2\tP3\tFinal\tMedal\n");
    for(int i=1; i<=n; i++)
    {
        printf("%-32s%-32s%d\t%d\t%d\t%d\t%d\t%d\t%d\t%-c\n", vdv[i].name, vdv[i].nation, vdv[i].dky[0], vdv[i].dky[1],vdv[i].dky[2], vdv[i].pass[0], vdv[i].pass[1], vdv[i].pass[2], vdv[i]. final, vdv[i].medal);
    }
    return;
}

void Update()
{
    int error;
    printf("Nhap so lan pham loi: ");
    scanf("%d",&error);
    for(int i = 1; i<= error; i++)
    {
        char errname[100];
        int errnum;
        scanf("%s %d", errname, &errnum);
        for(int j=1; j<=n; j++)
        {
            if(strcmp(errname, vdv[j].name) == 0)
                vdv[j].pass[errnum-1] = 0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        vdv[i].final = 0;
        for(int j=0; j<3; j++)
        {
            if(vdv[i].pass[j] && vdv[i].final < vdv[i].dky[j])
                vdv[i].final = vdv[i]. dky[j];
        }
    }
    Sort();
    return;
}