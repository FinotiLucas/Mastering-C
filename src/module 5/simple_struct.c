// User Entity Module (Multi-Allocation Pattern)
// ============================================
//
// This module implements a 'User' data structure with dynamically allocated
// string fields. It follows the manual lifecycle management pattern where
// each member owns its specific heap allocation.
//
// Engineering Principles Applied:
// ------------------------------
// - Leak Prevention: Implementation of a "Cleanup Ladder" ensures that
//   partial allocations are rolled back if subsequent memory requests fail.
// - Deep Copy Semantics: The module clones input buffers (name/email),
//   ensuring the structure remains valid even if the caller's original
//   buffers are modified or go out of scope.
// - Defensive Programming: Includes NULL pointer checks for inputs and
//   post-deallocation pointer sanitization to mitigate "Use-After-Free" risks.
//
// Ownership & Contract:
// ---------------------
// 1. The `create_user` function transfers full memory ownership to the caller.
// 2. The caller IS RESPONSIBLE for invoking `user_destroy` to release
// resources.
// 3. The User structure encapsulates three distinct memory segments:
//    [Base Struct] -> [Name Buffer] -> [Email Buffer]
//
// Error Handling:
// ---------------
// In Out-Of-Memory (OOM) scenarios, the function returns NULL and guarantees
// that no partial memory leaks occur (Error Atomicity).
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int age;
  char *name;
  char *email;
} User;

User *create_user(const char *name, const char *email, int age) {
  if (name == NULL) {
    return NULL;
  }

  User *user = malloc(sizeof(*user));
  if (user == NULL) {
    return NULL;
  }

  size_t len_name = strlen(name) + 1;
  size_t len_email = strlen(email) + 1;

  user->name = malloc(len_name);
  if (user->name == NULL) {
    free(user);
    return NULL;
  }

  user->email = malloc(len_email);
  if (user->email == NULL) {
    free(user->name);
    free(user);
    return NULL;
  }

  memcpy(user->name, name, len_name);
  memcpy(user->email, email, len_email);

  user->age = age;

  return user;
}

User *clone_user(const User *u) {
  if (u == NULL) {
    return NULL;
  }

  return create_user(u->name, u->email, u->age);
}

void user_destroy(User *user) {
  if (user == NULL) {
    return;
  }

  free(user->name);
  user->name = NULL;

  free(user->email);
  user->email = NULL;

  free(user);
}

int main(void) {
  char name[] = "Lucas";
  char email[] = "lucas@email.com";
  int age = 28;

  User *user = create_user(name, email, age);
  User *user_clone = clone_user(user);

  if (user && user_clone) {

    printf("User name: %s, User email: %s, User age: %d\n", user->name,
           user->email, user->age);

    printf("Clone name: %s, Clone email: %s, Clone age: %d\n", user_clone->name,
           user_clone->email, user_clone->age);

    user_destroy(user);
    user_destroy(user_clone);

    user = NULL;
    user_clone = NULL;
  }

  return 0;
}
