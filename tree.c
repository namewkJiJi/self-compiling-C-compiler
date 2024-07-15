/*
建立AST树的相关函数
*/

#include "defs.h"
#include "decl.h"
#include <stdlib.h>
#include <stdio.h>

//创建AST节点
ASTNode_t * mk_astnode(int op,ASTNode_t * left,ASTNode_t * right,int intvalue){
    ASTNode_t * n = (ASTNode_t *)malloc(sizeof(ASTNode_t));

    if(!n){
        printf("memory error:failed to create AST node\n");
        exit(1);
    }

    n->op = op;
    n->left = left;
    n->right = right;
    n->intvalue = intvalue;

    return n;
}

ASTNode_t * mk_astleaf(int op,int val){
    return mk_astnode(op,NULL,NULL,val);
}

ASTNode_t * mk_astunary(int op,ASTNode_t * left,int val){
    return mk_astnode(op,left,NULL,val);
}