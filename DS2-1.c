#include <stdio.h>
#define size 5     //size of deque(double ended queue)
int dq[size],f=-1,r=-1;
void ins_atfront() {
  int v;
  if(r==0) {
    puts("Deque Overflow At Front...");
    return;
  }
  if(f==-1) f=r=size;
  printf("Enter a Element to Front of Deque: ");
  scanf(" %d",&v);
  f--;
  dq[f]=v;
  if(r==size) {
    r=size-1;
  }
}
void ins_atrear() {
  int v;
  if(r==size-1) {
    puts("Deque Overflow At Rear...");
    return;
  }
  else {
    if(f==-1) f=0;
    printf("Enter a Element to Rear of Deque: ");
    scanf(" %d",&v);
    r++;
    dq[r]=v;
    display();
  }
}
void dlt_fromfront() {
  int v;
  if(f==-1) {
    puts("Deque is Underflow.");
  }
  else {
    v=dq[f];
    if(f==r) f=r=-1;
    else f++;
    printf("Removed element is %d.",v);
    display();
  }
}
void dlt_fromrear(){
  int v;
  if(r==-1) puts("Deque is Underflow.");
  v=dq[r];
  printf("Removed element is %d.",v);
  if(f==r) f=r=-1;
  else r--;
}
void display() {
  if(f==-1) {
    puts("Deque is Underflow.");
  }
  else {
    puts("Elements are...");
    for(int i=f;i<=r;i++) {
      printf(" %d",dq[i]);
    }
  }puts("");
}
int main()
{
  int c;
  do {
    puts("press 0 for Exit...");
    puts("press 1 for Insert at Rear...");
    puts("press 2 for Insert at Front...");
    puts("press 3 for Delete from Rear...");
    puts("press 4 for Delete from Front...");
    puts("press 5 for Display Deque...");
    puts("press from above...");
    scanf("%d",&c);
    if(c==0) break;
    else if(c==1) ins_atrear();
    else if(c==2) ins_atfront();
    else if(c==3) dlt_fromrear();
    else if(c==4) dlt_fromfront();
    else if(c==5) display();
    else puts("Invalid choice...\nTry Again...");
    getch();
  }while(c != 0);
}
