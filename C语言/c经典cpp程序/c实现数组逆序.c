#include <stdio.h>
//#include <stdlib.h>
#define N 4  //这个地方的N是数组的长度
int main()
{
int array[N]={98,87,45,43};
//实现数组的逆序-原理就是数组的首尾元素进行交换
int temp;
int i;
for(int i=0;i<N/2;i++)
{
//第i个值和第N-i-1个的值相交换
        temp=array[i];
        array[i]=array[N-i-1];
        array[N-i-1]=temp;
}
printf("\n");
for(int i=0;i<N;i++)
{

    printf("%d\t",*(array+i));
}

}
