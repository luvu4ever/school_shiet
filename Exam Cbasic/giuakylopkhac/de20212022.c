#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUBJECT_MAX 32
#define ROOM_MAX 12
#define SLOT_MAX 12
#define CLASS_MAX 202

void Menu();
void AddClass();
void PrintClass();
void SearchClass();
void SortClass();
 void CheckSameClass();

struct _Class{
    int id;
    char subject[SUBJECT_MAX];
    char room[ROOM_MAX];
    int day;
    char slot[SLOT_MAX];
    int start, end;
};

int totalClass = 0;
struct _Class class[CLASS_MAX];

int main()
{
    
    Menu();
    return 0;
}

void Menu()
{
    int order;
    printf("-----------MENU-----------\n");
    printf("Nhap yeu cau nguoi dung:");
    scanf("%d", &order);
    if(order == 1)
    {
        AddClass();
        Menu();
        return;
    }
    if(order == 2)
    {
        PrintClass();
        Menu();
        return;
    }
    if(order == 3)
    {
        SearchClass();
        Menu();
        return;
    }
    if(order == 4)
    {
        SortClass();
        Menu();
        return;
    }
    if(order == 5)
    {
        CheckSameClass();
        Menu();
        return;
    }
}

void AddClass()
{
    int n;
    printf("---BO SUNG LOP HOC-----------\n");
    do{
        printf("Nhap vao so lop hoc muon them vao: ");
        scanf("%d", &n);
    }
    while (n<1 || totalClass + n > 200);
    for(int i=1; i<=n; i++)
    {
        int cur = i + totalClass;
        
        printf("Nhap ma lop hoc: ");
        scanf("%d", &class[cur].id);

        printf("Nhap ten hoc phan: ");
        getchar();
        fgets(class[cur].subject, SUBJECT_MAX, stdin);
        class[cur].subject[strlen(class[cur].subject)-1] = '\0'; 
        //printf("%s\n", class[cur].subject);  

        printf("Nhap phong hoc: ");
        //getchar();
        fgets(class[cur].room, ROOM_MAX, stdin);
        class[cur].room[strlen(class[cur].room)-1] = '\0';
        //printf("%s\n", class[cur].room);

        do{
            printf("Nhap ngay hoc trong tuan: ");
            scanf("%d", &class[cur].day);
        }
        while(class[cur].day < 2 || class[cur].day > 7);
        getchar();
        char stringStart[3], stringEnd[3];
        do{
            printf("Nhap cac tiet lop hoc duoc su dung: ");
            class[cur].slot[0]= '\0';
            stringStart[0]= '\0';
            stringEnd[0]= '\0';
            fgets(class[cur]. slot, SLOT_MAX, stdin);
            class[cur].slot[strlen(class[cur].slot)-1] = '\0';
            printf("%s\n", class[cur].slot);
            for(int j = 0; j < strlen(class[cur].slot); j++)
            {
                if(class[cur].slot[j] != '-') stringStart[j] = class[cur].slot[j];
                else 
                {
                    stringStart[j] = '\0';
                    break;
                }
            }
            class[cur].start = atoi(stringStart);

            for(int j = strlen(stringStart); j <= strlen(class[cur].slot); j++) 
            {
                if(class[cur].slot[j] != '\0') 
                    stringEnd[j - strlen(stringStart)] = class[cur].slot[j];
                else 
                {
                    stringEnd[j - strlen(stringStart)] = '\0';
                    break;
                }
            }
            class[cur].end = atoi(stringEnd) * -1;
            //printf("%s %s\n", stringStart, stringEnd); 
        }
        while(class[cur].start >= class[cur].end || class[cur].start < 1 || class[cur].start > 12 || class[cur].end < 1 || class[cur].end > 12);    
    }
    totalClass += n;
}

void PrintClass()
{
    printf("-------------In thong tin cac lop hoc---------------\n");
    printf("Ma lop\tTen mon hoc\t\t\tTen phong\tThu\tTiet hoc\n");
    for(int i=1; i<= totalClass; i++)
    {
        printf("%d\t%-32s%-16s%d\t%-16s\n", class[i].id, class[i].subject, class[i].room, class[i].day, class[i].slot);
    }
}


void SearchClass()
{
    char tenphong[ROOM_MAX];
    int dem = 0;
    printf("\nNhap ten phong can tim kiem:");
    getchar();
    fgets(tenphong, ROOM_MAX, stdin);
    tenphong[strlen(tenphong) - 1] = '\0';
    for(int i=1; i<= totalClass; i++)
    {
        if(!strcmp(tenphong, class[i].room))
            dem++;
    }
    if(dem == 0)
        printf("Khong ton tai phong %s trong danh sach", tenphong);
    else
    {
        printf("So lop hoc: %d\nThong tin lop hoc:\n", dem);
        printf("Ma lop\tTen mon hoc\t\t\tTen phong\tThu\tTiet hoc\n");
        for(int i=1; i<= totalClass; i++)
        {
            if(!strcmp(tenphong, class[i].room))
                printf("%d\t%-32s%-16s%d\t%-16s\n", class[i].id, class[i].subject, class[i].room, class[i].day, class[i].slot);
        }
    }
}

void SwapClass(struct _Class *a, struct _Class *b)
{
    struct _Class temp = *a;
    *a = *b;
    *b = temp; 
}

void SortClass()
{
    for(int i=1; i<=totalClass; i++)
    {
        for(int j=i+1; j<=totalClass; j++)
        {
            if(class[i].id > class[j].id)
                SwapClass(&class[i], &class[j]);
        }
    }
    printf("Ma lop\tTen mon hoc\t\t\tTen phong\tThu\tTiet hoc\n");
    for(int i=1; i<= totalClass; i++)
    {
        printf("%d\t%-32s%-16s%d\t%-16s\n", class[i].id, class[i].subject, class[i].room, class[i].day, class[i].slot);
    }
}

void CheckSameClass()
{
    printf("Danh sach cac lop bi trung la: ");
    for(int i=1; i<= totalClass; i++)
    {
        for(int j=i+1; j<= totalClass; j++)
        {
            if(class[i].day != class[j].day) continue;
            if(strcmp(class[j].room, class[i].room)) continue;
            if(class[i].start > class[j].start && class[i].start < class[j].end)
                printf("\n%d", class[i].id);
            if(class[j].start > class[i].start && class[j].start < class[i].end)
                printf("\n%d", class[i].id);
        }
    }
    printf("\n");
}