//SerialDriver.h
#ifndef _SERIALDRIVER_H_
#define _SERIALDRIVER_H_
#ifdef __cplusplus
extern "C" {
#endif
    #if (defined(MATLAB_MEX_FILE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER))
        /* This will be run in Rapid Accelerator Mode */
        #define SerialDriver_Init(a)        (0)
        #define SerialDriver_Step(a,b,c)    (0)
        #define SerialDriver_Terminate()    (0)
    #else
        #include <stdint.h>

        void SerialDriver_Init(int8_t);
        void SerialDriver_Step(int8_t, uint8_t*, int8_t*) ;
        void SerialDriver_Terminate(void);
#endif
#ifdef __cplusplus
}
#endif
#endif 