#include<stdio.h>
int main(){

int a[5]={97,98,100,86,74};
int *ptr;
ptr=&a[2];
printf("%d",*ptr);
return 0;
}
