#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

uint64_t hash(char *word, int len)
{
    uint64_t val = 0;
    for (int i = 0; i < len; i++) {
        val = val * 12345UL + (word[i] - 'a' + 1);
    }
    return val;
}

bool query(uint64_t *hashTbl, int wordDictSize, uint64_t hashVal)
{
    for (int i = 0; i < wordDictSize; i++) {
        if (hashVal == hashTbl[i]) {
            return true;
        }
    }

    return false;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {       
    uint64_t hashTbl[wordDictSize];
    int s_len = strlen(s);
    bool mark[s_len + 1];
    int i, j;

    for (i = 0; i < wordDictSize; i++) {
        hashTbl[i] = hash(wordDict[i], strlen(wordDict[i]));
    }

    memset(mark, 0, sizeof(mark));
    mark[0] = true;
    for (i = 1; i <= s_len; i++) {
        for (j = 0; j < i; j++) {
            if (mark[j] && query(hashTbl, wordDictSize, hash(&s[j], (i - j)))) {
                mark[i] = true;
                break;
            }
        }
    } 

    return mark[s_len];
}

int main()
{

    {
        char s[] = "cbca";
        char *wordDict[] = { "bc", "ca" };

        assert(wordBreak(s, wordDict, sizeof(wordDict) / sizeof(wordDict[0])));
    }

    {
        char s[] = "applepenapple";
        char *wordDict[] = { "pen", "apple" };

        assert(wordBreak(s, wordDict, sizeof(wordDict) / sizeof(wordDict[0])));
    }

    {
        char s[] = "leetcode";
        char *wordDict[] = { "leet", "code" };

        assert(wordBreak(s, wordDict, sizeof(wordDict) / sizeof(wordDict[0])));
    }

    {
        char s[] = "catsandog";
        char *wordDict[] = { "cats","dog","sand","and","cat" };

        assert(!wordBreak(s, wordDict, sizeof(wordDict) / sizeof(wordDict[0])));
    }
}
