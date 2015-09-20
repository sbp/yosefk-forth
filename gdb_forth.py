class StackPrettyPrinter(object):
  bottom = None
  bot_expr = 'stack + sizeof(stack)/sizeof(stack[0])'
  def __init__(self,s):
    self.s = s
  def to_string(self):
    if not self.bottom:
      self.bottom = gdb.parse_and_eval(self.bot_expr)
    s = self.s
    i = 0
    words = []
    while s[i].address != self.bottom:
      words.append(str(s[i]))
      i += 1
    return ' '.join(reversed(words))

def stack_lookup_func(val):
  if str(val.type) == 'data *':
    return StackPrettyPrinter(val)

gdb.pretty_printers.append(stack_lookup_func)
print 'loaded Forth extensions'
