#ifndef MOOSTRING_H
#define MOOSTRING_H

struct CharBuffer {
    char* start;
    char* end;
}; 
typedef struct CharBuffer CharBuffer;

void append_cstr(CharBuffer* buf, char const* cstr);
void print_buf(CharBuffer const* buf);

#endif//MOOSTRING_H
