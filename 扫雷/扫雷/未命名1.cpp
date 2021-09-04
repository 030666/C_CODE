/* 本程序用于统计小写字母次数 */
/* 请在此处添加代码，统计每个小写英文字母出现的次数 */
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
        printf("字母%c出现的次数为：%d\n",ret,a[i]);
        ret++;
    }
    return 0;
}
    
    
/********** End **********/

