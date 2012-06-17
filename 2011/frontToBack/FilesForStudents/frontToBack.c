/*
 *  frontToBack.c
 *  sup pracExam 2011
 *  SAMPLE SOLUTION
 *  Created by Richard Buckland on 20/06/11.
 *  Copyright 2011. All rights reserved.
 */

// Implement the frontToBack function below
// so that it moves the first node in a non-empty linked list 
// of nodes to be the last node in the list, leaving the 
// relative position of all the other nodes unchanged.

// You may assume the input list contains at least one node.
//
// Your function should do the moving by changing pointers 
// in the nodes and list structs, (don't use malloc or make 
// any new nodes)
//
// You need to pass the tests in testFrontToBack.c
//
// Compile and run the tests using 
// gcc -Wall -Werror -O -o tester frontToBack.c testFrontToBack.c
// ./tester
//
// When a test fails look in the testFrontToBack.c file to see
// what the test was testing.  There are 3 tests in that file.
// Once you have passed all the tests you have finished.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "frontToBack.h"

list frontToBack (list items) {
   // write your code here
   return items;
}
