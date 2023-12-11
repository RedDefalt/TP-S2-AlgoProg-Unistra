#include <stdio.h>


void echange1(int p1, int p2){
  int t= p1;
  p1 = p2;
  p2 = t;
  return;
}

void echange2 (int* p1, int* p2){
  int i = *p1;
  *p1 = *p2;
  *p2 = i;
  return;
}

void echange3(int* p1, int* p2){
  int* t= p1;
  p1 = p2;
  p2 = t;
  return;
}

void echange4(int** p1, int** p2){
  int* t= *p1;
  *p1 = *p2;
  *p2 = t;
  return;
}



int main() {
  int i =5;
  int j =7;
  int* pa = &i;
  int* pb = &j;

  printf("echange 1\n");
  printf("avant : i=%d et j=%d, *pa=%d et *pb=%d\n",i,j,*pa,*pb);
  echange1(*pa,*pb);
  printf("apres : i=%d et j=%d, *pa=%d et *pb=%d\n\n",i,j,*pa,*pb);

  i=5; j=7;  pa = &i; pb = &j;

  printf("echange 2\n");
  printf("avant : i=%d et j=%d, *pa=%d et *pb=%d\n",i,j,*pa,*pb);
  echange2(pa,pb);
  printf("apres : i=%d et j=%d, *pa=%d et *pb=%d\n\n",i,j,*pa,*pb);

  i=5; j=7;  pa = &i; pb = &j;

  printf("echange 3\n");
  printf("avant : i=%d et j=%d, *pa=%d et *pb=%d\n",i,j,*pa,*pb);
  echange3(pa,pb);
  printf("apres : i=%d et j=%d, *pa=%d et *pb=%d\n\n",i,j,*pa,*pb);

  i=5; j=7;  pa = &i; pb = &j;

  printf("echange 4\n");
  printf("avant : i=%d et j=%d, *pa=%d et *pb=%d\n",i,j,*pa,*pb);
  echange4(&pa,&pb);
  printf("apres : i=%d et j=%d, *pa=%d et *pb=%d\n\n",i,j,*pa,*pb);

  return 0;
}
