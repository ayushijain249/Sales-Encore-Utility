
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define MAX 50

void layout();
void log_s();
void pr_tab(int n1);
void input(int x,int y,char input[]);
void main_menu(int tot_op ,char c);
void drawMenu(int defc ,int selc,int tot_op, char c);

int selected=1;
int ecount=0;      //NO of employees
int pcount=0;      //NO of prospects

struct prospect
{
 char pname[21];
 char pphone[15];
 char padd[41];
 char pemail[31];
 char pstatus[5];


}pro[MAX];

class employee
{
 public:
 char eloginName[11];
 char epass[11];
 char erole[15];
 char ename[21];
 char eemail[31];
 char ephone[15];

 employee()
 {
  strcpy(eloginName,"HP");
  strcpy(epass,"1234");
  strcpy(erole,"admin");
  strcpy(ename,"Ayushi");
  strcpy(eemail,"jain");
  strcpy(ephone,"9289214424");

 }
}emp[MAX] ;
void admin_s(employee emp[],int j);
void monitor_s(employee emp[],int j);


void main()
{
  int gd=DETECT,gm,max,may;
  initgraph(&gd,&gm,"c://turboc++//turboc3//disk//bgi");
  cleardevice();
  log_s();
}
/******************SCREEN LAYOUT*********************/
void layout()
{
 cleardevice();
 setbkcolor(11);
 setfillstyle(INTERLEAVE_FILL,12);
 bar(0,30,getmaxx(),130);
 setcolor(12);
 rectangle(0,30,getmaxx(),130);
 setfillstyle(SOLID_FILL,12);
 bar(30,0,80,getmaxy());
 bar(90,0,95,getmaxy());
}

/*******************Login Page*************************/

void log_s()
{
   layout();
   settextstyle(1,0,5);
   setcolor(4);
   outtextxy(120,50,"SALES ENCORE UTILITY");
    int tot_op=3;

    main_menu(tot_op ,'L');

     switch(selected)
   {
     case 1:   cleardevice();
	       layout();
	       settextstyle(1,0,5);
	       setcolor(4);
	       outtextxy(80,50," EMPLOYEE LOGIN DETAILS ");
	       setcolor(BLUE);
	       settextstyle(7,0,2);
	       outtextxy(120,250," LOGIN NAME :");
	       char n[11];
	       int flag=0;
	       input(350,250,n);
	      for(int j=0;j<MAX;j++)

	      {
		 if(!strcmp(n,emp[j].eloginName))
		{
		 setcolor(1);
		 outtextxy(120,290," PASSWORD   :");
		 char str[11];
		  int x=350;

		  for(int l=0;(str[l]=getch())!=13;l++)
		{  setcolor(9);
		    str[l+1]='\0';
		    if(str[l]=='\b')
		  {
		    setfillstyle(SOLID_FILL,LIGHTCYAN);
		    bar(350+((l-1)*10),290,370+((l-1)*10),320);
		    str[l-1]='\0';
		    l=l-2;
		    continue;
		  }

		   outtextxy(350+(l*10),290,"*");
		}
		str[l]='\0';

		 if(!strcmp(str,emp[j].epass))
		 {
		    flag=1;
		   if(!strcmp(emp[j].erole,"admin") )
		   {
		   admin_s(emp,j);

		   break;
		   }
		   else if(!strcmp(emp[j].erole,"monitor"))
		   {
		   monitor_s(emp,j);
		   break;
		   }
		 }

		}
	      }

	       if(flag==0)
	       outtextxy(120,330," INVALID LOGIN NAME OR PASSWORD ! ! !");

	       getch();
	       log_s();
	       break;
     case 2:   cleardevice();
	       layout();
	       settextstyle(1,0,5);
	       setcolor(4);
	       outtextxy(150,50," ABOUT DEVELOPERS ");
	       setcolor(BLUE);
	       settextstyle(7,0,2);
	       outtextxy(270,250," AYUSHI JAIN");
	       outtextxy(250,300," B-TECH 1st YEAR");
	       getch();
	       log_s();

     case 3:
	       cleardevice();
	       closegraph();
	       exit(0);


   }
}
/******************TAKE INPUT FRPM USER*******************************/
	void input(int x,int y,char input[])
      {  char c,str1[11];
	 int j=0,x1;
	 setcolor(LIGHTBLUE);
	 while((c=getch())!=13)
	 {


	  input[j]=c;

	  j++;
	  input[j]='\0';

	  outtextxy(x,y,input);

	    if(c=='\b')
	  {
	   x1=x+textwidth(input);
	   char tmp[2];
	   tmp[0]=input[j-2];
	   tmp[1]='\0';
	   setfillstyle(SOLID_FILL,LIGHTCYAN);
	   bar(x1-(textwidth(tmp)),y-5,x1+20,y+30);


	   j=j-2;
	   input[j]='\0';

	  }



	 }
      }



