#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<graphics.h>
class KMAP
{
    int storage[20][9];
    int value[16][4];
    int storpoi;
    int a[4][4];
    char exp[100];

   public:
    int ans_page_sop();
    int ans_page_pos();
    int intro();
    int background();
    void graphics();
    KMAP();
    void output2();
    int indata2();
    int indata1();
    void val();
    void store_octet();
    void chck1(int);
    void store_quad();
    void store_pair();
    void generate_exp2();
    void generate_exp1();
    void output1();
    void solve_kmap()
    {
	store_octet();
	store_quad();
	store_pair();
	assign_redundant();
    }
    int check_re(int, int, int, int);
    void assign_redundant()
    {
      chck1(4);
      chck1(2);
    }
};
int KMAP:: ans_page_pos()
{
  cleardevice();
  int driver=DETECT,mode;
  initgraph(&driver,&mode,"c:\\TURBOC3\\BGI");
  settextstyle(1,0,2);
  outtextxy(50,0,"Your K-map looks like:");
  settextstyle(1,0,2);
  setcolor(2);
  outtextxy(80,35,"OCTATE: GREEN ");
  setcolor(14);
  outtextxy(80,60,"QUAD: YELLOW");
  setcolor(6);
  outtextxy(80,85,"PAIR: BROWN");
  moveto(225,180);
  setcolor(3);
  rectangle(225,140,275,190);
  rectangle(275,140,325,190);
  rectangle(325,140,375,190);
  rectangle(375,140,425,190);
  rectangle(225,190,275,240);
  rectangle(275,190,325,240);
  rectangle(325,190,375,240);
  rectangle(375,190,425,240);
  rectangle(225,240,275,290);
  rectangle(275,240,325,290);
  rectangle(325,240,375,290);
  rectangle(375,240,425,290);
  rectangle(225,290,275,340);
  rectangle(275,290,325,340);
  rectangle(325,290,375,340);
  rectangle(375,290,425,340);
  settextstyle(0,0,1);

  outtextxy(190,160,"X+Y");
  outtextxy(190,210,"X+Y' ");
  outtextxy(177,260," X'+Y' ");
  outtextxy(180,310," X'+Y ");
  outtextxy(240,130,"Z+W");
  outtextxy(288,130,"Z+W'");
  outtextxy(328,130," Z'+W' ");
  outtextxy(378,130," Z'+W ");
  int x=254,y=155;
  settextstyle(1,0,2);
   for(int i=0;i<4;i++)
    {
       for(int j=0;j<4;j++)
	{     if(a[i][j]==1)
		      outtextxy(x+(j*50),y+(50*i),"0");
	      else
		      outtextxy(x+(j*50),y+(50*i),"1");
	}

    }

  setcolor(15);
  outtextxy(50,360,"ANSWER IS:");
  outtextxy(200,360,exp);
  settextstyle(1,0,1);
  outtextxy(50,400,"1. RETURN");
  outtextxy(50,420,"2. EXIT");
  outtextxy(50,440,"YOUR CHOICE: ");
  int l;
s: gotoxy(25,25);
  cin>>l;
  if(l!=1 && l!=2)
    {
       outtextxy(150,420,"WRONG CHOICE! YOU HAVE 1 MORE TRY");
       goto s;
    }
  cleardevice();
  return l;
}
int KMAP:: indata2()
{     cleardevice();
      int x,i,b[16],r,c,s;
      cout<<"\n Enter the number of 1's term: ";
      cin>>x;
      for(i=0;i<x;i++)
      {
	 cout<<"\n Enter the positions of 1's: ";
	 cin>>b[i];
      }

      for(i=0;i<x;i++)
      {
	 r=(b[i])/4;
	 if(b[i]>=8 && b[i]<=11)
	      r++;
	 else if(b[i]>=12 && b[i]<=15)
	      r--;
	 c=(b[i])%4;
	 if(c==3)
	      c--;
	 else if(c==2)
	      c++;
	 a[r][c]=1;
      }

      for(i=0;i<4;i++)
      {
	 for(int j=0;j<4;j++)
	     s=s+a[i][j];
      }
      if(s==16)
	  return 1;
      else
	  return 0;
   }

