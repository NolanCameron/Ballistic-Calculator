#include <math.h>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
//sl/ft^3
#ifndef Air_Density
    #define Air_Density  0.00237 
#endif
#ifndef Gr_Per_Kg//[gr/kg]
    #define Gr_Per_Kg  15432.09876543
#endif
#ifndef M_Per_In//[m/in]
    #define M_Per_In  0.0254
#endif
#ifndef M_Per_Yd//[m/yd]
    #define M_Per_Yd  0.9144
#endif
#ifndef M_Per_Ft //[m/ft]
    #define M_Per_Ft  0.3048006
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

//vel1, vel2 [ft/sec] and distance [feet]
float calculateK(int vel1, int vel2, int distance){
    return log(vel1/vel2)/distance;
}

//kAvg is from avergaging K, mass [sl], radius [feet], rho is air density [sl/ft^3]
float calculateDragCo(float kAvg, float mass, float radius, float rho){
    return 2*kAvg*mass/(M_PI*pow(radius, 2)*rho);
}

//Used to calculate BC scale factor, height is the distance[feet] between start and target with negative being below
float BCScaleFactor(int height){
    return 1 + 1.3*pow(10, -5)*height;
}

double grToKgs(float gr){
    return gr/Gr_Per_Kg;
}

double inToM(float in){
    return in*M_Per_In;
}

double ydToM(float yd){
    return yd*M_Per_Yd;
}

double ftToM(float ft){
    return ft*M_Per_Ft;
}

double dragForce(float rho, double vel, double dragCo, double area){
    return rho*pow(vel, 2)*dragCo*area;
}

double terminalVel(double mass, double grav, double dragCo, double rho, double area){
    return sqrt((2*mass*grav)/(dragCo*rho*area));
}

double timeToImpact(double terminalVel, double grav, double velx0, double distancex){
    return (exp(distancex*grav/pow(terminalVel, 2))*pow(terminalVel, 2) - pow(terminalVel, 2))/(grav*velx0);
}
