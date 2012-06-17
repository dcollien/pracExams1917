// Test List implementation
// 1917 prac exam 2011s1
// David Collien
// tweaked richard buckland for marking
// dcollien@cse.unsw.edu.au
// 20 June 2011
//
// this program runs a simple test inserting on a list

// DO NOT ALTER OR SUBMIT THIS FILE
// we will use our own copy when marking

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "insertAfter.h"

void testInsertAfter (void);

int main (int argc, const char * argv[]) {
   testInsertAfter();
   return EXIT_SUCCESS;
}

void testInsertAfter (void) {
   list word;
   
   node q;
   node a1;
   node n;
   node t;
   node a2;
   node s;
   
   node c;
   node u;
   node e;
   node o;
   
   q.letter = 'Q';
   a1.letter = 'A';
   n.letter = 'N';
   t.letter = 'T';
   a2.letter = 'A';
   s.letter = 'S';
   
   o.letter = 'O';
   u.letter = 'U';
   c.letter = 'C';
   e.letter = 'E';
   
   
   
   
   printf ("Test 0: Inserting 'O' into \"n\" after 'N'\n");
   printf ("Expecting: \"no\"\n");

   word.first = &n;
   n.rest = NULL;

   
   insertAfter (&o, word, 'N');
   
   printf ("   checking first node\n");   
   assert (word.first == &n);
   assert (word.first->letter == 'N');
   
   printf ("   checking node inserted correctly\n");
   
   assert (word.first->rest == &o);
   assert (word.first->rest->letter == 'O');
   
   printf ("   checking NULL at end\n");
   
   assert (word.first->rest->rest == NULL);
   
   printf ("Test 0 passed!\n");
 
   
   
   
   printf ("Test 1: Inserting 'E' into \"caut\" after 'T'\n");
   printf ("Expecting: \"caute\"\n");

   word.first = &c;
   c.rest     = &a1;
   a1.rest    = &u;
   u.rest     = &t;
   t.rest     = NULL;
   
   e.rest = &c;
   
   insertAfter (&e, word, 'T');
   
   printf ("  checking nodes before insertion point\n");
   assert (word.first == &c );
   assert (word.first->letter == 'C');
   assert (word.first->rest == &a1);
   assert (word.first->rest->letter == 'A');
   assert (word.first->rest->rest == &u);
   assert (word.first->rest->rest->letter == 'U');
   assert (word.first->rest->rest->rest == &t);
   assert (word.first->rest->rest->rest->letter == 'T');
   
   printf ("  checking node inserted correctly\n");
   assert (word.first->rest->rest->rest->rest == &e);
   assert (word.first->rest->rest->rest->rest->letter == 'E');
   
   printf ("  checking NULL at end\n");
   assert (word.first->rest->rest->rest->rest->rest == NULL);
   
   printf ("Test 1 passed!\n");
   
   
   printf ("Test 2: Inserting 'U' into \"qantas\" after 'Q'\n");
   printf ("Expecting: \"quantas\"\n");
   
   q.rest  = &a1;
   a1.rest = &n;
   n.rest  = &t;
   t.rest  = &a2;
   a2.rest = &s;
   s.rest  = NULL;
   
   word.first = &q;
   
   insertAfter (&u, word, 'Q');
   
   printf ("  checking first node\n");
   assert (word.first == &q);
   assert (word.first->letter == 'Q');
   
   printf ("  checking node inserted correctly\n");
   assert (word.first->rest == &u );
   assert (word.first->rest->letter == 'U');
   
   printf ("  checking rest of linked list word\n");
   assert (word.first->rest->rest == &a1);
   assert (word.first->rest->rest->letter == 'A');
   assert (word.first->rest->rest->rest == &n);
   assert (word.first->rest->rest->rest->letter == 'N');
   assert (word.first->rest->rest->rest->rest == &t);
   assert (word.first->rest->rest->rest->rest->letter == 'T');
   assert (word.first->rest->rest->rest->rest->rest == &a2);
   assert (word.first->rest->rest->rest->rest->rest->letter == 'A');
   assert (word.first->rest->rest->rest->rest->rest->rest == &s);
   assert (word.first->rest->rest->rest->rest->rest->rest->letter == 'S');
   assert (word.first->rest->rest->rest->rest->rest->rest->rest == NULL);
   
   printf ("Test 2 passed!\n");
   
   printf ("All PRAC EXAM tests passed! You are AWESOME!\n");
} 


