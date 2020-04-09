#include<unistd.h>
#include<stdio.h>
int a;
int comt[100]={0};
int c=0;
int ariv_t[100];
int bur_t[100];
int p;
int k;
int m1[100]={0};
int t_a_t;
int wait_t;
int timeq=1;
int m[100]={0};


void q1(int f,int t);
void q2(int f, int t);
void out(int f);
float l, q;
int flag=0,t=0,ee=0,f=0;
void out(int f){
m[ee]=f+1;
ee++;
}
void q1(int f,int t){
for(int x=f+1;x<4;x++){
if(ariv_t[x]<=t){
m[ee]=x+1;
ee++;}
}
}
void q2(int f, int t){
for(int x=f+1;x<4;x++){
int fl=0;
for(int y=0;y<ee;y++){
if(m[y]==x+1){
fl++;}}
if(ariv_t[x]<=t && fl==0 && m1[x]!=0){
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
scanf("%d",&p);
for(int x=0;x<p;x++){
printf("\n Process %d",x+1);
printf("\nEnter Arrival Time  :");
scanf("%d",&ariv_t[x]);
printf(" Enter Burst Time  :");
scanf("%d",&bur_t[x]);
m1[x]=bur_t[x];}
do{
if(flag==0){
k=ariv_t[0];
if(m1[0]<=timeq){
t=k+m1[0];
m1[0]=0;
q1(f,t);}
else{
m1[0]=m1[0]-timeq;
t=k+timeq;
q1(f,t);
out(f);}
}
else{
f=m[0]-1;
k=t;
for(int x=0;x<ee && ee!=1;x++){
m[x]=m[x+1];}
ee--;
if(m1[f]<=timeq){
t=k+m1[f];
m1[f]=0;
q2(f, t);}
else{
m1[f]=m1[f]-timeq;
t=k+timeq;
q2(f, t);
out(f);}
}
if(m1[f]==0){
comt[f]=t;
}
flag++;
}while(ee!=0);
printf("}  ");
printf("\n\nProcess\t Arriv_Time\t Burst_Time\tfinish_Time\tT_a_T\t \tWait_Time\n");
printf("------------------------------------------------------------------------------\n");
for(int x=0;x<p;x++){
t_a_t=comt[x]-ariv_t[x];
wait_t=t_a_t-bur_t[x];

printf("P%d\t|  %d\t|\t   %d\t|\t  %d\t|\t  %d\t|\t   %d\n",x+1,ariv_t[x],bur_t[x],comt[x],t_a_t,wait_t);
printf("------------------------------------------------------------------------------\n");
q=q+wait_t;
l=l+t_a_t;
}
printf("\n__________________________________________________________");
printf("\nAvg_Turn_Around_Time: %f\n____________________________________________________\nAvg_Waiting_Time: %f",l/4,q/4);
printf("\n__________________________________________________________");

printf("\nEnter '1' if u want to run again.\n Enter '0' if you want to exit :");
scanf("%d",&a);
}while(a==1);
printf("--------------------------------Have great day!!----------------------------");
printf("\n-------------------------------Thank-You!!----------------------------------");
}
