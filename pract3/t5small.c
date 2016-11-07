#include <stdio.h>
double mysqrt(double x){double rt=1,ort=0;while(ort!=rt){ort=rt;rt=((x/rt)+rt)/2;}return rt;}
