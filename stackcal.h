/*************************************************************************
    > File Name: stackcal.h
    > Author: NoMi
    > Mail: 1559674040@qq.com
    > Created Time: 2019年08月01日 星期四 14时16分27秒
 ************************************************************************/

#ifndef _STACKCAL_H
#define _STACKCAL_H
#endif

#include<stdio.h>
#include<string.h>
#include<QString>

QString Run(QString STR);
float op_num(char c, float d1, float d2);

typedef struct stack_op{
    char op[2019];
    int top;
}oprator, *oprator_t;
typedef struct stack_cu{
    float data[2019];
    int top;
}number, *number_t;

//创建操作符栈
oprator_t create_opratorstack(void);
//创建操作数栈
number_t create_numberstack(void);

//操作符入栈
int pushStack_op(oprator_t op_S, char c);
//操作符出栈
char readStack_op(oprator_t op_S);
//判断栈满
int isFull_stack_op(oprator_t op_S);
//判断栈空
int isEmpty_stack_op(oprator_t op_S);

//操作数入栈
int pushStack_cu(number_t num_S, float a);
//操作数出栈
float readStack_cu(number_t num_S);
//判断栈满
int isFull_stack_num(number_t num_S);
//判断栈空
int isEmpty_stack_num(number_t num_S);

//初始化操作符栈
void init_oprator(oprator_t op_S);
//遍历操作符栈
void print_oprator(oprator_t op_S);

//初始化操作数栈
void init_number(number_t num_S);
//遍历操作数栈
void print_number(number_t num_S);

//返回优先级
int pri(char ch);
//是否为可执行字符(运算符，操作数)
int is_op(char ch);
int is_num(char ch);

