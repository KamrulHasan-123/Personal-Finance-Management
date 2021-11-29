void update_gender(){
    FILE *data, *temp;

    data = fopen("data.dat","r");
    temp = fopen("temp.dat","a");

    extern char fname[10];
    int day,mon,year,age,g;
    char fdata[15],pass[15],occu[15],newfile[] = "temp.dat",filename[] = "data.dat",gen[7] = "";

    printf("Select your gender: 1. Male / 2. Female ");
    b: scanf("%d",&g);

    if(g > 2){
        printf("Select 1.Male or 2.Female");
        goto b;
    }

    if(g == 1){
        strcpy(gen,"Male");
    }  else if (g == 2) {
        strcpy(gen,"Female");
    }

    while(fscanf(data,"%s",fdata) == 1){
        fprintf(temp,"%s ",fdata);

        if(strcmp(fdata,fname) == 0){
            fscanf(data,"%s %*s %d %d %d %d %s",&pass,&day,&mon,&year,&age,&occu);
            fprintf(temp,"%s %s %d %d %d %d %s ",pass,gen,day,mon,year,age,occu);
        }
    }

    fclose(data);
    fclose(temp);
    remove(filename);
    rename(newfile,filename);
}

void update_bday(){
    FILE *data, *temp;

    data = fopen("data.dat","r");
    temp = fopen("temp.dat","a");

    extern char fname[10];
    int day,mon,year,age;
    char fdata[15],pass[15],gen[7],occu[15],newfile[] = "temp.dat",filename[] = "data.dat";

    printf("Enter your date of birth(day/month/year): ");
    scanf("%d %*c %d %*c %d",&day,&mon,&year);
    age = 2018 - year;

    while(fscanf(data,"%s",fdata) == 1){
        fprintf(temp,"%s ",fdata);

        if(strcmp(fdata,fname) == 0){
            fscanf(data,"%s %s %*d %*d %*d %*d %s",&pass,&gen,&occu);
            fprintf(temp,"%s %s %d %d %d %d %s ",pass,gen,day,mon,year,age,occu);
        }
    }

    fclose(data);
    fclose(temp);
    remove(filename);
    rename(newfile,filename);
}

void update_occ(){
    FILE *data, *temp;

    data = fopen("data.dat","r");
    temp = fopen("temp.dat","a");

    extern char fname[10];
    int day,mon,year,age;
    char fdata[15],pass[15],gen[7],occu[15],newfile[] = "temp.dat",filename[] = "data.dat";

    printf("Enter your occupation: ");
    scanf("%s",&occu);

    while(fscanf(data,"%s",fdata) == 1){
        fprintf(temp,"%s ",fdata);

        if(strcmp(fdata,fname) == 0){
            fscanf(data,"%s %s %d %d %d %d %*s",&pass,&gen,&day,&mon,&year,&age);
            fprintf(temp,"%s %s %d %d %d %d %s ",pass,gen,day,mon,year,age,occu);
        }
    }

    fclose(data);
    fclose(temp);
    remove(filename);
    rename(newfile,filename);
}

void update_informations(){
    printf("\n\n\t\tWhat do you want to change?");
    printf("\n\t\t1.Gender");
    printf("\n\t\t2.Date of birth.");
    printf("\n\t\t3.Occupation");

    int p;
    a: scanf("%d",&p);

    if (p > 3){
        printf("\t\tChoose a number between 1 to 3: ");
        goto a;
    }

    switch(p){
    case 1:
        update_gender();
        printf("Gender updated.");
        return_menu();
        break;
    case 2:
        update_bday();
        printf("Date of birth updated.");
        return_menu();
        break;
    case 3:
        update_occ();
        printf("Occupation updated");
        return_menu();
        break;
    }
}
