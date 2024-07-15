#ifndef DECL_H
#define DECL_H

#include "defs.h"

//scan
int scan(token_t *token);

//tree
ASTNode_t * mk_astnode(int op,ASTNode_t * left,ASTNode_t * right,int intvalue);
ASTNode_t * mk_astleaf(int op,int val);
ASTNode_t * mk_astunary(int op,ASTNode_t * left,int val);

//expr
ASTNode_t * binexpr(int prec);

//interp
int interpretAST(ASTNode_t * node);

#endif