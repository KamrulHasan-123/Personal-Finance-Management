#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#include "creatAccount.h"
#include "login.h"
#include "mainMenu.h"
#include "viewAccount.h"
#include "changeAccount.h"
#include "delete.h"
#include "addData.h"
#include "deleteAccount.h"
#include "update.h"
#include "changeMonth.h"
#include "allMonth.h"
#include "Search.h"

char fname[10],month[10];
long save=0;

void main()
{
    printf("\t\t---------------------------\n");
    printf("\t\tPersonal Finance Management\n");
    printf("\t\t---------------------------\n");
    login_menu();
}
