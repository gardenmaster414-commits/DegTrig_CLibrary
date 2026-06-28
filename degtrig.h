#ifndef DEGTRIG_H
#define DEGTRIG_H

/*
    DegTrig Library
    Version: 1.2.0

    Degree-based trigonometry and vector mathematics library.
*/

#include <math.h>


//===========================================================
// Vector structures

typedef struct {
    double x;
    double y;
} vector2ddt; //2d vector that can be used in degtrig functions


typedef struct {
    double x;
    double y;
    double z;
} vector3ddt; //3d vectors that can be used in degtrig functions


//===========================================================
// Unit conversion

double find_radians(double degrees);
double find_degrees(double radians);


//===========================================================
// 6 trig functions (degrees)

double deg_sin(double deg);
double deg_cos(double deg);
double deg_tan(double deg);

double deg_sec(double deg);
double deg_cosec(double deg);
double deg_cotan(double deg);


//===========================================================
// 6 inverse trig functions (returns degrees)

double deg_atan(double x);
double deg_asin(double x);
double deg_acos(double x);

double deg_asec(double x);
double deg_acosec(double x);
double deg_acotan(double x);


//===========================================================
// Vector creation

//Create vectors using coordinates

vector2ddt vector2ddt_from_xy(double x, double y);

vector3ddt vector3ddt_from_xyz(double x, double y, double z);


// Create vectors using length and angles

vector2ddt vector2d_from_values(double length, double degrees);

vector3ddt vector3d_from_values(double length, double theta, double phi);


//===========================================================
// Vector comparison

double deg_from_xy(double y1, double x1, double y2, double x2);

double endpoint_diff_vector2ddt(vector2ddt v1, vector2ddt v2);

double length_diff_vector2ddt(vector2ddt v1, vector2ddt v2);

double deg_diff_vector2ddt(vector2ddt v1, vector2ddt v2);

double pitch_diff_vector3ddt(vector3ddt v1, vector3ddt v2);

double yaw_diff_vector3ddt(vector3ddt v1, vector3ddt v2);


//===========================================================
// Vector component calculations

// 2D
double deg_vectorX2(double length, double degrees);

double deg_vectorY2(double length, double degrees);


// 3D
double deg_vectorX3(double length, double theta, double phi);

double deg_vectorY3(double length, double phi);

double deg_vectorZ3(double length, double theta, double phi);


//===========================================================
// Vector angle extraction

double deg_from_vector2d(vector2ddt v);


double deg_pitch_xyz(double x, double y, double z);

double deg_yaw_xyz(double x, double z);


double deg_pitch_vector3ddt(vector3ddt v);

double deg_yaw_vector3ddt(vector3ddt v);


//===========================================================
// Extra utilities

double deg_normalize(double deg);


#endif