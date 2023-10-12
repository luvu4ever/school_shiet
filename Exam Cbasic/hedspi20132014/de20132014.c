#include<stdio.h>
#include<string.h>

typedef struct{
    char name[25];
    int old;
    int score[6];
} Game;

Game person[25];
char str[50], dapan[50], kytu[3], traloi[50];
int yeucau,n,diem[5];

void Khoitao()
{
    printf("Yeu cau nhap xau:\n");
    while (getchar()!='\n');
        scanf("%s", str);
    while (strlen(str) < 20 || strlen(str) > 40)
    {
        printf("Yeu cau nhap lai xau:\n");
        while (getchar()!='\n');
            scanf("%s", str);
    }
    printf("Yeu cau nhap so nguoi choi:\n");
    scanf("%d", &n);
    while (n>4)
    {
        printf("Yeu cau nhap lai so nguoi choi:\n");
        scanf("%d", &n);
    }
    for(int i = 1; i <= n; i++)
    {
        printf("Ten nguoi choi %d:\n",i);
        scanf("%s", person[i].name);
        printf("Tuoi nguoi choi %d:\n",i);
        scanf("%d", &person[i].old);
    }
    printf("Ho va ten\tTuoi\n");
    for(int i=1; i<=n; i++)
    {
        printf("%s\t\t%d\n", person[i].name, person[i].old);
    }

}

void Doan()
{
    printf("%s\n", dapan);
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<strlen(str); j++)
        {
            dapan[j] = '*';
        }
        printf("%s:\n", person[i].name);
        for(int j=1; j<=4; j++)
        {
            printf("Lan doan %d:",j);
            scanf("%s", kytu);
            for(int q=0; q < strlen(dapan); q++)
            {
                if(str[q] == kytu[0] && str[q] && dapan[q] == '*')
                {
                    dapan[q] = kytu[0];
                    person[i].score[j]++;
                }
            }
            person[i].score[5] += person[i].score[j];
            printf("\n%s\n", dapan);
        }
        printf("Nhap dap an cua nguoi choi:\n");
        scanf("%s", traloi);
        int check = 0;
        for(int i=0; i < strlen(dapan); i++)
        {
            if(str[i] != traloi[i])
                check = 1;
        }
        if(check == 0)
        {
            person[i].score[5] += 20;
            printf("Xau dap an dung\n");
        }
        else
            printf("Xau dap an sai\n");
    }
    printf("Ho ten\tL1\tL2\tL3\tL4\tKetqua\n");
    for(int i=1; i<=n; i++)
    {
        printf("%s", person[i].name);
        for(int j=1; j<=5; j++)
        {
            printf("\t%d",person[i].score[j]);
        }
        diem[i] = person[i].score[5];
        printf("\n");
    }
}

void Tonghopketqua()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(diem[i] < diem[j])
            {
                int temp = diem[i];
                diem[i] = diem[j];
                diem[j] = temp;
            }
        }
    }
    printf("Ho va ten\tDiem\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(person[j].score[5] == diem[i])
                printf("%s\t%d\n", person[j].name, person[j].score[5]);
        }
    }
}


void Menu()
{
    printf("\tMenu\n\n");
    printf("1. Khoi tao chuong trinh\n2. Doan ky tu\n3. Tong hop ket qua\n4. Ket thuc chuong trinh\n");
    scanf("%d", &yeucau);
    if(yeucau == 1)
    {
        Khoitao();
        Menu();
    }
    if(yeucau == 2)
    {
        Doan();
        Menu();
    }
    if(yeucau == 3)
    {
        Tonghopketqua();
        Menu();
    }
}

int main()
{
    Menu();
    return 0;
}