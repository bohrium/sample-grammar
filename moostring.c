#include "moostring.h"
#include <stdio.h>

void append_cstr(CharBuffer* buf, char const* cstr)
{
    while (buf->start!=buf->end && *cstr) {
        *(buf->start) = *cstr;
        buf->start += 1;
        cstr += 1;
    }
    *(buf->start) = '\0';
}

void print_buf(CharBuffer const* buf)
{
    printf("%s", buf->start);
}
