#ifndef MOOTYPES_H
#define MOOTYPES_H

#include "moostring.h"

/*===========================================================================*/
/*====  0. TYPES  ===========================================================*/
/*===========================================================================*/

#define tag_arrow 0
#define tag_multiset 1
#define tag_base 2

struct Type {
    union {
        struct {
            struct Type* out;
            struct Type* arg;
        } arrow; 
        struct {
            struct Type* child;
        } multiset; 
        char base[8];
    } data;
    char tag;
};
typedef struct Type Type;

void print_type(Type const* t); 
Type make_base(char* name);
Type make_arrow(Type* out, Type* arg); 
Type make_multiset(Type* child);
void hello(void);

#endif//MOOTYPES_H
