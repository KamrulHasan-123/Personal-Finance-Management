void change_month(){
    FILE *data, *temp;
    char file[] = "currentMonth.dat", tempfile [] = "temp.dat",tempdata[15],currentMonth[10] = "";
    extern char fname[10];

    char month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    data = fopen(file,"r");
    temp = fopen(tempfile,"a");

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

    strcpy(currentMonth,month[p-1]);

    while(fscanf(data,"%s",tempdata) == 1){
        fprintf(temp,"%s ",tempdata);

        if(strcmp(tempdata,fname) == 0){
            fscanf(data,"%s",tempdata);
            fprintf(temp,"%s ",currentMonth);
        }
    }

    fclose(data);
    fclose(temp);
    remove(file);
    rename(tempfile,file);
}
