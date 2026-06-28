## DegTrig Team, 2026



# About

DegTrig (Degree Trigonometry Library) is a lightweight C library designed for when a project requires angles in degrees, rather than radians. 

The standard C math library requires radians, which can complicate the logic of a program. DegTrig allows calculations directly
using degrees, which is more human friendly. 



# Uses

 DegTrig is useful for projects involving math, physics, simulations, game logic, and so on. The functions have simple names, and require simple arguments. It grants a function to turn radians into degrees, as well as degrees into radians. It features degree based sine, cosine, tangent, secant, cosecant, and cotangent calculations. As well as the inverse trigonometric functions of those 6, outputting degrees based on a ratio. It also includes triangle side conversions, 2D & 3D vector creation, and angle normalization.

Save time and complexity by keeping your data in degree format, rather than having to manage math and conversions in your source code. Get more done, and make the data more human friendly for developers and end users.




# Buiding from source

# Requirements

you will need:

a C compiler (GCC, Clang, or another)

Make (optional)

# Guide

install by either downloading using a webrowser at https://github.com/gardenmaster414-commits/DegTrig_CLibrary.git or cloning the repository with the BASH command:

git clone https://github.com/gardenmaster414-commits/DegTrig_CLibrary.git

there should be a working Makefile in the DegTrig project folder. Create the library by changing to the DegTrig/ directory and entering the command: 

make

If you do not have Make on your machine, you may manually compile with the following command (using GCC as an example): 

gcc -c degtrig.c -o degtrig.o

And then:

ar rcs libdegtrig.a degtrig.o

Now you have the library. 




# Using DegTrig
 To use DegTrig, include it with your other header files with the name <degtrig.h> 
use its functions like any other header program. All functions return double float values and expect float values in their function arguments, so prepare your variables accordingly, and dont forget the %lf format specifier when working with double floats. 

I reccoment placing libdegtrig.a and degtrig.h in the same folder as your source code, so you do not need to write out the entire path when compiling. If the header is in the same folder as the source code, write "degtrig.h" instead of <degtrig.h> in the .c file because the "" tells the compiler to look in the current directory. make sure to write 
-L. -ldegtrig 
when compiling if you are putting the library and .h file in the same folder as your project. 

# Features and Functions
DegTrig contains structs and functions. The two new structs are vector2ddt and vector3ddt, as in "vector 2D DegTrig", the names are self explanatory: vector2ddt holds x,y coordinates, while vector3ddt holds x,y,z coordinates. These vectors are a specific struct of vector, that are required to use most DegTrig vector functions, thus other structs of vectors or non structured coordinate data must be converted to a DegTrig vector to be passed through a DegTrig function that handles vectors. However, there are functions that allow for inputting unstructured coordinates, for your convenience. 

The following is the list of functions included in the current release of degtrig.h in the style of:

returntype function_name(inputtype input); // Description

====================================================================

# Functions

## Unit Conversion

double find_radians(double degrees); // Converts degrees into radians

double find_degrees(double radians); // Converts radians into degrees


## Trigonometric Functions

double deg_sin(double deg); // Calculates sine using degrees

double deg_cos(double deg); // Calculates cosine using degrees

double deg_tan(double deg); // Calculates tangent using degrees. Returns NAN if undefined

double deg_sec(double deg); // Calculates secant using degrees. Returns NAN if undefined

double deg_cosec(double deg); // Calculates cosecant using degrees. Returns NAN if undefined

double deg_cotan(double deg); // Calculates cotangent using degrees. Returns NAN if undefined


## Inverse Trigonometric Functions

double deg_atan(double x); // Calculates inverse tangent and returns degrees

double deg_asin(double x); // Calculates inverse sine from a ratio and returns degrees. Returns NAN outside -1 to 1

double deg_acos(double x); // Calculates inverse cosine from a ratio and returns degrees. Returns NAN outside -1 to 1

double deg_asec(double x); // Calculates inverse secant from a ratio and returns degrees. Returns NAN when input is invalid

double deg_acosec(double x); // Calculates inverse cosecant from a ratio and returns degrees. Returns NAN when input is invalid

double deg_acotan(double x); // Calculates inverse cotangent from a ratio and returns degrees


## Vector Creation

vector2ddt vector2ddt_from_xy(double x, double y); // Creates a 2D vector from X and Y components. Useful for converting another 2D vector struct into a degtrig compatible vector.

vector3ddt vector3ddt_from_xyz(double x, double y, double z); // Creates a 3D vector from X, Y, and Z components. Useful for converting another 3D vector struct into a degtrig compatible vector.

vector2ddt vector2ddt_from_values(double length, double degrees); // Creates a 2D vector from magnitude and angle

vector3ddt vector3ddt_from_values(double length, double theta, double phi); // Creates a 3D vector from spherical coordinates


## Vector Comparison

double deg_from_xy(double x1, double y1, double x2, double y2); // Finds the degree angle between two coordinate points

double endpoint_diff_vector2ddt(vector2ddt v1, vector2ddt v2); // Finds the distance between the endpoints of two 2D vectors

double length_diff_vector2ddt(vector2ddt v1, vector2ddt v2); // Finds the difference in magnitude between two 2D vectors

double deg_diff_vector2ddt(vector2ddt v1, vector2ddt v2); // Finds the smallest angle difference between two 2D vectors

double pitch_diff_vector3ddt(vector3ddt v1, vector3ddt v2); // Finds the difference between the pitch (vertical) angles of two 3D vectors

double yaw_diff_vector3ddt(vector3ddt v1, vector3ddt v2); // Finds the difference between the yaw (horizontal) angles of two 3D vectors


## Vector Components

double deg_vectorX2d(double length, double degrees); // Calculates the X component of a 2D vector

double deg_vectorY2d(double length, double degrees); // Calculates the Y component of a 2D vector

double deg_vectorX3d(double length, double theta, double phi); // Calculates the X component of a 3D vector

double deg_vectorY3d(double length, double phi); // Calculates the Y component of a 3D vector

double deg_vectorZ3d(double length, double theta, double phi); // Calculates the Z component of a 3D vector


## Vector Angle Extraction

double deg_from_vector2ddt(vector2ddt v); // Gets the angle of a 2D vector in degrees

double deg_pitch_xyz(double x, double y, double z); // Calculates the pitch angle of a 3D coordinate

double deg_yaw_xyz(double x, double z); // Calculates the yaw angle of a 3D coordinate

double deg_pitch_vector3ddt(vector3ddt v); // Gets the pitch angle of a 3D vector

double deg_yaw_vector3ddt(vector3ddt v); // Gets the yaw angle of a 3D vector


## Extra Functions

double deg_normalize(double deg); // Normalizes an angle into the range 0-360 degrees

====================================================================





# License 

DegTrig is under the MIT liscence, as detailed in the LISCENCE file included in the project folder. 

The MIT liscnece grants anyone the permission for any person who obtains this software freedom to: use, modify, copy, distribute, sublicense, and sell this software, including in commercial projects.

The only requirement is that the original copyright notice and license text are
included.

This software is provided "as is" without warranty. The author is not
responsible for any damages, data loss, or issues resulting from use of this
software.
