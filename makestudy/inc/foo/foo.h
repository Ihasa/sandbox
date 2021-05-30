#ifndef FOO_H
#define FOO_H

#ifdef DEF_FOO_C
#define GLOBAL
#define GINI(val) =val
#else
#define GLOBAL extern
#define GINI(val)
#endif

GLOBAL int sum(int,int);
GLOBAL int mul(int,int);
GLOBAL float average(float[],int);
GLOBAL const float pi GINI(3.14159f);

#undef GLOBAL
#endif
