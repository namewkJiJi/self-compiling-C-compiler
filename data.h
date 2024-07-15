/*
输入相关
*/
#ifndef DATA_H
#define DATA_H


//解释见readmme/extern_的使用
#ifndef extern_
#define extern_ extern
#endif

#include <stdio.h>
#include "defs.h"

extern_ int line;
extern_ int putBack;

extern_ FILE * inFile;

extern_ token_t token;

#endif