#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "splashscreen.h"
#include "menu.h"
#include "login.h.h"

//void intro();
//void head();
//void time();

int main(void) {/*

    system("cls");
    intro();
    time();
    printf("\n\n\n\t\t\tPress any key to continue....!!");
    getch();
    system("cls");
    head();
    char id[6], pass[8];
    printf("\n\n\t\t\t\tusername => ");
    fflush(stdin);
    scanf("%s", id);
    printf("\n\t\t\t\tpassword => ");
    fflush(stdin);
    scanf("%s", pass);
    printf("\n\n\t");
    time();
    printf("\t");
    if (strcmp(id, "admin") == 0 && strcmp(pass, "****") == 0)
        printf("\n\n\t\t\t  !!!Login Successfull!!!");
    else {
        printf("\n\n\t\t\t!!!INVALID CREDENTIALS!!!");
        getch();
        exit(0);
    }
    printf("\n\n\n\t\t\tPress any key to continue....!!");
    getch();*/
    intro();
    get_login_info();
    login();
    main_menu();
    return 0;
}
