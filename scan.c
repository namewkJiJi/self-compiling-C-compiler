/*
词法扫描相关函数
*/
#include "data.h"
#include "defs.h"
#include "decl.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// 编译器可以识别的数字字符
const char* dec_num = "0123456789";


//从输入流中获取下一个输入
static int get_next(void){
    int c = -1;

    //优先返回需要写回的字符（若存在）
    if(putBack){
        c = putBack;
        putBack = 0;
        return c;
    }    

    c = fgetc(inFile);
    if('\n' == c){
        line++;
    }

    return c;//若返回值小于0代表出现错误
}

//当读取超过预期时，需要将读取的字符串放回
//输入流，以备下次读取使用
static void put_back(int c){
    putBack = c;
}

//跳过不需要处理的输入值
static int is_valid_input(int c){
    if(' ' == c || '\t' == c || '\n' == c
    || '\r' == c || '\f' == c 
    ) return 0;


    return 1;
}

static int skip(void){
    int c = get_next();

    while(!is_valid_input(c)){
        c = get_next();
    }

    return c;
}

//读取数字输入
static int chrpos(const char * numbers,int c){
    const char * temp = numbers;
    
    temp = strchr(numbers,c);

    return (temp ? temp - numbers : -1);
}

static int scan_int(int c){
    int k = -1;    
    int val = 0;

    while((k=chrpos(dec_num,c)) >= 0){
        val = val*10 + k;
        c = skip();        
    }

    //跳出循环时，c多读取了一个输入值
    //需要将多读的字符放回输入流
    put_back(c);

    return val;
}

//获取token值
int scan(token_t *token){
    int c = skip();

    switch (c)
    {
    case EOF:
        return 0;
    case '+':
        token->token_type = PLUS_T;
        break;
    case '-':
        token->token_type = MINUS_T;
        break;
    case '*':
        token->token_type = STAR_T;
        break;
    case '/':
        token->token_type = SLASH_T;
        break;

    default:
        if(isdigit(c)){
            token->token_type = INTLIT_T;
            token->intvalue = scan_int(c);
            break;
        }

        printf("Unkown token %c on line %d\n",c,line);
        exit(0);
    }

}