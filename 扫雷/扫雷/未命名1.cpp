/* ����������ͳ��Сд��ĸ���� */
/* ���ڴ˴���Ӵ��룬ͳ��ÿ��СдӢ����ĸ���ֵĴ��� */
/********** Begin **********/
#include<stdio.h>
int main ()
{
    char a[50],b[26]={0};
    scanf("%s",&a);
    int i=0;
    while(a[i]!='\0')
    {
        if(a[i]>='a'&&a[i]<='z')
        {
            int n=a[i]-'a';
            b[n]++;
        }
        i++;
    }
    char ret='a';
    for(int i=0;i<26;i++)
    {
        printf("��ĸ%c���ֵĴ���Ϊ��%d\n",ret,a[i]);
        ret++;
    }
    return 0;
}
    
    
/********** End **********/

