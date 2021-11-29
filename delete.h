void view_rec(char filename[15], char month[10]){
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

void delete_data(char filename[15], char month[10]){
    if (strcmp(filename,"income.dat")==0){
        printf("\n\n\t======== Your Monthly Income ========\n\n");
        view_rec("income.dat",month);
    } else if (strcmp(filename,"expense.dat")==0){
        printf("\n\n\t======= Your Monthly Expense ========\n\n");
        view_rec("expense.dat",month);
    }

    char p;

    do {
        FILE *data,*temp;
        char udata[15],fdata[15],afdata[15],aafdata[15],newfile[]="temp.dat";
        extern char fname[10];
        long fdeli;

        data = fopen(filename,"r");
        temp = fopen("temp.dat","a");

        printf("\n\nEnter the data to delete\n");

        scanf("%s",&udata);

        while(fscanf(data,"%s",fdata) == 1){
            fprintf(temp,"%s ",fdata);

            if(strcmp(fdata,fname)==0){
                while(fscanf(data,"%s",afdata) == 1 && strcmp(afdata,"newuser") !=0){
                    if(strcmp(afdata,udata)==0){
                        fscanf(data,"%ld",&fdeli);
                        printf("%s : %ld is deleted.\n",udata,fdeli);
                        break;
                    }
                    fprintf(temp,"%s ",afdata);
                }
            }
        }

        fclose(data);
        fclose(temp);

        remove(filename);
        rename(newfile,filename);

        printf("Do you want to Delete another data? Y/N ");
        p = getch();

    }while(p == 'y' || p == 'Y');
    return_menu();
}

void del_month(char filename[15]){
    char month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("\n\t\tSelect the month.\n");
    for(int i = 1; i <= 12; i++){
        printf("\n\t\t%d.%s",i,month[i-1]);
    }

    int p;

    a: scanf("%d",&p);
    if(p > 12){
        printf("\n\t\tSelect a number between 1 to 12.");
        goto a;
    }

    delete_data(filename,month[p-1]);
}
