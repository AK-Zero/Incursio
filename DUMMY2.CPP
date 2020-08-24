
       #include<iostream.h>
       #include<conio.h>
       #include<stdio.h>
       #include<dos.h>
       #include<graphics.h>
       #include<process.h>
       #include<string.h>
       #include<stdlib.h>
       #include<fstream.h>

    struct patt
  {
  int qwerty[9];
  int stat;
  };

  int score2;char cj;
    struct player {
  patt rto;
  int status;
  char name[20];
  char gamerid[20];
  int score;
  int x,y;
    }g;

  union REGS in,out;

int callmouse()
{
  in.x.ax=1;
  int86(51,&in,&out);
  return 1;
}

void mouseposi(int &xpos,int &ypos,int &click)
{

  in.x.ax=3;
  int86(51,&in,&out);
  click=out.x.bx;
  xpos=out.x.cx;
  ypos=out.x.dx;

}

void setposi(int &xpos,int &ypos)
{
  in.x.ax=4;
  in.x.cx=xpos;
  in.x.dx=ypos;
  int86(51,&in,&out);

}

int mousehide()
{
  in.x.ax=2;
  int86(51,&in,&out);
  return 1;
}

void akk(int x,int y)
{
  setcolor(BLUE);
  for(int i=60;i<=62;i++)
  circle(x,y,i);
  setcolor(YELLOW);
  for(i=70;i<78;i++)
  circle(x,y,i);
  setcolor(4);
  for(i=90;i<=98;i++)
  circle(x,y,i);
  setcolor(15);
  rectangle(x-5,y+110,x+5,y+120);
  setfillstyle(1,15);
  floodfill(x,y,BLUE);
}
void cicada(int x,int y,int j)
{
setcolor(j);
for(int h=0;h<20;h++)
circle(x,y,h);
}
void restrictmouseptr(int x1,int x2,int y1,int y2)
{
  in.x.ax=7;
  in.x.cx=x1;
  in.x.dx=x2;
  int86(51,&in,&out);
  in.x.ax=8;
  in.x.cx=y1;
  in.x.dx=y2;
  int86(51,&in,&out);
}
struct pop
{
  int x,y,z;
};
void symmetry()
{

  clrscr();
  ofstream fout("Kaka.dat",ios::binary);
  int x,y,cl,a,b;
  char ch;
  int g=DETECT,m;
  initgraph(&g,&m,"..\\bgi");
  setcolor(WHITE);
  line(320,75,320,500);
  line(321,75,321,500);
  line(322,75,322,500);
  line(323,75,323,500);
  line(0,75,640,75);
  line(0,74,640,74);
  line(0,73,640,73);
  line(0,72,640,72);
  line(0,71,640,71);
  setcolor(3);
  settextstyle(0,HORIZ_DIR,4);
  outtextxy(25,20,"Get Creative....");
  setcolor(15);
  for(int r=0;r<5;r++)
 {
  rectangle(r,r,639-r,479-r);
}
  setcolor(RED);
  line(610,450,630,470);
  line(610,450,590,470);
  line(600,460,620,460);
  line(610,460,600,470);
  line(610,460,620,470);//Logo
  line(610,450,620,440);
  line(620,440,630,450);
  line(630,450,620,460);
  line(610,450,600,440);
  line(600,440,590,450);
  line(590,450,600,460);
  line(600,460,580,460);

  a=100;
  b=400;
  randomize();
  int z=random(16);
  pop q;
  setposi(a,b);
  callmouse();
  restrictmouseptr(0,320,76,500);
do
{
  mouseposi(x,y,cl);
  q.x=x;q.y=y;q.z=0;
  gotoxy(1,1);
  if(cl==1)
{
  putpixel(x,y,z);
  putpixel(640-x,y,z);
  q.z=z;
}
  if(cl==2)
  z++;
  fout.write((char*)&q,sizeof(pop));
  if(kbhit())
  ch=getch();
}while(ch!=' ');

  mousehide();
  fout.close();
  getch();
  closegraph();
}
void symmetry2()
{
  clrscr();
  ifstream fin("Kaka.dat",ios::binary);
  int gf=DETECT,gd;
  initgraph(&gf,&gd,"..\\bgi");
  setcolor(WHITE);
  line(320,75,320,500);
  line(321,75,321,500);
  line(322,75,322,500);
  line(323,75,323,500);
  line(0,75,640,75);
  line(0,74,640,74);
  line(0,73,640,73);
  line(0,72,640,72);
  line(0,71,640,71);
  setcolor(12);
  settextstyle(0,HORIZ_DIR,4);
  outtextxy(25,20,"Your art....");
  setcolor(15);
  for(int r=0;r<5;r++)
 {
  rectangle(r,r,639-r,479-r);
}
  setcolor(RED);
  line(610,450,630,470);
  line(610,450,590,470);
  line(600,460,620,460);
  line(610,460,600,470);
  line(610,460,620,470);//Logo
  line(610,450,620,440);
  line(620,440,630,450);
  line(630,450,620,460);
  line(610,450,600,440);
  line(600,440,590,450);
  line(590,450,600,460);
  line(600,460,580,460);
  pop w;
  while(fin.read((char*)&w,sizeof(w)))
{
  putpixel(w.x,w.y,w.z);
  putpixel(640-w.x,w.y,w.z);

}
  fin.close();
  getch();
  closegraph();
}

