#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void func() {
    int x = 0;
    printf("%d\n", x);
}

void foo() {
    int x = 0;
    printf("%d\n", x);
    func();
}

int main() {
    int x = 0;
    printf("%d\n", x);
    foo();
    return 0;
}
