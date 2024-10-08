#### Suzy Shaker has just invented what she thinks is a great sorting algorithm. Consider the following code:
```cpp
void shaker_sort(int array[], const int length) {
     int max_index = length, min_index = 1;
     bool sorted;
     do {
          sorted = true;
          for (int i = min_index; i < max_index; i++) {
               if (array[i - 1] > array[i]) {
                    swap(array, i - 1, i);
                    sorted = false;
               }
          }
          max_index--;
          if (sorted) break;
          for (int i = max_index - 1; i >= min_index; i--) {
               if (array[i - 1] > array[i]) {
                    swap(array, i - 1, i);
                    sorted = false;
               }
          }
          min_index++;
     } while (!sorted);
}
```

#### Show the array [2, 1, 9, 7, 6] after the do-while loop executes once. Parameters: `int array[] = [2, 1, 9, 7, 6], const int length = 5`
> Order of elements: 1, 2, 6, 7, 9

#### What is the best-case complexity of the algorithm above?
> $`\Theta`$$(n)$

#### What is the worst-case complexity of the algorithm above?
> $`\Theta`$(n<sup>2</sup>)

#### Which of the sorting algorithms discussed in class is closest to what Suzy has written?
> Bubble sort
