char ex_name[10];

long View_Total_val(char filename[15],char month[10]){
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

void view_all_month(){
    extern char fname[10];
    char income[20],mon[10],month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int sp2 = 0;
    long val = 0,yearly = 0;

    for(int i = 0; i < 12; i++){
        FILE *inf;
        inf = fopen("income.dat","r");
        long Ival = 0,save = 0;

        while(fscanf(inf,"%s",ex_name) == 1){
            if (strcmp(fname,ex_name)==0){
                fscanf(inf,"%s",mon);

                if (strcmp(mon,month[i]) == 0){
                    printf("\n\n\n\t\t=====Income Detail of %s month =====\n\n", month[i]);

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
        Ival = View_Total_val("income.dat",month[i]);

        if (Ival == 0){
            printf("\n\n\t\tYou have no income data of %s month\n",month[i]);
        } else {
            printf("\n\t\t-----------------------");
            printf("\n\t\tTotal Income : %ld",Ival);
        }

        fclose(inf);

        FILE *epf;
        epf = fopen("expense.dat","r");

        long Eval = 0;

        while(fscanf(epf,"%s",ex_name) == 1){
            if (strcmp(fname,ex_name)==0){
                fscanf(epf,"%s",mon);

                if (strcmp(mon,month[i]) == 0){
                    printf("\n\n\n\t\t=====Expense Detail of %s month =====\n\n", month[i]);

                    while((fscanf(epf,"%s",&income) ==1 ) && strcmp(income,"newuser") != 0){
                        fscanf(epf,"%ld",&val);
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
        Eval = View_Total_val("expense.dat",month[i]);

        if (Eval == 0){
            printf("\n\n\n\t\tYou have no expense data of %s month\n",month[i]);
        } else {
            printf("\n\t\t-----------------------");
            printf("\n\t\tTotal Expense : %ld",Eval);
        }

        fclose(epf);

        printf("\n\n\t\t====================================");

        if(Ival > Eval){
            printf("\n\t\tYou Saved  : %ld",save = Ival - Eval);
        } else if (Ival < Eval) {
            printf("\n\t\tYou have spent more by : %ld",save = Eval - Ival);
        } else {
            printf("\n\t\tYour Income and expense is same.\n\n");
        }

        yearly = yearly + Ival - Eval;
    }

    printf("\n\n\n\t\t============================================\n");
    printf("\t\t============================================\n");
    printf("\n\t\t============Your Yearly summary============\n");

    if ( yearly > 0){
        printf("\n\t\tThis year you saved: %ld\n",yearly);
    } else if (yearly < 0) {
        printf("\n\t\tThis year you Expensed more by: %ld\n",yearly);
    } else {
        printf("\n\t\tThis year you haven't save anything.\n");
    }

    return_menu();
}

