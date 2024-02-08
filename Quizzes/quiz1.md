#### In what region of memory has the following object been created (write only one word for your answer)?
`Student s("John", "Doe");`
> Answer: Stack

#### Consider the following function to print out data about each student in a vector of students. Fill in the blank:
```cpp
void print_students (const vector<Student> &students) {

   for (const _____ &student : students) {
      student.print_info();
   }
}
```
> Answer: auto

#### Suppose you run the maxtwo program on the command line as such:
`./maxtwo 66 28`. What is argv[2]?
> Answer: 28

#### Suppose you have the following main and pass_by_pointer functions:
```cpp
void pass_by_pointer(int *x) {
   *x = 10;
}

int main(void) {
   int x = 5;
   pass_by_pointer(&x);
   cout << x;
   return 0;
}
```
> Answer: 10

#### If you would like to convert a string into an integer, what class from <sstream> would you use to perform the conversion (write only one C++ word for your answer)?
> Answer: `istringstream`
