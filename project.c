#include<unistd.h>
#include<stdio.h>
int comt[40]={0};
int t_q=1;
int qas[40]={0};
int c=0;
int st;
int btm[40]={0};
int tt;
int wt;
int at[40];
int bt[40];
int zz;
int a;
void queue1(int fin,int tm);
void queue2(int fin, int tm);
void pop(int fin);
float att, awt;
int flg=0,tm=0,ee=0,fin=0;
void pop(int fin){
qas[ee]=fin+1;
ee++;
}
void queue1(int fin,int tm){
for(int x=fin+1;x<4;x++){
if(at[x]<=tm){
qas[ee]=x+1;
ee++;}
}
}
void queue2(int fin, int tm){
for(int x=fin+1;x<4;x++){
int fl=0;
for(int y=0;y<ee;y++){
if(qas[y]==x+1){
fl++;}}
if(at[x]<=tm && fl==0 && btm[x]!=0){
qas[ee]=x+1;
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
scanf("%d",&at[x]);
printf(" Enter Burst Time  :");
scanf("%d",&bt[x]);
btm[x]=bt[x];}
do{
if(flg==0){
st=at[0];
if(btm[0]<=t_q){
tm=st+btm[0];
btm[0]=0;
queue1(fin,tm);}
else{
btm[0]=btm[0]-t_q;
tm=st+t_q;
queue1(fin,tm);
pop(fin);}
}
else{
fin=qas[0]-1;
st=tm;
for(int x=0;x<ee && ee!=1;x++){
qas[x]=qas[x+1];}
ee--;
if(btm[fin]<=t_q){
tm=st+btm[fin];
btm[fin]=0;
queue2(fin, tm);}
else{
btm[fin]=btm[fin]-t_q;
tm=st+t_q;
queue2(fin, tm);
pop(fin);}
}
if(btm[fin]==0){
comt[fin]=tm;
}
flg++;
}while(ee!=0);
printf("}  ");
printf("\n\nProcess\t Arriv_Time\t Burst_Time\tfinish_Time\tT_a_T\t \tWait_Time\n");
printf("------------------------------------------------------------------------------\n");
for(int x=0;x<zz;x++){
tt=comt[x]-at[x];
wt=tt-bt[x];

printf("P%d\t|  %d\t|\t   %d\t|\t  %d\t|\t  %d\t|\t   %d\n",x+1,at[x],bt[x],comt[x],tt,wt);
printf("------------------------------------------------------------------------------\n");
awt=awt+wt;
att=att+tt;
}
printf("\nAvg_Turn_Around_Time: %f\nAvg_Waiting_Time: %f",att/4,awt/4);

printf("\nEnter '1' if u want to run again.\n Enter '0' if you want to exit");
scanf("%d",&a);
}while(a==1);
printf("--------------------------------Have great day!!----------------------------");
printf("\n-------------------------------Thank-You!!----------------------------------");
}
