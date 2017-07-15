#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void add( );
void list();
void modify();
void delet();
void ex();
void marksheet();
void search();


struct stu
{
char name[40];
char roll[40];
char course[40];
char phone[12];
char address[40];
char pname[20];
int id;
int dd,mm,yyyy;
int wt,e,cl,cf,m;
}s;

int main()
{
    system("cls");
int choice,another;
long int recsize;
while(1)
{
printf("\n\n\t\t\t****************************\n");
printf("\t\t\t*   EXAMINATION RESULT  *\n");
printf("\t\t\t****************************\n");
printf("\n\n\t\t\t****************************\n");
printf("\t\t\t*  Enter 1 to Add Record   *\n");
printf("\t\t\t*  Enter 2 Report of Records  *\n");
printf("\t\t\t*  Enter 3 Modify Records  *\n");
printf("\t\t\t*  Enter 4 Delete Records  *\n");
printf("\t\t\t*  Enter 5 Search          *\n");
printf("\t\t\t*  Enter 6 Marksheet       *\n");
printf("\t\t\t*  Enter 0 Exit            *\n");
printf("\t\t\t****************************\n");
printf("\t\t\t       Your Choice ");
scanf("%d",&choice);
system("cls");
switch(choice)
{
case 1:
system("cls");
add();
break;
case 2:
system("cls");
list();
break;
case 3:
system("cls");
modify();
break;
case 4:
system("cls");
delet();
break;
case 5:
system("cls");
search();
break;
case 6:
system("cls");
marksheet();
break;
case 0:
ex();
default:
{
printf("wrong choice ");
}
}
}
}

void add()
{
FILE  *fp;
int x,id,i,flag,z;
char ch;
long int recsize;
char another;
system("cls");
fp=fopen("stu.dat","ab");
recsize=sizeof(s);
fread(&s,recsize,1,fp);
another = 'y';
do
{
fp=fopen("stu.dat","ab+");
s.id++;
printf("\n Student ID no %d ",s.id);
l1:

printf("\n Enter Student Name ");
fflush(stdin);
gets(s.name);
strcpy(s.name, strupr(s.name));
	if(strlen(s.name)<3)
	{
	printf("\n Name is too short");
	goto l1;
	}
	for(i=0; s.name[i]!='\0';i++)
	{
	if(s.name[i]==' ')
	continue;
	if(s.name[i]<65||s.name[i]>90)
	{
	printf("Not a valid name\n");
	goto l1;
	}
	}


printf("\n Enter Student Roll no ");
gets(s.roll);
printf("\n Enter Student Course ");
gets(s.course);
printf("\n Enter your Address ");
gets(s.address);
do
{
flag=1;

printf("\n Enter Your Phone Number ");
scanf("%s",s.phone);
x=strlen(s.phone);
if(x<8||x>11)
flag=0;
if(flag==0)
printf("Enter Correctly\n");
}while (flag==0);
printf("\n Enter the issue date of the marksheet \n ");
l4:
fflush(stdin);
printf("Date ");
scanf("%d",&s.dd);
printf("\nMonth ");
scanf("%d",&s.mm);
printf("\nYear ");
scanf("%d",&s.yyyy);
printf("\n");

		if((s.dd>=1 && s.dd<=31) &&
      (s.mm==1 || s.mm==3 || s.mm==5 || s.mm==7 ||
      s.mm==8 || s.mm==10 || s.mm==12) &&
      (s.yyyy<=2016))
      {
	printf("%d / %d / %d is a valid date", s.dd, s.mm, s.yyyy);
      }
      else
      if((s.dd>=1 && s.dd<=30) &&
      (s.mm==4 || s.mm==6 || s.mm==9 || s.mm==11) &&
      (s.yyyy<=2016))
      {
	printf("%d / %d / %d is a valid date", s.dd,s.mm,s.yyyy);
      }
       else
      if((s.dd>=1 && s.dd<=29) && (s.mm==2) &&
      (s.yyyy<=2016) &&
      (s.yyyy%100!=0 && s.yyyy%4==0))
      {
	 printf("%d / %d / %d is a valid date",s.dd,s.mm,s.yyyy);
      }
      else
      if((s.dd>=1 && s.dd<=28) && (s.mm==2)&&(s.yyyy<=2016))
      {
	 printf("%d / %d / %d is a valid date", s.dd,s.mm,s.yyyy);
      }

      else
      {
       printf("Invalid date");
       printf("\n Please re-enter the date : \n ");
       goto l4;
       }

       printf("\nEnter Your Marks \n ");
     do
     {


     printf("English  ");
     }while(scanf("%d",&s.e) && (s.e>100 && printf(" marks limit exceed\n")));


    do{
    printf("\nC Language  ");
    }while(scanf("%d",&s.cl) && (s.cl>100 && printf(" marks limit exceed\n")));

    do{
     printf("\nWeb Technology  ");
     }while(scanf("%d",&s.wt) && (s.wt>100 && printf(" marks limit exceed\n")));

     do{
     printf("\nMaths  ");
     }while(scanf("%d",&s.m) && (s.m>100 && printf(" marks limit exceed\n")));

     do{
     printf("\nComputer Fundamental   ");
     }while(scanf("%d",&s.cf) && (s.cf>100 && printf(" marks limit exceed\n")));


fseek(fp,0,SEEK_END);
fwrite(&s,sizeof(s),1,fp);

fclose(fp);
printf("\n Add another records(Y/N)");
scanf("%c",&ch);
another=ch;
}while(another=='y');
printf("\nPress any key to go back\n");
getch();
}

