void view_record(char filename[15],char month[10]);
long Total_val(char filename[15],char month[10]);
void data(char month[10]);

void searchByMonth(){
    char month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},selectedMonth[10];

    printf("\n\t\tSelect the month:\n");

    for(int i = 1; i <= 12; i++){
        printf("\t\t%d.%s\n",i,month[i-1]);
    }

    int p;
    scanf("%d",&p);

    strcpy(selectedMonth,month[p-1]);

    system("cls");

    printf("\n\t========== Month: %s ==========\n",month[p-1]);
    data(month[p-1]);
    final_data(month[p-1]);
}

void SearchByItem(char filename[15],char selectedItem[20]){
    char month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char tempMonth[10];
    char temp[15];
    extern char fname[10];
    long val = 0;

    FILE *inf;

    inf = fopen(filename,"r");

    while(fscanf(inf,"%s",temp) == 1){

        if(strcmp(temp,fname) == 0){
            fscanf(inf,"%s",tempMonth);

            while((fscanf(inf,"%s",temp) == 1) && (strcmp(temp,"newuser") != 0)){
                if(strcmp(temp,selectedItem) == 0){
                    fscanf(inf,"%ld",&val);
                    printf("\n\t\tMonth: %s",tempMonth);
                    printf("\n\t\t---------------------");
                    printf("\n\t\t%s: %ld\n\n",temp,val);
                }
            }
        }
    }
}

void search_function(){
    printf("\n\t\tSelect your search type:\n");
    printf("\n\t\t1.Search by Month");
    printf("\n\t\t2.Search by item\n");

    char selectedItem[20];

    int p;
    a: scanf("%d",&p);

    if(p > 2) {
        printf("Select between 1 and 2.");
        goto a;
    }

    switch(p){
    case 1:
        system("cls");
        searchByMonth();
        return_menu();
        break;
    case 2:
        system("cls");
        printf("\n\t\tEnter the item name:");
        scanf("%s",&selectedItem);

        printf("\n\t\tItems found in Income records:\n");
        SearchByItem("income.dat",selectedItem);
        printf("\n\t\tItems found in Expense records:\n");
        SearchByItem("expense.dat",selectedItem);
        return_menu();
        break;
    }
}
