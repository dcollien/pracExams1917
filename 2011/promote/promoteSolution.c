/*
 *  promote.c - saple solution
 *  comp1917 sup sup pracExam 2011s1 UNSW
 *
 * Author: richard buckland
 * Date: 20 July 2011
 * License: Public Domain
 */

// given a pointer to a list of nodes each containing a letter (word)
// and a non-negative integer (position)
// this function moves the node at position 'position' in the list
// to the front of the list.
// note that the function should not create new nodes 
// or change the value field of existing nodes.

// the function may assume that length > 0 ("length" is the length
// of the list) and that position is an integer in the range
// 0 .. ("length"-1)

// Your function should do the moving by changing pointers 
// in the nodes and list structs, (don't use malloc or make 
// any new nodes)
// 
// You need to pass the tests in testPromote.c
//
// Compile and run the tests using 
// gcc -Wall -Werror -O -o tester promote.c testPromote.c
// ./tester
//
// When a test fails look in the testPromote.c file to see
// what the test was testing.  There are a number of tests in that file.
//
// Once you have passed all the tests you have finished.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "promote.h"

void promote (list *word, int position) {
   
   assert (word != NULL);
   assert (word->first !=NULL);
   assert (position >= 0);
   
   if (position != 0) {
      node *previous = word->first;
      int count = 1;
      
      // find previous
      while (count < position) {
         assert (previous->rest != NULL);
         previous = previous->rest;
         count++;
      }
      
      // find node to be promoted
      node *promoted = previous->rest;
      
      // extract it from the list
      previous->rest = previous->rest->rest;
      
      // append the old list after the promoted node
      promoted->rest = word->first;
      
      // attach the promoted node to the front
      word->first = promoted;
   }
}
