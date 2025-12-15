#ifndef PCB_H
#define PCB_H

#include <string>
#include <vector>

struct PCB {
    int processID{};
    std::string processName;
    std::string processStatus;
    int commandCounter{};
    std::vector<int> cpuRegisters;
};

#endif

