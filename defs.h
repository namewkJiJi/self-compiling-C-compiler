/*
存放编译器所需的数据结构定义
*/
#ifndef DEFS_H
#define DEFS_H

// token in lexical scanning
enum
{
    PLUS_T,
    MINUS_T,
    STAR_T,
    SLASH_T,
    INTLIT_T,// integer literal
    EOF_T,
};

typedef struct _token_t
{
    int token_type;
    int intvalue;//数字类型有值   
}token_t;


//AST 
enum
{
    A_ADD,
    A_SUBTRACT,
    A_MULTIPLY,
    A_DIVID,
    A_INTLIT,
};

typedef struct _ASTNode_t
{
    int op;
    struct _ASTNode_t * left;
    struct _ASTNode_t * right;
    int intvalue;
}ASTNode_t;

#endif