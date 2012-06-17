/*
 *  insertAfter.c
 *  pracExam 2011
 *
 *  Created by David Collien on 21/06/11.
 *  Copyright 2011. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "insertAfter.h"

#define FALSE 0
#define TRUE 1

void insertAfter (node *item, list word, char letter) {
   node *before;
   
   int isInserted = FALSE;
   before = word.first;
   while ((before!=NULL) && !isInserted) {
      if (before->letter == letter) {
         item->rest = before->rest;
         before->rest = item;
         isInserted = TRUE;
      }
      before = before->rest;
   }
}
