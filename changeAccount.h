void login_menu(){
    printf("\n\n\t\t======= Login Menu =======\n");
    printf("\n\t\t1.Create a new Account.");
    printf("\n\t\t2.Login with Existing account.");
    printf("\n\n\t\t3.Exit\n\n");

    int p;
    a: scanf("%d",&p);
    if (p > 3){
        printf("\t\tChoose a number between 1 to 3: ");
        goto a;
    }

    switch(p) {
    case 1:
        create_account();
        system("cls");
        printf("\n\t\tNow Login with your created account:\n");
        login();
        system("cls");
        main_menu();
        break;
    case 2:
        login();
        system("cls");
        main_menu();
        break;
    case 3:
        system("cls");
        printf("\n\t\tThank you for using my program.");
        printf("\n\n\t\tCreated by:\n\t\tMusfiquer Rhman\tID: 17181103098");
        printf("\n\t\tSection: 3\n\t\tIntake: 37\n\n");
        exit(0);
        break;
    }
}

void log_out(){
    printf("\n\t\tAre you sure you want to log out?");
    printf("\n\n\t\t1.\"YES\"\t2.\"NO\"\n");

    int p;
    a: scanf("%d",&p);

    if (p > 2){
        printf("\t\tChoose a number between 1 to 2: ");
        goto a;
    }

    switch(p) {
    case 1:
        printf("\t\tYou have been Logged out");
        printf("\n\t\tPress any key to continue.");
        getch();
        system("cls");
        login_menu();
        break;
    case 2:
        system("cls");
        main_menu();
        break;
    }
}
