class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1. Compute the length and find the old tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Handle cases where k >= length
        k = k % length;
        if (k == 0) return head;

        // 3. Connect tail to head to make it circular
        tail->next = head;

        // 4. Find the new tail: (length - k) nodes from the start
        ListNode* new_tail = head;
        for (int i = 0; i < length - k - 1; i++) {
            new_tail = new_tail->next;
        }

        // 5. Set the new head and break the circle
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;

        return new_head;
    }
};
