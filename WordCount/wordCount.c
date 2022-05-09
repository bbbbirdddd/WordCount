#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char name[100]={0};//文件名格式"E:\GIT\git\WordCount\'char'_input.txt"
    char ch;
    int length=0;
    //getchar();
    scanf("%s",name);
    length=strlen(name);
    ch=name[21];
    if(ch=='C') CharCount(name);//若文件名以"C"开头则统计字符数
    else WordCount(name);            //若文件名以"W"开头则统计单词数
    /*
    puts(name);
    printf("length=%d name[21]=%c\n",length,name[21]);
    */
    return 0;
}

void CharCount(char name[100]){//统计文件中的字符数
    FILE *fpr;
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
    printf("字符数: %d\n",total);
    
}

void WordCount(char name[100]){//统计文件中的单词数
    int total;
    FILE *fpr;
    char ch;
    if((fpr = fopen(name,"r")) == NULL)//判断文件是否存在
    {
        printf("Can't open %s\n",name);
        exit(1);
    }
    if(fpr==NULL)
    {
        printf("Open Failed!\n");
        exit(1);
    }
    while((ch = fgetc(fpr)) != EOF)
    {
       /*if((ch>=65&&ch<=90) || (ch>=97&&ch<=122))//字母的ASCII码
       {
           total++;
       }*/
       if(ch==32)//空格的ASCII码
           total++;
    }
    printf("单词数为%d\n",total+1);
}

