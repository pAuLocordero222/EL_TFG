#include <stdio.h>
#include <stdlib.h>

#include "pid.h"

#define PID_KP  3.062f
#define PID_KI  0.003f
#define PID_KD  129.1296f


#define LIM_MAX 1.0f
#define LIM_MIN 0.0f


#define LIM_MAX_INT 1.0f
#define LIM_MIN_INT 0.0f

#define SAMPLE_T 0.000008f

float PID(float setpoint, float measurment){

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


    float out = PIDController_update(&pid, setpoint, measurment);

    return out;

}