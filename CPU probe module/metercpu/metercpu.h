/* metercpu.h */
#ifndef METERCPU_H
#define METERCPU_H

#include "reference.h"

class MeterCpu : public Reference {
    GDCLASS(MeterCpu, Reference);

    double perc[20];

private:
    int start[20][2], end[20][2], numCpus;
    //long int memAvailable, totalMem, memoryUsed;
protected:
    static void _bind_methods();

public:
    void CalcForAllCpu();
    double cpu(int i);
    double cpuAvg();
    int numberOfCpus();
    long int memAvail();
    long int totalMemory();
    long int memUsed();
    long int swapTot(void);
    long int swapUsed(void);
    MeterCpu();
};

#endif
