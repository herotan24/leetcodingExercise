#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/glist.h>

int Nresult[] = {
    1,
    1,
    1 * 2,
    1 * 2 * 3,
    1 * 2 * 3 * 4,
    1 * 2 * 3 * 4 * 5,
    1 * 2 * 3 * 4 * 5 * 6,
    1 * 2 * 3 * 4 * 5 * 6 * 7,
    1 * 2 * 3 * 4 * 5 * 6 * 7 * 8,
    1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9,
};

char res[100];

char *getPermutation(int n, int k)
{
    int num_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n_rest = n;
    int x;
    char tmp[10] = {0};
    int k0 = k - 1;

    memset(res, 0, sizeof(res));

    for (int i = 0; i < n; i++) {
        x = k0 / Nresult[n_rest - 1];
        k0 %= Nresult[n_rest - 1];
        sprintf(tmp, "%d", num_list[x]);
        strcat(&res[0], tmp);

        for (int j = x; j < (n - i  - 1); j++) {
            num_list[j] = num_list[j + 1];
        }
        n_rest--;
    }

    return &res[0];
}

int main()
{
    assert(!strcmp("123", getPermutation(3, 1)));
    assert(!strcmp("213", getPermutation(3, 3)));
    assert(!strcmp("2314", getPermutation(4, 9)));
    assert(!strcmp("123", getPermutation(3, 1)));
}


/*
k 组
0 0
1 0

2 1
3 1
 (n-1)! = 2
 k = 3
 123
 132

 213 1  k
 231

 312
 321

1st: k/(n-1)! + 1, 余数 j = k%(n-1)!
2nd: j/(n-2)! + 1



   */
