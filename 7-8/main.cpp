#include <iostream>
#include "PCB.h"
#include "ProcessList.h"

PCB makePCB(int pid, const std::string& name, const std::string& status,
            int cmdCounter, std::initializer_list<int> regs) {
    PCB pcb;
    pcb.processID = pid;
    pcb.processName = name;
    pcb.processStatus = status;
    pcb.commandCounter = cmdCounter;
    pcb.cpuRegisters = regs;
    return pcb;
}

int main() {
    ProcessList plist;

    plist.insert(makePCB(3, "Editor", "Running", 120, {1, 2, 3, 4}));
    plist.insert(makePCB(1, "Shell", "Waiting", 45, {10, 20}));
    plist.insert(makePCB(5, "Browser", "Stopped", 300, {7, 8, 9}));
    plist.insert(makePCB(2, "Daemon", "Running", 200, {5, 5, 5}));

    std::cout << "After insertions:\n";
    plist.printList();
    std::cout << "\n";

    std::cout << "Insert duplicate PID 3: "
              << (plist.insert(makePCB(3, "Duplicate", "Waiting", 0, {0})) ? "success" : "fail")
              << "\n\n";

    std::cout << "Insert duplicate PID 1: "
              << (plist.insert(makePCB(1, "Shell", "Waiting", 45, {10, 20})) ? "success" : "fail")
              << "\n\n";


    std::cout << "Remove PID 1: " << (plist.remove(1) ? "success" : "not found") << "\n";
    std::cout << "Remove PID 42: " << (plist.remove(42) ? "success" : "not found") << "\n\n";

    std::cout << "After removals:\n";
    plist.printList();
    std::cout << "\n";

    std::cout << "Final list state:\n";
    plist.printList();

    return 0;
}

