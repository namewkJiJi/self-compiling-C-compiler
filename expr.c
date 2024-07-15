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

//Pratt Parsing
static int op_prec[] = {10,10,20,20,  0     ,0};
//               +,  -, *, /,INTLIT_T,EOF_T

static int get_prec(int op){
   int prec = op_prec[op];
   //syntax check
   if(prec == 0){
    printf("syntax error on line %d\n",line);
    exit(1);
   }

   return prec; 
}

//建立二元表达式的AST树
ASTNode_t * binexpr(int prec){
    //局部变量，递归在不同的层有不同的值
    ASTNode_t *left,* right;
    int op;

    //获取左子树(数字)
    left = primary();
    
    //获取根节点（符号）
    if(token.token_type == EOF_T){
        return left;
    }
    op = token.token_type;
    
    while(get_prec(op) > prec){
        //更新token
        //放在此位置：
        //token是全局的，要在进入下一层递归前更新
        scan(&token);

        //获取右子树
        right = binexpr(get_prec(op));

        //生成子树
        left = mk_astnode(arith_op(op),left,right,0);//根节点无整数值，设为0，无所谓

        //更新操作符
        if(token.token_type == EOF_T){
            return left;
        }
        op = token.token_type;
    }
    
    return left;
}
