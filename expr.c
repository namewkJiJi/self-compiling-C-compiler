/*
解析器生成表达式
*/

#include "defs.h"
#include "data.h"
#include "decl.h"
#include <stdlib.h>

//token to ast operation
static int arith_op(int tok){
    switch (tok)
    {
    case PLUS_T:
        return A_ADD;
    case MINUS_T:
        return A_SUBTRACT;
    case STAR_T:
        return A_MULTIPLY;
    case SLASH_T:
        return A_DIVID;
    default:
        printf("unknown token %c on line %d\n",tok,line);
        exit(1);
    }
}

//分配数字节点
static ASTNode_t * primary(void){
    ASTNode_t * n;

    switch (token.token_type)
    {
    case INTLIT_T:
        n = mk_astleaf(INTLIT_T,token.intvalue);
        
        //更新token值
        scan(&token);

        return n;
    default:
        printf("syntax error on line %d\n",line);
        exit(1);
    }
}

//建立二元表达式的AST树
ASTNode_t * binexpr(void){
    ASTNode_t * n, *left,* right;
    int intvalue,op;

    //获取左子树
    left = primary();
    if(token.token_type == EOF_T){
        return left;
    }

    //获取根节点（符号）
    op = token.token_type;
    //更新token
    scan(&token);

    //获取右子树
    right = binexpr();

    //设置根节点
    n = mk_astnode(op,left,right,0);//根节点无整数值，设为0，无所谓
    return n;
}
