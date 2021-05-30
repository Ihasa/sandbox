#define DEF_FOO_C
#include "foo.h"

//const float pi = 3.141592f;
static float sumF(float[],int);

int sum(int x, int y){
    return x+y;
}

int mul(int x, int y){
    return x*y;
}

float average(float vals[], int size){
    return sumF(vals, size) / size;
}

static float sumF(float vals[], int size){
    float ret = 0.0f;
    for(int i = 0;i < size; i++){
        ret += vals[i];
    }
    return ret;
}
