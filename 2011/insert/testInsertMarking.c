// Marking version of testInsert
// 1917 prac exam 2011s1
// David Collien
// Richard Buckland
// dcollien@cse.unsw.edu.au
// 20 June, 1 July 2011

// revised (simplified) richard buckland 29 june 2011
//
// this program runs simple tests inserting into an ordered list

// DO NOT ALTER OR SUBMIT THIS FILE
// we will use our own copy when marking

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "insert.h"

#define BIGGEST  1000
#define BIGGER    750
#define BIG       610
#define MIDDLE    555
#define SMALL     420
#define SMALLER    70
#define SMALLEST  -20

#define SIZE 7

static void testInsert (void);
static void ensureListMatch (list inputList, int correctValues[SIZE], node *correctAddresses[SIZE]);

int main (int argc, const char * argv[]) {
   testInsert();
   return EXIT_SUCCESS;
}

static void testInsert (void) {
   list inputList;
   list outputList;
   
   // create some nodes
   node biggest;
   node bigger;
   node big;
   node middle;
   node smallest;
   node smaller;
   node small;

   // initialise their values (all tests will use the same values)
   biggest.value=BIGGEST;
   bigger.value=BIGGER;
   big.value=BIG;
   middle.value=MIDDLE;
   smallest.value=SMALLEST;
   smaller.value=SMALLER;
   small.value=SMALL;
   
   printf ("test 1: insert -2 into empty list ... \n");
   // empty list
   inputList.first = NULL;
   // single node to insert
   middle.rest = NULL;
   
   outputList = insert (&middle, inputList);
   assert (outputList.first == &middle);
   assert (outputList.first->value == MIDDLE);
   assert (outputList.first->rest == NULL);
   printf ("passed!\n");
   
   
   // Tests 2..7 test inserting into a list of size 5
   
   // the desired output for each test is the same
   int correctValues[SIZE] = {
      SMALLEST,
      SMALLER,
      SMALL,
      MIDDLE,
      BIG,
      BIGGER,
      BIGGEST
   };
   
   node *correctRestPtrs[SIZE] = {
      &smaller,
      &small,
      &middle,
      &big,
      &bigger,
      &biggest,
      NULL
   };
   
   printf ("test 2: insert smallest (-20) into front \n");
   printf ("        of a non-empty list 70,420,610,750,1000 ...\n");
   
   // set up the list, missing smallest (-20)
   inputList.first = &smaller;
   smaller.rest = &small;
   small.rest = &middle;
   middle.rest = &big;
   big.rest = &bigger;
   bigger.rest = &biggest;
   biggest.rest = NULL;
   
   outputList = insert (&smallest, inputList);
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   
   printf ("test 3: insert smaller (70) into -20,420,555,610,750,1000 ...\n");

   // set up the list, missing smaller (70)
   inputList.first = &smallest;
   smallest.rest = &small;
   small.rest = &middle;
   middle.rest = &big;
   big.rest = &bigger;
   bigger.rest = &biggest;
   biggest.rest = NULL;
   
   outputList = insert (&smaller, inputList);
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   printf ("test 4: insert small (420) into -20,70,555,610,750,1000 ...\n");
   
   // set up the list, missing small (420)
   inputList.first = &smallest;
   smallest.rest = &smaller;
   smaller.rest = &middle;
   middle.rest = &big;
   big.rest = &bigger;
   bigger.rest = &biggest;
   biggest.rest = NULL;
   
   outputList = insert (&small, inputList);
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   
   printf ("test 5: insert big (610) into -20,70,420,555,750,1000 ...\n");
   
   // set up the list, missing big (610)
   inputList.first = &smallest;
   smallest.rest = &smaller;
   smaller.rest = &small;
   small.rest = &middle;
   middle.rest = &bigger;
   bigger.rest = &biggest;
   biggest.rest = NULL;
   
   outputList = insert (&big, inputList);
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   printf ("test 6: insert 750 into -20,70,420,555,610,1000 ...\n");  
   
   // set up the list, missing bigger (750)
   inputList.first = &smallest;
   smallest.rest = &smaller;
   smaller.rest = &small;
   small.rest = &middle;
   middle.rest = &big;
   big.rest = &biggest;
   biggest.rest = NULL;
   
   outputList = insert (&bigger, inputList);
   
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   printf ("test 7: insert 1000 at rear of a \n");
   printf ("        non-empty list -20,70,420,610,750 ...\n");  
   
   // set up the list, missing biggest (1000)
   inputList.first = &smallest;
   smallest.rest = &smaller;
   smaller.rest = &small;
   small.rest = &middle;
   middle.rest = &big;
   big.rest = &bigger;
   bigger.rest = NULL;
   
   outputList = insert (&biggest, inputList);
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   printf ("All PRAC EXAM tests passed! You are AWESOME!\n");
} 


// utility function used to test that a list contains the expected values
static void ensureListMatch (list inputList, int correctValues[SIZE], node *correctAddresses[SIZE]) {
   nodePtr first;
   first = inputList.first;
   
   printf ("   testing values match and nodes not altered\n" );
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

