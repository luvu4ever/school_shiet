#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAME_MAX 35
#define ROOM_MAX 12

typedef struct _Class{
    int id, day;
    char subject[NAME_MAX];
    char room[ROOM_MAX];
    char slots[ROOM_MAX];
    int start, end;
} Classroom;

Classroom class[205];
int totalclass = 0;

void AddRoom();
void InformRoom();
void SearchRoom();
void SortRoom();
void SameRoom();
void Menu();


int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int yeucau = 0;
    printf("\tMenu\n\n");
    printf("1. Bo sung lop hoc\n2. In thong tin lop hoc\n3. Tim kiem theo phong\n4. Sap xep\n5. Kiem tra trung phong\n6. Thoat chuong trinh\n\n");
    scanf("%d", &yeucau);
    if(yeucau == 1)
    {
        AddRoom();
        Menu();
    }
    if(yeucau == 2)
    {
        InformRoom();
        Menu();
    }
    if(yeucau == 3)
    {
        SearchRoom();
        Menu();
    }
    if(yeucau == 4)
    {
        Menu();
    }
    if(yeucau == 5)
    {
        SameRoom();
        Menu();
    }
}

void AddRoom()
{
    int n;
    int i, j;
    do
    {
        printf("Nhap so lop hoc nhap them vao: ");
        scanf("%d", &n);
        printf("\n");
    }
    while(totalclass + n > 200 || n<1);

    for(i=1; i<=n; i++)
    {
        int cur = totalclass + i;
        char strstart[ROOM_MAX], strend[ROOM_MAX];
        printf("Nhap ma lop:");
        scanf("%d", &class[cur].id);
        printf("Nhap ten hoc phan:");
        getchar();
        fgets(class[cur].subject, NAME_MAX, stdin);
        class[cur].subject[strlen(class[cur].subject)-1] = '\0';
        printf("Nhap ten lop hoc:");
        fgets(class[cur].room, ROOM_MAX, stdin);
        class[cur].room[strlen(class[cur].room)-1] = '\0';
        do{
            printf("Nhap ngay hoc: ");
            scanf("%d", &class[cur].day);
        }
        while(class[cur].day < 2 || class[cur].day > 7);
        do{
            printf("Nhap khoang tiet hoc: ");
            getchar();
            fgets(class[cur]. slots, ROOM_MAX, stdin);
            class[cur].slots[strlen(class[cur].slots)-1] = '\0';
            for(j=0; j<strlen(class[cur].slots)-1; j++)
            {
                if(class[cur].slots[j] != '-') strstart[j] = class[cur].slots[j];
                    else strstart[j] = '\0';
            }
            class[cur].start = atoi(strstart);
            for(j= strlen(strstart); j< strlen(class[cur].slots); j++)
            {
                if(class[cur].slots[j] != '\0') strend[j-strlen(strstart)] = class[cur].slots[j];
                    else strend[j-strlen(strstart)] = '\0';
            }
            class[cur].end = atoi(strend) * -1;
            //printf("%d%d", class[cur].start, class[cur].end);
        }
        while(class[cur].start < 0 ||class[cur].end < 0 || class[cur].end > 12 || class[cur].start > class[cur].end);
        printf("\n\n");
    }
    totalclass += n;
}

void InformRoom()
{
    int i;
    printf("Ma lop\tTen mon hoc\t\t\tTen phong\tThu\tTiet hoc\n");
    for(i=1; i<= totalclass; i++)
    {
        printf("%d\t%-32s%-10s\t%d\t%-10s\n", class[i].id, class[i].subject, class[i].room, class[i].day, class[i].slots);
    }
}

void SearchRoom()
{
    char tenphong[ROOM_MAX];
    int dem = 0, i, j;
    printf("\nYeu cau nhap ten phong can tim kiem:");
    getchar();
    fgets(tenphong, ROOM_MAX, stdin);
    tenphong[strlen(tenphong)-1] = '\0';
    for(i=1; i<=totalclass; i++)
    {
        int check = 1;
        if(strlen(tenphong) != strlen(class[i].room))
            check = 0;
        for(j=0; j< strlen(tenphong)-1; j++)
        {
            if(tenphong[j] != class[i].room[j])
                check = 0;
        }
        if(check ==1)
            dem++;
    }
    printf("So lop hoc: %d\nThong tin lop hoc:\n", dem);
    printf("Ma lop\tTen mon hoc\t\t\tTen phong\t\tThu\tTiet hoc\n");
    for(i=1; i<= totalclass; i++)
    {
        int check = 1;
        if(strlen(tenphong) != strlen(class[i].room))
            check = 0;
        for(j=0; j< strlen(tenphong)-1; j++)
        {
            if(tenphong[j] != class[i].room[j])
                check = 0;
        }
        if(check == 1)
            printf("%d\t%-32s%-10s\t%d\t%-10s\n", class[i].id, class[i].subject, class[i].room, class[i].day, class[i].slots);
    }
}


void SameRoom()
{
    int i, j, x;
    printf("Danh sach cac lop bi trung la: ");
    for(i=1; i<= totalclass; i++)
    {
        for(j=i+1; j<= totalclass; j++)
        {
            int check =1;
            if(class[i].day != class[j].day) check = 0;
            if(strlen(class[i].room) != strlen(class[j].room))
                check = 0;
            for(x=0; x< strlen(class[i].room)-1; x++)
            {
                if(class[i].room[x] != class[j].room[x])
                    check = 0;
            }
            if(check ==0) continue;
            if(class[i].start > class[j].start && class[i].start < class[j].end)
                printf("\n%d", class[i].id);
            if(class[j].start > class[i].start && class[j].start < class[i].end)
                printf("\n%d", class[i].id);
        }
    }
    printf("\n");
}