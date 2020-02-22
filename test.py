import moo

a = moo.make_base("goo")
moo.print_type(a)
b = moo.make_base("moo")
c = moo.make_arrow(a, b) 
moo.print_type(c)
