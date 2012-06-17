/*
 *  insert.h
 *  pracExam 2011
 *
 *  Created by Richard Buckland on 26/07/09.
 *  Modified by David Collien on 20/06/11.
 *  Copyright 2011. All rights reserved.
 *
 */

// DO NOT ALTER OR SUBMIT THIS FILE
// we will use our own copy when marking

typedef struct _node *nodePtr;

typedef struct _list {
   nodePtr first;
} list;

typedef struct _node {
   int      value;
   nodePtr  rest;
} node;

// given a node (*item) and a sorted list of nodes (items)
// (sorted in increasing order of the value field) 
// this function inserts the node into the correct location
// so that the list remains sorted.
// note that the function does not create new nodes 
// or change the value field of existing nodes.
list insert (node *item, list items);
