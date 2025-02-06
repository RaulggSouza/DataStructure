#include <stdio.h>

float harmonic_number(int n){
    float h = 0.0;
    for(float f = 1.0; f <= n; f++){
        h += (1/f);
    }
    return h;
}

int main(int argc, char const *argv[]){
    float h = harmonic_number(4);
    printf("%.4f\n", h);
    return 0;
}
