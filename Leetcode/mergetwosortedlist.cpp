#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    
    // Constructor
    ListNode(int value) : val(value), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify the code
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Traverse both lists
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // If one of the lists is not fully traversed, append the remaining nodes
        if (l1 != nullptr) {
            current->next = l1;
        } else {
            current->next = l2;
        }

        // Head of the merged list (skipping the dummy node)
        ListNode* mergedHead = dummy->next;

        // Clean up the dummy node (no memory leak)
        delete dummy;

        return mergedHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example 1
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution solution;
    ListNode* mergedList1 = solution.mergeTwoLists(list1, list2);
    std::cout << "Example 1: ";
    printList(mergedList1);

    // Example 2
    ListNode* emptyList1 = nullptr;
    ListNode* emptyList2 = nullptr;

    ListNode* mergedList2 = solution.mergeTwoLists(emptyList1, emptyList2);
    std::cout << "Example 2: ";
    printList(mergedList2);

    // Example 3
    ListNode* emptyList3 = nullptr;
    ListNode* list3 = new ListNode(0);

    ListNode* mergedList3 = solution.mergeTwoLists(emptyList3, list3);
    std::cout << "Example 3: ";
    printList(mergedList3);

    // Clean up memory
    delete list1;
    delete list2;
    delete mergedList1;
    delete mergedList2;
    delete mergedList3;
    
    return 0;
}