void pattern()
{

clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");
setbkcolor(0);
setcolor(11);
settextstyle(0,HORIZ_DIR,4);
outtextxy(25,25,"Enter your Pattern");

setcolor(15);
for(int r=0;r<5;r++)
{rectangle(r,75+r,639-r,479-r);
}
setcolor(14);
for(int polo=0;polo<5;polo++)
{rectangle(200-polo,165-polo,420+polo,385+polo);
line(270+polo,165,270+polo,385);
line(345+polo,165,345+polo,385);
line(200,235+polo,420,235+polo);
line(200,310+polo,420,310+polo);
}
int x,y,cl;
char ch;

setposi(200,165);
callmouse();
restrictmouseptr(200,420,165,385);
do{

mouseposi(x,y,cl);
setcolor(2);
if(x>200&&x<270&&y>165&&y<235&&cl==1)
{
int op=1;
for(int ip=0;ip<=g.rto.stat;ip++)
if(g.rto.qwerty[ip]==1)
op=0;
if(op)
g.rto.qwerty[g.rto.stat++]=1;
cicada(235,200,12);
}
if(x>275&&x<345&&y>165&&y<235&&cl==1)
{
int op=1;
for(int ip=0;ip<=g.rto.stat;ip++)
if(g.rto.qwerty[ip]==2)
op=0;
if(op)
g.rto.qwerty[g.rto.stat++]=2;
cicada(310,200,12);
}
if(x>345&&x<420&&y>165&&y<235&&cl==1)
{
int op=1;
for(int ip=0;ip<=g.rto.stat;ip++)
if(g.rto.qwerty[ip]==3)
op=0;
if(op)
g.rto.qwerty[g.rto.stat++]=3;
cicada(385,200,12);
}
if(x>200&&x<270&&y>235&&y<310&&cl==1)
{
int op=1;
for(int ip=0;ip<=g.rto.stat;ip++)
if(g.rto.qwerty[ip]==4)
op=0;
if(op)
g.rto.qwerty[g.rto.stat++]=4;
cicada(235,270,12);
}
if(x>275&&x<345&&y>235&&y<310&&cl==1)
{
int op=1;
for(int ip=0;ip<=g.rto.stat;ip++)
if(g.rto.qwerty[ip]==5)
op=0;
if(op)
g.rto.qwerty[g.rto.stat++]=5;
cicada(310,270,12);
}
if(x>345&&x<420&&y>235&&y<310&&cl==1)
{
int op=1;
for(int ip=0;ip<=g.rto.stat;ip++)
if(g.rto.qwerty[ip]==6)
op=0;
if(op)
g.rto.qwerty[g.rto.stat++]=6;
cicada(385,270,12);
}
if(x>200&&x<270&&y>310&&y<385&&cl==1)
{
int op=1;
for(int ip=0;ip<=g.rto.stat;ip++)
if(g.rto.qwerty[ip]==7)
op=0;
if(op)
g.rto.qwerty[g.rto.stat++]=7;
cicada(235,350,12);
}
if(x>275&&x<345&&y>310&&y<385&&cl==1)
{
int op=1;
for(int ip=0;ip<=g.rto.stat;ip++)
if(g.rto.qwerty[ip]==8)
op=0;
if(op)
g.rto.qwerty[g.rto.stat++]=8;
cicada(310,350,12);
}
if(x>345&&x<420&&y>310&&y<385&&cl==1)
{
int op=1;
for(int ip=0;ip<=g.rto.stat;ip++)
if(g.rto.qwerty[ip]==9)
op=0;
if(op)
g.rto.qwerty[g.rto.stat++]=9;
cicada(385,350,12);
}
}while(!kbhit());

mousehide();

getch();
closegraph();

}



