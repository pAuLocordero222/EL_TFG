#include <stdio.h>
#include "fuzzy.h"

//Membership functions 
FuzzySet error_set = {-0.125, -0.0625, 0.0, 0.0625, 0.125};
FuzzySet d_error_set = {-0.125, -0.0625, 0.0, 0.0625, 0.125};
FuzzySet d_cycle_set = {0.0, 0.25, 0.5, 0.75, 1.0};


//This function allows to fuzzyfy an entry using the membership functions
double* fuzzify(double value, FuzzySet *levels){
    
    double fuzzy_array[5];
    
    if (value <= levels->NB){
        fuzzy_array[0] = 1.0;
        fuzzy_array[1] = 0.0;
        fuzzy_array[2] = 0.0;
        fuzzy_array[3] = 0.0;
        fuzzy_array[4] = 0.0;
    }

    else if (value > levels->NB && value <= levels->NS){
        fuzzy_array[0] = (levels->NS - value)/(levels->NS - levels->NB);
        fuzzy_array[1] = (value - levels->NB)/(levels->NS - levels->NB);
        fuzzy_array[2] = 0.0;
        fuzzy_array[3] = 0.0;
        fuzzy_array[4] = 0.0;
    }

    else if (value > levels->NS && value <= levels->ZZ){
        fuzzy_array[0] = 0.0;
        fuzzy_array[1] = (levels->ZZ - value)/(levels->ZZ - levels->NS);
        fuzzy_array[2] = (value - levels->NS)/(levels->ZZ - levels->NS);
        fuzzy_array[3] = 0.0;
        fuzzy_array[4] = 0.0;
    }

    else if (value > levels->ZZ && value <= levels->PS){
        fuzzy_array[0] = 0.0;
        fuzzy_array[1] = 0.0;
        fuzzy_array[2] = (levels->PS - value)/(levels->PS - levels->ZZ);
        fuzzy_array[3] = (value - levels->ZZ)/(levels->PS - levels->ZZ);
        fuzzy_array[4] = 0.0;
    }

    else if (value > levels->PS && value <= levels->PB){
        fuzzy_array[0] = 0.0;
        fuzzy_array[1] = 0.0;
        fuzzy_array[2] = 0.0;
        fuzzy_array[3] = (levels->PB - value)/(levels->PB - levels->PS);
        fuzzy_array[4] = (value - levels->PS)/(levels->PB - levels->PS);
    }

    else {
        fuzzy_array[0] = 0.0;
        fuzzy_array[1] = 0.0;
        fuzzy_array[2] = 0.0;
        fuzzy_array[3] = 0.0;
        fuzzy_array[4] = 1.0;
    }

    return fuzzy_array;

}

//This function returns the lower value betewwn two values
double min_value(double a, double b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
}

//This function evaluates the fuzzy rules
double* rules(double* e, double* de){
    double rule_results[25];

    int rule = 0;

    for (int i = 0; i < 5 ; i++){
        for (int j = 0; j < 5; j++){
            rule_results[rule] = min_value(e[i], de[j]);
            rule++;
        }

    } 
    return rule_results;
    
}


//This function make de defuzzify process using the centroid method
double defuzzy(double* outs){

    double sum = 0.0;
    double den = 0.0;

    for (int i = 0; i < 25 ; i++){
        sum += outs[i]*((i+1)/25);
        den += outs[i];
    }

    return sum/den;


}


//This function replicates the controller functionality
double fuzzyControl(double error, double derror){


    double* fuzzy_error;
    double* fuzzy_derror;
    double* rules_res;
    double dc;

    fuzzy_error = fuzzify(error, &error_set);
    fuzzy_derror = fuzzify(derror, &d_error_set);

    rules_res = rules(fuzzy_error, fuzzy_derror);

    dc = defuzzy(rules_res);

    return dc;
    



}