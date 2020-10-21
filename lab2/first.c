#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
    int a = INT_MAX;
    double b = DBL_MAX;
    float c = FLT_MAX;

    printf("%d %d \n",sizeof(a), a);
    printf("%d %lf\n",sizeof(b), b);
    printf("%d %f\n",sizeof(c), c);
    return 0;
}
