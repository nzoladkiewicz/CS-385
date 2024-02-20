Give the running time of the following functions. Choose the most appropriate notation from among $\Theta$, O, and $\Omega$. Simplify your answer
as much as possible. Be sure to indicate the correct bawse for logarithms.

1a.
```cpp
void function1 (int n) {
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j -= i) {
      cout << "*";
    }
  }
}
```
> Answer: $\Theta(n lg n)$

1b.
```cpp
void function2 (int n) {
  if (n < 1) {
    return;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = 1; k <= n; k *= 2) {
        cout << "*";
      }
    }
  }
}
```
> Answer: $\Theta(n^2 lg (n))$

1c. 
```cpp
int function3 (int arr1[], int arr2[], int n) {
  int count = 0;
  for (int i = 1; i <= n / i && arr1[i] != arr2[i]; i++) {
    count++;
  }
  return count;
```
> Answer: $O \sqrt n$

1d. 
```cpp
int function4 (int array[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (array[i] < 0) {
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    sum += array[i];
  }
  return sum;
}
```
> Answer: $O(n)$

1e. `function5` takes as input a sorted array of integers and a second array of integer keys. Applies binary search to every key in the second array, returning an array of Booleans as to whether or not each key is in the sorted array. Assume both arrays are of size n elements. 
> Answer: $\Theta(n lg(n))$

2a. Consider the following 2 functions. $f(n) = n + n ln(n)$ and $g(n) = n \sqrt(n)$. Which of the following is true?
- $f \in O(g)$
- $g \in O(f)$
- Both $f \in O(g)$ and $g \in O(f)$ are true.

2b. Consider the following 2 functions: $f(n) = n$ and $g(n) = 2<sup>lg(n)</sup>$. Which of the following is true?
- $f \in O(g)$
- $g \in O(f)$
- Both $f \in O(g)$ and $g \in O(f)$ are true.

2c. The graph shown below shows $\Theta(g(n))$. Select the correct line for $n_0$.
- <img width="282" alt="Screenshot 2024-01-30 at 12 29 49 PM" src="https://github.com/nzoladkiewicz/CS385/assets/94705730/0da59244-ec0f-412a-a755-d1f79879d0cd">

> Answer: On the test, $n_0$ won't be labeled. You can see the answer in the image above.

2d. True or false? $f(n) = n(2n(3n + 7) + 2) + 4 \in O(n^4)$?
> Answer: True

2e. Prove that $f(n) = 2n^2 + 4n + 12 \in O(n^2)$ by giving values for the required constants $c$ and $n_0$ with the tightest integer value of $c$ possible. 
> Answer: c = 3, n = 6

2f. Show that $f(n) = 7n^2 + 4n + 3 \notin \Omega(n^3)$ with a contradiction that the relationship holds for $n ≤$ a constant.

4a. What is printed on the screen after executing the following statements?
```cpp
int a = 11;
cout << (((a << 3) | 14) >> (a & 23)) << endl;
```
> Answer: 11

4b. Suppose you have allocated an array of twenty doubles, called `values`, on the heap. Write the line of code to free up the memory when the array is no longer needed.
> Answer: `delete [] values;`

4c. What values are printed on the screen after executing the following code?
```cpp
void pass_vars (int &x, int *y) {
  x = 0;
  *y = 0;
}
int main() {
  int x = 20, y = 30;
  pass_vars(x, &y);
  cout << x << " " << y << endl;
  return 0;
}
```
> Answer: x 0 y 0

4d. Suppose you have an executable named `maximum` that takes in exactly 5 command line arguments. If you run the program as follows: 
`./maximum 21 3 107 50 hi`
then what is the value of `argv[argc - 2]` from within your C++ program?
> Answer: 50

4e. Suppose you have the following code and want to print out each `MyPoint` on the screen. The `MyPoint` class has a `print_coords()` method that you need to call. Fill in the blank to complete the function.
```cpp
void display_points (const vector<MyPoint> &points) {
  for (auto it = points.cbegin(); it != ______; it++) {
    it-> print_coords();
  }
}
```
> Answer: `points.cend()`

5. Extra Credit: Solve the following recurrence relation $x(n) = x(n/3) + n$ for all $n > 1$, $x(1) = 1$. You can assume that $n = 3^k$.
