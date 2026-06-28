#include <math.h>
#include "degtrig.h"

//essential macros 
#define PI 3.14159265358979323846
#define getrad (PI / 180.0) //coefficient to convert degrees to radians
#define getdeg (180.0 / PI) //coefficient to convert radians to degrees


//the purpose of this function library is to enable 
//trigonometry calculations using degrees of a 360 circle.
//It generates data to
//use in your calculations.

//I made unit conversion functions and other 
//easy trig functions to streamline your code.
 

//rad is short for radians
//deg is short for degrees 

//every number is in double float format. format specifier will be %lf

//sections are divided by === lines. 
//sections: conversion, 6 trig, 6 inverse, vectors, and extra




//============================================================================
//unit conversion

//input degrees and get radians
double find_radians(double degrees){
    return degrees * getrad;
}

//input radians and get degrees
double find_degrees(double radians){
    return radians * getdeg;
}

//================================================================
//the 6 ratios

//tan with degrees
double deg_tan(double deg){
    //return tan(deg * getrad);
    double c = deg_cos(deg);

    if(fabs(c) < 1e-12)
        return NAN;

    return deg_sin(deg) / c;

}

//sin with degrees
double deg_sin(double deg){
    return sin(deg * getrad);
}

//cos with degrees
double deg_cos(double deg){
    return cos(deg * getrad);
}

//secant with degrees
double deg_sec(double deg){
    //return 1.0 / (cos(deg * getrad));
    double c = deg_cos(deg);

    if(fabs(c) < 1e-12)
        return NAN;

    return 1.0 / c;
}

//cosecant with degrees
double deg_cosec(double deg){
    //return 1.0 / (sin(deg * getrad));
    double s = deg_sin(deg);

    if(fabs(s) < 1e-12)
        return NAN;

    return 1.0 / s;
}

//cotangent with degrees
double deg_cotan(double deg){
    //return 1.0 / (tan(deg * getrad));
    double s = deg_sin(deg);

    if(fabs(s) < 1e-12)
        return NAN;

    return deg_cos(deg) / s;
}

//===========================================================
//the 6 inverse functions, returning a degree value using a ratio

//inverse tangent
double deg_atan(double x){
    return atan(x) * getdeg;
}

//inverse sine
double deg_asin(double x){
    //return asin(x) * getdeg;
    if(x < -1 || x > 1)
        return NAN;

    return asin(x) * getdeg;
}

//inverse cosine
double deg_acos(double x){
    //return acos(x) * getdeg;
    if(x < -1 || x > 1)
        return NAN;

    return acos(x) * getdeg;
}
//inverse secant
double deg_asec(double x){
    //return acos(1.0 / (x)) * getdeg;
    if(isnan(x)){
    return NAN;
    }
    if(x > -1 && x < 1){
        return NAN;
}
    return acos(1.0 / x) * getdeg;
}
//inverse cosecant
double deg_acosec(double x){
    //return asin(1.0 / (x)) * getdeg;
    if(isnan(x)){
    return NAN;
    }
    if(x > -1 && x < 1)
        return NAN;

    return asin(1.0 / x) * getdeg;
}
//inverse cotangent. Has a convention of -45 degrees when x is -1
double deg_acotan(double x){
    if(x == 0){
        return 90.0;
    }
    return atan(1.0 / (x)) * getdeg;
}

//==================================================================
//vector functions 

//vector creation-------------------------------------------------

//create a degtrig vector from x,y components, also can accept the components of another struct of 2D vector to convert it into a degtrig vector and use in degtrig functions.  
vector2ddt vector2ddt_from_xy(double x, double y){
    vector2ddt nv;
    nv.x = x;
    nv.y = y;
    return nv;
}

//create a degtrig vector from x,y,z components, good for converting a 3d vector from another struct to make a 3D vector compatible with degtrig functions.
vector3ddt vector3ddt_from_xyz(double x, double y, double z){
    vector3ddt nv;
    nv.x = x;
    nv.y = y;
    nv.z = z;
    return nv;
}
//makes vector coordinates, using length and theta in degrees
vector2ddt vector2ddt_from_values(double length, double degrees){
   vector2ddt v;
    v.x = deg_vectorX2d(length, degrees);
    v.y = deg_vectorY2d(length, degrees);
    return v;
}

//intakes the length, theta in degrees, and phi in degrees to make the coordinates of a 3d vector
vector3ddt vector3ddt_from_values(double length, double theta, double phi){
   vector3ddt v;

    v.x = deg_vectorX3d(length, theta, phi);
    v.y = deg_vectorY3d(length, phi);
    v.z = deg_vectorZ3d(length, theta, phi);

    return v;
}