void list()
{
FILE *ft, *fp;
long int recsize;
fp=fopen("stu.dat","r");
recsize=sizeof(s);
system("cls");
printf("student id\t student name\t address\t phone number\t issue date");
while(fread(&s,recsize,1,fp)==1)
{

printf("\n %d",s.id);
printf("\t\t %s",s.name);
printf("\t %s",s.address);
printf("\t\t %s",s.phone);
printf("\t %d/%d/%d\n",s.dd,s.mm,s.yyyy);

}
getch();
}
void modify()
{
FILE *ft, *fp;
char another;
int cid,flag,x,i;
long int recsize;
fp=fopen("stu.dat","rb+");
ft=fopen("T.dat","wb+");
recsize=sizeof(s);
another='y';
l1:
do
{
printf("\n Enter Student to Modify the record ");
scanf("%d",&cid);
rewind(fp);
while(fread(&s,sizeof(s),1,fp)==1)
{
if(s.id!=cid)
fwrite(&s,sizeof(s),1,ft);
else
{
printf("\n Enter Student Name ");
fflush(stdin);
gets(s.name);
strcpy(s.name, strupr(s.name));
	if(strlen(s.name)<3)
	{
	printf("\n Name is too short");
	goto l1;
	}
	for(i=0; s.name[i]!='\0';i++)
	{
	if(s.name[i]==' ')
	continue;
	if(s.name[i]<65||s.name[i]>90)
	{
	printf("Not a valid name\n");
	goto l1;
	}
	}

printf("\n Enter your Address ");
scanf("%s",s.address);
do
{
flag=1;
printf("\n Enter Your Phone Number ");
scanf("%s",s.phone);
x=strlen(s.phone);
if(x<8||x>11)
flag=0;
if(flag==0)
printf(" Enter Correctly\n");
}while (flag==0);
printf("\n Enter the issue date of the marksheet\n ");
l4:
fflush(stdin);
printf(" Date ");
scanf("%d",&s.dd);
printf("\n Month ");
scanf("%d",&s.mm);
printf("\n Year ");
scanf("%d",&s.yyyy);
printf("\n");

		if((s.dd>=1 && s.dd<=31) &&
      (s.mm==1 || s.mm==3 || s.mm==5 || s.mm==7 ||
      s.mm==8 || s.mm==10 || s.mm==12) &&
      (s.yyyy<=2016))
      {
	printf("%d / %d / %d is a valid date", s.dd, s.mm, s.yyyy);
      }
      else
      if((s.dd>=1 && s.dd<=30) &&
      (s.mm==4 || s.mm==6 || s.mm==9 || s.mm==11) &&
      (s.yyyy<=2016))
      {
	printf("%d / %d / %d is a valid date", s.dd,s.mm,s.yyyy);
      }
       else
      if((s.dd>=1 && s.dd<=29) && (s.mm==2) &&
      (s.yyyy<=2016) &&
      (s.yyyy%100!=0 && s.yyyy%4==0))
      {
	 printf("%d / %d / %d is a valid date",s.dd,s.mm,s.yyyy);
      }
      else
      if((s.dd>=1 && s.dd<=28) && (s.mm==2)&&(s.yyyy<=2016))
      {
	 printf("%d / %d / %d is a valid date\n", s.dd,s.mm,s.yyyy);
      }

      else
      {
       printf("Invalid date");
       printf("\n Please re-enter the date : \n ");
       goto l4;
      }

  printf("\nEnter Your Marks \n ");
     printf("English  ");
     scanf("%d",&s.e);
    printf("\nC Language  ");
    scanf("%d",&s.cl);
     printf("\nWeb Technology  ");
     scanf("%d",&s.wt);
     printf("\nMaths  ");
     scanf("%d",&s.m);
     printf("\nComputer Fundamental   ");
     scanf("%d",&s.cf);
   fwrite(&s,sizeof(s),1,ft);
}
}
fclose(fp);
fclose(ft);
remove("stu.dat");
rename("T.dat","stu.dat");
fp=fopen("stu.dat","rb+");
printf("\n Modify another records(Y/N)");
fflush(stdin);
another=getche();
}
while(another=='y');
}

