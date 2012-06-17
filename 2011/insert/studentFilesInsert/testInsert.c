// Test List implementation
// 1917 prac exam 2011s1
// David Collien
// dcollien@cse.unsw.edu.au
// 20 June 2011

// revised (simplified) richard buckland 29 june 2011
//
// this program runs simple tests inserting into an ordered list

// DO NOT ALTER OR SUBMIT THIS FILE
// we will use our own copy when marking

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "insert.h"

#define BIGGEST  100
#define BIGGER    75
#define BIG       61
#define SMALL     42
#define SMALLER    7
#define SMALLEST  -2

#define SIZE 6

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
   node smallest;
   node smaller;
   node small;

   // initialise their values (all tests will use the same values)
   biggest.value=BIGGEST;
   bigger.value=BIGGER;
   big.value=BIG;
   smallest.value=SMALLEST;
   smaller.value=SMALLER;
   small.value=SMALL;
   
   printf ("test 1: insert -2 into empty list ... \n");
   // empty list
   inputList.first = NULL;
   // single node to insert
   smallest.rest = NULL;
   
   outputList = insert (&smallest, inputList);
   assert (outputList.first == &smallest);
   assert (outputList.first->value == SMALLEST);
   assert (outputList.first->rest == NULL);
   printf ("passed!\n");
   
   
   // Tests 2..7 test inserting into a list of size 5
   
   // the desired output for each test is the same
   int correctValues[SIZE] = {
      SMALLEST,
      SMALLER,
      SMALL,
      BIG,
      BIGGER,
      BIGGEST
   };
   
   node *correctRestPtrs[SIZE] = {
      &smaller,
      &small,
      &big,
      &bigger,
      &biggest,
      NULL
   };
   
   printf ("test 2: insert smallest (-2) into front \n");
   printf ("        of a non-empty list 7,42,61,75,100 ...\n");
   
   // set up the list, missing smallest (-2)
   inputList.first = &smaller;
   smaller.rest = &small;
   small.rest = &big;
   big.rest = &bigger;
   bigger.rest = &biggest;
   biggest.rest = NULL;
   
   outputList = insert (&smallest, inputList);
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   
   printf ("test 3: insert smaller (7) into -2,42,61,75,100 ...\n");

   // set up the list, missing smaller (7)
   inputList.first = &smallest;
   smallest.rest = &small;
   small.rest = &big;
   big.rest = &bigger;
   bigger.rest = &biggest;
   biggest.rest = NULL;
   
   outputList = insert (&smaller, inputList);
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   printf ("test 4: insert small (42) into -2,7,61,75,100 ...\n");
   
   // set up the list, missing small (42)
   inputList.first = &smallest;
   smallest.rest = &smaller;
   smaller.rest = &big;
   big.rest = &bigger;
   bigger.rest = &biggest;
   biggest.rest = NULL;
   
   outputList = insert (&small, inputList);
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   
   printf ("test 5: insert big (61) into -2,7,42,75,100 ...\n");
   
   // set up the list, missing big (61)
   inputList.first = &smallest;
   smallest.rest = &smaller;
   smaller.rest = &small;
   small.rest = &bigger;
   bigger.rest = &biggest;
   biggest.rest = NULL;
   
   outputList = insert (&big, inputList);
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   printf ("test 6: insert 75 into -2,7,42,61,100 ...\n");  
   
   // set up the list, missing bigger (75)
   inputList.first = &smallest;
   smallest.rest = &smaller;
   smaller.rest = &small;
   small.rest = &big;
   big.rest = &biggest;
   biggest.rest = NULL;
   
   outputList = insert (&bigger, inputList);
   
   assert (outputList.first == &smallest);
   ensureListMatch (outputList, correctValues, correctRestPtrs);
   printf ("passed!\n");
   
   printf ("test 7: insert 100 at rear of a \n");
   printf ("        non-empty list -2,7,42,61,75 ...\n");  
   
   // set up the list, missing biggest (100)
   inputList.first = &smallest;
   smallest.rest = &smaller;
   smaller.rest = &small;
   small.rest = &big;
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

