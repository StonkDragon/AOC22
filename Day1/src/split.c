#include "../scale_support.h"

void Method_Array_init(void);
void Method_Array_push(void);

sclDefFunc(splitAtDelim, struct Array*) {
    scl_str sep = stack.data[--stack.ptr].s;
    scl_str string = strdup(stack.data[--stack.ptr].s);
    struct Array* arr = scl_alloc_struct(sizeof(struct Array), "Array");
    stack.data[stack.ptr++].i = 10;
    stack.data[stack.ptr++].v = arr;
    Method_Array_init();

    scl_str line = strtok(string, sep);
    while (line != NULL) {
        stack.data[stack.ptr++].s = line;
        stack.data[stack.ptr++].v = arr;
        Method_Array_push();
        // printf("Line: %s\n", line);
        line = strtok(NULL, sep);
    }
    return arr;
}
