#include "../scale_support.h"

void Method_Array_init(struct Array*, scl_int);
void Method_Array_push(struct Array*, scl_value);

sclDefFunc(splitAtDelim, struct Array*, scl_str sep, scl_str string) {
    struct Array* arr = scl_alloc_struct(sizeof(struct Array), "Array");
    Method_Array_init(arr, 10);

    scl_str line = strtok(string, sep);
    while (line != NULL) {
        Method_Array_push(arr, line);
        line = strtok(NULL, sep);
    }
    return arr;
}
