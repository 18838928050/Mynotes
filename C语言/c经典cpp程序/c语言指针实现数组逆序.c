#include <stdio.h>
#include <stdlib.h>
#define N 5  //����ط���N������ĳ���
int main()
{
    int array[N]={15,87,45,43,45};
    //ʵ�����������-ԭ������������βԪ�ؽ��н���
    int temp;
    int i;
    int * ptr_arr_start=array;//ָ��������Ԫ�ص�ָ��
    int * ptr_arr_end=array+N-1;//ָ������ĩԪ�ص�ָ�룬3������ĳ��ȣ�Ҳ����������N-1��������һ����
     while(ptr_arr_start != ptr_arr_end)
        {
       //��β������ָ��ֱ���и���
        temp= *ptr_arr_start;
        *ptr_arr_start= *ptr_arr_end;
        *ptr_arr_end= temp;
        //��Ԫ��ָ��Ҫ����ƶ���
        ptr_arr_start++;
        //ĩԪ��ָ����ǰ�ƶ�
        ptr_arr_end--;

        }

        printf("\n");
        for(i=0;i<N;i++)
        {

        printf("%d\t",*(array+i));
        }

}
