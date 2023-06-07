#ifndef FUZZY_CONTROLLER_H
#define FUZZY_CONTROLLER_H

typedef struct{
    double NB;
    double NS;
    double ZZ;
    double PS;
    double PB;
} FuzzySet;

//double trimemfunc(float value, FuzzySet *levels);
double defuzzy(float* outs, int nouts);
double fuzzyControl(double error, double derror);
double* rules(double* e, double* de);
double min_value(double a, double b);
double* fuzzify(double value, FuzzySet *levels);

#endif 