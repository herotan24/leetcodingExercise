#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/glist.h>


struct entry {
    int key;
    int val;
};

typedef struct {
    GList *head;
    int n;
    int cap;
} LRUCache;

LRUCache g_LRUctrl;

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache *ctrl = &g_LRUctrl;

    memset(ctrl, 0, sizeof(*ctrl));
    ctrl->cap = capacity;

    return ctrl;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    LRUCache *ctrl = &g_LRUctrl;
    struct entry *data;
    GList *node;

    if (ctrl->n < ctrl->cap) {
        data = malloc(sizeof(struct entry));
        data->key = key;
        data->val = value;
        ctrl->head = g_list_prepend(ctrl->head, data);
        ctrl->n++;
        return;
    }

    node = g_list_last(ctrl->head);
    ctrl->head = g_list_remove_link(ctrl->head, node);
    data = (struct entry *)node->data;
    data->key = key;
    data->val = value;
    ctrl->head = g_list_concat(node, ctrl->head);
}

int lRUCacheGet(LRUCache* obj, int key)
{
    LRUCache *ctrl = &g_LRUctrl;
    struct entry *data;

    for (GList *iter = ctrl->head; iter; iter = iter->next) {
        data = (struct entry *)iter->data;
        if (data->key == key) {
            ctrl->head = g_list_remove_link(ctrl->head, iter);
            ctrl->head = g_list_concat(iter, ctrl->head);
            return data->val;
        }
    }

    return -1;
}

int main() {
    LRUCache *lru;

    assert(lru = lRUCacheCreate(2));
    lRUCachePut(lru, 1, 1);
    lRUCachePut(lru, 2, 2);
    assert(lRUCacheGet(lru, 1) == 1);
    lRUCachePut(lru, 3, 3);
    assert(lRUCacheGet(lru, 2) == -1);
    lRUCachePut(lru, 4, 4);
    assert(lRUCacheGet(lru, 1) == -1);
    assert(lRUCacheGet(lru, 3) == 3);
    assert(lRUCacheGet(lru, 4) == 4);
    return 0;
}
