#include "rational.h"

void Rat_init(int, int, Rational*);
void Rat_add(Rational*, Rational*, Rational*);
void Rat_sub(Rational*, Rational*, Rational*);
void Rat_mul(Rational*, Rational*, Rational*);
void Rat_div(Rational*, Rational*, Rational*);
unsigned char Rat_getFloatValue(Rational*, float*);
void Rat_reduction(Rational*);

void Rat_init(int numer, int denom, Rational* result) {
    result->sig = (numer*denom >= 0) ? 1 : -1;
    result->numer = (numer >= 0) ? numer : -numer;
    result->denom = (denom >= 0) ? denom : -denom;
}

void Rat_add(Rational* r1, Rational* r2, Rational* result) {
    if(r1->sig == r2->sig){
        result->sig = r1->sig;
        result->numer = r1->numer*r2->denom + r2->numer*r1->denom;
        result->denom = r1->denom * r2->denom;
    } else {
        if(r2->sig == -1){
            r2->sig = 1;
            Rat_sub(r1,r2,result);
        } else {
            r1->sig = 1;
            Rat_sub(r2,r1,result);
        }
    }
}
void Rat_sub(Rational* r1, Rational* r2, Rational* result) {
    int tmp_numer;
    if(r1->sig == r2->sig){
        tmp_numer = r1->numer*r2->denom - r2->numer*r1->denom;
        if(tmp_numer >= 0){
            result->sig = 1;
            result->numer = tmp_numer;
        } else {
            result->sig = -1;
            result -> numer = -tmp_numer;
        }
        result -> denom = r1->denom * r2->denom;
    } else {
        r2->sig = -r2->sig;
        Rat_add(r1,r2,result);
    }
}
void Rat_mul(Rational* r1, Rational* r2, Rational* result) {
    result->numer = r1->numer * r2->numer;
    result->denom = r1->denom * r2->denom;
    result->sig = r1->sig * r2->sig;
}
void Rat_div(Rational* r1, Rational* r2, Rational* result) {
    result->numer = r1->numer * r2->denom;
    result->denom = r1->denom * r2->numer;
    result->sig = r1->sig * r2->sig;
}
unsigned char Rat_getFloatValue(Rational* value, float* result) {
    if(value->denom == 0){
        return 1;
    } else {
        *result = (float)(value->numer) / (value->denom) * (value->sig);
        return 0;
    }
}

static unsigned int gcd(unsigned int value1, unsigned int value2){
    //return (value1 % value2 == 0) ? value2 : gcd(value2,value1 % value2);
    unsigned int tmpval1=value1,tmpval2=value2;
    unsigned int mod;
    do{
        mod = tmpval1 % tmpval2;
        if(mod != 0){
            tmpval1 = tmpval2;
            tmpval2 = mod;
        }
    }while(mod != 0);

    return tmpval2;
}
void Rat_reduction(Rational* value){
    unsigned int mod = gcd(value->numer, value->denom);
    value -> numer /= mod;
    value -> denom /= mod;
}
