#include <stdio.h>
typedef long data;

#define PUSH(item) (--s, *s = (item))
#define OP2(op) (s[1] = s[1] op s[0], ++s)
#define PRINT() (printf("%ld ", s[0]), ++s)
#define cr(s) (printf("\n"), s)
#define drop(s) (s+1)
#define dup(s) (--s, s[0]=s[1], s)
#define tuck(s) (--s, s[0]=s[1], s[1]=s[2], s[2]=s[0], s)

#define MAX_DEPTH 4096 //arbitrary
data stack[MAX_DEPTH];
data* forth_main(data*);
int main() { forth_main(stack+MAX_DEPTH); return 0; }
