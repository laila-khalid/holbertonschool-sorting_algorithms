# Sorting algorithms & Big O

## Description
This project introduces various sorting algorithms and Big O notation in C. It covers how to implement them and evaluate their time complexity.

## Requirements
* Ubuntu 20.04 LTS
* gcc -Wall -Werror -Wextra -pedantic -std=gnu89
* Betty style

## Data Structure
The following data structure is used for doubly linked list tasks:
```c
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
