void login_menu();

void login(){
    extern char fname[10];

    printf("\n\t\tType EXIT (in Capital Letters) to go back to Login menu.\n");
    printf("\t\tEnter your name: ");

    scanf("%s",&fname);

    if(strcmp(fname,"EXIT")==0){
        system("cls");
        login_menu();
    } else {
        FILE *data;
        char ex_name[10],pass[10],ex_pass[10],flag[8];
        data = fopen("data.dat","r");
        int i=4;

        while(fscanf(data,"%s",flag) == 1){
        if(strcmp(flag,"newuser")==0){
            fscanf(data,"%s",ex_name);

            if(strcmp(ex_name,fname)==0){
                printf("\t\tEnter Password for %s: ",fname);
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
                        login_menu();
                    }
                }
            }
        }
    }

    if(feof(data)){
        printf("\n\t\tUser name not found, try again.\n");
        login();
    }
    fclose(data);
    }
}

