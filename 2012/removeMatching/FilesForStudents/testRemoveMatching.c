// Test Remove Matching implementation
// 1917 prac exam 2012s1
// David Collien
// dcollien@cse.unsw.edu.au
// 14 June 2012
//
// this program runs a simple test for cloning a list
//

// DO NOT ALTER OR SUBMIT THIS FILE
// we will use our own copy when marking

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "removeMatching.h"

#define DUMMY  42

#define FIRST  196
#define SECOND 887
#define THIRD  1675
#define FOURTH 7436
#define FIFTH  13783
#define SIXTH  52514

void testRemoveMatching(void);

int main(int argc, const char * argv[]) {
   testRemoveMatching();
   return EXIT_SUCCESS;
}

void testRemoveMatching(void) {
   printf("Starting removeMatching() tests...\n");
   
   list inputList;
   list outputList;
   
   
   printf("TEST 1: list with a single node matching");
   inputList.first = malloc(sizeof(node));
   inputList.first->value = FIRST;
   inputList.first->rest  = NULL;
   
   outputList = removeMatching(inputList, FIRST);
   
   assert(outputList.first == NULL);
   
   printf("TEST 1 passed!\n");
   
   printf("TEST 2: list with a single node not matching");
   inputList.first = malloc(sizeof(node));
   inputList.first->value = FIRST;
   inputList.first->rest  = NULL;
   
   outputList = removeMatching(inputList, DUMMY);
   
   assert(outputList.first != NULL);
   assert(outputList.first->rest == NULL);
   assert(outputList.first->value == FIRST);
   
   // free the node as it shouldn't have been removed
   free(outputList.first);
   
   printf("TEST 2 passed!\n");
   
   
   printf("TEST 3: list of 2 nodes not matching");
   inputList.first = malloc(sizeof(node));
   inputList.first->value = FIRST;
   inputList.first->rest  = malloc(sizeof(node));
   inputList.first->rest->value = SECOND;
   inputList.first->rest->rest = NULL;
   
   outputList = removeMatching(inputList, DUMMY);
   
   assert(outputList.first != NULL);
   
   assert(outputList.first->value == FIRST);
   assert(outputList.first->rest != NULL);
   
   assert(outputList.first->rest->value == SECOND);
   assert(outputList.first->rest->rest == NULL);
   
   
   free(outputList.first->rest);
   free(outputList.first);
   
   printf("TEST 3 passed!\n");
      
   
   printf("TEST 4: list of 2 nodes with first node matching");
   inputList.first = malloc(sizeof(node));
   inputList.first->value = FIRST;
   inputList.first->rest  = malloc(sizeof(node));
   inputList.first->rest->value = SECOND;
   inputList.first->rest->rest = NULL;
   
   outputList = removeMatching(inputList, FIRST);
   
   assert(outputList.first != NULL);
   
   assert(outputList.first->value == SECOND);
   assert(outputList.first->rest == NULL);
   
   free(outputList.first);
   
   printf("TEST 4 passed!\n"); 
   
   
   printf("TEST 5: list of 2 nodes with second node matching");
   inputList.first = malloc(sizeof(node));
   inputList.first->value = FIRST;
   inputList.first->rest  = malloc(sizeof(node));
   inputList.first->rest->value = SECOND;
   inputList.first->rest->rest = NULL;
   
   outputList = removeMatching(inputList, SECOND);
   
   assert(outputList.first != NULL);
   
   assert(outputList.first->value == FIRST);
   assert(outputList.first->rest == NULL);
   
   free(outputList.first);
   
   printf("TEST 5 passed!\n");
   
   printf("TEST 6: list of 3 nodes with first and last node matching");
   inputList.first = malloc(sizeof(node));
   inputList.first->value = FIRST;
   inputList.first->rest  = malloc(sizeof(node));
   inputList.first->rest->value = SECOND;
   inputList.first->rest->rest = malloc(sizeof(node));
   inputList.first->rest->rest->value = FIRST;
   inputList.first->rest->rest->rest = NULL;
   
   outputList = removeMatching(inputList, FIRST);
   
   assert(outputList.first != NULL);
   
   assert(outputList.first->value == SECOND);
   assert(outputList.first->rest == NULL);
   
   free(outputList.first);
   
   printf("TEST 6 passed!\n");
   
   printf("TEST 7: list of 3 nodes with middle node matching");
   inputList.first = malloc(sizeof(node));
   inputList.first->value = FIRST;
   inputList.first->rest  = malloc(sizeof(node));
   inputList.first->rest->value = SECOND;
   inputList.first->rest->rest = malloc(sizeof(node));
   inputList.first->rest->rest->value = THIRD;
   inputList.first->rest->rest->rest = NULL;
   
   outputList = removeMatching(inputList, SECOND);
   
   assert(outputList.first != NULL);
   
   assert(outputList.first->value == FIRST);
   assert(outputList.first->rest != NULL);
   
   assert(outputList.first->rest->value == THIRD);
   assert(outputList.first->rest->rest == NULL);
   
   free(outputList.first->rest);
   free(outputList.first);
   
   printf("TEST 7 passed!\n");
   
   
   printf("TEST 8: list of 3 nodes with all nodes matching");
   inputList.first = malloc(sizeof(node));
   inputList.first->value = SECOND;
   inputList.first->rest  = malloc(sizeof(node));
   inputList.first->rest->value = SECOND;
   inputList.first->rest->rest = malloc(sizeof(node));
   inputList.first->rest->rest->value = SECOND;
   inputList.first->rest->rest->rest = NULL;
   
   outputList = removeMatching(inputList, SECOND);
   
   assert(outputList.first == NULL);
   
   printf("TEST 8 passed!\n");
   
   
   printf("TEST 9: list of 5 nodes with some nodes matching");
   inputList.first = malloc(sizeof(node));
   inputList.first->value = THIRD;
   inputList.first->rest  = malloc(sizeof(node));
   inputList.first->rest->value = SECOND;
   inputList.first->rest->rest = malloc(sizeof(node));
   inputList.first->rest->rest->value = THIRD;
   inputList.first->rest->rest->rest = malloc(sizeof(node));
   inputList.first->rest->rest->rest->value = FOURTH;
   inputList.first->rest->rest->rest->rest = malloc(sizeof(node));
   inputList.first->rest->rest->rest->rest->value = THIRD;
   inputList.first->rest->rest->rest->rest->rest = NULL;
   
   outputList = removeMatching(inputList, THIRD);
   
   assert(outputList.first != NULL);
   
   assert(outputList.first->value == SECOND);
   assert(outputList.first->rest != NULL);
   assert(outputList.first->rest->value == FOURTH);
   assert(outputList.first->rest->rest == NULL);
   
   free(outputList.first->rest);
   free(outputList.first);
   
   printf("TEST 9 passed!\n");
   
   printf("TEST 10: list of 6 nodes with some nodes matching");
   inputList.first = malloc(sizeof(node));
   inputList.first->value = SIXTH;
   inputList.first->rest  = malloc(sizeof(node));
   inputList.first->rest->value = SIXTH;
   inputList.first->rest->rest = malloc(sizeof(node));
   inputList.first->rest->rest->value = SIXTH;
   inputList.first->rest->rest->rest = malloc(sizeof(node));
   inputList.first->rest->rest->rest->value = FOURTH;
   inputList.first->rest->rest->rest->rest = malloc(sizeof(node));
   inputList.first->rest->rest->rest->rest->value = SIXTH;
   inputList.first->rest->rest->rest->rest->rest = malloc(sizeof(node));
   inputList.first->rest->rest->rest->rest->rest->value = SIXTH;
   inputList.first->rest->rest->rest->rest->rest->rest = NULL;
   
   outputList = removeMatching(inputList, SIXTH);
   
   assert(outputList.first != NULL);
   
   assert(outputList.first->value == FOURTH);
   assert(outputList.first->rest == NULL);
   
   free(outputList.first);
   
   printf("TEST 10 passed!\n");
   
   printf("All PRAC EXAM tests passed! You are AWESOME!\n");
}
