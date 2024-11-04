#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int anArray[] = {5,16,33,99};//定义数组
  int * p = anArray;//定义指针
  printf("*p = %d\n", *p);//指向第一个
  p++;
  printf("Now *p = %d\n", *p);
  int * q = &anArray[3];//99    q为地址  *为访问
  int ** x = &q;// 多一层解引用   取地址  一个指针指向地址
  **x = 12;
  *x = p;
  **x = 42;
  q[1] = 9;
  for (int i =0; i < 4; i++){
    printf("anArray[%d] = %d\n",i, anArray[i]);
  }
  return EXIT_SUCCESS;
}
