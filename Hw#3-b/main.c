#include <stdio.h>
typedef struct my_mm {
    char m[10];
    int* p[10];
    int i[10];
    int n[10];
} my_mm_t;
int g_mem[10];
my_mm_t mms;

int* my_calloc(int n, int size) {
    int cnt = 0, start = 0;
    for (int i=0; i<10; i++) {
        if (mms.m[i] == 0) {
            if (cnt == 0) {
                start = i;
            }
            cnt++;
            if (cnt == n*size) {
                for (int i=start; i<start+n*size; i++) {
                    mms.m[i] = 1;
                }
                for (int i=0; i<10; i++) {
                    if (mms.p[i] == NULL) {
                        mms.p[i] = &g_mem[start];
                        mms.i[i] = start;
                        mms.n[i] = n*size;
                        break;
                    }
                }
                for (int i=0; i<n*size; i++) {
                    g_mem[start+i] = 0;
                }
                for (int i=0; i<10; i++) {
                    printf("%d", mms.m[i]);
                }
                printf("\n");
                return &g_mem[start];
            }
        } else {
            cnt = 0;
        }
    }
    for (int i=0; i<10; i++) {
        printf("%d", mms.m[i]);
    }
    return NULL;
}

void my_free(int *p) {
    for (int i=0; i<10; i++) {
        if (mms.p[i] == p) {
            mms.p[i] = NULL;
            for (int j=0; j<mms.n[i]; j++) {
                mms.m[mms.i[i]+j] = 0;
            }
            for (int i=0; i<10; i++) {
                printf("%d", mms.m[i]);
            }
            mms.n[i] = 0;
            mms.i[i] = 0;
            printf("\n");
            return;
        }
    }
    for (int i=0; i<10; i++) {
        printf("%d", mms.m[i]);
    }
}
int main() {
    int* np1 = my_calloc(1, 1);
    int* np2 = my_calloc(1, 2);
    int* np3 = my_calloc(1, 3);
    int* np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    int* np5 = my_calloc(1, 3);
    return 0;
}
