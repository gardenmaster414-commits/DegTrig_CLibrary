#include <math.h>
#include "degtrig.h"
#include <stdbool.h>
#include <stdio.h>

int main(){
    double radians;
    double degrees;
    bool killr = 0;

    while(killr == 0){
 
    printf(" \n give a radian and get a degree: \n radians:  ");
    scanf(" %lf", &radians);
    printf(" \n degrees: %lf \n or %lf \n ", find_degrees(radians), deg_normalize(find_degrees(radians)));

    printf(" \n give a degree and get a radian: \n degrees:  ");
    scanf(" %lf", &degrees);
    printf(" \n radians: %lf ", find_radians(degrees));

//this will test the 6 trig functions from the command line, given a degree. 

double test_degree;
printf(" \n insert the testing number, in degrees: \n");
scanf("%lf", &test_degree);
printf("tangent result %lf \n", deg_tan(test_degree));
printf("sine result %lf \n", deg_sin(test_degree));
printf("cosine result %lf \n", deg_cos(test_degree));
printf("secant result %lf \n", deg_sec(test_degree));
printf("cosecant result %lf \n", deg_cosec(test_degree));
printf("cotangent result %lf \n\n", deg_cotan(test_degree));



//this will test the 6 inverse functions from the command line, given a ratio.

double test_ratio;
printf(" \n insert the testing ratio: \n");
scanf("%lf", &test_ratio);
printf(" inverse tangent result %lf \n", deg_atan(test_ratio));
printf(" inverse sine result %lf \n", deg_asin(test_ratio));
printf(" inverse cosine result %lf \n", deg_acos(test_ratio));
printf(" inverse secant result %lf \n", deg_asec(test_ratio));
printf(" inverse cosecant result %lf \n", deg_acosec(test_ratio));
printf(" inverse cotangent result %lf \n\n", deg_acotan(test_ratio));


    killr = 1;
    }
    return 0;
}