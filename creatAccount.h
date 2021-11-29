void create_account(){
    FILE *data;
    data = fopen("data.dat","a");
    char name[10],pass[10],occ[10],ex_name[10];
    int gen,age,day,month,year,p;

    printf("Enter your name(Maximum 10 characters): ");
    a: scanf("%s",&name);

    data = fopen("data.dat","r");

    while((fscanf(data,"%s",ex_name)) == 1){
        if(strcmp(ex_name,name)==0){
            printf("Username already exist, enter a different name: ");
            goto a;
        }
    }

    data = fopen("data.dat","a");
    fprintf(data,"newuser ");
    fprintf(data,"%s ",name);

    printf("Enter your password(Maximum 10 characters): ");
    scanf("%s",&pass);
    fprintf(data,"%s ",pass);

    printf("Select your gender: 1. Male / 2. Female ");
    b: scanf("%d",&gen);

    if(gen > 2){
        printf("Select 1.Male or 2.Female");
        goto b;
    }
    if(gen == 1){
        fprintf(data,"Male ");
    }  else if (gen == 2) {
        fprintf(data,"Female ");
    }

    printf("Enter your date of birth(day/month/year): ");
    scanf("%d %*c %d %*c %d",&day,&month,&year);
    fprintf(data,"%d %d %d ",day,month,year);

    age = 2018 - year;
    fprintf(data,"%d ",age);

    printf("Enter your occupation: ");
    scanf("%s",&occ);
    fprintf(data,"%s ",occ);

    fclose(data);

    FILE *mon;
    mon = fopen("currentMonth.dat","a");
    char monthname[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    fprintf(data,"newuser ");
    fprintf(mon,"%s ",name);
    printf("\nSelect Current Month: ");

    for(int i = 1; i <= 12; i++){
        printf("\n\t\t%d.%s",i,monthname[i-1]);
    }

    c: scanf("%d",&p);
    if(p > 12 && p < 0){
        printf("Select a number between 1 to 12: ");
        goto c;
    }

    fprintf(mon,"%s ",monthname[p-1]);

    fclose(mon);
}
