#include "ProcessList.h"
#include "ListNode.h"

#include <iostream>
#include <iomanip>

ProcessList::ProcessList() : head(nullptr) {}

ProcessList::~ProcessList() {
    clear();
}

bool ProcessList::insert(const PCB& newPCB) {
    ListNode* newNode = new ListNode(newPCB);

    if (head && head->data.processID == newPCB.processID) {
        delete newNode;
        return false;
    }

    if (!head || newPCB.processID < head->data.processID) {
        newNode->next = head;
        head = newNode;
        return true;
    }

    ListNode* curr = head;
    while (curr->next && curr->next->data.processID < newPCB.processID) {
        curr = curr->next;
    }

    if (curr->next && curr->next->data.processID == newPCB.processID) {
        delete newNode;
        return false;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    return true;
}

bool ProcessList::remove(int pid) {
    if (!head) return false;

    if (head->data.processID == pid) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }

    ListNode* curr = head;
    while (curr->next && curr->next->data.processID != pid) {
        curr = curr->next;
    }

    if (!curr->next) return false;

    ListNode* tmp = curr->next;
    curr->next = curr->next->next;
    delete tmp;
    return true;
}

void ProcessList::printList() const {
    if (!head) {
        std::cout << "Process list is empty\n";
        return;
    }

    std::cout << std::left << std::setw(8) << "PID"
              << std::setw(15) << "Name"
              << std::setw(12) << "Status"
              << std::setw(8) << "CmdCnt"
              << "Registers\n";

    const ListNode* curr = head;
    while (curr) {
        std::cout << std::left << std::setw(8) << curr->data.processID
                  << std::setw(15) << curr->data.processName
                  << std::setw(12) << curr->data.processStatus
                  << std::setw(8) << curr->data.commandCounter;
        for (size_t i = 0; i < curr->data.cpuRegisters.size(); ++i) {
            std::cout << curr->data.cpuRegisters[i];
            if (i + 1 < curr->data.cpuRegisters.size()) std::cout << ",";
        }
        std::cout << "\n";
        curr = curr->next;
    }
}

void ProcessList::clear() {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}


