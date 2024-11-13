/* test.c: test binary search correctness and run-time
 *
 * Based on (limited) testing, I've seen redbinsearch
 * (reduced binary search, for removing one branch) be up
 * to 40% faster (differenes of ~24k vs ~14k clocks,
 * according to clock()). I should run this test X number
 * of times and take averages, plus remove writes and
 * other syscalls (and other things I don't know how to
 * do) for cleaner testing.
 */

#include <stdio.h>
#include <time.h>
#include "binsearch.h"
#define TESTNUM 1000000


void runtest(int x, int v[], int n);

int main()
{
    int i, l, n;
    clock_t start_time;
    int v[] = {-30, -20, -10, 0, 10, 20, 30, 40,
               50, 60, 70, 80, 90, 100, 110, 120};
    int test[] = {-30, -10, 0, 10, 100, 40,
                  16, 42, -5, 4, 111, 12, 1};

    n = (sizeof(v)/sizeof(int));
    l = (sizeof(test)/sizeof(int));
    printf("Correctness test\n----------------\n");
    for (i = 0; i < l; ++i)
        runtest(test[i], v, n);
    printf("Performance test\n----------------\n");
    start_time = clock();
    for (i = 0; i < TESTNUM; ++i)
        binsearch(test[3], v, n);
    printf("binsearch clock cycles: %ld\n", clock() - start_time);
    start_time = clock();
    for (i = 0; i < TESTNUM; ++i)
        redbinsearch(test[3], v, n);
    printf("redbinsearch clock cycles: %ld\n", clock() - start_time);
}

/* runtest: run a single test case */
void runtest(int x, int v[], int n)
{
    int i, j;

    i = binsearch(x, v, n);
    j = redbinsearch(x, v, n);
    printf("Testcase: x = %d, ", x);
    if (i == j)
        printf("PASS\n");
    else
        printf("FAIL: binsearch returned %d, redbinsearch returned %d\n", i, j);
}
