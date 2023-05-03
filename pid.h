#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

typedef struct
{
    float Ts; /*Sample time*/

    float Kp;
    float Ki;
    float Kd;


    /*Output limits*/
    float max;
    float min;

    float limMinInt;
    float limMaxInt;


    float integ;
    float preverr;
    float diff;
    float prevmeas;


    float out;

} PIDController;

void PIDController_init(PIDController *pid);
float PIDController_update(PIDController *pid, float setpoint, float measurment);

#endif
