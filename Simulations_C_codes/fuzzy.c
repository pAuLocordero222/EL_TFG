#include <stdio.h>
#include "fuzzy.h"


FuzzySet error_set = {-1.0, -0.5, 0.0, 0.5, 1.0};
FuzzySet d_error_set = {-1.0, -0.5, 0.0, 0.5, 1.0};
FuzzySet d_cycle_set = {0.0, 0.25, 0.5, 0.75, 1.0};

double trimemfunc(float value, FuzzySet *levels){
    if (value <= levels->NB){
        return 0;
    }
    else if (value >= levels->PB){
        return 1.0;
    }
    else if (value <= levels->NS){
        return (value-levels->NB)/(levels->NS-levels->NB);
    }
    else if (value <= levels->ZZ){
        return (value-levels->NS)/(levels->ZZ-levels->NS);
    }
    else if (value <= levels->PS){
        return (levels->PS-value)/(levels->PS-levels->ZZ);
    }
    else {
        return (levels->PB-value)/(levels->PB-levels->PS);
    }

}

double fuzzy_control (double error, double derror){


}

//typedef struct{
//    double NB;
//    double NS;
//    double ZZ;
//    double PS;
 //   double PB;
//} FuzzySet;

/*
FuzzySet error_set = {-1.0, -0.5, 0.0, 0.5, 1.0};
FuzzySet d_error_set = {-1.0, -0.5, 0.0, 0.5, 1.0};
FuzzySet d_cycle_set = {0.0, 0.25, 0.5, 0.75, 1.0};


double trimemfunc(float value, FuzzySet *levels){
    if (value <= levels->NB){
        return 0;
    }
    else if (value >= levels->PB){
        return 1.0;
    }
    else if (value <= levels->NS){
        return (value-levels->NB)/(levels->NS-levels->NB);
    }
    else if (value <= levels->ZZ){
        return (value-levels->NS)/(levels->ZZ-levels->NS);
    }
    else if (value <= levels->PS){
        return (levels->PS-value)/(levels->PS-levels->ZZ);
    }
    else {
        return (levels->PB-value)/(levels->PB-levels->PS);
    }

}

double fuzzyRules[5][5] = {
    {1.0, 1.0, 1.0, 0.5, 0.0},
    {1.0, 1.0, 0.5, 0.0, 0.5},
    {1.0, 0.5, 0.0, 0.5, 1.0},
    {0.5, 0.0, 0.5, 1.0, 1.0},
    {0.0, 0.5, 1.0, 1.0, 1.0}
};

double defuzzy(float* outs, int nouts){
    double sum = 0.0;
    double tw = 0.0;

    for (int i = 0; i< nouts; i++){
        sum += outs[i]*d_cycle_set.PS;
        tw += outs[i];
    }

    if (tw > 0.0){
        sum /= tw;
        return sum;
    }
    else{
        return 0.0;
    }
}


double fuzzyControl(double error, double derror){

    //double preverr = 0.0;

    //double error = setpoint - measurment;


    double eMem[5];
    double edMem[5];
    double out[5];

    eMem[0] = trimemfunc(error, &error_set);
    eMem[1] = trimemfunc(error, &error_set);
    eMem[2] = trimemfunc(error, &error_set);
    eMem[3] = trimemfunc(error, &error_set);
    eMem[4] = trimemfunc(error, &error_set);

    edMem[0]= trimemfunc(derror, &d_error_set);
    edMem[1]= trimemfunc(derror, &d_error_set);
    edMem[2]= trimemfunc(derror, &d_error_set);
    edMem[3]= trimemfunc(derror, &d_error_set);
    edMem[4]= trimemfunc(derror, &d_error_set);


    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            out[i] = fuzzyRules[i][j]*eMem[i]*edMem[j];
        }
    }
    
    double dc = defuzzy(out, 5);

    return dc;


}*/