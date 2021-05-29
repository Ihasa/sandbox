#ifndef FOO_H
#define FOO_H

#ifdef DEF_FOO_C
#define GLOBAL
#else
#define GLOBAL extern
#endif

GLOBAL int sum(int,int);

#undef GLOBAL
#endif
