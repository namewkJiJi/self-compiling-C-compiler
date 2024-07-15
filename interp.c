/*
解释AST树
*/
#include "decl.h"
#include "defs.h"
#include "data.h"
#include <stdlib.h>

int interpretAST(ASTNode_t * node){
    int left,right;

    if(INTLIT_T == node->op){
        return node->intvalue;
    }

    if(node->left) left = interpretAST(node->left);
    if(node->right) right = interpretAST(node->right);

    switch (node->op)
    {
    case A_ADD:
        return (left + right);
    
    case A_SUBTRACT:
        return (left - right);

    case A_MULTIPLY:
        return (left * right);

    case A_DIVID:
        return (left / right);
    default:
        printf("Unknown operator %c on line %d\n",node->op,line);
        exit(1);
    }
}