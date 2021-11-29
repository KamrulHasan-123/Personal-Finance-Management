void add_data(char filename[15], char month[10]){
    FILE *inf;

    char income[20];
    extern char fname[10];
    char c;
    long val;

    inf = fopen(filename,"ab");

    fprintf(inf,"newuser ");
    fprintf(inf,"%s ",fname);
    fprintf(inf,"%s ",month);

    do {
        printf("\nSource/Field (No space allowed): ");
        scanf("%s",&income);
        fprintf(inf,"%s ",income);
        printf("\nAmount : ");
        scanf("%ld",&val);
        fprintf(inf,"%ld ",val);
        printf("\n\nAdd another one? Y/N");
        c = getch();
    } while ( c == 'y' || c == 'Y');

    fclose(inf);
    return_menu();
}

void select_month(char filename[15]){
    char month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("\n\t\t.Select the month.\n");

    for(int i = 1; i <= 12; i++){
        printf("\n\t\t%d.%s",i,month[i-1]);
    }

    int p;
    a: scanf("%d",&p);
    if(p > 12){
        printf("\n\t\tSelect a number between 1 to 12.");
        goto a;
    }

    add_data(filename,month[p-1]);
}
