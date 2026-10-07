/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwo(struct ListNode* a, struct ListNode* b) {
    struct ListNode dummy;
    struct ListNode *cur = &dummy;
    dummy.next = NULL;

    while (a && b) {
        if (a->val <= b->val) {
            cur->next = a;
            a = a->next;
        } else {
            cur->next = b;
            b = b->next;
        }
        cur = cur->next;
    }

    cur->next = a ? a : b;

    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;

    while (listsSize > 1) {
        int newSize = 0;

        for (int i = 0; i < listsSize; i += 2) {
            if (i + 1 < listsSize)
                lists[newSize++] = mergeTwo(lists[i], lists[i + 1]);
            else
                lists[newSize++] = lists[i];
        }

        listsSize = newSize;
    }

    return lists[0];
}