//Vector comparison------------------------------------------------------


//input two coordinates to get the theta angle between them
double deg_from_xy(double x1, double y1, double x2, double y2){
    double diffx = x2 - x1;
    double diffy = y2 - y1;
    double result = (atan2(diffy, diffx) * getdeg);
    return deg_normalize(result);
}

//finds the distance between the endpoints of two degtrig vectors
double endpoint_diff_vector2ddt(vector2ddt v1, vector2ddt v2){
    double dx = v2.x - v1.x;
    double dy = v2.y - v1.y;
    return sqrt(dx*dx + dy*dy);

}

//finds the difference in magnitude/length of two degtrig vectors
double length_diff_vector2ddt(vector2ddt v1, vector2ddt v2){
    double length1 = hypot(v1.x, v1.y);
    double length2 = hypot(v2.x, v2.y);

    return fabs(length2 - length1);
}


//finds the difference in angle of two degtrig vectors. 

double deg_diff_vector2ddt(vector2ddt v1, vector2ddt v2){
     double theta1 = deg_normalize(deg_from_vector2ddt(v1));
    double theta2 = deg_normalize(deg_from_vector2ddt(v2));

    double diff = fabs(theta2 - theta1);

    if(diff > 180.0)
        diff = 360.0 - diff;

    return diff;
}


//finds the difference of pitch of two 3d degtrig vectors
double pitch_diff_vector3ddt(vector3ddt v1, vector3ddt v2){
    double pitch1 = deg_pitch_vector3ddt(v1);
    double pitch2 = deg_pitch_vector3ddt(v2);

    return fabs(pitch2 - pitch1);
}

//finds the difference of yaw of two 3D degtrig vectors
double yaw_diff_vector3ddt(vector3ddt v1, vector3ddt v2){
    double yaw1 = deg_normalize(deg_yaw_vector3ddt(v1));
    double yaw2 = deg_normalize(deg_yaw_vector3ddt(v2));

    double diff = fabs(yaw2 - yaw1);

    if(diff > 180.0)
        diff = 360.0 - diff;

    return diff;
}

//vector components-------------------------------------------------------

//finds an polar X vector component (horizontal leg of the right triangle, where length is the hypotenuse)
double deg_vectorX2d(double length, double degrees){
    return length * deg_cos(degrees);
}
//2D VERSION: finds a polar Y vector component (vertical leg of the right triangle, where length is the hypotenuse)
double deg_vectorY2d(double length, double degrees){
    return length * deg_sin(degrees);
}

//3D VERSION - finds the polar x component, insert theta and phi in degrees
double deg_vectorX3d(double length, double theta, double phi){
    double horizontal = length * deg_cos(phi);

    return horizontal * deg_cos(theta);
}
//3D VERSION - finds a polar Y vector component, insert phi in degrees
double deg_vectorY3d(double length, double phi){
    return length * deg_sin(phi);
}
////3D VERSION - finds the Z component of a vector using yaw(theta) and pitch(phi)
double deg_vectorZ3d(double length, double theta, double phi){
    double horizontal = length * deg_cos(phi);

    return horizontal * deg_sin(theta);
}


//takes a 2D vector from a degtrigvector and gets the theta angle, in degrees
double deg_from_vector2ddt(vector2ddt v){
    double result = atan2(v.y, v.x) * getdeg;
    return deg_normalize(result);
}




//takes a 3d vector coordinates and gets the up-down angle (pitch), in degrees.
double deg_pitch_xyz(double x, double y, double z){
    return (atan2(y, sqrt(x*x + z*z)) * getdeg);
}

//takes a 3d vector coordinates and gets the left-right angle (yaw), in degrees.
double deg_yaw_xyz(double x, double z){
   // return (atan2(x, z) * getdeg); 
    double result = atan2(x, z) * getdeg;
    return deg_normalize(result);
}

//takes a vector3ddt and gets the pitch in degrees
double deg_pitch_vector3ddt(vector3ddt v){
    return (atan2(v.y, sqrt(v.x*v.x + v.z*v.z)) * getdeg);
}

//takes a vector3ddt and gets the yaw in degrees
double deg_yaw_vector3ddt(vector3ddt v){
    double result = atan2(v.x, v.z) * getdeg; 
    return deg_normalize(result);
}

//===============================================================
//extra functions




//normalize an angle to simplify it. In degrees.
//its not required for the above functions to work
double deg_normalize(double deg){
    deg = fmod(deg, 360.0);

    if(deg < 0){
        deg += 360.0;
    }

    return deg;

    }
