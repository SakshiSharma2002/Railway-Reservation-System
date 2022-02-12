#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "conio2.h"
#include "rlyres.h"
int enterchoice()
{
    int choice,i;
    textcolor(LIGHTRED);
    gotoxy(28,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    textcolor(GREEN);
    for(i=0;i<80;i++)
    printf("-");
    textcolor(YELLOW);
    printf("\nSelect an option\n1- View Trains\n2- Book Ticket\n3- View Ticket\n4- Search Ticket No\n5- View All Bookings\n6- View Train Bookings\n7- Cancel Ticket\n8- Cancel Train\n9- Quit\n");
    printf("\nEnter choice:");
    textcolor(WHITE);
    scanf("%d",&choice);
    textcolor(YELLOW);
    return choice;
}
void add_trains()
{
    Train alltrains[4]={
        {"123","BPL","GWA",2100,1500},
        {"546","BPL","DEL",3500,2240},
        {"345","HBJ","AGR",1560,1135},
        {"896","HBJ","MUM",4500,3360},
        };
    FILE *fp=fopen("e:\\myproject\\alltrains.dat","rb");
    if(fp==NULL)
    {
        fp=fopen("e:\\myproject\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        printf("File created and saved!\n");
    }
    else
       printf("File already present\n");
    fclose(fp);
}

void view_trains()
{
    int i;
    gotoxy(28,1);
    textcolor(GREEN);
    printf("Train Details\n");
    textcolor(YELLOW);
    for(i=0;i<80;i++)
    printf("-");
    gotoxy(1,3);
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE\n");
    for(i=1;i<=80;i++)
        printf("-");
    FILE *fp=fopen("e:\\myproject\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
    }
    printf("\n\n\n\n");
    fclose(fp);
}
int check_train_no(char *trainno)
{
    FILE *fp=fopen("e:\\myproject\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
        return 0;
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
            return 0;
        p_mob++;
    }
    return 1;
}
Passenger *get_passenger_details()
{
    clrscr();
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    _getch();
    static Passenger psn;
    printf("Enter passenger name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(psn.p_name,20,stdin);
    textcolor(YELLOW);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    int valid;
    printf("Enter gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        textcolor(WHITE);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        if(psn.gender!='M'&&psn.gender!='F')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("ERROR!Gender should be M or F (in uppercase)");
            valid=0;
            getch();
            gotoxy(19,2);
            printf(" \b");
            textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,3);
    textcolor(YELLOW);
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        textcolor(WHITE);
        scanf("%s",psn.train_no);
        if(strcmp(psn.train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        valid=check_train_no(psn.train_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!Invalid Train Number");
            getch();
            gotoxy(20,3);
            printf("\t\t\t\t\t\t\t");
            gotoxy(20,3);
            textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,4);
    textcolor(YELLOW);
    printf("Enter travelling class(First AC-F,Second AC-S):");
    do
    {
        valid=1;
        fflush(stdin);
        textcolor(WHITE);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        if(psn.p_class!='F'&&psn.p_class!='S')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!Travelling class should be F or S(in upper case)");
            valid=0;
            getch();
            gotoxy(48,4);
            printf(" \b");
            textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,5);
    textcolor(YELLOW);
    printf("Enter address:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(psn.address,20,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    gotoxy(1,6);
    textcolor(YELLOW);
    printf("Enter age:");
    do
    {
        valid=1;
        textcolor(WHITE);
        fflush(stdin);
        scanf("%d",&psn.age);
        if(psn.age==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        if(psn.age<=0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!Age should be positive");
            valid=0;
            getch();
            gotoxy(11,6);
            printf("\t\t\t\t\t\t\t");
            gotoxy(11,6);
            textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,7);
    textcolor(YELLOW);
    printf("Enter mobile no:");
    do
    {
        fflush(stdin);
        textcolor(WHITE);
        fgets(psn.mob_no,12,stdin);
        pos=strchr(psn.mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(strcmp(psn.mob_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled!");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        valid=check_mob_no(psn.mob_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!Invalid Mobile Number");
            getch();
            gotoxy(17,7);
            printf("\t\t\t\t\t\t\t");
            gotoxy(17,7);
            textcolor(YELLOW);
        }
    }while(valid==0);
    return &psn;
}
int get_booked_ticket_count(char *train_no,char tc)
{
    FILE *fp=fopen("e:\\myproject\\alltrains.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==tc)
            ++count;
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
     FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    fseek(fp,-1L*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}
int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==2)
    {
        textcolor(LIGHTRED);
        printf("All seats in train no %s in class %c are full",p.train_no,p.p_class);
        return -1;
    }
    int ticket_no=last_ticket_no()+1;
    p.ticketno=ticket_no;
    FILE *fp=fopen("e:\\myproject\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!File cannot be opened");
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}
int accept_ticket_no()
{
    int valid;
    int ticket_no;
    gotoxy(60,1);
    textcolor(GREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter a valid ticket no:");
    do
    {
        valid=1;
        fflush(stdin);
        textcolor(WHITE);
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Cancelling Input...!");
            textcolor(YELLOW);
            return 0;
        }
        if(ticket_no<0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!Ticket no should be positive");
            valid=0;
            getch();
            gotoxy(25,1);
            printf("\t\t");
            gotoxy(25,1);
            textcolor(YELLOW);
        }
    }while(valid==0);
    textcolor(YELLOW);
    return ticket_no;
}
void view_ticket(int ticket_no)
{
    clrscr();
    FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("No bookings done yet!");
        return;
    }
    Passenger pr;
    textcolor(GREEN);
    printf("Following are the Details of Ticket Number %d\n",ticket_no);
    textcolor(YELLOW);
    for(int i=0;i<80;i++)
        printf("-");
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticketno==ticket_no)
        {
            printf("\nNAME:%s\nGENDER:%c\nTRAIN NO:%s\nCLASS:%c\nADDRESS:%s\nAGE:%d\nMOBILE NO:%s\nTICKET NO:%d",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
            found=1;
            break;
        }
    }
    if(found==0)
    {
        textcolor(LIGHTRED);
        printf("\nNo details of the ticket no %d found!",ticket_no);
    }
    fclose(fp);
}
char *accept_mob_no()
{
    static char mob_no[12];
    char *pos;
    int valid;
    gotoxy(60,1);
    textcolor(GREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter valid mobile number:");
    do
    {
        fflush(stdin);
        textcolor(WHITE);
        fgets(mob_no,13,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelling Input!");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!Invalid Mobile Number");
            getch();
            gotoxy(27,1);
            printf("\t\t\t\t\t\t\t");
            gotoxy(27,1);
            textcolor(YELLOW);
        }
    }while(valid==0);
    textcolor(YELLOW);
    clrscr();
    return mob_no;
}
int *get_ticket_no(char *p_mob_no)
{
    int count=0;
    FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry file cannot be opened!");
        return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
    }
    if(!count)
    {
        fclose(fp);
        return NULL;
    }
    int *p=(int*)malloc((count+1)*sizeof(int));
    rewind(fp);
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
         {
             *(p+i)=pr.ticketno;
             i++;
         }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;
}
void view_all_tickets(char *pmob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nSorry!No tickets booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen...");
        textcolor(YELLOW);
        getch();
        return;
    }
    textcolor(GREEN);
    printf("Following are the tickets booked for the mobile number %s",pmob_no);
    textcolor(YELLOW);
    int i;
    printf("\n\nTICKET NUMBERS\n");
    for(i=0;i<14;i++)
    printf("-");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
    textcolor(WHITE);
    printf("\n\nPress any key to go back to the main screen...");
    textcolor(YELLOW);
    getch();
    free(pticket_no);
}
char *accept_train_no()
{
    static char train_no[10];
    int valid;
    gotoxy(60,1);
    textcolor(GREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter train number:");
    do
    {
        valid=1;
        fflush(stdin);
        textcolor(WHITE);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelling Input...!");
            textcolor(YELLOW);
            return NULL;
        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!Invalid train Number");
            getch();
            gotoxy(20,1);
            printf("\t\t\t\t");
            gotoxy(20,1);
            textcolor(YELLOW);
        }
    }while(valid==0);
    textcolor(YELLOW);
    clrscr();
    return train_no;
}
void view_booking(char *train_no)
{
    int found=0;
    FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry file cannot be opened!");
        return;
    }
    Passenger pr;
    textcolor(GREEN);
    printf("Following are the bookings done for train no %s\n",train_no);
    textcolor(YELLOW);
    for(int i=1;i<=80;i++)
        printf("-");
    printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    for(int i=1;i<=80;i++)
        printf("-");
    int row=5;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            row++;
            found=1;
        }
    }
    if(found==0)
    {
        clrscr();
        textcolor(LIGHTRED);
        printf("\nNo details of the train no %s found!",train_no);
    }
    textcolor(WHITE);
    printf("\n\nPress any key to go back to the main screen...");
    textcolor(YELLOW);
    getch();
    fclose(fp);
}
int cancel_ticket(int ticket_no)
{
    int result;
    FILE *fp1=fopen("e:\\myproject\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet!");
        return -1;
    }
    FILE *fp2=fopen("e:\\myproject\\temp.dat","wb");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno==ticket_no)
            found=1;
        else
            fwrite(&pr,sizeof(pr),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
       remove("e:\\myproject\\temp.dat");
    }
    else
    {
       result=remove("e:\\myproject\\allbookings.dat");
       if(result!=0)
        return 2;
       result=rename("e:\\myproject\\temp.dat","e:\\myproject\\allbookings.dat");
       if(result!=0)
        return 2;
    }
    return found;
}
void view_all_bookings()
{
    int found=0;
    FILE *fp=fopen("e:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry file cannot be opened!");
        return;
    }
    Passenger pr;
    textcolor(GREEN);
    printf("Following are the total Bookings Done\n");
    textcolor(YELLOW);
    for(int i=0;i<80;i++)
        printf("-");
    printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    for(int i=1;i<=80;i++)
        printf("-");
    int row=5;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
        gotoxy(41,row);
        printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
        row++;
        found=1;
    }
    if(found==0)
    {
        clrscr();
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet!");
    }
    textcolor(WHITE);
    printf("\n\nPress any key to go back to the main screen...");
    textcolor(YELLOW);
    getch();
    fclose(fp);
}
int cancel_train(char *train_no)
{
    int result;
    FILE *fp1=fopen("e:\\myproject\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet!");
        return -1;
    }
    FILE *fp2=fopen("e:\\myproject\\temp.dat","wb");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
            found=1;
        else
            fwrite(&pr,sizeof(pr),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
       remove("e:\\myproject\\temp.dat");
    }
    else
    {
       result=remove("e:\\myproject\\allbookings.dat");
       if(result!=0)
        return 2;
       result=rename("e:\\myproject\\temp.dat","e:\\myproject\\allbookings.dat");
       if(result!=0)
        return 2;
    }
    return found;
}
