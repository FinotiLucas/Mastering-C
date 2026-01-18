// Static String Lifetime Demonstration
// ====================================
//
// This program demonstrates how returning a pointer to a static
// local buffer affects memory lifetime in C.
//
// The function `get_message` returns a pointer to a static character
// array, allowing the caller to access and modify the data after the
// function returns. This highlights differences between stack and
// static storage duration, as well as subtle memory ownership rules.
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT (see LICENSE file)

#include <stdio.h>

char *get_message(void) {
    static char buffer[32] = "Hello World";
    return buffer;
}

int main(void) {
    char *msg = get_message();

    msg[0] = 'h';
    printf("Message: %s\n", msg);

    return 0;
}
