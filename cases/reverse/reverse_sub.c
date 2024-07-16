#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include <glib/glist.h>

// 定义一个链表结构体，其中带有一个 int var 变量
struct node
{
    int var;
    struct node *next;
};

// 定义一个函数，函数功能入参为，链表h，其功能为计算链表长度
int len(struct node *h)
{
    int len;
    for (len = 0; h; h = h->next, len++);
    return len;
}

// 定义一个函数，函数功能入参为，链表h和int k，其功能为依次对链表中每 k 个元素进行反转，不足k个元素的不处理
void reverse_sub(struct node *h, int k)
{
    int list_len  = len(h);
    struct node sec_h = { .next = h };
    struct node **h_r;
    struct node *cur, *tmp;

    h_r = &sec_h.next;
    cur = *h_r;
    for (int i = 0; i < list_len / k; i++) {
        for (int j = 0; j < k - 1; j++) {
            tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = *h_r;
            *h_r = tmp;
        }
        h_r = &cur->next;
        cur = *h_r;
    }

    tmp = &sec_h;
    while (tmp->next) {
        printf("%d,", tmp->next->var);
        tmp = tmp->next;
    }
    printf("\n");
}

int main()
{
    // 构造一个链表，var 内容为 1 2 3 4 5
    struct node l5 = {5, NULL};
    struct node l4 = {4, &l5};
    struct node l3 = {3, &l4};
    struct node l2 = {2, &l3};
    struct node l1 = {1, &l2};
    struct node *h = &l1;

    reverse_sub(h, 2);
    while (1);
}


/*
 h -> a -> b -> c -> d -> e
      c
 h -> a t> b -> c -> d -> e
           c
 h t> b    a -> c -> d -> e
 h -> b -> a -> c -> d -> e
           c
 h -> b -> a t> c -> d -> e
 h t> c    b -> a -> d -> e
                c
 h -> c -> b -> a -> d -> e
 */
