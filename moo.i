%module moo

%{
#define SWIG_FILE_WITH_INIT
#include "moostring.h"
#include "mootypes.h"
%}

void append_cstr(CharBuffer* buf, char* const cstr);
void print_buf(CharBuffer* const buf);

struct Type {
    union {
        struct {
            struct Type* out;
            struct Type* arg;
        } arrow; 
        struct {
            struct Type* child;
        } multiset; 
        char* base;
    } data;
    char tag;
};

void hello(void);
Type make_base(char* name);
Type make_arrow(Type* out, Type* arg); 
Type make_multiset(Type* child);
void print_type(Type const* t); 
