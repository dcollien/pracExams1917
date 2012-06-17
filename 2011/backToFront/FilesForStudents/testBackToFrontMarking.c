// Test List implementation for Marking
// 1917 prac exam 2011s1
// David Collien
// dcollien@cse.unsw.edu.au
// 20 June 2011
//
// this program runs a simple test for rotating a list
// from back to front

// DO NOT ALTER OR SUBMIT THIS FILE
// we will use our own copy when marking

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "backToFront.h"

#define FIRST  19
#define SECOND 88
#define THIRD  167
#define FOURTH 743
#define FIFTH  1378

#define SIZE 5

void testRotate (void);
void ensureListMatch (list inputList, int correctValues[SIZE], node *correctAddresses[SIZE]);

int main (int argc, const char * argv[]) {
   testRotate();
   return EXIT_SUCCESS;
}

void testRotate (void) {
   list inputList;
   list outputList;
   
   node first;
   node second;
   node third;
   node fourth;
   node fifth;
   
   first.value = FIRST;
   second.value = SECOND;
   third.value = THIRD;
   fourth.value = FOURTH;
   fifth.value = FIFTH;
   
   int correctValues[SIZE] = {
      FIRST,
      SECOND,
      THIRD,
      FOURTH,
      FIFTH,
   };
   
   node *correctRestPtrs[SIZE] = {
      &second,
      &third,
      &fourth,
      &fifth,
      NULL
   };
   
   
   printf ("TEST1: rotate [88,16,74,137,19] ...\n");
   printf ("expecting [19,88,16,74,137] ...\n");
   
   
   inputList.first = &second;
   second.rest = &third;
   third.rest = &fourth;
   fourth.rest = &fifth;
   fifth.rest = &first;
   first.rest = NULL;
   
   outputList = backToFront (inputList);
   assert (outputList.first == &first);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("TEST 1 passed!\n");
   
   printf ("TEST 2: testing rotation on single item list [19]...\n");
   printf ("expecting [19] ...\n");
   
   inputList.first = &third;
   third.rest = NULL;
   
   outputList = backToFront (inputList);
   assert (outputList.first->value == THIRD);
   assert (outputList.first->rest == NULL);
   assert (outputList.first == &third);
   
   printf ("TEST 2 passed!\n");
   
    
   printf ("TEST 3: testing rotation on double item list [19,88]...\n");
   printf ("expecting [88,19] ...\n");
   
   inputList.first = &first;
   first.rest = &second;
   second.rest = NULL;
   
   outputList = backToFront (inputList);
   assert (outputList.first->value == SECOND);
   assert (outputList.first->rest == &first); // 9
   assert (outputList.first == &second);
   
   assert (outputList.first->rest->value == FIRST);
   assert (outputList.first->rest->rest == NULL);
   assert (outputList.first->rest == &first);
   
   printf ("TEST 3 passed!\n");
   
   
   
   printf ("All PRAC EXAM tests passed! You are AWESOME!\n");
}

void ensureListMatch (list inputList, int correctValues[SIZE], node *correctAddresses[SIZE]) {
   nodePtr first;
   first = inputList.first;
   
   //   testing values match and nodes not altered
   assert (first != NULL);
   
   assert (first->rest == correctAddresses[0]);
   assert (first->value == correctValues[0]);
   
   assert (first->rest->rest == correctAddresses[1]);
   assert (first->rest->value == correctValues[1]);
   
   assert (first->rest->rest->rest == correctAddresses[2]);
   assert (first->rest->rest->value == correctValues[2]);
   
   assert (first->rest->rest->rest->rest == correctAddresses[3]);
   assert (first->rest->rest->rest->value == correctValues[3]);
   
   assert (first->rest->rest->rest->rest->rest == correctAddresses[4]);
   assert (first->rest->rest->rest->rest->value == correctValues[4]);
   
}