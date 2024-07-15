/*
存放编译器所需的数据结构定义
*/
#ifndef DEFS_H
#define DEFS_H

// token by lexical scanning
typedef enum _token_type_t
{
    PLUS_T,
    MINUS_T,
    STAR_T,
    SLASH_T,
    INTLIT_T,// integer literal

}token_type_t;

typedef struct _token_t
{
    token_type_t token_type;
    int intvalue;//数字类型有值   
}token_t;

#endif