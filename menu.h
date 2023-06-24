#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct hotel
{
    int room_no;
    char name[30];
    char address[50];
    char phone[15];
    int days;
    float fare;
};

void main_menu();
void add();
void display();
void rooms();
void edit();
int check(int);
void modify(int);
void delete_rec(int);

void head()
{
    printf("|||||||||||||||||||||||||||||||||||||||||||");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("t\t\t\t\t\t\t\t\t       ");
    printf("t\t\t\t  MAHDI'S HOTEL\t\t\t       ");
    printf("t\t\t\t\t\t\t\t\t       ");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("|||||||||||||||||||||||||||||||||||||||||");
}

void time()
{
    int i = 0;
    long long j;
    printf("	\n\n\n	Connecting to Server\n 	Syncing DaTa");
    while (i < 10)
    {
        for (j = 5; j > 4; j++)
        {
            if (j == 99999)
            {
                printf(".");
                break;
            }
        }
        ++i;
    }
}

void main_menu()
{
    int choice;
    while (choice != 5)
    {
        system("cls");
        head();
        printf("\n\t\t\t\t*************");
        printf("\n\t\t\t\t* MAIN MENU *");
        printf("\n\t\t\t\t*************");
        printf("\n\n\n\t\t\t1.Book A Room");
        printf("\n\t\t\t2.Customer Record");
        printf("\n\t\t\t3.Rooms Allotted");
        printf("\n\t\t\t4.Edit Record");
        printf("\n\t\t\t5.Exit");
        printf("\n\n\t\t\tEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            rooms();
            break;
        case 4:
            edit();
            break;
        case 5:
            break;
        default:
            printf("\n\n\t\t\tWrong choice.....!!!");
            printf("\n\t\t\tPress any key to continue....!!");
            getch();
        }
    }
}

void add()
{
    system("cls");
    head();
    int r, flag;
    FILE *fout = fopen("Record.dat", "ab");
    printf("\n Enter Customer Details");
    printf("\n ----------------------");
    printf("\n\n Room no: ");
    scanf("%d", &r);
    flag = check(r);
    if (flag)
        printf("\n Sorry..!!!Room is already booked");
    else
    {
        struct hotel h;
        h.room_no = r;
        printf(" Name: ");
        fflush(stdin);
        gets(h.name);
        printf(" Address: ");
        fflush(stdin);
        gets(h.address);
        printf(" Phone No: ");
        fflush(stdin);
        gets(h.phone);
        printf(" No of Days to Checkout: ");
        scanf("%d", &h.days);
        h.fare = h.days * 900; // 900 is currently set as the default price per day
        fwrite(&h, sizeof(struct hotel), 1, fout);
        printf("\n Room is booked...!!!");
    }

    printf("\n Press any key to continue.....!!");
    getch();
    fclose(fout);
}

void display()
{
    system("cls");
    head();
    FILE *fin = fopen("Record.dat", "rb");
    int r, flag;
    printf("\n Enter room no: ");
    scanf("%d", &r);
    struct hotel h;
    while (fread(&h, sizeof(struct hotel), 1, fin))
    {
        if (h.room_no == r)
        {
            system("cls");
            head();
            printf("\n Customer Details");
            printf("\n ----------------");
            printf("\n\n Room no: %d", h.room_no);
            printf("\n Name: %s", h.name);
            printf("\n Address: %s", h.address);
            printf("\n Phone no: %s", h.phone);
            printf("\n Days: %d", h.days);
            printf("\n Total Fare: %.2f", h.fare);
            system("C:\\Users\\user\\Downloads\\room.jpg");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("\n Sorry Room no. not found or vacant....!!");
    printf("\n\n Press any key to continue....!!");
    getch();
    fclose(fin);
}

void rooms()
{
    system("cls");
    head();
    FILE *fin = fopen("Record.dat", "rb");
    printf("\n\t\t\t    List Of Rooms Allotted");
    printf("\n\t\t\t    ----------------------");
    struct hotel h;
    while (fread(&h, sizeof(struct hotel), 1, fin))
    {
        printf("\n Room no: %d\n Name: %s\n Address: %s\n Phone: %s\n Days: %d\n Total: %.2f",
               h.room_no, h.name, h.address, h.phone, h.days, h.fare);
        printf("\n**********************************");
    }
    printf("\n\n\n\t\t\tPress any key to continue.....!!");
    getch();
    fclose(fin);
}

void edit()
{
    system("cls");
    head();
    int choice, r;
    printf("\n EDIT MENU");
    printf("\n ---------");
    printf("\n\n 1.Modify Customer Record");
    printf("\n 2.Delete Customer Record");
    printf("\n Enter your choice: ");
    scanf("%d", &choice);

    system("cls");
    head();
    printf("\n Enter room no: ");
    scanf("%d", &r);
    switch (choice)
    {
    case 1:
        modify(r);
        break;
    case 2:
        delete_rec(r);
        break;
    default:
        printf("\n Wrong Choice.....!!");
    }
    printf("\n Press any key to continue....!!!");
    getch();
}

int check(int r)
{
    int flag = 0;
    FILE *fin = fopen("Record.dat", "rb");
    struct hotel h;
    while (fread(&h, sizeof(struct hotel), 1, fin))
    {
        if (h.room_no == r)
        {
            flag = 1;
            break;
        }
    }
    fclose(fin);
    return (flag);
}

void modify(int r)
{
    system("cls");
    head();
    long pos;
    int flag = 0;
    FILE *file = fopen("Record.dat", "r+b");
    struct hotel h;
    while (fread(&h, sizeof(struct hotel), 1, file))
    {
        pos = ftell(file);
        if (h.room_no == r)
        {
            printf("\n Enter New Details");
            printf("\n -----------------");
            printf("\n Name: ");
            fflush(stdin);
            gets(h.name);
            printf(" Address: ");
            fflush(stdin);
            gets(h.address);
            printf(" Phone no: ");
            fflush(stdin);
            gets(h.phone);
            printf(" Days: ");
            scanf("%d", &h.days);
            h.fare = h.days * 900;
            fseek(file, pos - sizeof(struct hotel), SEEK_SET);
            fwrite(&h, sizeof(struct hotel), 1, file);
            printf("\n Record is modified....!!");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("\n Sorry Room no. not found or vacant...!!");
    fclose(file);
}

void delete_rec(int r)
{
    system("cls");
    head();
    int flag = 0;
    char ch;
    FILE *fin = fopen("Record.dat", "rb");
    FILE *fout = fopen("temp.dat", "wb");
    struct hotel h;
    while (fread(&h, sizeof(struct hotel), 1, fin))
    {
        if (h.room_no == r)
        {
            printf("\n Name: %s", h.name);
            printf("\n Address: %s", h.address);
            printf("\n Phone No: %s", h.phone);
            printf("\n Days: %d", h.days);
            printf("\n Total Fare: %.2f", h.fare);
            printf("\n\n Do you want to delete this record(y/n): ");
            fflush(stdin);
            scanf("%c", &ch);
            if (ch == 'n')
                fwrite(&h, sizeof(struct hotel), 1, fout);
            flag = 1;
            break;
        }
        else
            fwrite(&h, sizeof(struct hotel), 1, fout);
    }
    fclose(fin);
    fclose(fout);
    if (flag == 0)
        printf("\n Sorry room no. not found or vacant...!!");
    else
    {
        remove("Record.dat");
        rename("temp.dat", "Record.dat");
    }
}
