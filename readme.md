# a self-compiling compiler for a subset of the C language

## Lexical Scanning

five lexical elements(token):

- `*`
- `+`
- `/`
- `-`
- digits

goals:

- read in one character at a time
- "put back" a character if we have read too far ahead in the input stream
- track what line we are currently on

extern_的使用：

- 其他文件（在引用data.h之前未定义extern_）：extern_ 替换为extern 即该变量在外部文件中定义
- 在main.c文件中，在引用data.h之前定义extern_为空，即在main.c中实际定义被声明为extern_的变量
- data.h中的宏extern_允许你通过在不同的编译单元中**有条件地包含文件**(是否在包含文件之前空定义extern_)来控制变量的定义与声明，从而实现变量的外部链接。在一个编译单元中定义变量，在其他编译单元中声明变量

## Operator Precedence

定义运算优先级-对表达式进行分类：乘法表达式和加法表达式
