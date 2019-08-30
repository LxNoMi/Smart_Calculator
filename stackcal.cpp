/*************************************************************************
    > File Name: stackal.c
    > Author: NoMi
    > Mail: 1559674040@qq.com
    > Created Time: 2019年08月01日 星期四 14时38分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"stackcal.h"

QString backmsg = "0";

//创建操作符栈
oprator_t create_opratorstack(void)
{
    oprator_t op_s = (oprator_t)malloc(sizeof(oprator));
    op_s->top = 0;
    op_s->op[op_s->top] = '#';
    return op_s;
}
//创建操作数栈
number_t create_numberstack(void)
{
    number_t num_s = (number_t)malloc(sizeof(number));
    num_s->top = -1;
    return num_s;
}

//操作符入栈
int pushStack_op(oprator_t op_S, char c)
{
    if(isFull_stack_op(op_S))
        return -1;
    op_S->top++;
    op_S->op[op_S->top] = c;
    return 0;
}

//操作符出栈
char readStack_op(oprator_t op_S)
{
    char ch;
    if(isEmpty_stack_op(op_S))
        return 'E';
    ch = op_S->op[op_S->top];
    op_S->top--;
    return ch;
}

//判断栈满
int isFull_stack_op(oprator_t op_S)
{
    if(2019 == op_S->top)
        return 1;
    else
        return 0;
}

//判断栈空
int isEmpty_stack_op(oprator_t op_S)
{
    if(-1 == op_S->top)
        return 1;
    else
        return 0;
}

//操作数入栈
int pushStack_cu(number_t num_S, float a)
{
    if(isFull_stack_num(num_S))
        return -1;
    num_S->top++;
    num_S->data[num_S->top] = a;
    return 0;
}

//操作数出栈
float readStack_cu(number_t num_S)
{
    float a;
    if(isEmpty_stack_num(num_S))
        return -1.0;
    a = num_S->data[num_S->top];
    num_S->top--;
    return a;
}

//判断栈满
int isFull_stack_num(number_t num_S)
{
    if(2019 == num_S->top)
        return 1;
    else
        return 0;
}

//判断栈空
int isEmpty_stack_num(number_t num_S)
{
    if(-1 == num_S->top)
        return 1;
    else
        return 0;
}

//初始化操作符栈
void init_oprator(oprator_t op_S)
{
    int i = 'A';
    for(i = 'A'; i < 'G'; i++)
    {
        op_S->top++;
        op_S->op[op_S->top] = i;
    }
    return;
}
//遍历操作符栈
void print_oprator(oprator_t op_S)
{
    for(;op_S->top > -1; op_S->top--)
    {
        printf("%c ", op_S->op[op_S->top]);
    }
    printf("\n");
    return;
}

//初始化操作数栈
void init_number(number_t num_S)
{
    int i = 0;
    for(i = 0; i < 9; i++)
    {
        num_S->top++;
        num_S->data[num_S->top] = i+1;
    }
    return;
}
//遍历操作数栈
void print_number(number_t num_S)
{
    for(; num_S->top > -1; num_S->top--)
    {
        printf("%.2f ", num_S->data[num_S->top]);
    }
    printf("\n");
    return;
}

//返回优先级
int pri(char ch)
{
    switch(ch)
    {
        case '#':
        {
            return -1;
            break;
        }
        case '+':
        {
            return 2;
            break;
        }
        case '*':
        {
            return 3;
            break;
        }
        case '-':
        {
            return 2;
            break;
        }
        case 'x':
        {
            return 3;
            break;
        }
        case '/':
        {
            return 3;
            break;
        }
        case '^':
        {
            return 4;
            break;
        }
        case '(':
        {
            return 0;
            break;
        }
        case ')':
        {
            return 1;
            break;
        }
        default:
            printf("select pri faild!\n");

    }
    return -1;
}

//判断操作符
int is_op(char ch)
{
    int i = 0;
    char s[8] = {'+', '-', 'x', '/', '^', '(', ')', '*'};
    for(i = 0; i < 8; i++)
    {
        if(s[i] == ch)
            return 1;
    }
    return 0;
}

//判断操作数
int is_num(char ch)
{
    if(ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

//清洗字符串
void wash_str(char a[])
{
    char *p = a;
    while(1)
    {
        if('=' == *p)
            break;
        else
        {
            if('\0' == *(p+1))
            {
                *(++p) = '=';
                break;
            }
        }
        p++;
    }
    //printf("%s\n", a);
}

//程序执行函数
QString Run(QString STR)
{
    char str[41]="";
    QByteArray ba = STR.toLatin1();
    char *q = ba.data();
    strcpy(str, q);

    char *p = NULL;
    float d1, d2, d3;
    float count = 0;
    char t_c;
    int flag = 0;
    oprator_t opr = create_opratorstack();
    number_t num = create_numberstack();

    //处理输入字符串
    wash_str(str);
    p = str;

    //精华部分，入栈出栈，进行计算！
    while('\0' != *p)
    {
        //sleep(1);
        //操作数处理
        if(is_num(*p))
        {
            count = count*10 + (*p - '0');
            if(is_num(*(p+1)))
            {
                p++;
                continue;
            }
            else
            {
                pushStack_cu(num, count);
                //printf("in:%.2f ", count);
                count = 0;
            }
        }
        //操作符处理
        else if(is_op(*p))
        {
            //操作符进栈情况
            if(('(' == *p) || (pri(opr->op[opr->top]) < pri(*p)) )
               {
                pushStack_op(opr, *p);
                //printf("in:%c ", *p);
               }
            //右括号处理
            else if(')' == *p)
            {
                //printf("meet:) ");
                t_c = readStack_op(opr);
                while('(' != t_c)
                {
                    d1 = readStack_cu(num);
                    d2 = readStack_cu(num);
                    d3 = op_num(t_c, d2, d1);
                    pushStack_cu(num, d3);
                    //printf("take %.2f %.2f get:%.2f\n", d2, d1, d3);
                    t_c = readStack_op(opr);
                    //sleep(1);
                }
                //printf("out:( \n");
            }
            //优先级高，进行运算并继续比较
            else if(pri(opr->op[opr->top]) >= pri(*p))
            {
                d1 = readStack_cu(num);
                d2 = readStack_cu(num);
                d3 = op_num(readStack_op(opr), d2, d1);
                pushStack_cu(num, d3);
                //printf("take %.2f %.2f get:%.2f", d2, d1, d3);
                pushStack_op(opr, *p);
                //sleep(1);
            }
        }
        //遇到"="号
        else if('=' == *p)
        {
            while('#' != opr->op[opr->top])
            {
                d1 = readStack_cu(num);
                d2 = readStack_cu(num);
                d3 = op_num(readStack_op(opr), d2, d1);
                pushStack_cu(num, d3);
                //printf("take %.2f %.2f get:%.2f", d2, d1, d3);
                //sleep(1);
            }
        }
        if('z' == *p || 'Z' == *p)
        {
            flag = -1;
            break;
        }
        p++;
    }
    printf("\n\n*****************over*************************\n");
    if(backmsg == "ERROR")
    {
        return backmsg;
    }
    else
    {
        return QString("%1").arg(readStack_cu(num));
    }
}

//计算函数
float op_num(char c, float d1, float d2)
{
    switch(c)
    {
        case '+':
        {
            return d1 + d2;
            break;
        }
        case '-':
        {
            return d1 - d2;
            break;
        }
        case 'x':
        {
            return d1 * d2;
            break;
        }
        case '*':
        {
            return d1 * d2;
            break;
        }
        case '/':
        {
            if(0 == d2)
            {
                backmsg = "ERROR";
                printf("/0");
                return 0;
            }
            else
            {
                return d1/d2;
                break;
            }
        }
        case '^':
        {
            int n = d2;
            int sum = 1;
            while(n--)
                sum *= d1;
            return sum;
            break;
        }
        default:
            backmsg = "ERROR";
            printf("no opr");
            return 0;
    }
}

