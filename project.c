#include<unistd.h>
#include<stdio.h>
int a;
int comt[100]={0};
int timeq=1;
int m[100]={0};
int c=0;
int k;
int m1[100]={0};
int t_a_t;
int wait_t;
int ariv_t[100];
int bur_t[100];
int zz;

void queue1(int fin,int tm);
void queue2(int fin, int tm);
void pop(int fin);
float att, awt;
int flg=0,tm=0,ee=0,fin=0;
void pop(int fin){
m[ee]=fin+1;
ee++;
}
void queue1(int fin,int tm){
for(int x=fin+1;x<4;x++){
if(ariv_t[x]<=tm){
m[ee]=x+1;
ee++;}
}
}
void queue2(int fin, int tm){
for(int x=fin+1;x<4;x++){
int fl=0;
for(int y=0;y<ee;y++){
if(m[y]==x+1){
fl++;}}
if(ariv_t[x]<=tm && fl==0 && m1[x]!=0){
m[ee]=x+1;
ee++;}
}
}
int main()
{
printf("-------------------------------------------------welcome------------------------------------------------------\n");
printf("----------------------------------------------OS Assignment----------------------------------------------------\n");
do
{
printf("Enter no of process  :");
scanf("%d",&zz);
for(int x=0;x<zz;x++){
printf("\n Process %d",x+1);
printf("\nEnter Arrival Time  :");
scanf("%d",&ariv_t[x]);
printf(" Enter Burst Time  :");
scanf("%d",&bur_t[x]);
m1[x]=bur_t[x];}
do{
if(flg==0){
k=ariv_t[0];
if(m1[0]<=timeq){
tm=k+m1[0];
m1[0]=0;
queue1(fin,tm);}
else{
m1[0]=m1[0]-timeq;
tm=k+timeq;
queue1(fin,tm);
pop(fin);}
}
else{
fin=m[0]-1;
k=tm;
for(int x=0;x<ee && ee!=1;x++){
m[x]=m[x+1];}
ee--;
if(m1[fin]<=timeq){
tm=k+m1[fin];
m1[fin]=0;
queue2(fin, tm);}
else{
m1[fin]=m1[fin]-timeq;
tm=k+timeq;
queue2(fin, tm);
pop(fin);}
}
if(m1[fin]==0){
comt[fin]=tm;
}
flg++;
}while(ee!=0);
printf("}  ");
printf("\n\nProcess\t Arriv_Time\t Burst_Time\tfinish_Time\tT_a_T\t \tWait_Time\n");
printf("------------------------------------------------------------------------------\n");
for(int x=0;x<zz;x++){
t_a_t=comt[x]-ariv_t[x];
wait_t=t_a_t-bur_t[x];

printf("P%d\t|  %d\t|\t   %d\t|\t  %d\t|\t  %d\t|\t   %d\n",x+1,ariv_t[x],bur_t[x],comt[x],t_a_t,wait_t);
printf("------------------------------------------------------------------------------\n");
awt=awt+wait_t;
att=att+t_a_t;
}
printf("\nAvg_Turn_Around_Time: %f\nAvg_Waiting_Time: %f",att/4,awt/4);

printf("\nEnter '1' if u want to run again.\n Enter '0' if you want to exit");
scanf("%d",&a);
}while(a==1);
printf("--------------------------------Have great day!!----------------------------");
printf("\n-------------------------------Thank-You!!----------------------------------");
}
