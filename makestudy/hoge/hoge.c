#define DEF_HOGE_C
#include "hoge.h"
#include "foo.h"
#include "stdio.h"

void sayHello(){
    printf("Hello.\n");
    printf("%d + %d = %d\n", 3, 10, (sum(3,10)));
}
