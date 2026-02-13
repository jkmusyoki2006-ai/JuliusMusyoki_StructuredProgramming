## Assignment 3 — Pointers and Function Call Styles

Author: Julius Musyoki

This README explains the core ideas used in Assignment 3: the difference between normal variables and pointers, how to declare and use pointers, common situations where pointers are useful, the risks of pointers, and the difference between call by value and call by reference. The explanations are short and practical — aimed at someone who already knows basic C but is early in learning pointers.

### 1. What is a variable vs a pointer?

- A **variable** holds a value directly (for example, an `int` stores its number in memory).
- A **pointer** holds the memory address of another variable. It does not hold the value itself, but where the value is stored.

Example:

```c
int n = 10;      // n stores the value 10
int *p = &n;     // p stores the address of n
```

Here `&` gives the address of `n`, and the type `int *` means "pointer to int".

### 2. Declaration vs definition and the \* and & operators

- To declare and initialize a normal variable: `int n = 10;`
- To declare and initialize a pointer: `int *p = &n;`

- `*` when used in a declaration means "pointer to" (e.g., `int *p`).
- `*` when used with a pointer variable (not in the declaration) is the dereference operator: it accesses the value at the address stored by the pointer (for example `*p = 20;`).
- `&` gives the address of a variable: `&n` is the address of `n`.

Example showing both:

```c
int n = 10;
int *p = &n;   // p points to n
printf("n = %d\n", *p); // prints 10
*p = 15;       // changes n through the pointer
```

### 3. Dereferencing — what it means

- Dereferencing a pointer (using `*`) means: go to the memory address the pointer holds and read or write the value there.
- Use parentheses when modifying the pointed value, e.g. `(*p)++` increments the pointed value.

Correct example:

```c
int n = 10;
int *p = &n;
(*p)++;   // increments n to 11
```

Note: `int *p = &10;` is invalid — you cannot take the address of a literal.

### 4. When to use pointers (common cases)

- To let a function modify the original variable (e.g., swap two values).
- To work efficiently with arrays and strings without copying data.
- For dynamic memory allocation (`malloc`, `free`) when size isn't known at compile time.
- To pass large structures by reference instead of copying them.
- To build linked data structures (linked lists, trees).

Example: summing an array using pointer arithmetic

```c
int sum(int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += *(arr + i); // same as arr[i]
    }
    return total;
}
```

Example: dynamic array

```c
int n;
scanf("%d", &n);
int *arr = malloc(n * sizeof(int));
if (arr == NULL) return 1; // check allocation
for (int i = 0; i < n; i++) arr[i] = i * 2;
free(arr);
```

Example: simple linked list node

```c
struct Node {
    int data;
    struct Node *next;
};
```

### 5. Risks and limitations of pointers (short and practical)

- Pointers increase complexity and can make code harder to read.
- Dangling pointers: don't use a pointer after freeing the memory it points to.
- Null pointer dereference: always check pointers if they may be `NULL`.
- Memory leaks: free memory you allocate with `malloc` when it's no longer needed.
- Buffer overflows: be careful not to read or write outside allocated memory.

Best practice: initialize pointers, check allocation results, and `free` what you `malloc`.

### 6. Call by value vs call by reference

Short idea:

- **Call by value** passes a copy of the value to the function. The original variable is not changed.
- **Call by reference** (in C, done with pointers) passes an address so the function can modify the original variable.

Call by value example:

```c
void change(int x) {
    x = 20; // only changes local copy
}

int main() {
    int a = 10;
    change(a);
    // a is still 10 here
}
```

Call by reference example (swap two values):

```c
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int a = 5, b = 7;
    swap(&a, &b);
    // now a == 7 and b == 5
}
```

### Final tips for beginners

- Start by using pointers for simple tasks: passing arrays to functions, and writing small functions that modify an integer via a pointer.
- Always check pointer values before dereferencing (e.g., `if (p != NULL)`).
- Keep examples small and test often — small mistakes with pointers can crash your program.

If you'd like, I can also add short, tested example programs (one-file) that demonstrate each concept so you can compile and run them.
