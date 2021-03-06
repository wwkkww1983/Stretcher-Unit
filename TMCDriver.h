#ifndef TMCDRIVER_H_
#define TMCDRIVER_H_

class TMC2660 
{
    public:
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
        void blankTime(); //TBL the number of cycles after a switch, in which the sense resistor ringing is ignored (ripples are bad).
        void chopperMode(); //CHM 1: constant off-time mode    0: spreadCycle mode
        //Spreadcycle mode (dynamic TOFF mode)
        void hystEnd(); //HEND sets minimum allowable offset value from target current.
        void hystStart(); //HSTRT sets maximum allowable offset value from target current.
        void hystDecrement(); //HDEC sets the rate at which the value decrements from HSTRT+HEND to HEND.
        //Constant TOFF mode
        void slowDecayTime(); //TOFF   t = (1/fclk)*((TOFF * 32) + 12)

        //DRVCTRL_STEP/DIR_MODE
        void setMicroStep(uint8_t); //MRES
        void doubleStepping(); //DEDGE 0: Rising step pulse is active, falling is inactive    1: Both rising and falling edge active
        void stepInterpolation(); //INTPOL 0: Disable STEP pulse interpolation   1: Enable step pulse multiplication by 16.
        


        //TODO: DRVCTRL_SPI_MODE


    private:
        //Bitfield construction
        void constructBitField(uint32_t bits, uint32_t reg);
        uint32_t DRVCTRL_0;
        uint32_t DRVCTRL_1;
        uint32_t DRVCONF;
        uint32_t CHOPCONF;
        uint32_t SMARTEN;
        uint32_t SGCSCONF;

};



#endif