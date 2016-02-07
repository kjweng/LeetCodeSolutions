/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || !k) return head;
    // Find the kth last element
    struct ListNode* tail = head;
    int len = 1;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    k %= len;
    
    tail->next = head;
    for (int i = 0; i < len - k; i++) {
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
    
    return head;
}