#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

typedef struct
{
    double Ts; /*Sample time*/

    double Kp;
    double Ki;
    double Kd;


    /*Output limits*/
    double max;
    double min;

    double limMinInt;
    double limMaxInt;


    double integ;
    double preverr;
    double diff;
    double prevmeas;


    double out;

} PIDController;

void PIDController_init(PIDController *pid);
double PIDController_update(PIDController *pid, double setpoint, double measurment);
double PID(double setpoint, double measurment);
double PI(double setpoint_i, double measurment_i);
double limiter(double value);

#endif