void fn()
{
  g.x=0;g.y=265;
  if(1)

{


   int kd=DETECT,km;//First screen
   clrscr();
   getch();
   initgraph( &kd , &km , "..\\bgi");
   setbkcolor(0);
   setcolor(14);
   settextstyle(0,HORIZ_DIR,3);
   outtextxy(230,200,"LOADING.");
   for(int i=1,j=0,k=1;i<=110;i++,j++)
{
   if(i%10==0)
   k++;
   if(k%2!=0)
   setcolor(k);
   else
   setcolor(0);
   delay(100);
   circle(20+i,20+i,i);
   circle(500,130,i);
   circle(130,375,i);
   circle(400+i,275+i,i);
   delay(25);
   setcolor(15);
   circle(150+j,255,9);
  }
   setcolor(WHITE);
   for(i=j+120;i<460;i++)
{
   delay(40);
   circle(30+i,255,9); }
   closegraph();
   int gd=DETECT,gm;//Second screen
   clrscr();
   initgraph( &gd , &gm , "..\\bgi");
   setbkcolor(BLACK);
   setcolor(WHITE);
   for(i=0;i<3;i++)
   rectangle(25-i , 100 -i, 225+i , 300+i);
   delay(1000);
   setcolor(BLUE);
   for(i=97;i>=93;i--)
   circle(125,200,i);
   delay(1000);
   setcolor(WHITE);
   line(75,250,125,150);
   line(125,150,175,250);
   line(175,250,65,190);
   line(65,190,180,190);
   line(180,190,75,250);
   setfillstyle(4,RED);
   delay(200);
   floodfill(115,225,WHITE);
   delay(200);
   floodfill(145,225,WHITE);
   delay(200);
   floodfill(130,185,WHITE);
   delay(200);
   floodfill(165,195,WHITE);
   delay(200);
   floodfill(95,195,WHITE);
   delay(200);
   setfillstyle(4,YELLOW);
   floodfill(100,203,WHITE);
   delay(1000);
   setcolor(RED);
   for(i=70;i<=74;i++)
   circle(125,205,i);
   delay(1000);
   setcolor(YELLOW);
   delay(200);
   circle(90,165,12);
   floodfill(90,165,YELLOW);
   delay(200);
   circle(160,165,12);
   floodfill(160,165,YELLOW);
   delay(200);
   circle(180,215,12);
   floodfill(180,215,YELLOW);
   delay(200);
   circle(125,250,12);
   floodfill(125,250,YELLOW);
   delay(200);
   circle(70,215,12);
   floodfill(70,215,YELLOW);
   delay(250);
   setcolor(WHITE);
   settextstyle(4,HORIZ_DIR,7);
   outtextxy(300,125,"Incursio...");
   delay(100);
   setcolor(BLUE);
   settextstyle(10,HORIZ_DIR,2);
   outtextxy(330,200,"BY:");
   delay(1000);
   setcolor(3);
   settextstyle(4,HORIZ_DIR,2);
   delay(1000);
   outtextxy(360,240,"Abhinav Kothari");
   delay(1000);
   setcolor(12);
   settextstyle(4,HORIZ_DIR,3);
   outtextxy(0,350,"Fear scares the weak, the strong but bathe in it.....");
   delay(1000);
   setcolor(WHITE);
   settextstyle(1,HORIZ_DIR,1);
   outtextxy(330,400,"PRESS ENTER TO CONTINUE");
   getch();

   closegraph();


   int jd=DETECT,jm;//Synopsis
   clrscr();
   initgraph( &jd , &jm ,"..\\bgi");
   setbkcolor(0);
   settextstyle(0,HORIZ_DIR,3);
   outtextxy(175,100,"ABOUT THE GAME");
   settextstyle(3,HORIZ_DIR,1);
   delay(150);
outtextxy(25,175,"The Devil is on your heels and you have only one way to escape,  ");
   delay(700);
outtextxy(25,195,"through the path many fail to survive.Even the great Hercules");
   delay(700);
outtextxy(25,215,"could only barely make it.If you think you are strong enough ");
   delay(700);
outtextxy(25,235,"and could make it with ease ,be our guest.Each and every ");
   delay(700);
outtextxy(25,255,"hurdle is enchanted ,you touch it you burn in hellfire...");
   delay(700);
outtextxy(25,275,"Good luck...'Cause you are gonna need it...");
   delay(700);
   delay(700);

   int flag=0;
   for(i=15;i<=35;i+=5)
{
   if(flag==0)
   setcolor(BLUE);
   else if (flag==1)
   setcolor(GREEN);
   else if(flag==2)
   setcolor(7);
   else if(flag==3)
   setcolor(3);
   else
   setcolor(YELLOW);
   delay(200);
   circle(325,375,i);
   flag++;
   }
   setcolor(WHITE);
   delay(300);
   circle(325,375,10);
   setfillstyle(1,RED);
   floodfill(325,375,WHITE);
   getch();
   closegraph();
}


do{
  clrscr();
  char a;
  int u=0;
  int q,p;
  clrscr();
  int ld=DETECT,lm;
  initgraph( &ld , &lm , "..\\bgi");
  setbkcolor(0);
  akk(100,110);
  setcolor(0);
  settextstyle(7,HORIZ_DIR,4);
  outtextxy(65,70,"NEW");
  outtextxy(55,105,"GAME");
  akk(500,110);
  setcolor(0);
  outtextxy(455,70,"LOAD");
  outtextxy(455,105,"GAME");
  akk(295,345);
  setcolor(0);
  outtextxy(260,330,"QUIT");
  settextstyle(7,HORIZ_DIR,2);
  setfillstyle(1,13);
  floodfill(100,225,15);
  floodfill(500,225,15);
  floodfill(295,460,15);
  setcolor(12);
  int x,y,cl,d,b,w;
  d=100;
  b=400;
  setposi(a,b);
  callmouse();
   do{
  mouseposi(x,y,cl);
  w=cl;
  }while(!kbhit());
     if((x>95&&x<105)&&(y>220&&y<230)&&w==1)
{
     int wd=DETECT,wm;
     char ch;
     initgraph(&wd, &wm, "..\\bgi");
     setbkcolor(0);
     setcolor(14);
     settextstyle(10,HORIZ_DIR,3);
     outtextxy(250,50,"SIGNUP");
     settextstyle(7,HORIZ_DIR,3);
     char f[11];

     setcolor(4);
     outtextxy(100,150,"NAME     :");gotoxy(32,8);gets(f);
     outtextxy(100,200,"GAMERID  :");gotoxy(32,11);gets(g.name);
     gotoxy(32,14);gets(g.gamerid);
     outtextxy(250,430,"PRESS ENTER TO CONTINUE");
     getch();
     pattern();

   //BonusRound
      clrscr();
      int poda=DETECT,podi;
      initgraph( &poda , &podi ,"..\\bgi");
      setbkcolor(0);
      setcolor(12);
      settextstyle(0,HORIZ_DIR,3);
      outtextxy(80,100,"BONUS ROUND COMING UP...");
      setcolor(LIGHTCYAN);
      outtextxy(80,200,"TRY TO SNATCH ALL THE ");
      outtextxy(80,250,"1500 BONUS POINTS...");
      getch();
      closegraph();
      unsigned long int score=0;
      if(1){
  clrscr();
  int xn,yn,cln,an,bn;
  char chn;
  int gn=DETECT,mn;
  initgraph(&gn,&mn,"..\\bgi");
  setcolor(WHITE);
  line(0,75,640,75);
  line(0,74,640,74);
  line(0,73,640,73);
  line(0,72,640,72);
  line(0,71,640,71);
  setcolor(MAGENTA);
  settextstyle(0,HORIZ_DIR,3);
  outtextxy(25,20,"Beware....");
  setcolor(3);
  settextstyle(0,HORIZ_DIR,4);
  outtextxy(25,20,"Go On ....");
  setcolor(15);
  for(int rn=0;rn<5;rn++)
 {
  rectangle(rn,rn,639-rn,479-rn);
}

  an=20;
  bn=500;
  randomize();
  setposi(an,bn);
  callmouse();
  restrictmouseptr(0,630,76,470);
  int x1=random(100),y1=100 , x2=400+random(180),y2=230 , x3=random(200),y3=400
    ,x4=random(200),y4=75+random(126) , x5=400+random(180),y5=75+random(125);
  float tscore=0;
do
{
  setcolor(WHITE);
  line(0,75,640,75);
  line(0,74,640,74);
  line(0,73,640,73);
  line(0,72,640,72);
  line(0,71,640,71);
  setcolor(MAGENTA);
  settextstyle(0,HORIZ_DIR,3);
  outtextxy(25,20,"Beware....");
  setcolor(15);
  for(int rm=0;rm<5;rm++)
 {
  rectangle(rm,rm,639-rm,479-rm);
}
  mouseposi(xn,yn,cln);

  gotoxy(36,2);
  cout<<"If U click , U won't die...";

  gotoxy(36,3);
  cout<<"But score'll increase only if U don't Click.";

  gotoxy(44,4);
  cout<<"Score :"<<(int)(tscore)*100;

  setcolor(LIGHTCYAN);
  rectangle(x1,y1,x1+50,y1+30);
  rectangle(x1+1,y1+1,x1+49,y1+29);
  rectangle(x1+2,y1+2,x1+48,y1+28);

  setcolor(YELLOW);
  rectangle(x2,y2,x2+30,y2+60);
  rectangle(x2+1,y2+1,x2+29,y2+59);
  rectangle(x2+2,y2+2,x2+28,y2+58);

  setcolor(12);
  rectangle(x3,y3,x3+50,y3+50);
  rectangle(x3+1,y3+1,x3+49,y3+49);
  rectangle(x3+2,y3+2,x3+48,y3+48);

  setcolor(BLUE);
  rectangle(x4,y4,x4+60,y4+30);
  rectangle(x4+1,y4+1,x4+59,y4+29);
  rectangle(x4+2,y4+2,x4+58,y4+28);

  setcolor(GREEN);
  rectangle(x5,y5,x5+30,y5+50);
  rectangle(x5+1,y5+1,x5+29,y5+49);
  rectangle(x5+2,y5+2,x5+28,y5+48);

  if(cln==0 && ((xn>x1 && xn<x1+50 && yn>y1 && yn<y1+30)||
  (xn>x2 && xn<x2+30 && yn>y2 && yn<y2+60)||(xn>x3 && xn<x3+50 && yn>y3 && yn<y3+50)
  ||(xn>x4 && xn<x4+60 && yn>y4 && yn<y4+30)||(xn>x5 && xn<x5+30 && yn>y5 && yn<y5+50)))
  {
  setcolor(WHITE);
  settextstyle(0,HORIZ_DIR,4);
  outtextxy(120,190,"Bonus Round Over...");
  settextstyle(0,HORIZ_DIR,3);
  outtextxy(10,280,"The Spirit Boxes got U...");
  delay(5000);
  chn=' ';
  }
  if(score>1500){
  setcolor(WHITE);
  settextstyle(0,HORIZ_DIR,4);
  outtextxy(170,190,"Bonus Round Over...");
  settextstyle(0,HORIZ_DIR,3);
  outtextxy(40,280,"U bested the Spirit Boxes...");
  delay(5000);
  chn=' ';
  }
  x1+=10;
  x2-=14;
  x3+=18;
  x4+=16;
  y4+=16;
  x5-=20;
  y5+=20;
  if(cln==0 && xn!=20 && yn!=500)
  {
  tscore+=0.05;
  score=(int)(tscore)*100;
  }
  if(x1>585)
  x1=random(100);
  if(x2<30)
  x2=400+random(180);
  if(x3>585)
  x3=random(200);
  if(x4>585 || y4>500)
  {
  x4=random(200);
  y4=75+random(125);
  }
  if(x5<30 || y5>500)
  {
  x5=400+random(180);
  y5=75+random(125);
  }
  delay(100);
  cleardevice();
  if(kbhit())
  chn=getch();
}while(chn!=' ');

  mousehide();
  closegraph();
      }
int bscore=score;


int jd=DETECT,jm;
initgraph( &jd , &jm ,"..\\bgi");
     setbkcolor(0);
     setcolor(12);
     settextstyle(0,HORIZ_DIR,3);
     outtextxy(100,50,"LEVEL 1-EASY....PEASY");
     setcolor(14);

     for(int q=0,r=0;q<150;q++)
     {
     delay(100);
     if(q%10==0)
     r++;
     if(r%2!=0)
     setcolor(r);
     else
     setcolor(0);
     circle(300,250,q); }
     getch();
     closegraph();


int gd = DETECT ,gm;
initgraph( &gd , &gm ,"..\\bgi");
     int flag=1,i=0;
     int x=0,y=265;
     delay(1000);
while(flag)
{
     g.status=0;
     cleardevice();
     settextstyle(0,HORIZ_DIR,1);
     outtextxy(0,0,"Press 'S' to save...");
     setcolor(RED);
     line(0,300,800,300);
     line(0,301,800,301);
     line(0,302,800,302);
     int e;
     e=i%16;
     if(e!=0)
     setcolor(e);
     if(x==0)
     i=0;
     bar3d(300-i,160,320-i,300,5,1);
     bar3d(500-i,160,520-i,300,5,1);
     bar3d(700-i,160,720-i,300,5,1);
     bar3d(150-i,160,120-i,300,5,1);
     bar3d(850-i,160,860-i,300,5,1);
     char k='0';

if(kbhit())
     k=getch();
     if(x<getmaxx())
     x++;
     else
     x=0;
     if(k==' '&&(y==265||y==275))
{
     y=95;
     x+=80;
     score+=100;}
     if(y<265)
     y+=20;
     setcolor(15);
     putpixel(x-2,y-2,15);
     putpixel(x+2,y-2,15);
     arc(x,y,0,60,7);
     arc(x,y,265,295,3);
     circle(x,y,5);
     line(x,y+5,x,y+20);
     line(x,y+7,x+5,y+12);
     line(x,y+7,x-5,y+12);
     if(x%2==0)
     {line(x,y+20,x-5,y+25);
     line(x,y+20,x+5,y+25);}
     else
     {line(x,y+20,x-2,y+25);
     line(x,y+20,x+2,y+25);}
     if(k=='e')
     flag=0;
     if(k=='s')
     {
    x=x;g.y=y;g.score=score;
    flag=0;
    score2=score;
    g.status=1;
    }
    if((x+5>=300-i&&x+5<=320-i&&y+5>=160)||(x+5>=500-i&&x+5<=520-i&&y+5>=160)||(x+5>=700-i&&x+5<=720-i&&y+5>=160)||(x+5>=120-i&&x+5<=150-i&&y+5>=160)||(x+5>=850-i&&x+5<=860-i&&y+5>=160))
    {
    flag=0;
    setcolor(12);
    settextstyle(1,HORIZ_DIR,5);
    outtextxy(170,75," GAME OVER ");
    cout<<score;score2=score;
    g.score=score;
    getch();
}
    if(score>bscore+500)
{
    int gd = DETECT ,gm;
    initgraph( &gd , &gm ,"..\\bgi");
    if(5%2==1)
{
    cleardevice();
    int x=0,y=220;
    delay(1000);
    int flag=1,i;
    for(;flag;)
{
    cleardevice();

    setcolor(RED);
    rectangle(0,180,getmaxx(),210);
    rectangle(0,250,getmaxx(),280);
    setfillstyle(2,14);
    floodfill(300,190,RED);
    floodfill(300,260,RED);
    char k;
    if(x<getmaxx())
    x+=11;
    else
    flag=0;


    setcolor(15);
    putpixel(x-2,y-2,15);
    putpixel(x+2,y-2,15);
    arc(x,y,0,60,7);
    arc(x,y,265,295,3);
    circle(x,y,5);
    line(x,y+5,x,y+20);
    if(x%2==0)
    {line(x,y+7,x+10,y+2);
    line(x,y+7,x-10,y+2);}
    else
    {line(x,y+7,x+10,y+12);
    line(x,y+7,x-10,y+12);}
    if(x%2==0)
    {line(x,y+20,x-5,y+25);
    line(x,y+20,x+5,y+25);}
    else
    {line(x,y+20,x-2,y+25);
    line(x,y+20,x+2,y+25);}
    setcolor(12);
settextstyle(0,HORIZ_DIR,3);
outtextxy(50,95,"LEVEL TWO , COMING UP...");
i++;
delay(75);
}}
int flag=1,i=0,l=0;
int x=0,y=355;
delay(1000);
while(flag)
{
cleardevice();
settextstyle(0,HORIZ_DIR,1);
outtextxy(0,0,"Press 'S' to save...");
setcolor(RED);
line(0,400,800,400);
line(0,401,800,401);
line(0,402,800,402);

int e;
e=i%16;
if(e!=0)
setcolor(e);
if(x==0)
i=0;
bar3d(300-i,180,320-i,400,5,1);
bar3d(420-i,0,440-i,250,5,1); //
bar3d(200-i,130,220-i,400,5,1);//
bar3d(500-i,0,520-i,300,5,1);
bar3d(590-i,120,610-i,400,5,1);
bar3d(700-i,130,720-i,400,5,1);
bar3d(120-i,0,150-i,240,5,1);
bar3d(750-i,0,800-i,200,5,1);

char k='0';

if(kbhit())
k=getch();
if(x<getmaxx())
x+=3;
else
x=0;

if(l%2==1&&k==' '&&(y==275||y==265||y==355))
{
y=95;
x+=30;
score+=100;}
else if(k==' '&&(y==95||y==275))
{y=355;
x+=30;
score+=100;}
++l;
setcolor(15);
putpixel(x-2,y-2,15);
putpixel(x+2,y-2,15);
arc(x,y,0,60,7);
arc(x,y,265,295,3);
circle(x,y,5);
line(x,y+5,x,y+20);
if(x%2==0)
{line(x,y+7,x+10,y+12);
line(x,y+7,x-10,y+12);}
else
{line(x,y+7,x+10,y+2);
line(x,y+7,x-10,y+2);}
if(x%2==0)
{line(x,y+20,x-5,y+25);
line(x,y+20,x+5,y+25);}
else
{line(x,y+20,x-2,y+25);
line(x,y+20,x+2,y+25);}
if(k=='e')
flag=0;
if(k=='s')
{
g.x=x;g.y=y;g.score=600;
flag=0;
score2=score;
g.status=1;
ofstream fout3("Balde.dat",ios::binary|ios::app);
fout3.write((char*)&g,sizeof(g));
fout3.close();
goto l1;
}
if((x+5>=300-i&&x+5<=320-i&&y+5>=180)||
(x+5>=500-i&&x+5<=520-i&&y-5<=300)||
(x+5>=700-i&&x+5<=720-i&&y+5>=120)||
(x+5>=120-i&&x+5<=150-i&&y-5<=240)||
(x+5>=750-i&&x+5<=800-i&&y-5<=200)||
(x+5>=420-i&&x+5<=440-i&&y-5<=250)||
(x+5>=200-i&&x+5<=220-i&&y+5>=130)||
(x+5>=590-i&&x+5<=610-i&&y+5>=120))
{flag=0;
setcolor(12);
settextstyle(0,HORIZ_DIR,5);
outtextxy(170,75," GAME OVER ");
cout<<score;score2=score;
g.score=score;
ofstream fout2("Balde.dat",ios::binary|ios::app);
fout2.write((char*)&g,sizeof(g));
fout2.close();
getch();
goto l1;
}
if(score>bscore+1100)
{int ed=DETECT,em;
    initgraph( & ed, &em ,"..\\bgi");
    setcolor(12);
    settextstyle(0,HORIZ_DIR,5);
    outtextxy(50,150,"LEVEL THREE ");
    outtextxy(50,200,"COMING UP... ");
    getch();
    closegraph();
    int gd = DETECT ,gm;
initgraph( &gd , &gm ,"..\\bgi");
int a=getmaxx(),b=getmaxy(),flag=1,x=20,y=70;
char k;
setcolor(15);
for(int i=0;i<20;i++)
{line(i,0,i,b);
line(a-i,0,a-i,b);
}
int poly1[]={20,0,
	     a-20,0,
	     a-20,50,
	     a-150,50,
	     a-150,20,
	     a-190,20,
	     a-190,50,
	     a-320,50,
	     a-320,20,
	     a-360,20,
	     a-360,50,
	     a-480,50,
	     a-480,20,
	     a-520,20,
	     a-520,50,
	     20,50,
	     20,0};
drawpoly(17,poly1);
fillpoly(17,poly1);
int poly2[]={20,90,
	     a-460,90,
	     a-460,120,
	     a-420,120,
	     a-420,90,
	     a-290,90,
	     a-290,120,
	     a-250,120,
	     a-250,90,
	     a-60,90,
	     a-60,170,
	     a-160,170,
	     a-160,140,
	     a-200,140,
	     a-200,170,
	     a-310,170,
	     a-310,140,
	     a-350,140,
	     a-350,170,
	     a-490,170,
	     a-490,140,
	     a-530,140,
	     a-530,170,
	     20,170,
	     20,90};
drawpoly(24,poly2);
fillpoly(24,poly2);
int poly3[]={60,220,
	     160,220,       //
	     160,250,
	     200,250,
	     200,220,
	     450,220,
	     450,250,
	     490,250,
	     490,220,
	     a-20,220,
	     a-20,300,
	     a-200,300,   //
	     a-200,270,
	     a-240,270,
	     a-240,300,
	     a-360,300,
	     a-360,270,
	     a-400,270,
	     a-400,300,
	     60,300,
	     60,220};
drawpoly(21,poly3);
fillpoly(21,poly3);
int poly4[]={20,350,
	     220,350,
	     220,380,
	     260,380,
	     260,350,
	     a-60,350,
	     a-60,b-30,
	     20,b-30,
	     20,350};
drawpoly(9,poly4);
fillpoly(9,poly4);
while(flag){
setcolor(0);
settextstyle(0,HORIZ_DIR,1);
outtextxy(0,0,"Press 'S' to save...");
if(y==70)
{
setcolor(12);
circle(x+20,y,1);
circle(x+20,y,2);
circle(x+20,y,3);
circle(x+20,y,4);
setcolor(0);
circle(x+20-10,y,1);
circle(x+20-10,y,2);
circle(x+20-10,y,3);
circle(x+20-10,y,4);
 }
else if(y==195)
{setcolor(12);
circle(a-x-20,y,1);
circle(a-x-20,y,2);
circle(a-x-20,y,3);
circle(a-x-20,y,4);
setcolor(0);
circle(a-x-20+10,y,1);
circle(a-x-20+10,y,2);
circle(a-x-20+10,y,3);
circle(a-x-20+10,y,4);
}
else if(y==325)
{setcolor(12);
circle(x+20,y,1);
circle(x+20,y,2);
circle(x+20,y,3);
circle(x+20,y,4);
setcolor(0);
circle(x+20-10,y,1);
circle(x+20-10,y,2);
circle(x+20-10,y,3);
circle(x+20-10,y,4);
 }
setcolor(RED);
delay(100);
line(a-x-190,50,a-x-190,90);
line(a-x-20,50,a-x-20,90);
line(x+200,170,x+200,220);
line(a-x-50,300,a-x-50,350);
line(a-x-150,300,a-x-150,350);
setcolor(0);
if(x!=a-20)
{line(a-x+10-190,50,a-x+10-190,90);line(a-x+10-20,50,a-x+10-20,90);
line(x+200-10,170,x+200-10,220);
line(a-x+10-50,300,a-x+10-50,350);
line(a-x+10-150,300,a-x+10-150,350);
}
else
{line(a-x-190,50,a-x-190,90);line(a-x-20,50,a-x-20,90);
line(x+200,170,x+200,220);
line(a-x-50,310,a-x-50,350);
line(a-x-150,300,a-x-150,350);
}if(x+20<=a-19)
x+=10;
else
x=40;
k='0';
if( kbhit())
k=getch();
if(k==' '&&y==70&&((x>a-520&&x<a-480)||(x>a-360&&x<a-320)||(x>a-190||x>a-150)))
{score+=100;
delay(100);
x+=40;
y=30;}
else if(k==' '&&y==70&&((x>a-460&&x<a-420)||(x>a-290&&x<a-250)))
{
score+=100;delay(100);
y=30;
x+=40;}
if(y<70)
{delay(100);
y+=10;      }
if(k=='s')
{
g.x=x;g.y=y;g.score=1200;
flag=0;
score2=score;
g.status=1;
ofstream fout1("Balde.dat",ios::binary|ios::app);
fout1.write((char*)&g,sizeof(g));
fout1.close();
goto l1;
}
if((y==70&&((x>=a-x-35&&x<=a-x-10)||(x>=a-x-200&&x<=a-x-180)))||
   (y==195&&a-x-20>=x+190&&a-x-20<=x+210)||
   (y==325&&(x==500||((x>=a-x-60&&x<=a-x-40)||(x>=a-x-160&&x<=a-x-140)))))
{flag=0;
setcolor(12);
settextstyle(0,HORIZ_DIR,5);
outtextxy(150,b/2-60,"GAME OVER");
g.score=score;
ofstream fout8("Balde.dat",ios::binary|ios::app);
fout8.write((char*)&g,sizeof(g));
fout8.close();

}
if(y==70&&x>=a-30)
y=195;

if(k==' '&&y==195&&((a-x-20<=a-160&&a-x-20>=a-200)||(a-x-20<=a-330&&a-x-20>=350)||(a-x-20<=a-490&&a-x-20>=a-530)))
{delay(100);
x+=40;
score+=100;y=105;}
else if(k==' '&&y==195&&((a-x-20>=a-490&&a-x-20<=a-450)||(a-x-20>=a-200&&a-x-20<=a-160)))
{delay(100);
score+=100;y=105;
x+=40;}
if(y>70&&y<195)
{
y+=15;      }
if(y==195&&a-x-20<=50&&a-x-20>=40)
y=325;
if(k==' '&&y==325&&((x>a-240&&x<a-200)||(x>a-400&&x<a-360)))
{delay(100);
x+=40;
score+=100;y=280;}
else if(k==' '&&y==325&&x>220&&x<260)
{delay(100);
y=280;
score+=100;x+=40;}
if(y>195&&y<325)
{delay(100);
y+=15;      }

if(y==325&&x==310)
{
g.score=score;
ofstream fout007("Balde.dat",ios::binary|ios::app);
fout007.write((char*)&g,sizeof(player));
fout007.close();
flag=0;
}
if(k=='e')
flag=0;
score2=score;
if(flag==0)
 goto l1;
}}
i++;
delay(75);
}

closegraph();}
i++;
delay(75);
}

closegraph();
ofstream fout("Balde.dat",ios::binary|ios::app);
fout.write((char*)&g,sizeof(g));
fout.close();
}
else if((x>495&&x<505)&&(y>220&&y<230)&&w==1)
{int wd=DETECT,wm;
char ch;

initgraph(&wd, &wm, "..\\bgi");
setbkcolor(0);
setcolor(14);
settextstyle(0,HORIZ_DIR,3);

settextstyle(7,HORIZ_DIR,3);
setcolor(4);
player tap[20];
int top=0,messi=0;
ifstream fin00("Balde.dat",ios::binary);
ofstream fout00("Apple.dat",ios::binary);
player f00;
while(fin00.read((char*)&f00,sizeof(player)))
{
if(f00.status==1)
fout00.write((char*)&f00,sizeof(player));
}
fin00.close();
fout00.close();
ifstream fin("Apple.dat",ios::binary);
while(fin.read((char*)&tap[top],sizeof(player)))
{
top++;
}
fin.close();
do
{
cleardevice();
setcolor(14);
settextstyle(10,HORIZ_DIR,3);
outtextxy(250,50,"LOGIN");
settextstyle(7,HORIZ_DIR,3);
char f[11];

setcolor(4);
outtextxy(100,150,"NAME     :");gotoxy(32,8);gets(f);
outtextxy(100,200,"GAMERID  :");gotoxy(32,11);gets(g.name);
gotoxy(32,14);gets(g.gamerid);
outtextxy(250,430,"PRESS ENTER TO CONTINUE");
pattern();
for(int kk=0;kk<top;kk++)
if(strcmpi(g.name,tap[kk].name)==0&&strcmpi(g.gamerid,tap[kk].gamerid)==0)
if(g.rto.qwerty[0]==tap[kk].rto.qwerty[0]&&
   g.rto.qwerty[1]==tap[kk].rto.qwerty[1]&&
   g.rto.qwerty[2]==tap[kk].rto.qwerty[2]&&
   g.rto.qwerty[3]==tap[kk].rto.qwerty[3]&&
   g.rto.qwerty[4]==tap[kk].rto.qwerty[4]&&
   g.rto.qwerty[5]==tap[kk].rto.qwerty[5]&&
   g.rto.qwerty[6]==tap[kk].rto.qwerty[6]&&
   g.rto.qwerty[7]==tap[kk].rto.qwerty[7]&&
   g.rto.qwerty[8]==tap[kk].rto.qwerty[8])
{
messi++;
g=tap[kk];
break;
}
if(messi==0)
{
int hd=DETECT,hm;
initgraph( &hd , &hm ,"..\\bgi");
setbkcolor(0);
setcolor(3);
settextstyle(0,HORIZ_DIR,3);
outtextxy(0,430,"Player not found!");
getch();
closegraph();
}
}while(messi==0);



if(232323)
{int jd=DETECT,jm;
initgraph( &jd , &jm ,"..\\bgi");
setbkcolor(0);
setcolor(12);
settextstyle(0,HORIZ_DIR,3);
outtextxy(100,50,"LEVEL 1-EASY....PEASY");
setcolor(14);

for(int q=0,r=0;q<150;q++)
{delay(40);
if(q%10==0)
r++;
if(r%2!=0)
setcolor(r);
else
setcolor(0);
circle(300,250,q); }

getch();
closegraph();
int gd = DETECT ,gm;
initgraph( &gd , &gm ,"..\\bgi");
int flag=1,i=0;
int x=g.x,y=g.y;
int score=g.score;
delay(1000);
while(flag)
{
cleardevice();
setcolor(RED);
line(0,300,800,300);
line(0,301,800,301);
line(0,302,800,302);

int e;
e=i%16;
if(e!=0)
setcolor(e);
if(x==0)
i=0;
bar3d(300-i,160,320-i,300,5,1);
bar3d(500-i,160,520-i,300,5,1);
bar3d(700-i,160,720-i,300,5,1);
bar3d(150-i,160,120-i,300,5,1);
bar3d(850-i,160,860-i,300,5,1);
char k='0';

if(kbhit())
k=getch();
if(x<getmaxx())
x++;
else
x=0;
if(k==' '&&(y==265||y==275))
{
y=95;
x+=80;
score+=100;}
if(y<265)
y+=20;
setcolor(15);
putpixel(x-2,y-2,15);
putpixel(x+2,y-2,15);
arc(x,y,0,60,7);
arc(x,y,265,295,3);
circle(x,y,5);
line(x,y+5,x,y+20);
line(x,y+7,x+5,y+12);
line(x,y+7,x-5,y+12);
if(x%2==0)
{line(x,y+20,x-5,y+25);
line(x,y+20,x+5,y+25);}
else
{line(x,y+20,x-2,y+25);
line(x,y+20,x+2,y+25);}
if(k=='e')
flag=0;
if((x+5>=300-i&&x+5<=320-i&&y+5>=160)||(x+5>=500-i&&x+5<=520-i&&y+5>=160)||(x+5>=700-i&&x+5<=720-i&&y+5>=160)||(x+5>=120-i&&x+5<=150-i&&y+5>=160)||(x+5>=850-i&&x+5<=860-i&&y+5>=160))
{flag=0;
setcolor(12);
settextstyle(1,HORIZ_DIR,5);
outtextxy(170,75," GAME OVER ");
cout<<score;score2=score;
g.score=score;
g.status=0;
fstream f("Balde.dat",ios::binary|ios::in|ios::out);
player ramos;
while(f.read((char*)&ramos,sizeof(player)))
{
if(strcmpi(ramos.name,g.name)==0&&strcmpi(ramos.gamerid,g.gamerid)==0)
{

f.seekg(-1*((int)sizeof(player)),ios::cur);
f.write((char*)&g,sizeof(player));

break;
}
}
f.close();

getch();
}
if(score>500)
{ int gd = DETECT ,gm;
initgraph( &gd , &gm ,"..\\bgi");
if(5%2==1)
{cleardevice();
int x=0,y=220;
delay(1000);
int flag=1,i;
for(;flag;)
{cleardevice();
setcolor(RED);
rectangle(0,180,getmaxx(),210);
rectangle(0,250,getmaxx(),280);
setfillstyle(2,14);
floodfill(300,190,RED);
floodfill(300,260,RED);
char k;
if(x<getmaxx())
x+=11;
else
flag=0;


setcolor(15);
putpixel(x-2,y-2,15);
putpixel(x+2,y-2,15);
arc(x,y,0,60,7);
arc(x,y,265,295,3);
circle(x,y,5);
line(x,y+5,x,y+20);
if(x%2==0)
{line(x,y+7,x+10,y+2);
line(x,y+7,x-10,y+2);}
else
{line(x,y+7,x+10,y+12);
line(x,y+7,x-10,y+12);}
if(x%2==0)
{line(x,y+20,x-5,y+25);
line(x,y+20,x+5,y+25);}
else
{line(x,y+20,x-2,y+25);
line(x,y+20,x+2,y+25);}
setcolor(12);
settextstyle(0,HORIZ_DIR,3);
outtextxy(50,95,"LEVEL TWO , COMING UP...");
i++;
delay(75);
}}
int flag=1,i=0,l=0;
int x=0,y=355;
delay(1000);
while(flag)
{
cleardevice();
setcolor(RED);
line(0,400,800,400);
line(0,401,800,401);
line(0,402,800,402);

int e;
e=i%16;
if(e!=0)
setcolor(e);
if(x==0)
i=0;
bar3d(300-i,180,320-i,400,5,1);
bar3d(420-i,0,440-i,250,5,1); //
bar3d(200-i,130,220-i,400,5,1);//
bar3d(500-i,0,520-i,300,5,1);
bar3d(590-i,120,610-i,400,5,1);
bar3d(700-i,130,720-i,400,5,1);
bar3d(120-i,0,150-i,240,5,1);
bar3d(750-i,0,800-i,200,5,1);

char k='0';

if(kbhit())
k=getch();
if(x<getmaxx())
x+=3;
else
x=0;

if(l%2==1&&k==' '&&(y==275||y==265||y==355))
{
y=95;
x+=30;
score+=100;}
else if(k==' '&&(y==95||y==275))
{y=355;
x+=30;
score+=100;}
++l;
setcolor(15);
putpixel(x-2,y-2,15);
putpixel(x+2,y-2,15);
arc(x,y,0,60,7);
arc(x,y,265,295,3);
circle(x,y,5);
line(x,y+5,x,y+20);
if(x%2==0)
{line(x,y+7,x+10,y+12);
line(x,y+7,x-10,y+12);}
else
{line(x,y+7,x+10,y+2);
line(x,y+7,x-10,y+2);}
if(x%2==0)
{line(x,y+20,x-5,y+25);
line(x,y+20,x+5,y+25);}
else
{line(x,y+20,x-2,y+25);
line(x,y+20,x+2,y+25);}
if(k=='e')
flag=0;
if((x+5>=300-i&&x+5<=320-i&&y+5>=180)||
(x+5>=500-i&&x+5<=520-i&&y-5<=300)||
(x+5>=700-i&&x+5<=720-i&&y+5>=120)||
(x+5>=120-i&&x+5<=150-i&&y-5<=240)||
(x+5>=750-i&&x+5<=800-i&&y-5<=200)||
(x+5>=420-i&&x+5<=440-i&&y-5<=250)||
(x+5>=200-i&&x+5<=220-i&&y+5>=130)||
(x+5>=590-i&&x+5<=610-i&&y+5>=120))
{flag=0;
setcolor(12);
settextstyle(0,HORIZ_DIR,5);
outtextxy(170,75," GAME OVER ");
cout<<score;score2=score;
g.score=score;
g.status=0;
fstream f1("Balde.dat",ios::binary|ios::in|ios::out);
player neymar;
while(f1.read((char*)&neymar,sizeof(player)))
{
if(strcmpi(neymar.name,g.name)==0&&strcmpi(neymar.gamerid,g.gamerid)==0)
{
f1.seekg(-1*((int)sizeof(player)),ios::cur);
f1.write((char*)&g,sizeof(player));
break;
}
}
f1.close();


getch();
goto l1;
}
if(score>1100)
{int ed=DETECT,em;
    initgraph( & ed, &em ,"..\\bgi");
    setcolor(12);
    settextstyle(0,HORIZ_DIR,5);
    outtextxy(50,150,"LEVEL THREE ");
    outtextxy(50,200,"COMING UP... ");
    getch();
    closegraph();
    int gd = DETECT ,gm;
initgraph( &gd , &gm ,"..\\bgi");
int a=getmaxx(),b=getmaxy(),flag=1,x=20,y=70;
char k;
setcolor(15);
for(int i=0;i<20;i++)
{line(i,0,i,b);
line(a-i,0,a-i,b);
}
int poly1[]={20,0,
	     a-20,0,
	     a-20,50,
	     a-150,50,
	     a-150,20,
	     a-190,20,
	     a-190,50,
	     a-320,50,
	     a-320,20,
	     a-360,20,
	     a-360,50,
	     a-480,50,
	     a-480,20,
	     a-520,20,
	     a-520,50,
	     20,50,
	     20,0};
drawpoly(17,poly1);
fillpoly(17,poly1);
int poly2[]={20,90,
	     a-460,90,
	     a-460,120,
	     a-420,120,
	     a-420,90,
	     a-290,90,
	     a-290,120,
	     a-250,120,
	     a-250,90,
	     a-60,90,
	     a-60,170,
	     a-160,170,
	     a-160,140,
	     a-200,140,
	     a-200,170,
	     a-310,170,
	     a-310,140,
	     a-350,140,
	     a-350,170,
	     a-490,170,
	     a-490,140,
	     a-530,140,
	     a-530,170,
	     20,170,
	     20,90};
drawpoly(24,poly2);
fillpoly(24,poly2);
int poly3[]={60,220,
	     160,220,       //
	     160,250,
	     200,250,
	     200,220,
	     450,220,
	     450,250,
	     490,250,
	     490,220,
	     a-20,220,
	     a-20,300,
	     a-200,300,   //
	     a-200,270,
	     a-240,270,
	     a-240,300,
	     a-360,300,
	     a-360,270,
	     a-400,270,
	     a-400,300,
	     60,300,
	     60,220};
drawpoly(21,poly3);
fillpoly(21,poly3);
int poly4[]={20,350,
	     220,350,
	     220,380,
	     260,380,
	     260,350,
	     a-60,350,
	     a-60,b-30,
	     20,b-30,
	     20,350};
drawpoly(9,poly4);
fillpoly(9,poly4);
while(flag){
  if(y==70)
{
setcolor(3);
circle(x+20,y,1);
circle(x+20,y,2);
circle(x+20,y,3);
circle(x+20,y,4);
setcolor(0);
circle(x+20-10,y,1);
circle(x+20-10,y,2);
circle(x+20-10,y,3);
circle(x+20-10,y,4);
 }
else if(y==195)
{setcolor(3);
circle(a-x-20,y,1);
circle(a-x-20,y,2);
circle(a-x-20,y,3);
circle(a-x-20,y,4);
setcolor(0);
circle(a-x-20+10,y,1);
circle(a-x-20+10,y,2);
circle(a-x-20+10,y,3);
circle(a-x-20+10,y,4);
}
else if(y==325)
{setcolor(3);
circle(x+20,y,1);
circle(x+20,y,2);
circle(x+20,y,3);
circle(x+20,y,4);
setcolor(0);
circle(x+20-10,y,1);
circle(x+20-10,y,2);
circle(x+20-10,y,3);
circle(x+20-10,y,4);
 }
setcolor(15);
delay(100);
line(a-x-190,50,a-x-190,90);
line(a-x-20,50,a-x-20,90);
line(x+200,170,x+200,220);
line(a-x-50,300,a-x-50,350);
line(a-x-150,300,a-x-150,350);
setcolor(0);
if(x!=a-20)
{line(a-x+10-190,50,a-x+10-190,90);line(a-x+10-20,50,a-x+10-20,90);
line(x+200-10,170,x+200-10,220);
line(a-x+10-50,300,a-x+10-50,350);
line(a-x+10-150,300,a-x+10-150,350);
}
else
{line(a-x-190,50,a-x-190,90);line(a-x-20,50,a-x-20,90);
line(x+200,170,x+200,220);
line(a-x-50,310,a-x-50,350);
line(a-x-150,300,a-x-150,350);
}if(x+20<=a-19)
x+=10;
else
x=40;
k='0';
if( kbhit())
k=getch();
if(k==' '&&y==70&&((x>a-520&&x<a-480)||(x>a-360&&x<a-320)||(x>a-190||x>a-150)))
{delay(100);
score+=100;
x+=40;
y=30;}
else if(k==' '&&y==70&&((x>a-460&&x<a-420)||(x>a-290&&x<a-250)))
{delay(100);
score+=100;y=30;
x+=40;}
if(y<70)
{delay(100);
y+=10;      }
if((y==70&&((x>=a-x-35&&x<=a-x-10)||(x>=a-x-200&&x<=a-x-180)))||
   (y==195&&a-x-20>=x+190&&a-x-20<=x+210)||
   (y==325&&(x==500||((x>=a-x-60&&x<=a-x-40)||(x>=a-x-160&&x<=a-x-140)))))
{flag=0;
setcolor(12);
settextstyle(0,HORIZ_DIR,5);
outtextxy(150,b/2-60,"GAME OVER");
g.score=score;
g.status=0;
fstream f2("Balde.dat",ios::binary|ios::in|ios::out);
player bale;
while(f2.read((char*)&bale,sizeof(player)))
{
if(strcmpi(bale.name,g.name)==0&&strcmpi(bale.gamerid,g.gamerid)==0)
{
f2.seekg(-1*((int)sizeof(player)),ios::cur);
f2.write((char*)&g,sizeof(player));
break;
}
}
f2.close();


}
if(y==70&&x>=a-30)
y=195;

if(k==' '&&y==195&&((a-x-20<=a-160&&a-x-20>=a-200)||(a-x-20<=a-330&&a-x-20>=350)||(a-x-20<=a-490&&a-x-20>=a-530)))
{delay(100);
score+=100;x+=40;
y=105;}
else if(k==' '&&y==195&&((a-x-20>=a-490&&a-x-20<=a-450)||(a-x-20>=a-200&&a-x-20<=a-160)))
{delay(100);
y=105;
score+=100;x+=40;}
if(y>70&&y<195)
{
y+=15;      }
if(y==195&&a-x-20<=50&&a-x-20>=40)
y=325;
if(k==' '&&y==325&&((x>a-240&&x<a-200)||(x>a-400&&x<a-360)))
{delay(100);
score+=100;x+=40;
y=280;}
else if(k==' '&&y==325&&x>220&&x<260)
{delay(100);
score+=100;y=280;
x+=40;}
if(y>195&&y<325)
{delay(100);
y+=15;      }

if(k=='e')
flag=0;
score2=score;
if(flag==0)
goto l1;
}}
i++;
delay(75);
}

closegraph();}
i++;
delay(75);
}   }

getch();
}
else if ((x>290&&x<300)&&(y>455&&y<465)&&w==1)
exit(1);
mousehide();

l1:int ge=DETECT,gv;
initgraph(&ge, &gv, "..\\bgi");
setbkcolor(0);
setcolor(14);
settextstyle(0,HORIZ_DIR,3);
outtextxy(150,30,"HIGH SCORES");
settextstyle(7,HORIZ_DIR,3);
setcolor(4);
outtextxy(25,75,"RANK");
outtextxy(150,75,"NAME");
outtextxy(325,75,"GAMERID");
outtextxy(550,75,"SCORE");
player qwerty[20];
int qwe=0;
ifstream fin2("Balde.dat",ios::binary);
while(fin2.read((char*)&qwerty[qwe],sizeof(player)))
{qwe++;
}
fin2.close();
for (int op=0;op<qwe-1;op++)
for(int ip=0;ip<qwe-op-1;ip++)
if(qwerty[ip].score<qwerty[ip+1].score)
{player t=qwerty[ip];
qwerty[ip]=qwerty[ip+1];
qwerty[ip+1]=t;
}
char ab[10][20];
 for(op=0;op<qwe;op++)
itoa(qwerty[op].score,ab[op],10);
char e[50][2];
for(op=0;op<qwe;op++)
itoa(op+1,e[op],10);
for(int pr=0,v=50;pr<qwe;pr++,v+=50)
{
outtextxy(25,100+v,e[pr]);
outtextxy(130,100+v,qwerty[pr].name);
outtextxy(315,100+v,qwerty[pr].gamerid);
outtextxy(550,100+v,ab[pr]);}
settextstyle(7,HORIZ_DIR,1);
setcolor(4);



outtextxy(30,430,"DO YOU WANT TO CONTINUE WITH ANOTHER PLAYER?");
cin>>cj;
}while(cj=='s'||cj=='y');



getch();


cleardevice();
}
void main()
{
symmetry();
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");
setbkcolor(0);
setcolor(12);
settextstyle(0,HORIZ_DIR,4);
outtextxy(100,100,"Live long ");
outtextxy(100,150,"and prosper...");
setcolor(3);
outtextxy(100,300,"Let the fun ");
outtextxy(100,350,"begin...");
getch();
closegraph();

fn();
symmetry2();
int qd=DETECT,qm;
initgraph(&qd,&qm,"..\\bgi");
setbkcolor(0);
setcolor(15);
for(int qw=5;qw<getmaxx()/2;qw++)
{
delay(10);
if(qw%5==0)
setcolor(0);
else
setcolor(15);
line(qw,0,qw,getmaxy());
line(getmaxx()-qw,0,getmaxx()-qw,getmaxy());
}
cleardevice();
setbkcolor(0);
for(qw=5;qw<getmaxy()/2;qw++)
{
delay(10);
if(qw%5==0)
setcolor(0);
else
setcolor(15);
line(0,qw,getmaxx(),qw);
line(0,getmaxy()-qw,getmaxx(),getmaxy()-qw);
}
cleardevice();
setbkcolor(0);
setcolor(12);
settextstyle(0,HORIZ_DIR,4);
outtextxy(100,100,"Enjoyed?");
setcolor(3);
outtextxy(100,300,"Bon voyage...");
getch();
closegraph();

}
