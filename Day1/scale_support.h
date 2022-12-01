#ifndef SCALE_SUPPORT_H
#define SCALE_SUPPORT_H

#include <scale_internal.h>

#define scl_export(func_name) \
    void func_name (void); \
    void Function_ ## func_name (void); \
    void Function_ ## func_name () { func_name (); } \
    void func_name (void)

#define ssize_t signed long
typedef void* scl_value;
typedef long long scl_int;
typedef char* scl_str;
typedef double scl_float;

extern scl_stack_t stack;

struct Array {
  scl_int __type_identifier__;
  scl_str __type_string__;
  scl_value values;
  scl_int count;
  scl_int capacity;
};
#endif
