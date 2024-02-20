#### Consider the implementation of QuickSelect below:
```cpp
int lomuto_partition(int array[], int left, int right) {
    int p = array[left], s = left;
    for (int i = left + 1; i <= right; ++i) {
        if (array[i] < p) {
            ++s;
            swap(array[s], array[i]);
        }
    }
    swap(array[left], array[s]);
    return s;
}

int quick_select(int array[], size_t left, size_t right, size_t k) {
    size_t s = lomuto_partition(array, left, right);

    if (s == k - 1) {
        return _____(a)_____;
    }
    if (s > k - 1) {
        return quick_select(array, left, _____(b)_____, k);
    }
    return quick_select(array, _____(c)_____, right, _____(d)_____);
}

int quick_select(int array[], const size_t length, size_t k) {
    return quick_select(array, 0, length - 1, k);
}
```
#### Fill in the 4 blanks in the quickselect algorithm.
#### a = `array[s]`
#### b = `s-1`
#### c = `s+1`
#### d = `k`

#### Show the array `[4, 5, 6, 4, 0]` after running `lomuto_partition`.
> `[0, 4, 6, 4, 5]`

#### Suppose we are sorting an array of 8 integers using `quicksort` with `lomuto_partition` and have just finished the first call to `lomuto_partition`. The array now looks as follows: `[11, 4, 20, 45, 32, 60, 98, 70]`. Which value or values could have been the pivot?
> 20, 60

#### Suppose MergeSort were to cut the array into 3 evenly sized subarrays (instead of 2) and did a 3-way merge after making the recursive calls.
#### Write the recurrence relation for this modified version of mergesort (with the correct asymptotic symbol for the f(n) part of the relation).
> `T(n) = 3T(n/3) + O(n)`
#### Use the Master Theorem to determine its complexity. (answer depends on correct 4a, indicate base for logarithm)
> `T(n) ∈ Θ(n log n)`