void KMAP:: generate_exp2()
{     cleardevice();
      int quad=0,pair=0,octate=0;
      for(int i=0;i<storpoi;i++)
      {
	  int c=0;
	  for(int j=0;j<8;j++)
	  {
	       if(storage[i][j]!=-1)
	       {
		       c++;
	       }
	       else
		 break;
	  }
	 if(c==8)
	     octate++;
	 else if(c==4)
	     quad++;
	 else if(c==2)
	     pair++;
     }

     char s[50]="\0";
     int t1,t2,t3,t4,t5,t6,t7,t8, z;

     for(i=0;i<octate;i++)
     {
	t1=storage[i][0];
	t2=storage[i][1];
	t3=storage[i][2];
	t4=storage[i][3];
	t5=storage[i][4];
	t6=storage[i][5];
	t7=storage[i][6];
	t8=storage[i][7];
	strcat(s,"( ");
	for(int j=0;j<4;j++)
	{
	   z=value[t1][j];
	   if(z==value[t2][j] && z==value[t3][j] && z==value[t4][j] && z==value[t5][j] && z==value[t6][j] && z==value[t7][j] && z==value[t8][j])
	   {
	      if(j==0)
	      {
		 if(z==0)
		     strcat(s,"X'");
		 else if(z==1)
		     strcat(s,"X");
	      }

	      if(j==1)
	      {
		 if(z==0)
		     strcat(s,"Y'");
		 else if(z==1)
		     strcat(s,"Y");
	      }

	      if(j==2)
	      {
		 if(z==0)
		     strcat(s,"Z'");
		 else if(z==1)
		     strcat(s,"Z");
	      }

	      if(j==3)
	      {
		 if(z==0)
		     strcat(s,"W'");
		 else if(z==1)
		     strcat(s,"W");
	      }

	   }
	}
	 strcat(s," )+");

    }

    strcat(s,"\0");

    for(i=octate;i<quad;i++)
    {
	if(storage[i][8]==-1)
	{  strcat(s,"( ");
	   int t1,t2,t3,t4;
	   t1=storage[i][0];
	   t2=storage[i][1];
	   t3=storage[i][2];
	   t4=storage[i][3];
	   for(int j=0;j<4;j++)
	   {
	      if(value[t1][j]==value[t2][j] && value[t1][j]==value[t3][j] && value[t1][j]==value[t4][j])
	      {

		 if(j==0)
		 {
		    if(value[t1][j]==0)
			strcat(s,"X'");
		    else if(value[t1][j]==1)
			strcat(s,"X");
		 }

		 if(j==1)
		 {
		    if(value[t1][j]==0)
			strcat(s,"Y'");
		    else if(value[t1][j]==1)
			strcat(s,"Y");
		 }

		 if(j==2)
		 {
		    if(value[t1][j]==0)
			strcat(s,"Z'");
		    else if(value[t1][j]==1)
			strcat(s,"Z");
		 }

		 if(j==3)
		 {
		    if(value[t1][j]==0)
			 strcat(s,"W'");
		    else if(value[t2][j]==1)
			 strcat(s,"W");
		 }

	      }

	   }
	   strcat(s," )+");
	}
    }
    strcat(s,"\0");

    for(i=quad+octate;i<quad+octate+pair;i++)
    {
       if(storage[i][8]==-1)
       {
	 int t1,t2;
	 t1=storage[i][0];
	 t2=storage[i][1];

	 for(int j=0;j<4;j++)
	 {
	   if(value[t1][j]==value[t2][j])
	   {
		   if(j==0)
		   {
		    if(value[t1][j]==0)
			strcat(s,"X'");
		    else if(value[t1][j]==1)
			strcat(s,"X");
		   }

		   if(j==1)
		   {
		     if(value[t1][j]==0)
			 strcat(s,"Y'");
		     else if(value[t1][j]==1)
			 strcat(s,"Y");
		   }

		   if(j==2)
		   {
		      if(value[t1][j]==0)
			 strcat(s,"Z'");
		      else if(value[t1][j]==1)
			 strcat(s,"Z");
		   }

		  if(j==3)
		  {
		     if(value[t1][j]==0)
			 strcat(s,"W'");
		     else if(value[t2][j]==1)
			 strcat(s,"W");
		   }

	    }

	  }
	  strcat(s," )+");
       }
    }
    strcat(s,"\0");
    int k=strlen(s);
    s[k-1]='\0';
    cout<<s;
    strcpy(exp,s);
    cleardevice();
    getch();
}

int KMAP::indata1()
{
    cleardevice();
    int x,i,b[16],r,c,s;
    cout<<"\n Enter the number of 0's term: ";
    cin>>x;
    for(i=0;i<x;i++)
    {
       cout<<"\n Enter the positions of 0's: ";
       cin>>b[i];
    }

    for(i=0;i<x;i++)
    {
       r=(b[i])/4;
       if(b[i]>=8 && b[i]<=11)
	    r++;
       else if(b[i]>=12 && b[i]<=15)
	    r--;
       c=(b[i])%4;
       if(c==3)
	    c--;
       else if(c==2)
	    c++;
       a[r][c]=1;
    }

    for(i=0;i<4;i++)
    {
       for(int j=0;j<4;j++)
	     s=s+a[i][j];
    }

    if(s==16)
	  return 1;
    else
	  return 0;
}

int KMAP:: intro()
{
   cleardevice();
   putpixel(50,50,GREEN);
   settextstyle(1,0,3);
   outtextxy(250,50,"INTRODUCTION");
   settextstyle(0,0,1);
   outtextxy(50,150,"Karnaugh map (K-map) is a method of simplifying Boolean algebra ");
   outtextxy(50,160,"expressions.We can minimize Boolean expressions of 4-5 variables");
   outtextxy(50,170,"very easily using K-map without using any Boolean algebra theorems.");
   outtextxy(50,180,"K-map can take two forms Sum of Product (SOP) and Product of Sum (POS)");
   outtextxy(50,190,"according to the need of problem. K-map is table like representation ");
   outtextxy(50,200,"but it gives more information than truth table. We fill grid of ");
   outtextxy(50,210,"K-map with 0's and 1's then solve it by making groups.");
   settextstyle(1,0,1);
   outtextxy(50,340,"1.BACK");
   outtextxy(50,360,"2.EXIT");
   outtextxy(50,380,"ENTER YOUR CHOICE : ");
   int n;
s: gotoxy(33,25);
   cin>>n;
   if(n!=1 && n!=2)
   {  outtextxy(50,400,"WRONG CHOICE! YOU HAVE 1 MORE TRY");
      goto s;
   }
   getch();
   cleardevice();
   return n;

}

