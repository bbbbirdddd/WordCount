#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fpr;
    char name[100] = {0};//存储路径名(文件名)
    int ch;
    int number = 0;//存储数字数量
    int character = 0;//存储字母数量
    int space = 0;//存储空格数量
    int total = 0;//存储所有字符数量

    scanf("%s",name);

    if((fpr = fopen(name,"r")) == NULL)//判断文件是否存在
    {
        printf("Can't open %s\n",name);
        exit(1);
    }
    while((ch = fgetc(fpr)) != EOF)
    {
       if(ch>=48 &&ch<=57)//数字的ASCII码
       {
            number++;
       }
       if((ch>=65&&ch<=90) || (ch>=97&&ch<=122))//字母的ASCII码
       {
           character++;
       }
       if(ch == 32)//空格的ASCII码
       {
           space++;
       }
       total++;
    }
    printf("字符数 = %d\n",total);
    return 0;
}
