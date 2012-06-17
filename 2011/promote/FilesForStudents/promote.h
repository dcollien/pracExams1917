/*
 *  promote.h
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
   char     value;
   nodePtr  rest;
} node;

// given a pointer to a list of nodes each containing a letter (word)
// and a non-negative integer (position)
// this function moves the node at position 'position' in the list
// to the front of the list.
// note that the function does not create new nodes 
// or change the value field of existing nodes.
// this function assumes that length > 0 ("length" is the length
// of the list) and that position is an integer in the range
// 0 .. ("length"-1)
void promote (list *word, int position);