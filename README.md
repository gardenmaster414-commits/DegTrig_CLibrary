DegTrig Team, 2026



1. DegTrig (Degree Trigonometry Library) is a lightweight C library designed for when a project requires angles in degrees, rather than radians. 

The standard C math library requires radians, which can complicate the logic of a program. DegTrig allows calculations directly
using degrees, which is more human friendly. 



2. DegTrig is useful for projects involving math, physics, simulations, game logic, and so on. The functions have simple names, and require simple arguments. It grants a function to turn radians into degrees, as well as degrees into radians. It features degree based sine, cosine, tangent, secant, cosecant, and cotangent calculations. As well as the inverse trigonometric functions of those 6, outputting degrees based on a ratio. It also includes triangle side conversions, 2D & 3D vector creation, and angle normalization.

Save time and complexity by keeping your data in degree format, rather than having to manage math and conversions in your source code. Get more done, and make the data more human friendly for developers and end users.




3. ##Buiding from source

##Requirements

you need:
-a C compiler (GCC, Clang, or another)
-Make (optional)

install by either downloading using a webrowser at https://github.com/yourname/DegTrig_CLibrary.git or cloning the repository with the BASH command:

git clone https://github.com/yourname/DegTrig_CLibrary.git 

there should be a working Makefile in the DegTrig project folder. Create the library by changing to the DegTrig/ directory and entering the command: 

make

If you do not have Make on your machine, you may manually compile with the following command (using GCC as an example): 

gcc -c degtrig.c -o degtrig.o

And then:

ar rcs libdegtrig.a degtrig.o

Now you have the library. 




4. To use DegTrig, include it with your other header files with the name <degtrig.h> 
use its functions like any other header program. All functions return double float values and expect float values in their function arguments, so prepare your variables accordingly, and dont forget the %lf format specifier when working with double floats. 

5. DegTrig contains structs and functions. The two new structs are vector2d and vector3d, the names are self explanatory: vector2d holds x,y coordinates, while vector3d holds x,y,z coordinates. 

The following is the list of functions included in the current release of degtrig.h in the style of 
returntype function_name(inputtype input);

====================================================================

double find_radians(double degrees); //input degrees to get radians.
double find_degrees(double radians); //input radians to get degrees.

double deg_tan(double deg); //similar to tan() from math.h, but accepts the angle in degrees. 

double deg_sin(double deg); //get sine from degrees.

double deg_cos(double deg); //get cosine from degrees.

double deg_sec(double deg); //get secant from degrees.

double deg_cosec(double deg); //get cosecant from degrees.

double deg_cotan(double deg); //get cotangent from degrees.


double deg_atan(double x); //similair to atan() from math.h, but converts the ratio to degrees instead

double deg_asin(double x); //input the sine ratio to inverse and get the angle in degrees

double deg_acos(double x); //degrees from cosine ratio

double deg_asec(double x); //degrees from secant ratio

double deg_acosec(double x); //degrees from cosecant ratio

double deg_acotan(double x); //degrees from cotangent ratio


double deg_vectorX(double length, double degrees); //takes the length/magnitude and theta angle of a vector to give x-axis value

double deg_vectorY(double length, double degrees); //takes the length/magnitude and theta angle of a vector to give y-axis value

double deg_vectorZ(double length, double phi); //takes the length and phi angle of a vector to give z-axis value


vector2d deg_vector2d(double length, double degrees); //takes vector parameters to make 2D vector

vector3d deg_vector3d(double length, double theta, double phi); //takes vector parameters to make a 3D vector

double deg_normalize(double deg); //input an angle in degrees to normalize it (take an angle out of the bounds of 0-360 and translate it to an angle within the bounds of 0-360). *note: normalization is not required for the functions of DegTrig to work, but it does make angles easier for humans to read.

====================================================================





6. DegTrig is under the MIT liscence, as detailed in the LISCENCE file included in the project folder. 

The MIT liscnece grants anyone the permission for any person who obtains this software freedom to: use, modify, copy, distribute, sublicense, and sell this software, including in commercial projects.

The only requirement is that the original copyright notice and license text are
included.

The software is provided without warranty.
