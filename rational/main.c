#include "stdio.h"
#include "rational.h"

void Rat_show(Rational* rat){
    float fvalue;
    int res = Rat_getFloatValue(rat, &fvalue);
    if(rat->sig >= 0){
        printf("%d/%d = %f\n", rat->numer, rat->denom, fvalue);
    } else {
        printf("-%d/%d = %f\n", rat->numer, rat->denom, fvalue);
    }
}

void main(){
    Rational r1;
    Rational r2;
    Rational r3;
    Rat_init(5,12,&r1);
    Rat_init(3,8,&r2);

    Rat_add(&r1, &r2, &r3);
    Rat_show(&r3);
    Rat_reduction(&r3);
    Rat_show(&r3);

    Rat_sub(&r1, &r2, &r3);
    Rat_show(&r3);
    Rat_reduction(&r3);
    Rat_show(&r3);

    Rat_mul(&r1, &r2, &r3);
    Rat_show(&r3);
    Rat_reduction(&r3);
    Rat_show(&r3);

    Rat_div(&r1, &r2, &r3);
    Rat_show(&r3);
    Rat_reduction(&r3);
    Rat_show(&r3);

}

