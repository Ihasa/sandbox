#ifndef _RATIONAL_DEFINE_
#define _RATIONAL_DEFINE_

typedef struct {
    int sig;    /* 符号 */
    unsigned int numer;  /* 分子 */
    unsigned int denom;  /* 分母 */
} Rational;

extern void Rat_init(int, int, Rational*);
extern void Rat_add(Rational*, Rational*, Rational*);
extern void Rat_sub(Rational*, Rational*, Rational*);
extern void Rat_mul(Rational*, Rational*, Rational*);
extern void Rat_div(Rational*, Rational*, Rational*);
extern unsigned char Rat_getFloatValue(Rational*, float*);

#endif
