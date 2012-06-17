/*
 *  backToFront.c
 *  comp1917 pracExam #2 2011s1 UNSW
 *
 * Author: WRITE YOUR NAME HERE
 * Date: 21 June 2011
 * License: Public Domain
 */

// Implement the backToFront function below
// so that it moves the last node in a non-empty linked list 
// of nodes to be the first node in the list, leaving the 
// relative position of all the other nodes unchanged.

// You may assume the input list contains at least one node.
//
// Your function should do the moving by changing pointers 
// in the nodes and list structs, (don't use malloc or make 
// any new nodes)
// 
// Your function should return the new list.
//
// You need to pass the tests in testBackToFront.c
//
// Compile and run the tests using 
// gcc -Wall -Werror -O -o tester backtToFront.c testBackToFront.c
// ./tester
//
// When a test fails look in the testBackToFront.c file to see
// what the test was testing.  There are 3 tests in that file.
//
// Once you have passed all the tests you have finished.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "backToFront.h"

list backToFront (list items) {
   nodePtr currentPos;
   nodePtr secondLastPos;
   nodePtr previousPos;
   nodePtr initialPos;
   initialPos = items.first;
   secondLastPos = items.first;
   currentPos = items.first;
   while (currentPos -> rest != NULL) {
      currentPos = currentPos -> rest;
   }
   printf("%d\n\n", currentPos -> value);
   if (initialPos != currentPos) {
      while (secondLastPos -> rest -> rest != NULL) {
         secondLastPos = secondLastPos -> rest;
      }
      secondLastPos -> rest = NULL;
      previousPos = items.first;
      currentPos -> rest = previousPos;
      items.first = currentPos;
   }
   return items;
}

/*
list backToFront (list items) {
   // write your code here
   return items;
}
*/