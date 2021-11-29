char ex_name[10];

void view_data(){
    FILE *data;
    extern char fname[10];
    char fgen[6],focc[10];
    char d;
    int fage,day,month,year;

    data = fopen("data.dat","rb");
    printf("\n\t======== Personal informations =======\n\n");

    while(fscanf(data,"%s",ex_name) == 1){
        if(strcmp(ex_name,fname)==0){
            fscanf(data,"%*s %s %d %d %d %d %s",&fgen,&day,&month,&year,&fage,&focc);
            printf("\t\tName:           %s\n",fname);
            printf("\t\tGender:         %s\n",fgen);
            printf("\t\tDate of Birth:  %d/%d/%d\n",day,month,year);
            printf("\t\tage:            %d Years\n",fage);
            printf("\t\tOccupation:     %s\n",focc);
        }
    }
    fclose(data);
}

void view_record(char filename[15],char month[10]){
    extern char fname[10];
    char income[20],mon[10];
    int sp2=0;
    long val=0;

    FILE *inf;
    inf = fopen(filename,"r");

    while(fscanf(inf,"%s",ex_name) == 1){
        if (strcmp(fname,ex_name)==0){
            fscanf(inf,"%s",mon);

            if (strcmp(mon,month) == 0){
                while((fscanf(inf,"%s",&income) ==1 ) && strcmp(income,"newuser") != 0){
                    fscanf(inf,"%ld",&val);
                    printf("\t\t%s",income);
                    sp2 = strlen(income);

                    for(int i = 0;i<14-sp2;i++){
                        printf(" ");
                    }
                    printf(": %ld\n",val);
                }
            }
        }
    }
    fclose(inf);
}

long Total_val(char filename[15],char month[10]){
    extern char fname[10];
    char income[20],mon[10];
    long val=0,total_val=0;

    FILE *inf;
    inf = fopen(filename,"r");

    while(fscanf(inf,"%s",ex_name) == 1){
        if (strcmp(fname,ex_name)==0){
            fscanf(inf,"%s",mon);

            if (strcmp(mon,month) == 0){
                while((fscanf(inf,"%s",&income) ==1 ) && strcmp(income,"newuser") != 0){
                    fscanf(inf,"%ld",&val);
                    total_val += val;
                }
            }
        }
    }

    fclose(inf);
    return total_val;
}

void final_data(char month[10]){
    long total_income = Total_val("income.dat",month);
    long total_expense = Total_val("expense.dat",month);

    extern long save;

    printf("\n\n\t====================================");

    if(total_income > total_expense){
        printf("\n\t\tYou Saved  : %ld",save = total_income - total_expense);
    } else if (total_income < total_expense) {
        printf("\n\t\tYou have spent more by : %ld",save = total_expense - total_income);
    } else {
        printf("\n\tYour Income and expense is same.");
    }
}

void data(char month[10]){
    long total_income = Total_val("income.dat",month);
    long total_expense = Total_val("expense.dat",month);

    if (total_income == 0){
        printf("\nYou haven't added any income data of %s month\n\n",month);
    } else {
        printf("\n\n\t>-------> Your Monthly Income <-------<\n\n");
        view_record("income.dat",month);
        printf("\n\t\t-----------------------");
        printf("\n\t\tTotal Income : %ld",total_income);
    }

    if (total_expense == 0){
        printf("\n\nYou haven't added any expense data of %s month\n\n",month);
    } else {
        printf("\n\n\t>-------> Your Monthly Expense <-------<\n\n");
        view_record("expense.dat",month);
        printf("\n\t\t-----------------------");
        printf("\n\t\tTotal Expense : %ld", total_expense);
    }
}

void view_account(){
    extern char month[10];
    view_data();

    printf("\n\n\tShowing records of Current Month: %s\n",month);

    data(month);

    final_data(month);
    return_menu();
}
