/*
 *  insert.c
 *  pracExam 2011
 *
 *  Created by Richard Buckland on 26/07/09.
 *  Modified by David Collien on 20/06/11.
 *  Copyright 2011. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "insert.h"

list insert (node *item, list items) {
   list newList;
   node *before;
   node *first;
   
   first = items.first;
   
   // if we insert at front
   if ((first==NULL) || (item->value <= first->value)) {
      item->rest = first;
      newList.first = item;
   } else {
   
      // inserting after the front 
      // (so the head of the list is unchanged))
      newList = items;
      
      before = first;
      while ((before->rest != NULL) && 
             (item->value > before->rest->value)) {
         before = before->rest;
      }
      
      item->rest = before->rest;
      before->rest = item;
   }      
   return newList;
}
