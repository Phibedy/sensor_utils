#ifndef LMS_PID_CONTROLLER_H
#define LMS_PID_CONTROLLER_H

namespace sensor_utils{
class PID{
    //params
    double m_Vbias;
    double m_Kp;
    double m_Ki;
    double m_Kd;
    double m_dt;

    //used to calculate PID
    double eSum;
    double eOld;

public:
    PID(){
        reset();
    }

    /**
     * @param Kp is a proportional tuning constant
     * @param Ki is an integral tuning constant
     * @param Kd is a derivative tuning constant
     * @param dt is the rate the loop runs at, by default 1
     */
    void set(double Kp,double Ki,double Kd,double dt = 1){
        m_Kp  = Kp;
        m_Ki = Ki;
        m_Kd = Kd;
        m_dt = dt;
    }

    void reset(){
        eSum = 0;
        eOld = 0;
    }

public:
    double pid(double e){
        return pid(e,m_dt);
    }

    double pid(double e, double dt) {
        double v;
        eSum = eSum + e;
        v = m_Kp*e + m_Ki * eSum + m_Kd * (e - eOld)/dt;
        eOld = e;
        return v;
    }
};
}

#endif //LMS_PID_CONTROLLER_H
