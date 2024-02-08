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
