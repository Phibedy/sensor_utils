#ifndef LMS_PID_CONTROLLER_H
#define LMS_PID_CONTROLLER_H

namespace sensor_utils{
class PID{
    //params
    double m_Vbias;
    double m_Kc;
    double m_Ti;
    double m_Td;
    double m_dt;

    //used to calculate PID
    double eSum;
    double eOld;

public:
    /**
     * @brief PID
     * @param Vbias is an optional, user set bias for the controller output
     * @param Kc is a proportional tuning constant
     * @param Ti is an integral tuning constant
     * @param Td is a derivative tuning constant
     * @param dt is the rate the loop runs at, by default 1
     */
    PID(double Vbias, double Kc,double Ti,double Td,double dt = 1){
        m_Vbias = Vbias;
        m_Kc  = Kc;
        m_Ti = Ti;
        m_Td = Td;
        m_dt = dt;
        reset();
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
        v = m_Kc(* e + 1/m_Ti * eSum + m_Td * (e – ealt)/dt);
        eOld = e;
        return v;
    }
};
}

#endif //LMS_PID_CONTROLLER_H
