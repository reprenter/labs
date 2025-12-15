#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include "PCB.h"

struct ListNode;

class ProcessList {
public:
    ProcessList();
    ~ProcessList();

    bool insert(const PCB& newPCB);
    bool remove(int pid);
    void printList() const;

private:
    ListNode* head;

    void clear();
};

#endif


