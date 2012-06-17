// Test promote implementation
// 1917 sup sup prac exam 2011s1
// richard buckland 20 july based on prac exam
// marking code by David Collien
// dcollien@cse.unsw.edu.au
// 20 June 2011
//
// this program runs a simple test for promoting the nth element
// of a list to the front

// DO NOT ALTER OR SUBMIT THIS FILE
// we will use our own copy when marking

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "promote.h"

#define FIRST  'H'
#define SECOND 'a'
#define THIRD  'm'
#define FOURTH 'l'
#define FIFTH  'e'
#define SIXTH  't'

#define SIZE 6

void testPromote (void);
void ensureListMatch (list inputList, int correctValues[SIZE], 
                      node *correctAddresses[SIZE]);

int main (int argc, const char * argv[]) {
   testPromote();
   return EXIT_SUCCESS;
}

void testPromote (void) {
   list list;
   
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
   
   
   printf ("TEST1: promote [196,887,1675,7436,13783,52514] 0 ...\n");
   printf ("expecting [196,887,1675,7436,13783,52514] ...\n");
   
   list.first = &first;
   first.rest = &second;
   second.rest = &third;
   third.rest = &fourth;
   fourth.rest = &fifth;
   fifth.rest = &sixth;
   sixth.rest = NULL;
   
   promote (&list, 0);
   assert (list.first == &first);
   ensureListMatch (list, correctValues, correctRestPtrs);
   printf ("TEST 1 passed!\n");
   

   
   printf ("TEST2: promote [887] 0 ...\n");
   printf ("expecting [887] ...\n");
   
   list.first = &second;
   second.rest = NULL;
   
   promote (&list, 0);
   assert (list.first == &second);
   assert (second.rest == NULL);
   assert (second.value == SECOND);
   printf ("TEST 2 passed!\n");
   
   
   printf ("TEST3: promote [887,1675,7436,13783,52514,196] 5 ...\n");
   printf ("expecting [196,887,1675,7436,13783,52514] ...\n");
   
   list.first = &second;
   second.rest = &third;
   third.rest = &fourth;
   fourth.rest = &fifth;
   fifth.rest = &sixth;
   sixth.rest = &first;
   first.rest = NULL;
   
   promote (&list, 5);
   assert (list.first == &first);
   ensureListMatch (list, correctValues, correctRestPtrs);
   printf ("TEST 3 passed!\n");
   
   
   
   printf ("TEST4: promote [887,1675,7436,13783,196,52514] 4 ...\n");
   printf ("expecting [196,887,1675,7436,13783,52514] ...\n");
   
   list.first  = &second;
   second.rest = &third;
   third.rest  = &fourth;
   fourth.rest = &fifth;
   fifth.rest  = &first;
   first.rest  = &sixth;
   sixth.rest  = NULL;
   
   promote (&list, 4);
   assert (list.first == &first);
   ensureListMatch (list, correctValues, correctRestPtrs);
   printf ("TEST 4 passed!\n");
   
   
   printf ("TEST5: promote [887,1675,7436,196,13783,52514] 3 ...\n");
   printf ("expecting [196,887,1675,7436,13783,52514] ...\n");
   
   list.first  = &second;
   second.rest = &third;
   third.rest  = &fourth;
   fourth.rest = &first;
   first.rest  = &fifth;
   fifth.rest  = &sixth;
   sixth.rest  = NULL;
   
   promote (&list, 3);
   assert (list.first == &first);
   ensureListMatch (list, correctValues, correctRestPtrs);
   printf ("TEST 5 passed!\n");
   
   
   
   printf ("TEST6: promote [887,1675,196,7436,13783,52514] 2 ...\n");
   printf ("expecting [196,887,1675,7436,13783,52514] ...\n");
   
   list.first  = &second;
   second.rest = &third;
   third.rest  = &first;
   first.rest = &fourth;
   fourth.rest  = &fifth;
   fifth.rest  = &sixth;
   sixth.rest  = NULL;
   
   promote (&list, 2);
   assert (list.first == &first);
   ensureListMatch (list, correctValues, correctRestPtrs);
   printf ("TEST 6 passed!\n");
   
   
   printf ("TEST7: promote [887,196,1675,7436,13783,52514] 1 ...\n");
   printf ("expecting [196,887,1675,7436,13783,52514] ...\n");
   
   list.first  = &second;
   second.rest = &first;
   first.rest  = &third;
   third.rest = &fourth;
   fourth.rest  = &fifth;
   fifth.rest  = &sixth;
   sixth.rest  = NULL;
   
   promote (&list, 1);
   assert (list.first == &first);
   ensureListMatch (list, correctValues, correctRestPtrs);
   printf ("TEST 7 passed!\n");
   
   
   printf ("All PRAC EXAM tests passed! You are AWESOME!\n");
}

void ensureListMatch (list inputList, int correctValues[SIZE], node *correctAddresses[SIZE]) {
   nodePtr first;
   first = inputList.first;
   
   //   testing the values match and the nodes were not altered
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