void delet()
{
FILE *ft, *fp;
char another;
int cid;
fp=fopen("stu.dat","rb+");
another='y';
do
{
printf("\n Enter Student ID no to delete record ");
scanf("%d",&cid);
ft=fopen ("T.dat","wb+");
rewind(fp);
while(fread(&s,sizeof(s),1,fp)==1)
{
if(s.id!=cid)
fwrite(&s,sizeof(s),1,fp);
else
{
printf("\n\nStudent ID %d",s.id);
printf("\nStudent Name %s",s.name);
printf("\nAddress %s",s.address);
printf("\nPhone no %s",s.phone);
printf("\nDate %d/%d/%d",s.dd,s.mm,s.yyyy);
printf("\nMarksheet %s",s.pname);
}
}
fclose(fp);
fclose(ft);
remove("stu.dat");
rename("T.dat","stu.dat");
fp=fopen("stu.dat","rb+");
printf("\nDelete another records(Y/N)");
fflush(stdin);
another=getche();

}
while(another=='y');
}

 void marksheet()
{
    FILE *fp,*ft;
    int cid;
    fp=fopen("stu.dat","rb+");
    printf("enter student id no ");
    scanf("%d",&cid);
    rewind(fp);
     while(fread(&s,sizeof(s),1,fp)==1)
      {
        if(s.id==cid)
        {

         printf("Your Marks \n");
     printf("English %d \n",s.e);
    printf("C Language %d \n",s.cl);
     printf("Web Technology %d\n",s.wt);
     printf("Maths  %d\n",s.m);
     printf("Computer Fundamental %d\n",s.cf);

        }
      }
        getch();
     }



void search()
{
	FILE *fp,*ft;
       int cid ;
	      fp=fopen("stu.dat","rb+");
printf("Enter student id no to search ");
	scanf("%d",&cid);
	rewind(fp);
       while(fread(&s,sizeof(s),1,fp)==1)
	{
		 if(s.id==cid)
		  {
printf("\nRecord Found ");
printf("\nStudent ID %d",s.id);
printf("\nStudent Name %s",s.name);
printf("\nAddress %s",s.address);
printf("\nPhone no %s",s.phone);
printf("\nDate %d/%d/%d",s.dd,s.mm,s.yyyy);

		}
	}
	getch();
	fclose(fp);
}




void ex()
{
FILE *fp ,*ft;
fclose(fp);

exit(0);
}