int  KMAP::ans_page_sop()
{
  cleardevice();
  settextstyle(1,0,2);
  outtextxy(50,0,"Your K-map looks like:");
  settextstyle(1,0,2);
  setcolor(2);
  outtextxy(80,35,"OCTATE: GREEN ");
  setcolor(14);
  outtextxy(80,60,"QUAD: YELLOW");
  setcolor(6);
  outtextxy(80,85,"PAIR: BROWN");
  moveto(225,180);
  setcolor(3);
  rectangle(225,140,275,190);
  rectangle(275,140,325,190);
  rectangle(325,140,375,190);
  rectangle(375,140,425,190);
  rectangle(225,190,275,240);
  rectangle(275,190,325,240);
  rectangle(325,190,375,240);
  rectangle(375,190,425,240);
  rectangle(225,240,275,290);
  rectangle(275,240,325,290);
  rectangle(325,240,375,290);
  rectangle(375,240,425,290);
  rectangle(225,290,275,340);
  rectangle(275,290,325,340);
  rectangle(325,290,375,340);
  rectangle(375,290,425,340);
  settextstyle(0,0,1);
  outtextxy(190,160,"X'Y'");
  outtextxy(190,210,"X'Y ");
  outtextxy(190,260," XY ");
  outtextxy(190,310," XY'");
  outtextxy(240,130,"Z'W'");
  outtextxy(290,130,"Z'W ");
  outtextxy(340,130," ZW ");
  outtextxy(390,130," ZW'");
  int x=245,y=155;
  settextstyle(0,0,2);
  setcolor(15);
  for(int i=0;i<4;i++)
    {
       for(int j=0;j<4;j++)
	{     if(a[i][j]==1)
		      outtextxy(x+(j*50),y+(50*i),"1");
	      else
		      outtextxy(x+(j*50),y+(50*i),"0");
	}

    }

  settextstyle(1,0,2);
  setcolor(15);
  outtextxy(50,360,"ANSWER IS:");
  outtextxy(200,360,exp);
  settextstyle(1,0,1);
  outtextxy(50,400,"1. RETURN");
  outtextxy(50,420,"2. EXIT");
  outtextxy(50,440,"YOUR CHOICE: ");
  int l;
  gotoxy(26,26);
  cin>>l;
  cleardevice();
  return l;
}

int KMAP:: background()
{
   int n;
   cleardevice();
   setbkcolor(0);
   setcolor(5);

   settextstyle(1,0,4);
   outtextxy(50,80,"  WELCOME TO K-MAP SIMPLIFIER");

   settextstyle(0,0,2);
   setcolor(15);
   outtextxy(50,180,"1. INTRODUCTION");
   outtextxy(50,230,"2. SUM OF PRODUCT FORM");
   putpixel(50,275,GREEN);
   outtextxy(50,280,"3. PRODUCT OF SUM FORM");
   outtextxy(50,330,"4. EXIT");
   outtextxy(50,385,"ENTER YOUR CHOICE: ");
s: gotoxy(45,25);
   cin>>n;
   return n;
}

void KMAP::graphics()
{
  cleardevice();
  line(0,0,638,0);
  line(0,0,0,478);
  line(638,0,638,478);
  line(0,478,638,478);
  settextstyle(1,0,5);
  outtextxy(50,50,"KARNAUGH MAP SIMPLIFIER");

  moveto(75,200);
  rectangle(80,200,130,250);
  rectangle(130,200,180,250);
  rectangle(180,200,230,250);
  rectangle(230,200,280,250);
  rectangle(80,250,130,300);
  rectangle(130,250,180,300);
  rectangle(180,250,230,300);
  rectangle(230,250,280,300);
  rectangle(80,300,130,350);
  rectangle(130,300,180,350);
  rectangle(180,300,230,350);
  rectangle(230,300,280,350);
  rectangle(80,350,130,400);
  rectangle(130,350,180,400);
  rectangle(180,350,230,400);
  rectangle(230,350,280,400);
  settextstyle(0,0,1);
  outtextxy(50,225,"X'Y'");
  outtextxy(50,275,"X'Y ");
  outtextxy(45,325," XY ");
  outtextxy(45,375," XY'");
  outtextxy(90,190,"Z'W'");
  outtextxy(140,190,"Z'W");
  outtextxy(190,190," ZW ");
  outtextxy(240,190," ZW'");

  rectangle(400,200,450,250);
  rectangle(450,200,500,250);
  rectangle(500,200,550,250);
  rectangle(550,200,600,250);
  rectangle(400,250,450,300);
  rectangle(450,250,500,300);
  rectangle(500,250,550,300);
  rectangle(550,250,600,300);
  rectangle(400,300,450,350);
  rectangle(450,300,500,350);
  rectangle(500,300,550,350);
  rectangle(550,300,600,350);
  rectangle(400,350,450,400);
  rectangle(450,350,500,400);
  rectangle(500,350,550,400);
  rectangle(550,350,600,400);
  outtextxy(370,225,"X+Y");
  outtextxy(370,275,"X+Y'");
  outtextxy(360,325,"X'+Y'");
  outtextxy(365,375,"X'+Y");
  putpixel(425,190,GREEN);
  outtextxy(415,190,"Z+W");
  outtextxy(460,190,"Z+W'");
  outtextxy(510,190,"Z'+W'");
  outtextxy(560,190,"Z'+W");
  getch();
}

