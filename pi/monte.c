#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"

#define TRYMAX 100000000

float getRandPos();
bool isInCircle(float,float);

void main(){
    float x,y;
    float _piSum;
    float _pi;
    unsigned int iTry, iSample;
    unsigned int trynum;
    unsigned int samplenum;
    unsigned int _inCircle, _inSquare;
    unsigned int randseed;
    
    printf("seed?:");
    scanf("%d",&randseed);
    srand(randseed);

    printf("tries?:");
    scanf("%d", &trynum);
    trynum = (trynum > TRYMAX) ? TRYMAX : trynum;

    printf("samples?:");
    scanf("%d", &samplenum);

    _piSum = 0;
    for(iSample = 0; iSample < samplenum; iSample++){
        _inCircle = 0;
        _inSquare = 0;
        for(iTry = 0; iTry < trynum; iTry++){
            x = getRandPos();
            y = getRandPos();
            if(isInCircle(x, y) == true){
                _inCircle++;
                _inSquare++;
            } else {
                _inSquare++;
            }
        }
        _piSum += 4.0f * (float)_inCircle / _inSquare;
    }

    printf("%d, %d\n", _inCircle, _inSquare);
    _pi = _piSum / samplenum;
    printf("PI = %f\n", _pi);
}

float getRandPos() {
    /* -1 ～ 1までの値が欲しい */
    float randvalF = (float)rand() / RAND_MAX; /* これで0 ～ 1 */
    return (-1.0f + randvalF*2);
}

bool isInCircle(float x, float y){
    return sqrt(x * x + y * y) <= 1;
}
