#include "pid.h"



void PIDController_init(PIDController *pid){


    pid -> out = 0.0f;
    pid -> integ = 0.0f;
    pid -> diff = 0.0f;
    pid -> preverr = 0.0f;
    pid -> prevmeas = 0.0f;

}


double PIDController_update(PIDController *pid, double setpoint, double measurment){



    double error = setpoint - measurment; //error

    double prop = pid->Kp*error; //proportional


    pid->integ = pid->integ + pid -> Ki * error;//integral

    if (pid->max > prop){
    
        pid->limMaxInt = pid->max - prop;
    
    } else{
    
        pid->limMaxInt = 0.0f;

    }

    if (pid->min < prop){
    
        pid->limMinInt = pid->min-prop;
    
    }else{
    
        pid->limMinInt = 0.0f;

    }




    if (pid->integ > pid->limMaxInt){
        
        pid->integ = pid->limMaxInt;

    } else if (pid->integ < pid->limMinInt){
    
        pid->integ = pid->limMinInt;
    
    }

    //diff

    pid->diff = pid->Kd * (error - pid->preverr);


    pid->out = prop + pid -> integ + pid -> diff;

    if (pid->out > pid->max){
    
        pid->out = pid->max;
    
    } else if (pid->out < pid->min){
    
        pid->out = pid->min;

    }


    pid->preverr = error;
    pid->prevmeas = measurment;

    return pid->out;

}