KMAP::KMAP()
{
   val();
   exp[100]='\0';
   storpoi=0;
   for(int i=0;i<20;i++)
   {
      for (int j=0;j<9; j++)
      {
	  storage[i][j]=-1;
      }
   }
   for(i=0;i<4;i++)
   {
      for (int j=0;j<4; j++)
      {
	  a[i][j]=0;
      }
   }
}

void KMAP::output1()
{
     generate_exp1();
     getch();
}
void KMAP::output2()
{
     generate_exp2();
     getch();
}


void KMAP::val()
{
    for(int i=0;i<16;i++)
    {
       for(int j=0;j<4;j++)
       {
	    value[i][j]=0;
       }
    }
    for(i=0; i<=15; i++)
    {
       int k=i,j=3;
       while(k>0)
       {
	   value[i][j]=k%2;
	   k=k/2;
	   j--;
       }
    }
}

int KMAP::check_re(int i, int j, int st, int en)
{
   int p,o;
   for(p=st;p<en;p++)
   {
      if(storage[p][8] !=99)
      {
	 for(o=0;o<8;o++)
	 {
	    if(storage[p][0]!=-1 && storage[i][j]==storage[p][o])
	       return 1;
	 }
      }
   }
   return 0;
}

void KMAP::chck1(int m)
{
    int c=0,j,flag=0;
    for(int i=storpoi-1; i>=0; i--)
    {   flag=0;
	c=0;
	for(j=0; j<9; j++)
	 {
	     if(storage[i][j]==-1 && j==m)
	     {    flag=1;
		  break;
	      }
	 }
	 if(flag == 1)
	 {  int ch=0;
	    for(j=0;j<m;j++)
	    {  if(i != storpoi-1)
	       {
		   ch=check_re(i,j,0,i);
		   if(ch!=1)
		     ch=check_re(i,j,i+1,storpoi);
	       }
	       else
		   ch=check_re(i,j,0,i);
	      c+=ch;
	      ch=0;
	   }
	   if(c==m)
	     storage[i][8]=99;
	 }
     }
}

void KMAP::store_octet()
{
  for(int i=0;i<4;i++)
  {
    int c=0;
    for(int j=0;j<4;j++)
    {
      if(i==3)
      {
	 if(a[i][j]==1 && a[0][j]==1)
	     c++;
      }
      else if(a[i][j]==1 && a[i+1][j]==1)
	 c++;
    }
    if(c==4)
    {
       if(i==0)
       {
	  storage[storpoi][0]=0;
	  storage[storpoi][1]=1;
	  storage[storpoi][2]=3;
	  storage[storpoi][3]=2;
	  storage[storpoi][4]=4;
	  storage[storpoi][5]=7;
	  storage[storpoi][6]=5;
	  storage[storpoi][7]=6;
	  storpoi++;
       }

       else if(i==1)
       {
	  storage[storpoi][0]=4;
	  storage[storpoi][1]=5;
	  storage[storpoi][2]=7;
	  storage[storpoi][3]=6;
	  storage[storpoi][4]=12;
	  storage[storpoi][5]=13;
	  storage[storpoi][6]=14;
	  storage[storpoi][7]=15;
	  storpoi++;
       }

       else if(i==2)
       {
	  storage[storpoi][0]=11;
	  storage[storpoi][1]=10;
	  storage[storpoi][2]=9;
	  storage[storpoi][3]=8;
	  storage[storpoi][4]=12;
	  storage[storpoi][5]=13;
	  storage[storpoi][6]=15;
	  storage[storpoi][7]=14;
	  storpoi++;
       }

       else if(i==3)
       {
	  storage[storpoi][0]=8;
	  storage[storpoi][1]=9;
	  storage[storpoi][2]=11;
	  storage[storpoi][3]=10;
	  storage[storpoi][4]=0;
	  storage[storpoi][5]=1;
	  storage[storpoi][6]=2;
	  storage[storpoi][7]=3;
	  storpoi++;
       }
    }
  }

  for(i=0;i<4;i++)
  {
    int d=0;
    for(int j=0;j<4;j++)
    {
      if(i==3)
      {
	if(a[j][i]==1 && a[j][0] ==1)
		d++;
      }
      else if(a[j][i]==1 && a[j][i+1]==1)
	   d++;
    }
    if(d==4)
    {
       if(i==0)
       {
	  storage[storpoi][0]=0;
	  storage[storpoi][1]=1;
	  storage[storpoi][2]=4;
	  storage[storpoi][3]=5;
	  storage[storpoi][4]=12;
	  storage[storpoi][5]=13;
	  storage[storpoi][6]=8;
	  storage[storpoi][7]=9;
	  storpoi++;
       }

       else if(i==1)
       {
	  storage[storpoi][0]=1;
	  storage[storpoi][1]=3;
	  storage[storpoi][2]=7;
	  storage[storpoi][3]=5;
	  storage[storpoi][4]=15;
	  storage[storpoi][5]=13;
	  storage[storpoi][6]=11;
	  storage[storpoi][7]=9;
	  storpoi++;
       }

       else if(i==2)
       {
	  storage[storpoi][0]=2;
	  storage[storpoi][1]=3;
	  storage[storpoi][2]=7;
	  storage[storpoi][3]=6;
	  storage[storpoi][4]=15;
	  storage[storpoi][5]=14;
	  storage[storpoi][6]=11;
	  storage[storpoi][7]=10;
	  storpoi++;
       }

       else if(i==3)
       {
	  storage[storpoi][0]=0;
	  storage[storpoi][1]=2;
	  storage[storpoi][2]=4;
	  storage[storpoi][3]=6;
	  storage[storpoi][4]=12;
	  storage[storpoi][5]=14;
	  storage[storpoi][6]=8;
	  storage[storpoi][7]=10;
	  storpoi++;
       }
    }
  }
}

