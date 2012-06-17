// Test List Clone implementation
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
#include "clone.h"

#define DUMMY  42

#define FIRST  196
#define SECOND 887
#define THIRD  1675
#define FOURTH 7436
#define FIFTH  13783
#define SIXTH  52514

#define SIZE 6

void testClone(void);

int main(int argc, const char * argv[]) {
   testClone();
   return EXIT_SUCCESS;
}

void testClone(void) {
   printf("Starting clone() tests...\n");
   
   list inputList;
   list outputList;
   
   node first;
   node second;
   node third;
   node fourth;
   node fifth;
   node sixth;
   
   node *outputNode;
   node *freeingNode;
   
   void *firstAddress  = &first;
   void *secondAddress = &second;
   void *thirdAddress  = &third;
   //void *fourthAddress = &fourth;
   //void *fifthAddress  = &fifth;
   //void *sixthAddress  = &sixth;
   
   first.value = FIRST;
   second.value = SECOND;
   third.value = THIRD;
   fourth.value = FOURTH;
   fifth.value = FIFTH;
   sixth.value = SIXTH;
   
   printf("TEST 0: program compiles...\n");
   printf("TEST 0 passed!\n");
   
   printf("\nTEST CASE 1: cloning a list of length 1\n\n");
   
   
   first.value = FIRST;
   inputList.first = &first;
   first.rest = NULL;
   
   outputList = clone(inputList);
   
   printf("TEST 1: testing output list has the same values as input list...\n");
   printf("    (expecting [%d])\n", FIRST);
   
   assert(outputList.first->value == FIRST);
   assert(outputList.first->rest == NULL);
   
   printf("TEST 1 passed!\n");
 
   printf("TEST 2: testing that the original list is still intact...\n");
   printf("    (expecting original memory addresses in input list)\n");
   
   assert(inputList.first == firstAddress);
   
   printf("TEST 2 passed!\n");
   
   
   printf("TEST 3: testing that changing the input list doesn't change the output list...\n" );
   printf("    (expecting no change)\n");
   
   inputList.first->value = DUMMY;
   assert(outputList.first->value == FIRST);
   
   printf("TEST 3 passed!\n");
   
   
   printf("TEST 4: testing that the new list is using new memory...\n");
   printf("    (expecting new memory address)\n");
   
   assert(outputList.first != firstAddress);
   
   outputNode = outputList.first;
   while (outputNode != NULL) {
      freeingNode = outputNode;
      outputNode = outputNode->rest;
      free(freeingNode);
   }
   
   printf("TEST 4 passed!\n");
   
   
   printf("\nTEST CASE 2: cloning a list of length 2\n\n");
   
   first.value = FIRST;
   second.value = SECOND;
   
   inputList.first = &first;
   first.rest = &second;
   second.rest = NULL;
   
   outputList = clone(inputList);
   
   
   printf("TEST 5: testing output list has the same values as input list...\n");
   printf("    (expecting [%d, %d])\n", FIRST, SECOND);
   
   assert(outputList.first->value == FIRST);
   assert(outputList.first->rest != NULL);
   
   assert(outputList.first->rest->value == SECOND);
   assert(outputList.first->rest->rest == NULL);
   
   printf("TEST 5 passed!\n");
   
   printf("TEST 6: testing memory changed correctly...\n");
   
   assert(inputList.first       == firstAddress);
   assert(inputList.first->rest == secondAddress);
   
   assert(&outputList.first       != firstAddress);
   assert(&outputList.first->rest != secondAddress);
   
   outputNode = outputList.first;
   while (outputNode != NULL) {
      freeingNode = outputNode;
      outputNode = outputNode->rest;
      free(freeingNode);
   }
   
   printf("TEST 6 passed!\n");
   
   
   printf("\nTEST CASE 3: cloning a list of length 3\n\n");
   
   
   first.value = FIRST;
   second.value = SECOND;
   third.value = THIRD;
   
   inputList.first = &first;
   first.rest = &second;
   second.rest = &third;
   third.rest = NULL;
   
   outputList = clone(inputList);
   
   printf("TEST 7: testing output list has the same values as input list...\n");
   printf("    (expecting [%d, %d, %d])\n", FIRST, SECOND, THIRD);
   
   assert(outputList.first->value == FIRST);
   assert(outputList.first->rest != NULL);
   
   assert(outputList.first->rest->value == SECOND);
   assert(outputList.first->rest->rest != NULL);
   
   assert(outputList.first->rest->rest->value == THIRD);
   assert(outputList.first->rest->rest->rest == NULL);
   
   printf("TEST 7 passed!\n");
   
   printf("TEST 8: testing memory changed correctly...\n");
   
   assert(inputList.first == firstAddress);
   assert(inputList.first->rest == secondAddress);
   assert(inputList.first->rest->rest == thirdAddress);
   
   assert(outputList.first != firstAddress);
   assert(outputList.first->rest != secondAddress);
   assert(outputList.first->rest->rest != thirdAddress);
   
   outputNode = outputList.first;
   while (outputNode != NULL) {
      freeingNode = outputNode;
      outputNode = outputNode->rest;
      free(freeingNode);
   }
   
   printf("TEST 8 passed!\n");
   
   printf("\nTEST CASE 3: cloning a list of length 6\n\n");
   
   first.value = FIRST;
   second.value = SECOND;
   third.value = THIRD;
   fourth.value = FOURTH;
   fifth.value = FIFTH;
   sixth.value = SIXTH;
   
   inputList.first = &first;
   first.rest = &second;
   second.rest = &third;
   third.rest = &fourth;
   fourth.rest = &fifth;
   fifth.rest = &sixth;
   sixth.rest = NULL;
   
   
   outputList = clone(inputList);
   
   printf("TEST 9: testing clone on list\n\n");
   printf("    (expecting [%d, %d, %d, %d, %d, %d])\n", FIRST, SECOND, THIRD, FOURTH, FIFTH, SIXTH);
   
   inputList.first->value = DUMMY;
   inputList.first->rest->value = DUMMY;
   inputList.first->rest->rest->value = DUMMY;
   inputList.first->rest->rest->rest->value = DUMMY;
   inputList.first->rest->rest->rest->rest->value = DUMMY;
   inputList.first->rest->rest->rest->rest->rest->value = DUMMY;
   
   assert(outputList.first->value == FIRST);
   assert(outputList.first->rest != NULL);
   assert(outputList.first != inputList.first);
   
   assert(outputList.first->rest->value == SECOND);
   assert(outputList.first->rest->rest != NULL);
   assert(outputList.first->rest != inputList.first->rest);
   
   assert(outputList.first->rest->rest->value == THIRD);
   assert(outputList.first->rest->rest->rest != NULL);
   assert(outputList.first->rest->rest != inputList.first->rest->rest);
   
   assert(outputList.first->rest->rest->rest->value == FOURTH);
   assert(outputList.first->rest->rest->rest->rest != NULL);
   assert(outputList.first->rest->rest->rest != inputList.first->rest->rest->rest);
   
   assert(outputList.first->rest->rest->rest->rest->value == FIFTH);
   assert(outputList.first->rest->rest->rest->rest->rest != NULL);
   assert(outputList.first->rest->rest->rest->rest != inputList.first->rest->rest->rest->rest);
   
   assert(outputList.first->rest->rest->rest->rest->rest->value == SIXTH);
   assert(outputList.first->rest->rest->rest->rest->rest->rest == NULL);
   assert(outputList.first->rest->rest->rest->rest->rest != inputList.first->rest->rest->rest->rest->rest);
   
   outputNode = outputList.first;
   while (outputNode != NULL) {
      freeingNode = outputNode;
      outputNode = outputNode->rest;
      free(freeingNode);
   }
   
   printf("TEST 9 passed!\n");
   
   
   printf("All PRAC EXAM tests passed! You are AWESOME!\n");
}
