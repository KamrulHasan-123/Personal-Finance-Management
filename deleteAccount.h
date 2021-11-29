void delete_alldata(char filename[15]){
    FILE *data,*temp;
    char fdata[15],afdata[15],newfile[]="temp.dat";
    extern char fname[10];

    data = fopen(filename,"r");
    temp = fopen("temp.dat","a");

    while(fscanf(data,"%s",fdata) == 1){
        if(strcmp(fdata,fname)==0){
            while(fscanf(data,"%s",afdata) == 1 && strcmp(afdata,"newuser") !=0){
                fprintf(temp,"%s","");
            }
        } else {
            fprintf(temp,"%s ",fdata);
        }
    }

    fclose(data);
    fclose(temp);
    remove(filename);
    rename(newfile,filename);
}

void verify(){
    FILE *data;
    char ex_name[10],pass[10],ex_pass[10],flag[8];
    extern char fname[10];

    data = fopen("data.dat","r");
    int i=4;

    while(fscanf(data,"%s",flag) == 1){
        if(strcmp(flag,"newuser")==0){
            fscanf(data,"%s",ex_name);

            if(strcmp(ex_name,fname)==0){
                printf("\n\t\tEnter the Password of %s: ",fname);
                fscanf(data,"%s",ex_pass);
                a: scanf("%s",&pass);

                if((strcmp(pass,ex_pass))==0){
                    system("cls");
                    break;
                } else {
                    printf("\t\tPassword not matched, try again(%d): ",i);

                    if(i<=4 && i>0){
                        i--;
                        goto a;
                    } else {
                        system("cls");
                        main_menu();
                    }
                }
            }
        }
    }
    fclose(data);
}

void delete_account(){
    printf("\n\n\t\tAre you sure you want to delete your account?");
    printf("\n\t\tThis will delete all of your personal informations, income and expense data.");
    printf("\n\n\t\t1.\"YES\" Delete My Account.");
    printf("\n\t\t2.\"NO\" Go to Main Menu.\n");

    int s;
    scanf("%d",&s);

    if ( s == 1){
        verify();

        delete_alldata("data.dat");
        delete_alldata("income.dat");
        delete_alldata("expense.dat");
        delete_alldata("currentMonth.dat");

        system("cls");
        printf("\n\t\tYour Account has been deleted");
        printf("\n\t\tPress any key to continue\n");

        getch();
        system("cls");
        login_menu();
    } else {
        system("cls");
        main_menu();
    }
}

