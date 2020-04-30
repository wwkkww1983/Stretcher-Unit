#ifndef TMCDRIVER_H_
#define TMCDRIVER_H_

class TMC2660 
{
    void init();

    //DRVCONF
    void slopeControlHigh();
    void slopeControlLow();
    void motorShortTimer();    //TS2G short to ground timer. (turns off power mosfets)
    void stepMode();   //RDSEL 0: step and dir interface, 1: SPI interface 
    void rmsCurrent();  //VSENSE
    void readMode(); //RDSEL Microstep positon or stallguard or coolStep current level readback

    //SGCSCONF
    void filterMode(); //SFILT 0: standard mode, rapid stall detection 1: Filtered mode for precise load measurement.
    void stallGrdThresh(); //SGT the higher the value, the higher the torque required to indicate a stall, start with 0.
    void currentScale(); //CS

    //SMARTEN
    void minCoilCurrent(); //SEIMIN 0: 1/2 of CS    1: 1/4 of CS
    void coilDecrementSpd(); //SEDN number of times stallguard2 is above threshold is sampled before decrement.
    void coilUpperThreshold(); //SEMAX Threshold (high) is (SEMIN + SEMAX + 1)*32 decreases current scaling when above threshold.
    void coilLowerThreshold(); //SEMIN Threshold (low) is (SEMIN)*32 increases current scaling when below threshold.
    void coilIncrementSize(); //SEUP The magnitude of compensation when the coil current drops below the low threshold.

    //CHOPCONF
    
};



#endif