void KMAP::store_quad()
{
    for(int i=0;i<4;i++)
    {
       for(int j=0;j<4;j++)
       {
	  if(i==3)
	  {
	     if(j==0)
	     {
		if(a[i][j]==1 && a[i][j+1]==1 && a[0][j]==1 && a[0][j+1]==1)
		{
		   storage[storpoi][0]=8;
		   storage[storpoi][1]=9;
		   storage[storpoi][2]=0;
		   storage[storpoi][3]=1;
		   storpoi++;
		}
	     }

	     else if(j==1)
	     {
		if(a[i][j]==1 && a[i][j+1]==1 && a[0][j]==1 && a[0][j+1]==1)
		{
		   storage[storpoi][0]=11;
		   storage[storpoi][1]=9;
		   storage[storpoi][2]=3;
		   storage[storpoi][3]=1;
		   storpoi++;
		}
	     }

	     else if(j==2)
	     {
		if(a[i][j]==1 && a[i][j+1]==1 && a[0][j]==1 && a[0][j+1]==1)
		{
		   storage[storpoi][0]=11;
		   storage[storpoi][1]=10;
		   storage[storpoi][2]=2;
		   storage[storpoi][3]=3;
		   storpoi++;
		}
	     }

	     else if(j==3)
	     {
		if(a[i][j]==1 && a[i][0]==1 && a[0][j]==1 && a[0][0]==1)
		{
		   storage[storpoi][0]=8;
		   storage[storpoi][1]=10;
		   storage[storpoi][2]=0;
		   storage[storpoi][3]=2;
		   storpoi++;
		}
	     }

	  }

	  else
	  {
	     if(i==0)
	     {
		if(j==0)
		{
		   if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
		   {
		      storage[storpoi][0]=0 ;
		      storage[storpoi][1]=4;
		      storage[storpoi][2]=5;
		      storage[storpoi][3]=1;
		      storpoi++;
		   }
		}

		else if(j==1)
		{
		   if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
		   {
		      storage[storpoi][0]=7;
		      storage[storpoi][1]=5;
		      storage[storpoi][2]=3;
		      storage[storpoi][3]=1;
		      storpoi++;
		   }
		}

		else if(j==2)
		{
		   if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
		   {
		      storage[storpoi][0]=3;
		      storage[storpoi][1]=2;
		      storage[storpoi][2]=6;
		      storage[storpoi][3]=7;
		      storpoi++;
		   }
		}

		else if(j==3)
		{
		   if(a[i][j]==1 && a[i][0]==1 && a[i+1][j]==1 && a[i+1][0]==1)
		   {
		      storage[storpoi][0]=0;
		      storage[storpoi][1]=2;
		      storage[storpoi][2]=4;
		      storage[storpoi][3]=6;
		      storpoi++;
		   }
		}
	     }

	     if(i==1)
	     {
		if(j==0)
		{
		   if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
		   {
		      storage[storpoi][0]=12;
		      storage[storpoi][1]=13;
		      storage[storpoi][2]=4;
		      storage[storpoi][3]=5;
		      storpoi++;
		   }
		}

		else if(j==1)
		{
		   if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
		   {
		      storage[storpoi][0]=15;
		      storage[storpoi][1]=13;
		      storage[storpoi][2]=7;
		      storage[storpoi][3]=5;
		      storpoi++;
		   }
		}

		else if(j==2)
		{
		   if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
		   {
		      storage[storpoi][0]=7;
		      storage[storpoi][1]=6;
		      storage[storpoi][2]=15;
		      storage[storpoi][3]=14;
		      storpoi++;
		   }
		}

		else if(j==3)
		{
		   if(a[i][j]==1 && a[i][0]==1 && a[i+1][0]==1 && a[i+1][j]==1)
		   {
		      storage[storpoi][0]=14;
		      storage[storpoi][1]=12;
		      storage[storpoi][2]=4;
		      storage[storpoi][3]=6;
		      storpoi++;
		   }
		}
	     }

	     if(i==2)
	     {
		if(j==0)
		{
		   if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
		   {
		      storage[storpoi][0]=13;
		      storage[storpoi][1]=12;
		      storage[storpoi][2]=8;
		      storage[storpoi][3]=9;
		      storpoi++;
		   }
		}

		else if(j==1)
		{
		   if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
		   {
		      storage[storpoi][0]=13;
		      storage[storpoi][1]=15;
		      storage[storpoi][2]=11;
		      storage[storpoi][3]=9;
		      storpoi++;
		   }
		}

		else if(j==2)
		{
		   if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
		   {
		      storage[storpoi][0]=15;
		      storage[storpoi][1]=14;
		      storage[storpoi][2]=11;
		      storage[storpoi][3]=10;
		      storpoi++;
		   }
		}

		else if(j==3)
		{
		   if(a[i][j]==1 && a[i][0]==1 && a[i+1][0]==1 && a[i+1][j]==1)
		   {
		      storage[storpoi][0]=14;
		      storage[storpoi][1]=12;
		      storage[storpoi][2]=8;
		      storage[storpoi][3]=10;
		      storpoi++;
		   }
		}
	     }
	  }
       }
    }
    for(i=0;i<4;i++)
    {
       int c=0;
       for(int j=0;j<4;j++)
       {
	  if(a[i][j]==1)
	     c++;
       }
       if(c==4)
       {
	  if(i==0)
	  {
	     storage[storpoi][0]=0;
	     storage[storpoi][1]=1;
	     storage[storpoi][2]=2;
	     storage[storpoi][3]=3;
	     storpoi++;
	  }

	  if(i==1)
	  {
	     storage[storpoi][0]=4;
	     storage[storpoi][1]=5;
	     storage[storpoi][2]=7;
	     storage[storpoi][3]=6;
	     storpoi++;
	  }

	  if(i==2)
	  {
	     storage[storpoi][0]=12;
	     storage[storpoi][1]=13;
	     storage[storpoi][2]=15;
	     storage[storpoi][3]=14;
	     storpoi++;
	  }

	  if(i==3)
	  {
	     storage[storpoi][0]=8;
	     storage[storpoi][1]=9;
	     storage[storpoi][2]=11;
	     storage[storpoi][3]=10;
	     storpoi++;
	  }
       }
    }
    for(i=0;i<4;i++)
    {
       int c=0,j;
       for(j=0;j<4;j++)
       {
	  if(a[j][i]==1)
	     c++;
       }
       if(c==4)
       {
	  if(i==0)
	  {
	     storage[storpoi][0]=0;
	     storage[storpoi][1]=4;
	     storage[storpoi][2]=12;
	     storage[storpoi][3]=8;
	     storpoi++;
	  }

	  if(i==1)
	  {
	     storage[storpoi][0]=1;
	     storage[storpoi][1]=5;
	     storage[storpoi][2]=13;
	     storage[storpoi][3]=9;
	     storpoi++;
	  }

	  if(i==2)
	  {
	     storage[storpoi][0]=3;
	     storage[storpoi][1]=7;
	     storage[storpoi][2]=15;
	     storage[storpoi][3]=11;
	     storpoi++;
	  }

	  if(i==3)
	  {
	     storage[storpoi][0]=2;
	     storage[storpoi][1]=6;
	     storage[storpoi][2]=14;
	     storage[storpoi][3]=10;
	     storpoi++;
	  }
       }
    }
}

