#include <stdio.h>
#include <math.h>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
//sl/ft^3
#ifndef Air_Density
    #define Air_Density  0.00237 
#endif

//q
//rho is air pressure in slugs per cubic foot, vel is fps
float dynamicPressure(float rho, float vel){
    return 1/2*rho*pow(vel, 2);//pounds per square foot
} 

//s
//cal is in inches
float frontalArea(float cal){
    return M_PI*pow(cal/24, 2);//square feet
}

//drag
//q is dynamic pressure (lb/f^2), s if frontal area (ft^2), Cd is dragCO
float aeroDynamicDrag(float q, float s, float dragCO){
    return q*s*dragCO; //pounds
}

int main() {
    return 0;
}