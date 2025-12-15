#ifndef LISTNODE_H
#define LISTNODE_H

#include "PCB.h"

struct ListNode {
    PCB data;
    ListNode* next;

    explicit ListNode(const PCB& pcb);
};

#endif
