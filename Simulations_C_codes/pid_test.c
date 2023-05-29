#include <stdio.h>
#include <stdlib.h>

#include "pid.h"

#include <pid.c>


#define PID_KP  10.8522f
#define PID_KI  0.0356f
#define PID_KD  386.7920f

//#define PID_KP  0.02401f
//#define PID_KI  0.000545f
//#define PID_KD  0.000403f

#define PID_KP_P  -0.00108f
#define PID_KI_P -5.3f
#define PID_KD_P  -0.151f

#define PI_KP 7.1578f
#define PI_KI 0.1643f
#define PI_KD 0.0f


#define LIM_MAX 1.0f
#define LIM_MIN 0.0f


#define LIM_MAX_INT 1.0f
#define LIM_MIN_INT 0.0f

#define SAMPLE_T 0.000008f



double PID(double setpoint, double measurment){

    PIDController pid = {
        SAMPLE_T,
        PID_KP,
        PID_KI,
        PID_KD,
        LIM_MAX,
        LIM_MIN,
        LIM_MAX_INT,
        LIM_MIN_INT
    };



    PIDController_init(&pid);


    double outs = PIDController_update(&pid, setpoint, measurment);

    return outs;

}

double PI(double setpoint_i, double measurment_i){

    PIDController pid = {
        SAMPLE_T,
        PI_KP,
        PI_KI,
        PI_KD,
        LIM_MAX,
        LIM_MIN,
        LIM_MAX_INT,
        LIM_MIN_INT
    };



    PIDController_init(&pid);


    double outs_pi = PIDController_update(&pid, setpoint_i, measurment_i);

    return outs_pi;

}

double limiter(double value){

    if (value < 0){
        double dc = 0; 
    }

    else if (value > 1){
        double dc = 1;
    }

    else {
        double dc = value;
    }
}