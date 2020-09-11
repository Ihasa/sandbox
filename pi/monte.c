#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"

#define TRYMAX 100000000

float getRandPos();
bool isInCircle(float,float);

void main(){
    float x,y;
    float _pi;
    int i;
    unsigned int _inCircle=0, _inSquare=0;
    unsigned int randseed;
    
    printf("seed?:");
    scanf("%d",&randseed);
    srand(randseed);

    for(i = 0; i < TRYMAX; i++){
        x = getRandPos();
        y = getRandPos();
        if(isInCircle(x, y) == true){
            _inCircle++;
            _inSquare++;
        } else {
            _inSquare++;
        }
    }

    printf("%d, %d\n", _inCircle, _inSquare);
    _pi = 4.0f * (float)_inCircle / _inSquare;
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
