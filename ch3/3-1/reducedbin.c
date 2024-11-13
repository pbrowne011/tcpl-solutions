/* redbinsearch: find x in v[0] <= v[1] <= ... <= v[n-1], one test in loop */
int redbinsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (x == v[low])
        return low;             /* found match */
    else
        return -1;              /* no match */
}

/*
 * Future readers will note that it took me glancing at the chapter from
 * "Beautiful Code" to realize that the loop invariant deals with low,
 * not mid. Whoops.
 */
