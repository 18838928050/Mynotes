#include <stdio.h>
#include <stdlib.h>
#define N 5  //这个地方的N是数组的长度
int main()
{
    int array[N]={15,87,45,43,45};
    //实现数组的逆序-原理就是数组的首尾元素进行交换
    int temp;
    int i;
    int * ptr_arr_start=array;//指向数组首元素的指针
    int * ptr_arr_end=array+N-1;//指向数组末元素的指针，3是数组的长度，也可以是数组N-1，道理是一样的
     while(ptr_arr_start != ptr_arr_end)
        {
       //首尾交换，指针分别进行更新
        temp= *ptr_arr_start;
        *ptr_arr_start= *ptr_arr_end;
        *ptr_arr_end= temp;
        //首元素指针要向后移动；
        ptr_arr_start++;
        //末元素指针向前移动
        ptr_arr_end--;

        }

        printf("\n");
        for(i=0;i<N;i++)
        {

        printf("%d\t",*(array+i));
        }

}
