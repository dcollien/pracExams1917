/*
 *  clone.c
 *  pracExam 2012
 *  SAMPLE SOLUTION
 *  Created by David Collien 14/06/2012
 *  Copyright 2012. All rights reserved.
 */

// Implement the clone function below
// so that it returns a copy of a linked list
// where all nodes are in the same order and
// have the same value.

// You may assume the input list contains at least one node.
//
//
// You need to pass the tests in testClone.c
//
// Compile and run the tests using 
// gcc -Wall -Werror -O -o tester clone.c testClone.c
// ./tester


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "clone.h"

list clone(list oldList) {
   list newList;
   node *currentOld;
   node *currentNew;
   node *newNode;
   
   currentOld = oldList.first;
   
   // copy over the first node
   newNode = malloc(sizeof(node));
   newNode->value = (oldList.first)->value;
   newNode->rest = NULL;
   newList.first = newNode;
   
   // start at the second old node, first new node
   currentOld = (oldList.first)->rest;
   currentNew = newNode;
   while (currentOld != NULL) {
      
      // copy over the current node
      newNode = malloc(sizeof(node));
      newNode->value = currentOld->value;
      newNode->rest  = NULL;
      
      // link the previous to the new node
      currentNew->rest = newNode;
      
      currentNew = currentNew->rest;
      currentOld = currentOld->rest;
   }
	
   return newList;
}
