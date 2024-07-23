#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include <glib/glist.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void reverse(struct ListNode *h, char *buf, int size)
{
    struct ListNode *tmp = NULL;
    struct ListNode *pre = NULL;
    struct ListNode *cur = h;
    char tmpbuf[10];

    while (cur) {
        tmp = cur->next; 
        cur->next = pre;
        pre = cur;
        cur = tmp; 
    }

    tmp = pre;
    while (tmp) {
        sprintf(&tmpbuf[0], "%d,", tmp->val);
        strcat(buf, &tmpbuf[0]);
        tmp = tmp->next;
    }
}

int main()
{
	struct ListNode l5 = {5, NULL};
	struct ListNode l4 = {4, &l5};
	struct ListNode l3 = {3, &l4};
	struct ListNode l2 = {2, &l3};
	struct ListNode l1 = {1, &l2};
    struct ListNode *h = &l1;

    char buf[100];
    reverse(h, &buf[0], sizeof(buf));
    assert(!strcmp(buf, "5,4,3,2,1,"));
}

/*
 NULL l0 -> l1 -> l2 -> l3
 pre  c     t

 NULL l0 <- l1    l2 -> l3
      pre   h|c   tmp
 */
