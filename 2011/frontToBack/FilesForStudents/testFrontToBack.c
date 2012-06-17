// Test List implementation
// 1917 prac exam 2011s1
// David Collien
// dcollien@cse.unsw.edu.au
// 20 June 2011
//
// this program runs a simple test for rotating a list
// from front To Back

// DO NOT ALTER OR SUBMIT THIS FILE
// we will use our own copy when marking

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "frontToBack.h"

#define FIRST  196
#define SECOND 887
#define THIRD  1675
#define FOURTH 7436
#define FIFTH  13783
#define SIXTH  52514

#define SIZE 6

void testFrontToBack (void);
void ensureListMatch (list inputList, 
                      int correctValues[SIZE], 
                      node *correctAddresses[SIZE]);

int main (int argc, const char * argv[]) {
   testFrontToBack();
   return EXIT_SUCCESS;
}

void testFrontToBack (void) {
   printf ("Starting frontToBack() tests...\n");
   
   list inputList;
   list outputList;
   
   node first;
   node second;
   node third;
   node fourth;
   node fifth;
   node sixth;

   first.value = FIRST;
   second.value = SECOND;
   third.value = THIRD;
   fourth.value = FOURTH;
   fifth.value = FIFTH;
   sixth.value = SIXTH;
   
   printf ("TEST 1: testing rotation on single item list [196]...\n");
   printf ("    expecting [196] ...\n");
   
   inputList.first = &first;
   first.rest = NULL;
   
   outputList = frontToBack (inputList);
   assert (outputList.first->value == FIRST);
   assert (outputList.first->rest == NULL);
   assert (outputList.first == &first);
   
   printf ("TEST 1 passed!\n");
   
   
   printf ("TEST 2: testing rotation on double item list [196,887]...\n");
   printf ("    expecting [887,196] ...\n");
   
   inputList.first = &first;
   first.rest = &second;
   second.rest = NULL;
   
   outputList = frontToBack (inputList);
   assert (outputList.first->value == SECOND);
   assert (outputList.first->rest == &first); // 9
   assert (outputList.first == &second);
   
   assert (outputList.first->rest->value == FIRST);
   assert (outputList.first->rest->rest == NULL);
   assert (outputList.first->rest == &first);
   
   printf ("TEST 2 passed!\n");
   
   
   
   printf ("TEST3: rotate [52514,196,887,1675,7436,13783] ...\n");
   printf ("    expecting [196,887,1675,7436,13783,52514] ...\n");
   
   
   inputList.first = &sixth;
   sixth.rest = &first;
   first.rest = &second;
   second.rest = &third;
   third.rest = &fourth;
   fourth.rest = &fifth;
   fifth.rest =  NULL;
   
   outputList = frontToBack (inputList);
   
   int correctValues[SIZE] = {
      FIRST,
      SECOND,
      THIRD,
      FOURTH,
      FIFTH,
      SIXTH
   };
   
   node *correctRestPtrs[SIZE] = {
      &second,
      &third,
      &fourth,
      &fifth,
      &sixth,
      NULL
   };
   
   assert (outputList.first == &first);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
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
   
   assert (first->rest->rest->rest->rest->rest->rest == correctAddresses[5]);
   assert (first->rest->rest->rest->rest->rest->value == correctValues[5]);
}