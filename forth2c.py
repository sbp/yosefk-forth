#!/usr/bin/python
import sys
# "special" words - can't emit s=WORD(s)
special = {
  ':':'data* ',
  ';':'return s; }',
  '.':'PRINT();',
  'begin':'do {',
  'until':'} while(!*s++);',
  'repeat':'} while(1);',
  'while':'if(!*s++) break;',
}
# binary operators
binops='+ - * / = < > mod'.split()
op2c={'=':'==','mod':'%'}

def forth2c(inf,out):
  n = 0
  for line in inf:
    n += 1
    # emit line info for C tools (debuggers, etc.)
    # - a nice option C gives us
    print >> out,'\n#line',n,'"%s"'%infile
    for token in line.lower().strip().split():
      if token in special:
        print >> out,special[token],
      else:
        try:
          num = int(token)
          print >> out, 'PUSH(%d);'%num,
        except ValueError:
          if token in binops:
            print >> out,'OP2(%s);'%op2c.get(token,token),
          else:
            if defining:
              print >> out,token+'(data* s) {',
            else: # call
              print >> out,'s=%s(s);'%token,
      defining = token == ':'

out = open('forth_program.c','w')
print >> out, '#include "forth_runtime.h"'
for infile in sys.argv[1:]:
  forth2c(open(infile),out)
