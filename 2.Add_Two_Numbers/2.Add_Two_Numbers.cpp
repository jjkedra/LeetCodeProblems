#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
 * @brief
 * Takes head of the ll and returns it as unsigned long long int
*/
unsigned long long int delistify(ListNode* head)
{
    if (!head) {
        return 0;
    }
    unsigned long long int num = head->val;
    head = head->next;

    while (head != nullptr) {
        num *= 10;
        num += head->val;
        head = head->next;
    }
    return num;
}

ListNode* listify(unsigned long long int num)
{
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    while (num) {
        int digit = num % 10;
        num /= 10;

        ListNode* newNode = new ListNode();
        newNode->val = digit;
        newNode->next = nullptr;

        if (current == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}



ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the link

        // Move to the next pair of nodes
        prev = current;
        current = next;
    }

    // 'prev' will be the new head of the reversed list
    return prev;
}

ListNode* addLists(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    bool overflow = false;

    while (l1 || l2 || overflow) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (overflow ? 1 : 0);
        overflow = (sum > 9);

        ListNode* temp = new ListNode(sum % 10);
        temp->next = nullptr;

        if (current == nullptr) {
            head = temp;
            current = temp;
        } else {
            current->next = temp;
            current = temp;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return head;
}

unsigned long long int reverseNum(unsigned long long int num)
{
    unsigned long long int a = num%10;
    num /= 10;

    while (num) {
        a *= 10;
        a += num%10;
        num /= 10;
    }
    return a;
}

bool listIsEmpty(ListNode* list) {
    if (list->next == nullptr && list->val == 0) {
        return true;
    }
    return false;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return addLists(l1, l2);
}

int main()
{
    ListNode *l1 = new ListNode();
    l1->next = nullptr;
    l1->val = 9;
    ListNode *l2 = new ListNode();
    l2->next = l1;
    l2->val = 1;
    ListNode *l3 = new ListNode();
    l3->next = l2;
    l3->val = 1;
    // ListNode *l4 = new ListNode();
    // l4->next = l3;
    // l4->val = 5;
    // ListNode *l5 = new ListNode();
    // l5->next = l4;
    // l5->val = 6;
    // ListNode *l6 = new ListNode();
    // l6->next = l5;
    // l6->val = 8;
    // ListNode *l7 = new ListNode();
    // l7->next = l6;
    // l7->val = 3;
    // ListNode *l8 = new ListNode();
    // l8->next = l7;
    // l8->val = 5;
    // ListNode *l9 = new ListNode();
    // l9->next = l8;
    // l9->val = 7;

    ListNode *r1 = new ListNode();
    r1->next = nullptr;
    r1->val = 1;
    ListNode *r2 = new ListNode();
    r2->next = r1;
    r2->val = 1;
    ListNode *r3 = new ListNode();
    r3->next = r2;
    r3->val = 1;
    // ListNode *r4 = new ListNode();
    // r4->next = r3;
    // r4->val = 0;
    // ListNode *r5 = new ListNode();
    // r5->next = r4;
    // r5->val = 1;
    // ListNode *r6 = new ListNode();
    // r6->next = r5;
    // r6->val = 0;
    // ListNode *r7 = new ListNode();
    // r7->next = r6;
    // r7->val = 0;
    // ListNode *r8 = new ListNode();
    // r8->next = r7;
    // r8->val = 0;
    // ListNode *r9 = new ListNode();
    // r9->next = r8;
    // r9->val = 1;

    std::cout << delistify(addLists(l3, r3)) << std::endl;
    // std::cout << delistify(l9) << std::endl;


    return 0;
}