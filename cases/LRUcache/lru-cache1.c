#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <glib.h>


typedef struct {
#define MAX_CACHE_NUM (32)
    struct elemt {
        int key;
        int val;
    } entry[MAX_CACHE_NUM];;

    GList *head;
    GList *free;
    int n;
    int cap;
} LRUCache;

LRUCache g_LRUctrl;

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache *ctrl = &g_LRUctrl;
    if (capacity <= 0 || capacity > MAX_CACHE_NUM)
        return NULL;

    memset(ctrl, 0, sizeof(*ctrl));
    ctrl->cap = capacity;

    for (int i = 0; i < capacity; i++) {
        ctrl->free = g_list_append(ctrl->free, &ctrl->entry[i]);
    }

    return ctrl;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    LRUCache *ctrl = &g_LRUctrl;
    GList *tmp;

    if (ctrl->n < ctrl->cap) {
        tmp = g_list_last(ctrl->free);
        ctrl->free = g_list_remove_link(ctrl->free, tmp);
        ((struct elemt *)tmp->data)->key = key;
        ((struct elemt *)tmp->data)->val = value;
        ctrl->head = g_list_concat(tmp, ctrl->head);
        ctrl->n++;
        return;
    }

    tmp = g_list_last(ctrl->head);
    ctrl->head = g_list_remove_link(ctrl->head, tmp);
    ((struct elemt *)tmp->data)->key = key;
    ((struct elemt *)tmp->data)->val = value;
    ctrl->head = g_list_concat(tmp, ctrl->head);
    return;
}

int lRUCacheGet(LRUCache* obj, int key) {
    LRUCache *ctrl = &g_LRUctrl;
    struct elemt *entry;

    for (GList *tmp = ctrl->head; tmp; tmp = tmp->next) {
        entry = (struct elemt *)tmp->data;
        if (entry->key == key) {
            ctrl->head = g_list_remove_link(ctrl->head, tmp);
            ctrl->head = g_list_concat(tmp, ctrl->head);
            return entry->val;
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
