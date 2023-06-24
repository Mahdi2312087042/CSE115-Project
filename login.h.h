
#include<stdio.h>
#include<string.h>

 void get_login_info(void);

void login(void);
struct login
{
    char username[50];
    char password[50];

};
 void get_login_info(void)
{
    FILE *log;
    log  = fopen("login1.txt", "w");
    struct login l;

    printf("Create username: ");
    scanf("%s", l.username);
    printf("Create password: ");
    scanf("%s", l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);
    system("cls");

}



void login(void)
{
    char username[50];
    char password[50];


    FILE *log;
    log = fopen("login1.txt", "r");
    struct login l;

    printf("LOGIN TO PORTAL BY ENTERING USERNAME AND PASSWORD\n");


    while(fread(&l,sizeof(l),1,log))
    {
       while(1)

     {
           printf("\n");
           printf("Enter Username: ");
           scanf("%s", &username);
           printf("Enter Password: ");
           scanf("%s", &password);


        if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)
        {
            printf("Login Successful!!\n\n");
            break;

        }
        else
        {
             printf("\n");
             printf("Wrong username or password entered!!\n");
             printf("Try again!!\n\n");
        }
     }
    }
    fclose(log);
    sleep(2);
    system("cls");

}
