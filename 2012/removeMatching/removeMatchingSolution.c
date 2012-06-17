/*
 *  removeMatching.c
 *  pracExam 2012
 *  SAMPLE SOLUTION
 *  Created by David Collien 14/06/2012
 *  Copyright 2012. All rights reserved.
 */

 // Implement the removeMatching function below
 // so that it modifies a linked list so
 // all nodes that have a value matching the input
 // valueToRemove are removed.
 // The modified list is returned.
 // 
 // This function will free the memory for each of
 // the matching nodes.
 //
 // You may assume the input list contains at least one node.
 //
 // You need to pass the tests in testRemoveMatching.c
 //
 // Compile and run the tests using 
 // gcc -Wall -Werror -O -o tester removeMatching.c testRemoveMatching.c
 // ./tester

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "removeMatching.h"

list removeMatching(list items, int valueToRemove) {
   node *current;
   node *previous;
   
   previous = NULL;
   current = items.first;
   while (current != NULL) {
      if (current->value == valueToRemove) {
         // matching
         if (previous == NULL) {
            // current is the head of the list
            
            // point the first to the second
            items.first = current->rest;
            
            // free the first
            free(current);
            
            // current is now the new head
            current = items.first;
         } else {
            // skip over current
            previous->rest = current->rest;
            
            // free current
            free(current);
            
            // current is now the one after
            current = previous->rest;
         }
      } else {
         // non-matching, keep going
         previous = current;
         current = current->rest;
      }
   }
   
   return items;
}
