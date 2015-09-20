#include "forth_runtime.h"

#line 1 "countdown.4th"
data*  countdown(data* s) { 
#line 2 "countdown.4th"
do { 
#line 3 "countdown.4th"
s=dup(s); PRINT(); 
#line 4 "countdown.4th"
PUSH(1); OP2(-); 
#line 5 "countdown.4th"
s=dup(s); PUSH(0); OP2(==); 
#line 6 "countdown.4th"
} while(!*s++); 
#line 7 "countdown.4th"
s=drop(s); 
#line 8 "countdown.4th"
return s; } 
#line 1 "gcd.4th"
data*  gcd(data* s) { 
#line 2 "gcd.4th"
do { 
#line 3 "gcd.4th"
s=dup(s); 
#line 4 "gcd.4th"
if(!*s++) break; 
#line 5 "gcd.4th"
s=tuck(s); 
#line 6 "gcd.4th"
OP2(%); 
#line 7 "gcd.4th"
} while(1); 
#line 8 "gcd.4th"
s=drop(s); 
#line 9 "gcd.4th"
return s; } 
#line 1 "main.4th"
data*  forth_main(data* s) { 
#line 2 "main.4th"
PUSH(5); s=countdown(s); 
#line 3 "main.4th"
s=cr(s); 
#line 4 "main.4th"
PUSH(10); PUSH(6); s=gcd(s); PRINT(); 
#line 5 "main.4th"
PUSH(35); PUSH(75); s=gcd(s); PRINT(); 
#line 6 "main.4th"
PUSH(12856); PUSH(3248); s=gcd(s); PRINT(); 
#line 7 "main.4th"
s=cr(s); 
#line 8 "main.4th"
return s; }