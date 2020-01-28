#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

#define REP(i,a,b) for(int i=a;i<=b;++i)

char courseschar[10000],gradeschar[1000000],studentschar[10000],buff[2];
char studentsName[158][100];
char studentsRoll[158][100];
char gradesRoll[9954][100];
char gradesName[9954][100];
char gradesGrade[9954][100];
char courseSem[63][100];
char courseName[63][100];
char courseNum[63][100];
char courseCred[63][100];



int giv(char c)
{
  if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0')
  return 1;
  return 0;
}

int check(char s1[],char s2[])
{
  int n1 = strlen(s1);
  int n2 = strlen(s2);

  if(n1!=n2)
  return 0;
  int flag=1;
  REP(i,0,n1-1)
  if(s1[i]!=s2[i])
  flag=0;
  return flag;

}

int point(char grade[])
{
  if(grade[0]=='A'&&grade[1]=='A')
  return 10;
  if(grade[0]=='A'&&grade[1]=='B')
  return 9;
  if(grade[0]=='B'&&grade[1]=='B')
  return 8;
  if(grade[0]=='B'&&grade[1]=='C')
  return 7;
  if(grade[0]=='C'&&grade[1]=='C')
  return 6;
  if(grade[0]=='C'&&grade[1]=='D')
  return 5;
  if(grade[0]=='D'&&grade[1]=='D')
  return 4;
}
int credits(char c[])
{
  int n = strlen(c);
  int ans=0;
  REP(i,0,n-1)
  {
    ans+=pow(10,n-i-1)*atoi(c);

  }
  return ans;
}

int main(int argc,char*agrv[])
{
  int fd = open("students01.csv",O_RDONLY);

  int size=0;
  while(read(fd,buff,1))
  {
    studentschar[size]=buff[0];
    size++;
  }
  int i=0;
  int j=0;

  while(i<size)
  {



    int t=0;
    while(studentschar[i]!=',')
    {studentsName[j][t]=studentschar[i];t++;i++;}
    studentsName[j][t]='\0';
    i++;

    REP(k,1,9)
    {studentsRoll[j][k-1]=studentschar[i];i++;}
    studentsRoll[j][9]='\0';
    i++;

    j++;


  }


  fd = open("grades.csv",O_RDONLY);
  size=0;
  while(read(fd,buff,1))
  {
    gradeschar[size]=buff[0];
    size++;
  }
   i=0;
   j=0;

  while(i<size)
  {
    int t=0;
    while(gradeschar[i]!=',')
    {gradesRoll[j][t]=gradeschar[i];i++;t++;}
    gradesRoll[j][t]='\0';
    i++;
    t=0;
    while(gradeschar[i]!=',')
    {gradesName[j][t]=gradeschar[i];i++;t++;}
    gradesName[j][t]='\0';
    if(gradesName[j][t-1]==' ')
    gradesName[j][t-1]='\0';
    i++;

    gradesGrade[j][0]=gradeschar[i];
    i++;
    gradesGrade[j][1]=gradeschar[i];
    i+=2;
    gradesGrade[j][2]='\0';

    j++;


  }

  fd = open("courses.csv",O_RDONLY);
  size=0;
  while(read(fd,buff,1))
  {
    courseschar[size]=buff[0];
    size++;
  }
   i=0;
   j=0;

  while(i<size)
  {
    int t=0;
    while(courseschar[i]!=',')
    {courseSem[j][t]=courseschar[i];i++;t++;}
    courseSem[j][t]='\0';
    i++;
    t=0;
    while(courseschar[i]!=',')
    {courseNum[j][t]=courseschar[i];i++;t++;}
    courseNum[j][t]='\0';
    i++;
    t=0;
    while(courseschar[i]!=',')
    {courseName[j][t]=courseschar[i];i++;t++;}
    courseName[j][t]='\0';
    i++;

    while(courseschar[i]!=',')
    {i++;}
    i++;
    while(courseschar[i]!=',')
    {i++;}
    i++;
    while(courseschar[i]!=',')
    {i++;}
    i++;
    t=0;
    while(giv(courseschar[i]))
    {
      courseCred[j][t]=courseschar[i];
      t++;
      i++;
    }
    courseCred[j][t]='\0';

    i++;
    j++;
  }

  REP(x,0,157)
  {

  char file[15];
  REP(y,0,8)
  file[y]=studentsRoll[x][y];
  file[9]='.';
  file[10]='t';
  file[11]='x';
  file[12]='t';
  file[13]='\0';
  fd = open(file,O_CREAT|O_WRONLY|O_TRUNC,0600);

  char ans[1000000]="Name: ";
  strcat(ans,studentsName[x]);
  strcat(ans,"\n");
  strcat(ans,"RollNum: ");
  strcat(ans,studentsRoll[x]);
  strcat(ans,"\n");

  float cpi[8];
  float spi[8];
  float ccred=0;
  float cscore=0;
  REP(s,1,8)
  {
    float scred=0;
    float sscore=0;
    strcat(ans,"\n");
    strcat(ans,"SEMESTER: ");
    char temp = s+'0';
    strcat(ans,&temp);
    strcat(ans,"\n");
    strcat(ans,"Course Number | Course Name | C | Grade\n");
    REP(g,0,9953)
    {
      REP(c,0,62)
      {
        if(check(gradesRoll[g],studentsRoll[x]))
        {printf("%s %s",gradesRoll[g],studentsRoll[x]);
        printf("\n");}
        if(check(gradesRoll[g],studentsRoll[x])&&check(gradesName[g],courseNum[c])&&temp==courseSem[c][0])
        {
          strcat(ans,gradesName[g]);
          strcat(ans,"            ");
          strcat(ans,courseNum[c]);
          strcat(ans,"        ");
          strcat(ans,courseCred[c]);
          strcat(ans,"     ");
          strcat(ans,gradesGrade[g]);
          strcat(ans,"\n");
          sscore = point(gradesGrade[g])*credits(courseCred[c]);
          scred = credits(courseCred[c]);

        }
      }
    }
    spi[s-1]=(sscore)/(scred);
    ccred+=scred;
    cscore+=sscore;
    cpi[s-1]=(cscore)/(ccred);

  }
  strcat(ans,"\n");
  strcat(ans,"         ");
  strcat(ans,"1        ");
  strcat(ans,"2        ");
  strcat(ans,"3        ");
  strcat(ans,"4        ");
  strcat(ans,"5        ");
  strcat(ans,"6        ");
  strcat(ans,"7        ");
  strcat(ans,"8        \n");
  strcat(ans,"SPI      ");

  REP(y,0,7)
  {
  char temp[5];
  gcvt(spi[y],3,temp);

  strcat(ans,temp);
  strcat(ans,"    ");


  }
  strcat(ans,"\n");
  strcat(ans,"CPI      ");

  REP(y,0,7)
  {
  char temp[5];
  gcvt(cpi[y],3,temp);

  strcat(ans,temp);
  strcat(ans,"    ");


  }
  strcat(ans,"\n");
  strcat(ans,"\n");



  int n = strlen(ans);
  char fans[n];
  REP(k,0,n-1)
  fans[k]=ans[k];
  int t=write(fd,fans,n);

  }






}