void KMAP::store_pair()
{
    if(a[0][0]==1 && a[0][1])
    {
       storage[storpoi][0]=0;
       storage[storpoi][1]=1;
       storpoi++;
    }
    if(a[0][1]==1 && a[0][2]==1)
    {
       storage[storpoi][0]=3;
       storage[storpoi][1]=1;
       storpoi++;
    }
    if(a[0][2]==1 && a[0][3]==1)
    {
       storage[storpoi][0]=2;
       storage[storpoi][1]=3;
       storpoi++;
    }
   if(a[0][0]==1 && a[0][3]==1)
   {
       storage[storpoi][0]=0;
       storage[storpoi][1]=2;
       storpoi++;
   }
   if(a[1][0]==1 && a[1][1]==1)
   {
       storage[storpoi][0]=4;
       storage[storpoi][1]=5;
       storpoi++;
   }

  if(a[1][1]==1 && a[1][2]==1)
  {
       storage[storpoi][0]=7;
       storage[storpoi][1]=5;
       storpoi++;
  }
  if(a[1][2]==1 && a[1][3]==1)
  {
       storage[storpoi][0]=7;
       storage[storpoi][1]=6;
       storpoi++;
  }
  if(a[1][0]==1 && a[1][3]==1)
  {
       storage[storpoi][0]=4;
       storage[storpoi][1]=6;
       storpoi++;
  }
  if(a[2][0]==1 && a[2][1]==1)
  {
       storage[storpoi][0]=12;
       storage[storpoi][1]=13;
       storpoi++;
  }
  if(a[2][1]==1 && a[2][2]==1)
  {
       storage[storpoi][0]=13;
       storage[storpoi][1]=15;
       storpoi++;
  }
  if(a[2][2]==1 && a[2][3]==1)
  {
       storage[storpoi][0]=14;
       storage[storpoi][1]=15;
       storpoi++;
  }
  if(a[2][0]==1 && a[2][3]==1)
  {
       storage[storpoi][0]=12;
       storage[storpoi][1]=14;
       storpoi++;
  }
  if(a[3][0]==1 && a[3][1]==1)
  {
       storage[storpoi][0]=8;
       storage[storpoi][1]=9;
       storpoi++;
  }
  if(a[3][1]==1 && a[3][2]==1)
  {
       storage[storpoi][0]=9;
       storage[storpoi][1]=11;
       storpoi++;
  }
  if(a[3][2]==1 && a[3][3]==1)
  {
       storage[storpoi][0]=10;
       storage[storpoi][1]=11;
       storpoi++;
  }
  if(a[3][0]==1 && a[3][3]==1)
  {
       storage[storpoi][0]=8;
       storage[storpoi][1]=10;
       storpoi++;
  }
  if(a[0][0]==1 && a[1][0]==1)
  {
       storage[storpoi][0]=0;
       storage[storpoi][1]=4;
       storpoi++;
  }
  if(a[1][0]==1 && a[2][0]==1)
  {
       storage[storpoi][0]=4;
       storage[storpoi][1]=12;
       storpoi++;
  }
 if(a[2][0]==1 && a[3][0]==1)
  {
       storage[storpoi][0]=12;
       storage[storpoi][1]=8;
       storpoi++;
  }
 if(a[0][0]==1 && a[3][0]==1)
  {
       storage[storpoi][0]=0;
       storage[storpoi][1]=8;
       storpoi++;
  }
 if(a[0][1]==1 && a[1][1]==1)
  {
       storage[storpoi][0]=1;
       storage[storpoi][1]=5;
       storpoi++;
  }
  if(a[1][1]==1 && a[2][1]==1)
  {
       storage[storpoi][0]=5;
       storage[storpoi][1]=13;
       storpoi++;
  }
  if(a[2][1]==1 && a[3][1]==1)
  {
       storage[storpoi][0]=13;
       storage[storpoi][1]=9;
       storpoi++;
  }
  if(a[0][1]==1 && a[3][1]==1)
  {
       storage[storpoi][0]=1;
       storage[storpoi][1]=9;
       storpoi++;
  }
  if(a[0][2]==1 && a[1][2]==1)
  {
       storage[storpoi][0]=3;
       storage[storpoi][1]=7;
       storpoi++;
  }
 if(a[1][2]==1 && a[2][2]==1)
  {
       storage[storpoi][0]=7;
       storage[storpoi][1]=15;
       storpoi++;
  }
  if(a[2][2]==1 && a[3][2]==1)
  {
       storage[storpoi][0]=15;
       storage[storpoi][1]=11;
       storpoi++;
  }
  if(a[0][2]==1 && a[3][2]==1)
  {
       storage[storpoi][0]=3;
       storage[storpoi][1]=11;
       storpoi++;
  }
  if(a[0][3]==1 && a[1][3]==1)
  {
       storage[storpoi][0]=2;
       storage[storpoi][1]=6;
       storpoi++;
  }
  if(a[1][3]==1 && a[2][3]==1)
  {
       storage[storpoi][0]=6;
       storage[storpoi][1]=14;
       storpoi++;
  }
  if(a[2][3]==1 && a[3][3]==1)
  {
       storage[storpoi][0]=14;
       storage[storpoi][1]=10;
       storpoi++;
  }
  if(a[0][3]==1 && a[3][3]==1)
  {
       storage[storpoi][0]=2;
       storage[storpoi][1]=10;
       storpoi++;
  }
}
void KMAP:: generate_exp1()
{
      int quad=0,pair=0,octate=0;
      for(int i=0;i<storpoi;i++)
      {
	  int c=0;
	  for(int j=0;j<8;j++)
	  {
	       if(storage[i][j]!=-1)
	       {
		       c++;
	       }
	       else
		 break;
	  }
	 if(c==8)
	     octate++;
	 else if(c==4)
	     quad++;
	 else if(c==2)
	     pair++;
     }

     char s[50]="\0";
     int t1,t2,t3,t4,t5,t6,t7,t8, z;

     for(i=0;i<octate;i++)
     {
	t1=storage[i][0];
	t2=storage[i][1];
	t3=storage[i][2];
	t4=storage[i][3];
	t5=storage[i][4];
	t6=storage[i][5];
	t7=storage[i][6];
	t8=storage[i][7];
	strcat(s,"( ");
	for(int j=0;j<4;j++)
	{
	   z=value[t1][j];
	   if(z==value[t2][j] && z==value[t3][j] && z==value[t4][j] && z==value[t5][j] && z==value[t6][j] && z==value[t7][j] && z==value[t8][j])
	   {
	      if(j==0)
	      {
		 if(z==0)
		     strcat(s,"X");
		 else if(z==1)
		     strcat(s,"X'");
	      }

	      if(j==1)
	      {
		 if(z==0)
		     strcat(s,"Y");
		 else if(z==1)
		     strcat(s,"Y'");
	      }

	      if(j==2)
	      {
		 if(z==0)
		     strcat(s,"Z");
		 else if(z==1)
		     strcat(s,"Z'");
	      }

	      if(j==3)
	      {
		 if(z==0)
		     strcat(s,"W");
		 else if(z==1)
		     strcat(s,"W'");
	      }
	    strcat(s,"+");
	   }
	}
	int n=strlen(s);
	s[n-1]=' ';
	strcat(s,").");
    }

    strcat(s,"\0");

    for(i=octate;i<quad;i++)
    {
	if(storage[i][8]==-1)
	{  strcat(s,"( ");
	   int t1,t2,t3,t4;
	   t1=storage[i][0];
	   t2=storage[i][1];
	   t3=storage[i][2];
	   t4=storage[i][3];
	   for(int j=0;j<4;j++)
	   {
	      if(value[t1][j]==value[t2][j] && value[t1][j]==value[t3][j] && value[t1][j]==value[t4][j])
	      {

		 if(j==0)
		 {
		    if(value[t1][j]==0)
			strcat(s,"X");
		    else if(value[t1][j]==1)
			strcat(s,"X'");
		 }

		 if(j==1)
		 {
		    if(value[t1][j]==0)
			strcat(s,"Y");
		    else if(value[t1][j]==1)
			strcat(s,"Y'");
		 }

		 if(j==2)
		 {
		    if(value[t1][j]==0)
			strcat(s,"Z");
		    else if(value[t1][j]==1)
			strcat(s,"Z'");
		 }

		 if(j==3)
		 {
		    if(value[t1][j]==0)
			 strcat(s,"W");
		    else if(value[t2][j]==1)
			 strcat(s,"W'");
		 }
	       strcat(s,"+");
	      }

	   }
	  int n=strlen(s);
	  s[n-1]=' ';
	   strcat(s,").");
	}
    }
    strcat(s,"\0");

    for(i=quad+octate;i<quad+octate+pair;i++)
    {
       if(storage[i][8]==-1)
       { strcat(s,"( ");
	 int t1,t2;
	 t1=storage[i][0];
	 t2=storage[i][1];

	 for(int j=0;j<4;j++)
	 {
	   if(value[t1][j]==value[t2][j])
	   {
		   if(j==0)
		   {
		    if(value[t1][j]==0)
			strcat(s,"X");
		    else if(value[t1][j]==1)
			strcat(s,"X'");
		   }

		   if(j==1)
		   {
		     if(value[t1][j]==0)
			 strcat(s,"Y");
		     else if(value[t1][j]==1)
			 strcat(s,"Y'");
		   }

		   if(j==2)
		   {
		      if(value[t1][j]==0)
			 strcat(s,"Z");
		      else if(value[t1][j]==1)
			 strcat(s,"Z'");
		   }

		  if(j==3)
		  {
		     if(value[t1][j]==0)
			 strcat(s,"W");
		     else if(value[t2][j]==1)
			 strcat(s,"W'");
		   }
		 strcat(s,"+");
	    }

	  }
	  int n=strlen(s);
	  s[n-1]=' ';
	  strcat(s,").");
       }
    }
    strcat(s,"\0");
    int k=strlen(s);
    s[k-1]='\0';
    cout<<s;
    strcpy(exp,s);
    getch();
}


void main()
{
    int n,l;
    int driver=DETECT,mode;
    initgraph(&driver,&mode,"c:\\TURBOC3\\BGI");

    KMAP k;
    k.val();
    k.graphics();
s:  n= k.background();
    switch(n)
    {
      case 1:   l= k.intro();
		if(l==1)
			goto s;
		if(l==2)
			break;

      case 2:   cleardevice();

		int i=k.indata2();
		if(i==0)
		 {
		     k.solve_kmap();
		     k.assign_redundant();
		     k.output2();
		     l=k.ans_page_sop();
		     if(l==1)
			   goto s;
		     else if(l==2)
			   break;
		}
		break;

     case 3:    cleardevice();

		i=k.indata1();
		if(i==0)
		{
		     k.solve_kmap();
		     k.assign_redundant();
		     k.output1();
		     l=k.ans_page_pos();
		     if(l==1)
			   goto s;
		     else if(l==2)
			   break;
		}
		break;

     case 4:    break;

     default:   outtextxy(0,400,"WRONG CHOICE! YOU HAVE 1 MORE TRY ");
		goto s;

    }

    getch();
    closegraph();
}
