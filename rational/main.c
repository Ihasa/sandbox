#include "stdio.h"
#include "rational.h"

void Rat_show(Rational* rat){
    if(rat->sig >= 0){
        printf("%d/%d\n", rat->numer, rat->denom);
    } else {
        printf("-%d/%d\n", rat->numer, rat->denom);
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

    Rat_sub(&r1, &r2, &r3);
    Rat_show(&r3);

    Rat_mul(&r1, &r2, &r3);
    Rat_show(&r3);

    Rat_div(&r1, &r2, &r3);
    Rat_show(&r3);
}

