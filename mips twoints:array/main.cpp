

#include <stdlib.h>
#include <stdio.h>


int wain(int *a, int b) {
  int big = 536870912;
  int small = 16777216;
  int* Big = NULL;
  int num = 241;
  Big = a+big;
  if(Big >= Big-small) {
    num = num + 240000;
  } else {}
  if(big >= big-small) {
    num = num +   1000;
  } else {}
  if(Big <= Big+small) {
    num = num + 240000000;
  } else {}
  if(big <= big+small) {
    num = num +   1000000;
  } else {}
  return num;
}



int main(){
    int b;
    scanf("%d", &b);
    int *a = (int*)malloc(b * sizeof(int));
    for(int i=0; i<b; i++){
        scanf("%d", a+i);
    }
    printf("%d\n",wain(a,b));
    return 0;
}

//int main(){
//    int a;
//    int b;
//    scanf("%d", &a);
//    scanf("%d", &b);
//    printf("%d\n",wain(a,b));
//    return 0;
//}