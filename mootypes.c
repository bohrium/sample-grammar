#include "moostring.h"
#include "mootypes.h"
#include <stdio.h>

void hello(void)
{
    Type g = make_base("goo");
    Type s = make_base("sooch");
    Type t = make_arrow(&g, &s); 
    print_type(&t);
}

void render_type(Type const* t, CharBuffer* cb);
void print_type(Type const* t)
{
    char s[64+1];
    CharBuffer cb = {.start=s, .end=s+64}; 
    render_type(t, &cb);
    printf("%s\n", s); 
}
void render_type(Type const* t, CharBuffer* cb)
{
    switch (t->tag) {
        case tag_base:
            append_cstr(cb, t->data.base);
            break;
        case tag_arrow:
            append_cstr(cb, "(");
            render_type(t->data.arrow.out, cb);
            append_cstr(cb, "<-");
            render_type(t->data.arrow.arg, cb);
            append_cstr(cb, ")");
            break;
        case tag_multiset:
            append_cstr(cb, "{");
            render_type(t->data.multiset.child, cb);
            append_cstr(cb, "}");
            break;
    }
}

Type make_base(char* name)
{
    Type t = {
        .tag = tag_base,
    };
    char* p = t.data.base;
    while (*name) {
        *p = *name;
        p += 1;
        name += 1;
    }
    return t;
}
Type make_arrow(Type* out, Type* arg)
{
    Type t = {
        .tag = tag_arrow,
        .data.arrow.out = out,
        .data.arrow.arg = arg
    };
    return t;
} 
Type make_multiset(Type* child)
{
    Type t = {
        .tag = tag_multiset,
        .data.multiset.child = child
    };
    return t;
}
