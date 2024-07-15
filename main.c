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
  token_t T;

  while (scan(&T)) {
    printf("Token %s", tokstr[T.token_type]);
    if (T.token_type == INTLIT_T)
      printf(", value %d", T.intvalue);
    printf("\n");
  }
}

int main(int argc,char** argv){
  init();
  
  inFile = fopen(argv[1], "r");
  
  scanfile();
  
  return 0;    
}