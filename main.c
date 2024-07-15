#define extern_
#include "data.h"
#include "decl.h"
#include "defs.h"
#include <stdio.h>

static void init(){
    line = 1;
    putBack = 0;
}

// List of printable tokens
char *tokstr[] = { "+", "-", "*", "/", "intlit" };

// Loop scanning in all the tokens in the input file.
// Print out details of each token found.
static void scanfile() {
  scan(&token);
  ASTNode_t * n = binexpr(0);
  printf("%d\n",interpretAST(n));
}

int main(int argc,char** argv){
  init();
  
  inFile = fopen(argv[1], "r");
  
  scanfile();
  
  return 0;    
}