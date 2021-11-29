void view_account();
void select_month(char filename[15]);
void change_account();
void del_month(char filename[15]);
void return_menu();
void view_record(char filename[15],char month[10]);
void delete_account();
void login_menu();
void update_informations();
void log_out();
void change_month();
void view_all_month();
void search_function();

void main_menu(){
    extern char fname[10],month[10];

    FILE *data;
    char temp[10];
    data = fopen("currentMonth.dat","r");
    while(fscanf(data,"%s",temp) == 1){
        if(strcmp(temp,fname) == 0){
            fscanf(data,"%s",month);
        }
    }
    fclose(data);

    printf("\t\tPersonal Finance Management\n\n");
    printf("\n\t\tLogged in as: %s",fname);
    printf("\n\n\t\t========= MAIN MENU =========\n\n\n");
    printf("\t\t1.View Account Details.\n");
    printf("\t\t2.Show All Months.\n");
    printf("\t\t3.Change Current Month.\n");
    printf("\t\t4.Search.\n");
    printf("\t\t5.Add Monthly Income.\n");
    printf("\t\t6.Add Monthly Expense.\n");
    printf("\t\t7.Update Personal Informations.\n");
    printf("\t\t8.Delete data from Monthly Income.\n");
    printf("\t\t9.Delete data from Monthly Expense.\n");
    printf("\t\t10.Delete Account\n");
    printf("\n\t\t11.Log Out.\n");
    printf("\n\t\t12.Exit.\n");

    char incomefile[] = "income.dat",expensefile[] = "expense.dat";
    int p;

    a: scanf("%d",&p);

    if(p > 12){
        printf("\n\t\tChoose a number between 1 and 12.\n");
        goto a;
    }

    switch(p) {
    case 1:
        system("cls");
        view_account();
        break;
    case 2:
        system("cls");
        view_all_month();
        break;
    case 3:
        system("cls");
        change_month();
        break;
    case 4:
        system("cls");
        search_function();
        break;
    case 5:
        system("cls");
        printf("\n\n\t\t\t=====INCOME====\n");
        select_month(incomefile);
        break;
    case 6:
        system("cls");
        printf("\n\n\t\t\t=====EXPENSE====\n");
        select_month(expensefile);
        break;
    case 7:
        system("cls");
        update_informations();
        break;
    case 8:
        system("cls");
        del_month(incomefile);
        break;
    case 9:
        system("cls");
        del_month(expensefile);
        break;
    case 10:
        system("cls");
        delete_account();
        break;
    case 11:
        system("cls");
        log_out();
        break;
    case 12:
        system("cls");
        printf("\n\t\tThank you for using my program.");
        printf("\n\n\t\tCreated by:\n\t\tMusfiquer Rhman\tID: 17181103098");
        printf("\n\t\tSection: 3\n\t\tIntake: 37\n\n");
        exit(0);
        break;
    }
}

void return_menu(){
    printf("\n\n\t\tPress Any Key to Continue.");
    getch();
    system("cls");
    main_menu();
}