/****************************TO SELECT & PRINT OPTIONS****************/

void main_menu (int tot_op,char c)
{
int ch;
selected=1;

drawMenu ( BLUE , LIGHTRED ,tot_op ,c);
do
{

ch = getch();
if ( ch == 80 )
{
selected = selected >= tot_op ? 1 : selected + 1;
drawMenu (  BLUE , LIGHTRED ,tot_op,c);
}
else if ( ch == 72 )
{
selected = selected < 2 ? tot_op : selected - 1;
drawMenu (  BLUE , LIGHTRED ,tot_op,c);
}

}while ( ch != 13 );

}

void drawMenu(int  defc ,int selc,int tot_op,char c)
{
 char menu_option[3][20]= {
			  "1.LOGIN",
			  "2.ABOUT DEVELOPERS",
			  "3.TERMINATE PROGRAM"
			  };
  char admin_op[6][40]={
			 "1.Add New Prospect Monitor / Administor",
			 "2.View All Prospect Monitor",
			 "3.View All Prospects",
			 "4.Change Password",
			 "5.Delete Prospect Details",
			 "6.Signout",
		       };
  char pro_op[6][40]={
		       "1.ADD NEW PROSPECT",
		       "2.VIEW ALL PROSPECT",
		       "3.SEARCH PROSPECT",
		       "4.CHANGE PASSWORD",
		       "5.UPDATE PROSPECT'S PHONE NUMBER",
		       "6.SIGNOUT"
		     };
		setcolor(9);
		settextstyle(2,0,5);
		outtextxy(150,455,"USE ARROW KEYS TO SELECT OPTION AND PRESS ENTER... ");
  switch(c)
  {
    case 'L':
	       settextstyle(7,0,3);
	       for(int  i=1;i<=tot_op;i++)
	       {
		 if(selected==i)
		 setcolor(selc);

		 else
		 setcolor(defc);

		 outtextxy(230,200+(i*40),menu_option[i-1]);

	       }
	       break;
    case 'A':  settextstyle(7,0,2);
	       for( i=1;i<=tot_op;i++)
	       {
		 if(selected==i)
		 setcolor(selc);

		 else
		 setcolor(defc);
		 outtextxy(150,180+(i*40),admin_op[i-1]);
	       }
	       break;
    case 'P':  settextstyle(7,0,2);
	       for( i=1;i<=tot_op;i++)
	       {
		 if(selected==i)
		 setcolor(selc);

		 else
		 setcolor(defc);
		 outtextxy(150,180+(i*40),pro_op[i-1]);
	       }
	       break;
  }

}
/*******************ADMIN Page*************************/
void admin_s(employee emp[],int j)
{
  ad:
 layout();
 settextstyle(1,0,5);
 setcolor(4);
 outtextxy(120,50,"ADMINISTRATOR HOME");
 settextstyle(2,0,5);
 setcolor(LIGHTRED);
 outtextxy(250,150,"WELCOME ADMIN : Mr./Mrs.") ;
 char s[11];
 char s1[11];
 strcpy(s1,emp[j].ename);
 for(int i=0; s1[i]!='\0';i++)
 {
   s[i]=toupper(s1[i]);
 }
 s[i]='\0';
 outtextxy(430,150,s);
 setlinestyle(DOTTED_LINE,0,2);
 line(230,155+(textheight("W")),500,155+(textheight("W")));

 int tot_op=6;
 main_menu(tot_op,'A');
 switch(selected)
 {
   case 1: cleardevice();
	   layout();
	   ++ecount;
	   settextstyle(1,0,3);
	   setcolor(4);
	   outtextxy(150,60,"ADD NEW ADMINISTRATOR/MONITOR");
	   setcolor(1);
	   settextstyle(7,0,2);
	   outtextxy(150,150,"FULL NAME             : ");
	   input(420,150,emp[ecount].ename);
	   setcolor(1);
	   outtextxy(150,190,"ROLE(admin/moniotr) : ") ;
	   input(420,190,emp[ecount].erole);
	   setcolor(1);
	   outtextxy(150,220,"PHONE NUMBER       : ");
	   input(420,220,emp[ecount].ephone);
	   setcolor(1);
	   outtextxy(150,250,"EMAIL ID               : ") ;
	   input(420,250,emp[ecount].eemail);

	   setcolor(1);
	   outtextxy(150,320,"EMPLOYEE ADDED SUCCESSFULLY WITH");
	   outtextxy(150,350,"LOGIN NAME  :");
	   outtextxy(150,380,"PASSWORD    :");

	    setcolor(9);
	    char log[3];
	    log[0]='H';
	    log[1]='P';
	    log[2]='\0';
	    int num= ecount;
	    char log1[2];
	    sprintf(log1,"%d",num);
	    strcat(log,log1);

	    strcpy(emp[ecount].eloginName,log);
	    outtextxy(360,350,emp[ecount].eloginName);
	    char pass[5];
	    long p;
	    p:
	    randomize();
	    p=rand()%10000 ;
	    if(p<1000 || p==10000)
	    goto p;

	    sprintf(pass,"%d",p);

	    strcpy(emp[ecount].epass,pass) ;
	    outtextxy(360,380,emp[ecount].epass);
	    getch();
	    goto ad ;
	    break;

   case 2:  cleardevice();
	    pr_tab(1);
	    settextstyle(1,0,5);
	    setcolor(4);
	    outtextxy(100,50,"ALL MONITOR'S DETAILS");

	   settextstyle(2,0,6);
	   for(i=0;i<=ecount;i++)
	   {
	     int k=0;
	     setcolor(1);
	     outtextxy(30+(k*126),142+(textheight("y")*(i+1))+5,emp[i].ename);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,emp[i].erole);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,emp[i].ephone);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,emp[i].eemail);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,emp[i].eloginName);

	    }
	    getch();
	    goto ad;
	    break;
   case 3:  cleardevice();
	    pr_tab(2);
	    settextstyle(1,0,5);
	    setcolor(4);
	    outtextxy(100,50,"ALL PROSPECT DETAILS");

	   settextstyle(2,0,6);
	   for(i=0;i<=pcount;i++)
	   {
	     int k=0;
	     setcolor(1);
	     outtextxy(30+(k*126),142+(textheight("y")*(i+1))+5,pro[i].pname);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,pro[i].pstatus);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,pro[i].pphone);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,pro[i].pemail);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,pro[i].padd);

	   }

	   getch();
	   goto ad;
	   break;

  case 4:  cleardevice();
	   layout();
	   settextstyle(1,0,5);
	   setcolor(4);
	   outtextxy(180,50,"CHANGING PASSWORD");
	   setcolor(1);
	   settextstyle(7,0,2);
	   outtextxy(180,250,"ENTER OLD PASSWORD  :");
	   char old[11];
	   input(460,250,old);
	   if(!strcmp(old,emp[j].epass))
	   {
	   strcpy( emp[j].epass,NULL);
	    setcolor(1);
	    settextstyle(7,0,2);
	    outtextxy(180,290,"ENTER NEW PASSWORD :");
	    input(460,290,emp[j].epass);
	    outtextxy(180,350,"PASSWORD CHANGED SUCCESSFULLY ! ! !");


	   }
	   else  outtextxy(180,350,"WRONG PASSWORD ENTERED ! ! !");
	   getch();
	   goto ad;
	   break;
  case 5:  cleardevice();
	   layout();
	   settextstyle(1,0,5);
	   setcolor(4);
	   outtextxy(180,50," DELETE PROSPECT ");
	   setcolor(1);
	   settextstyle(7,0,2);
	   outtextxy(150,150,"ENTER NAME :");
	   char n[11];
	   int f1=0;
	   input(350,150,n);
	    for(i=1;i<=pcount;i++)
	    {

	      if(!strcmp(n,pro[i].pname))
	     {             f1=1;
			   settextstyle(2,0,5);
			   outtextxy(150,180,"PROSPECT DETAILS");
			   settextstyle(7,0,2);
			   setcolor(1);

			   outtextxy(150,200,"NAME     :");

			   outtextxy(150,230,"STATUS   :");

			   outtextxy(150,260,"PHONE NO.:");

			   outtextxy(150,290,"ADDRESS  :");

			   outtextxy(150,320,"EMAIL    :");
			   setcolor(9);
			   outtextxy(300,200,pro[i].pname);
			   outtextxy(300,230,pro[i].pstatus);
			   outtextxy(300,260,pro[i].pphone);
			   outtextxy(300,290,pro[i].padd);
			   outtextxy(300,320,pro[i].pemail);

			   setcolor(1);
			   outtextxy(100,380,"WANT TO DELETE THIS RECORD(y/n)? : ");
			   char ch1[2];
			   input(550,380,ch1) ;
			   if(!strcmp(ch1,"y"))
			   {


			    outtextxy(130,420,"RECORD DELETED SUCCESSFULLY !!!!!");
			    for(;i<=pcount;i++)
			    {
			       pro[i]=pro[i+1] ;

			    }
			    --pcount;
			    break;
			    }
			    else
			    goto ad;
	     }
	    }

	   if(f1==0)
	    outtextxy(150,350,"PROSPECT NOT FOUND !!!!!!");

	   getch();
	   goto ad;
	   break;
  case 6:  break;





 }
}
/*******************MONITOR PAGE*************************/
void monitor_s(employee emp[],int j)
{
  pro:
  cleardevice();
  layout();

  settextstyle(1,0,5);
  setcolor(4);
  outtextxy(100,50,"PROSPECT MONITOR HOME");
  settextstyle(2,0,5);
  setcolor(LIGHTRED);
  outtextxy(250,150,"WELCOME MONITOR : Mr./Mrs.") ;
  char s[11];
  char s1[11];
  strcpy(s1,emp[j].ename);
   for(int i=0; s1[i]!='\0';i++)
  {
   s[i]=toupper(s1[i]);
  }
  s[i]='\0';
  outtextxy(450,150,s);
  setlinestyle(DOTTED_LINE,0,2);
  line(230,155+(textheight("W")),500,155+(textheight("W")));

  int tot_op=6;
  main_menu(tot_op,'P');
  switch(selected)
  {
   case 1:cleardevice();
	   layout();
	   ++pcount;
	   settextstyle(1,0,5);
	   setcolor(4);
	   outtextxy(150,50,"ADD NEW PROSPECT");
	   setcolor(1);
	   settextstyle(7,0,2);
	   outtextxy(150,150,"FULL NAME :");
	   input(300,150,pro[pcount].pname);
	   setcolor(1);
	   outtextxy(150,190,"STATUS(hot/warm/cold) :") ;
	   input(450,190,pro[pcount].pstatus);
	    setcolor(1);
	    outtextxy(150,220,"PHONE NO. :");
	   input(300,220,pro[pcount].pphone);
	   setcolor(1);
	   outtextxy(150,250,"EMAIL :") ;
	   input(300,250,pro[pcount].pemail);
	   setcolor(1);
	   outtextxy(150,280,"ADDRESS :") ;
	   input(300,280,pro[pcount].padd);

	   setcolor(9);
	   outtextxy(150,350,"PROSPECT ADDED SUCCESSFULLY!!! ");
	    getch();
	    goto pro;
	    break;
   case 2: cleardevice();
	    pr_tab(2);
	    settextstyle(1,0,5);
	    setcolor(4);
	    outtextxy(100,50,"ALL PROSPECT DETAILS");

	   settextstyle(2,0,6);
	   for(i=0;i<=pcount;i++)
	   { int k=0;
	     setcolor(1);
	     outtextxy(30+(k*126),142+(textheight("y")*(i+1))+5,pro[i].pname);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,pro[i].pstatus);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,pro[i].pphone);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,pro[i].pemail);
	     outtextxy(30+((++k)*126),142+(textheight("y")*(i+1))+5,pro[i].padd);

	   }

	   getch();
	   goto pro;
	   break;
   case 3: cleardevice();
	   sch:
	   layout();
	   settextstyle(1,0,5);
	   setcolor(4);
	   outtextxy(180,50,"SEARCH PROSPECT");
	   setcolor(1);
	   settextstyle(7,0,2);
	   outtextxy(200,250,"1. SEARCH BY PROSPECT NAME");
	   outtextxy(200,290,"2. SEARCH BY PROSPECT STATUS");

	   settextstyle(2,0,6);
	   setcolor(9);
	   outtextxy(200,350,"ENTER YOUR CHOICE  ");
	   gotoxy(30,30);
	   char choice=getch();

	   switch(choice)
	   {
	     case '1':
		       cleardevice();
		       layout();
		       settextstyle(1,0,5);
		       setcolor(4);
		       outtextxy(180,50,"SEARCH BY NAME");
		       setcolor(1);
		       settextstyle(7,0,2);
		       outtextxy(150,150,"ENTER PROSPECT NAME:");

		       char name[11];
		       int f=0;
		       input(450,150,name);
			for(int i=1;i<=pcount;i++)
		       {
			 if(!strcmp(name,pro[i].pname))
			 {
			   f=1;
			   cleardevice();
			   layout();
			   settextstyle(1,0,5);
			   setcolor(4);
			   outtextxy(180,50,"SEARCH BY NAME");
			   settextstyle(7,0,2);
			   setcolor(1);
			   outtextxy(150,180,"NAME     :");

			   outtextxy(150,220,"STATUS   :");

			   outtextxy(150,260,"PHONE NO.:");

			   outtextxy(150,300,"ADDRESS  :");

			   outtextxy(150,340,"EMAIL    :");
			   setcolor(9);
			   outtextxy(300,180,pro[i].pname);
			   outtextxy(300,220,pro[i].pstatus);
			   outtextxy(300,260,pro[i].pphone);
			   outtextxy(300,300,pro[i].padd);
			   outtextxy(300,340,pro[i].pemail);
			 }
		       }
		       if (f==0)
		       {
			 outtextxy(150,350,"PROSPECT NOT FOUND !!!!");
			 getch();
			 goto pro;
		       }
			getch();
			goto pro;
			break;
	     case '2':  cleardevice();
			layout();
			settextstyle(1,0,5);
			setcolor(4);
			outtextxy(180,50,"SEARCH BY STATUS");
			setcolor(1);
			settextstyle(7,0,2);
			outtextxy(150,150,"ENTER PROSPECT'S STATUS:");

			char st[11];

			input(480,150,st);

			pr_tab(2);
			settextstyle(1,0,5);
			setcolor(4);
			outtextxy(100,50," PROSPECTS DETAILS");
			settextstyle(2,0,6);
			for( i=1, j=0;i<=pcount;i++)
		       {
			 if(!strcmp(st,pro[i].pstatus))
			 {
			     int k=0;
			     setcolor(1);
			     outtextxy(30+(k*126),142+(textheight("y")*(j+1))+5,pro[i].pname);
			     outtextxy(30+((++k)*126),142+(textheight("y")*(j+1))+5,pro[i].pstatus);
			     outtextxy(30+((++k)*126),142+(textheight("y")*(j+1))+5,pro[i].pphone);
			     outtextxy(30+((++k)*126),142+(textheight("y")*(j+1))+5,pro[i].pemail);
			     outtextxy(30+((++k)*126),142+(textheight("y")*(j+1))+5,pro[i].padd);
			     setcolor(12);

			     j++;
			 }
		       }
			getch();
			goto pro;
			break;
	     default :
			setcolor(BLUE);
			settextstyle(2,0,5);
			outtextxy(200,390," WRONG CHOICE ! ! ! ! !  ENTER AGAIN......") ;
			getch();
			cleardevice();
			goto sch;

			break;


	   }
	   goto pro;
	   break;
   case 4: cleardevice();
	   layout();
	   settextstyle(1,0,5);
	   setcolor(4);
	   outtextxy(180,50,"CHANGING PASSWORD");
	   setcolor(1);
	   settextstyle(7,0,2);
	   outtextxy(180,250,"ENTER OLD PASSWORD :");
	   char old[11];
	   input(450,250,old);
	   if(!strcmp(old,emp[j].epass))
	   {
	    strcpy( emp[j].epass,NULL);
	    setcolor(1);
	    settextstyle(7,0,2);
	    outtextxy(180,290,"ENTER NEW PASSWORD :");
	    input(450,290,emp[j].epass);
	    outtextxy(180,350,"PASSWORD CHANGED SUCCESSFULLY ! ! !");


	   }
	   else  outtextxy(180,350,"WRONG PASSWORD ENTERED ! ! !");
	   getch();
	   goto pro;
	   break;
   case 5: cleardevice();
	   layout();
	   settextstyle(1,0,4);
	   setcolor(4);
	   outtextxy(130,50,"UPDATE PROSPECT'S PHONE NO");
	   setcolor(1);
	   settextstyle(7,0,2);
	   outtextxy(150,250,"ENTER PROSPECT'S NAME :");
	   char name[11];
	   int flag=0;
	   input(480,250,name);
	   for(int i=1;i<=pcount;i++)
	   {
	    if(!strcmp(name,pro[i].pname))
	   {
	    strcpy( pro[i].pphone,NULL);
	    setcolor(1);
	    settextstyle(7,0,2);
	    outtextxy(150,290,"ENTER NEW PHONE NO. :");
	    input(480,290,pro[i].pphone);
	    outtextxy(150,350,"PHONE NO. UPDATED SUCCESSFULLY ! ! !");
	    flag=1;

	   }
	   }
	   if( flag==0)  outtextxy(180,350,"WRONG NAME ENTERED ! ! !");
	   getch();
	   goto pro;
	   break;
  case 6:
	  break;




  }


}
/************************TO PRINT DETAILS IN TABLE FORMAT*************/

