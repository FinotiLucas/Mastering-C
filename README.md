# C Programming Study Plan (Beginner → Advanced)

## MODULE 1 – C Foundations (Syntax & Mental Model) ✅✅✅

**Goal:** Understand what C *is* and how it differs from JS/TS

### Topics

* Compilation model (preprocess → compile → link)
* `main`, headers, source files
* Variables, types, operators
* Control flow (`if`, `for`, `while`, `switch`)
* Functions & function prototypes
* Stack vs heap (conceptual only)
* `stdio.h`, `printf`, `scanf`
* **No runtime safety net**

### Key Concepts (JS → C shift)

* No garbage collector
* No bounds checking
* No runtime type safety
* You control memory and lifetimes

### Exercises

1. Write a program that prints command-line arguments (`argc`, `argv`)✅
2. Implement a calculator using `switch` ✅
3. Write a function that swaps two integers (first attempt will fail—learn why) ✅
4. Implement your own `strlen` ✅

Compile with:

   ```sh
   gcc -Wall -Wextra -Werror
   ```

---

## MODULE 2 – Memory & Pointers (CORE MODULE) ✅✅✅

**Goal:** Become comfortable with pointers and memory ownership

### Topics

* Addresses and `&`
* Pointers and `*`
* Pointer arithmetic
* `NULL`
* Arrays vs pointers
* Stack memory layout
* Passing by value vs by pointer

### Undefined Behavior Introduced

* Dereferencing uninitialized pointers
* Out-of-bounds access
* Returning pointers to stack memory

### Exercises

1. Write a function that reverses an array **in place**✅
2. Print memory addresses of array elements✅
3. Implement `strcpy` using pointers✅
4. Write a program that **crashes**, then explain *why*✅

---

## MODULE 3 – Dynamic Memory Allocation✅✅✅

**Goal:** Understand heap memory and manual lifecycle management

### Topics

* `malloc`, `calloc`, `realloc`, `free`
* Ownership rules
* Memory leaks
* Double free
* Dangling pointers
* Heap vs stack lifetimes

### Tools Introduced

* `valgrind`
* `AddressSanitizer`

run with:
  ```sh
  gcc -g -Wall -Wextra -Werror main.c -o main && valgrind --leak-check=full ./main
  ```

### Exercises

1. Allocate an array dynamically and fill it✅
2. Implement a dynamic string type✅
3. Write a program with a memory leak, then fix it✅
4. Re-implement `strdup`✅
6. Re-implement `memcpy`✅

---

## MODULE 4 – Strings & Buffers (Security-Critical)

**Goal:** Learn why C strings are dangerous

### Topics

* Null-terminated strings
* Buffer overflow
* `strcpy` vs `strncpy` vs `snprintf`
* Input handling (`fgets` vs `gets`)
* Defensive coding

### Undefined Behavior

* Writing past buffer end
* Missing `\0`
* Reading uninitialized memory

### Exercises

1. Implement `strlen` safely✅
2. Write a safe input function using `fgets`✅
3. Implement string concatenation with size limits✅
4. Write a program vulnerable to buffer overflow, then fix it
5. Detect overflow using AddressSanitizer

---

## MODULE 5 – Structs, Enums & Data Modeling

**Goal:** Model complex data safely

### Topics

* `struct`, `typedef`
* Padding & alignment
* Nested structs
* Enums and bit flags
* Ownership inside structs

### Exercises

1. Define a `User` struct with dynamically allocated fields✅
2. Write create/destroy functions for a struct✅
3. Pass structs by value vs pointer—measure difference✅
4. Implement a linked list node
5. Introduce and fix a dangling pointer bug

---

## MODULE 6 – File I/O & System Interaction

**Goal:** Work with the OS

### Topics

* `FILE*`, `fopen`, `fread`, `fwrite`
* Binary vs text files
* Error handling with `errno`
* Resource leaks (files ≠ memory)

### Exercises

1. Read a file line by line
2. Write a binary file and read it back
3. Implement a config file parser
4. Handle all failure cases explicitly
5. Intentionally forget `fclose` and detect it

---

## MODULE 7 – Undefined Behavior (DEEP DIVE)

**Goal:** Learn what C *does not promise*

### Topics

* What UB actually is
* Strict aliasing
* Signed integer overflow
* Uninitialized reads
* Lifetime violations

### Exercises

1. Write code that behaves differently with `-O0` vs `-O2`
2. Trigger signed overflow
3. Use an uninitialized variable
4. Cast incompatible pointer types
5. Explain *why* behavior is undefined

---

## MODULE 8 – Advanced Memory & Performance

**Goal:** Think like a systems programmer

### Topics

* Custom allocators
* Memory pools
* Cache friendliness
* Alignment
* `restrict`
* Escape analysis

### Exercises

1. Write a simple arena allocator
2. Compare `malloc` vs arena performance
3. Implement a fixed-size object pool
4. Profile memory access patterns
5. Remove heap allocations from hot paths

---

## MODULE 9 – Concurrency (Low-Level)

**Goal:** Understand shared memory dangers

### Topics

* `pthread`
* Data races
* Mutexes
* Atomic operations
* False sharing

### Exercises

1. Write a multithreaded counter (broken)
2. Fix it with a mutex
3. Fix it with atomics
4. Cause a race condition intentionally
5. Analyze race with ThreadSanitizer

---

## MODULE 10 – Real-World C Projects

**Goal:** Prove mastery

### Project Ideas

* Custom memory allocator
* HTTP server (no frameworks)
* JSON parser
* `malloc` replacement
* Simple shell

### Requirements

* Zero memory leaks
* No undefined behavior
* Compiles with:

  ```sh
  -Wall -Wextra -Werror -fsanitize=address,undefined
  ```

---

## 🔧 Tooling You MUST Use

```sh
gcc / clang
valgrind
AddressSanitizer
UndefinedBehaviorSanitizer
gdb
```

---

## 🧠 Mindset Shift (Important)

From Node.js:

> “The runtime protects me”

To C:

> “The compiler trusts me—and will punish mistakes silently”

---

## 📚 Recommended Resources

* **Book:** *The C Programming Language* – K&R
* **Book:** *Expert C Programming* – Peter van der Linden
* **Book:** *Computer Systems: A Programmer’s Perspective*
* **Practice:** LeetCode (but in C, memory-safe)

---
