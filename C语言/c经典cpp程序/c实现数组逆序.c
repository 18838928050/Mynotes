#include <stdio.h>
//#include <stdlib.h>
#define N 4  //����ط���N������ĳ���
int main()
{
int array[N]={98,87,45,43};
//ʵ�����������-ԭ������������βԪ�ؽ��н���
int temp;
int i;
for(int i=0;i<N/2;i++)
{
//��i��ֵ�͵�N-i-1����ֵ�ཻ��
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