void pr_tab(int n)
{

 cleardevice();
 setbkcolor(11);
 setfillstyle(INTERLEAVE_FILL,12);
 bar(0,30,getmaxx(),130);
 setcolor(12);
 setlinestyle(SOLID_LINE,0,2);
 rectangle(0,30,getmaxx(),130);
 rectangle(10,40,getmaxx()-10,120);
 rectangle(10,120,getmaxx()-10,getmaxy()-10);
 for(int i=1;i<5;i++)
 line(10+(i*125),130,10+(i*125),getmaxy()-10);
 char det1[5][11]={
	      "FULL NAME",
	      "ROLE",
	      "PHONE",
	      "EMAIL",
	      "LOGIN NAME"
	      };
 char det2[5][11]={
	      "FULL NAME",
	      "STATUS",
	      "PHONE",
	      "EMAIL",
	      "ADDRESS"
	      };

switch(n)
{
case 1:  for(i=1;i<=5;i++)
	{
	 settextstyle(2,0,5);
	 setcolor(9);
	 outtextxy(40+((i-1)*126),135,det1[i-1]);
	}
	   break;
case 2: for(i=1;i<=5;i++)
	{
	 settextstyle(2,0,5);
	 setcolor(9);
	 outtextxy(40+((i-1)*126),135,det2[i-1]);
	}
	   break;
}
  setcolor(12);
  line(10,137+textheight("F"),getmaxx()-10,137+textheight("F"));
}