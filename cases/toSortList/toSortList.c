#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    struct ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val <= temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != NULL) {
        temp->next = temp1;
    } else if (temp2 != NULL) {
        temp->next = temp2;
    }
    return dummyHead->next;
}

struct ListNode* toSortList(struct ListNode* head, struct ListNode* tail) {
    if (head == NULL) {
        return head;
    }
    if (head->next == tail) {
        head->next = NULL;
        return head;
    }
    struct ListNode *slow = head, *fast = head;
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) {
            fast = fast->next;
        }
    }
    struct ListNode* mid = slow;
    return merge(toSortList(head, mid), toSortList(mid, tail));
}

struct ListNode* sortList(struct ListNode* head) {
    return toSortList(head, NULL);
}

int main() {
	{
	    struct ListNode e = { .val = 3, .next = NULL };
	    struct ListNode c = { .val = 1, .next = &e };
	    struct ListNode b = { .val = 2, .next = &c };
	    struct ListNode a = { .val = 4, .next = &b };
        struct ListNode *head = sortList(&a);

        assert(head->val == 1);
        assert(head->next->val == 2);
        assert(head->next->next->val == 3);
        assert(head->next->next->next->val == 4);
	}

    return 0;
}
