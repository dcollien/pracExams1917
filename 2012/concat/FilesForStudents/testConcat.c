// Test Remove Matching implementation
// 1917 prac exam 2012s1
// David Collien
// dcollien@cse.unsw.edu.au
// 14 June 2012
//
// this program runs a simple test for cloning a list
//

// DO NOT ALTER OR SUBMIT THIS FILE
// we will use our own copy when marking

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "concat.h"

#define FIRST_A  196
#define SECOND_A 887
#define THIRD_A  1675
#define FOURTH_A 7436
#define FIFTH_A  13783
#define SIXTH_A  52514

#define FIRST_B  197
#define SECOND_B 888
#define THIRD_B  1676
#define FOURTH_B 7437
#define FIFTH_B  13784
#define SIXTH_B  52515

void testConcat(void);

int main(int argc, const char * argv[]) {
   testConcat();
   return EXIT_SUCCESS;
}

void testConcat(void) {
   
   node first_a;
   node second_a;
   node third_a;
   node fourth_a;
   node fifth_a;
   node sixth_a;
   
   node first_b;
   node second_b;
   node third_b;
   node fourth_b;
   node fifth_b;
   node sixth_b;
   
   printf("Starting concat() tests...\n");
   
   list firstList;
   list secondList;
   list joinedList;
   
   printf("TEST 1: join two equal sized lists together\n");
   firstList.first = &first_a;
   first_a.value = FIRST_A;
   first_a.rest  = &second_a;
   second_a.value = SECOND_A;
   second_a.rest = &third_a;
   third_a.value = THIRD_A;
   third_a.rest = NULL;
   
   secondList.first = &first_b;
   first_b.value = FIRST_B;
   first_b.rest  = &second_b;
   second_b.value = SECOND_B;
   second_b.rest = &third_b;
   third_b.value = THIRD_B;
   third_b.rest = NULL;
   
   joinedList = concat(firstList, secondList);
   
   // input lists haven't been modified
   /*
   assert(firstList.first == (void *)&first_a);
   assert(firstList.first->value == FIRST_A);
   
   assert(firstList.first->rest == (void *)&second_a);
   assert(firstList.first->rest->value == SECOND_A);
   
   assert(firstList.first->rest->rest == (void *)&third_a);
   assert(firstList.first->rest->rest->value == THIRD_A);
   
   assert(firstList.first->rest->rest->rest == NULL);
   
   
   assert(secondList.first == (void *)&first_b);
   assert(secondList.first->value == FIRST_B);
   
   assert(secondList.first->rest == (void *)&second_b);
   assert(secondList.first->rest->value == SECOND_B);
   
   assert(secondList.first->rest->rest == (void *)&third_b);
   assert(secondList.first->rest->rest->value == THIRD_B);
   
   assert(secondList.first->rest->rest->rest == NULL);
   */
   
   // joined list
   assert(joinedList.first == (void *)&first_a);
   assert(joinedList.first->value == FIRST_A);
   
   assert(joinedList.first->rest == (void *)&second_a);
   assert(joinedList.first->rest->value == SECOND_A);
   
   assert(joinedList.first->rest->rest == (void *)&third_a);
   assert(joinedList.first->rest->rest->value == THIRD_A);


   assert(joinedList.first->rest->rest->rest == (void *)&first_b);
   assert(joinedList.first->rest->rest->rest->value == FIRST_B);
   
   assert(joinedList.first->rest->rest->rest->rest == (void *)&second_b);
   assert(joinedList.first->rest->rest->rest->rest->value == SECOND_B);
   
   assert(joinedList.first->rest->rest->rest->rest->rest == (void *)&third_b);
   assert(joinedList.first->rest->rest->rest->rest->rest->value == THIRD_B);
   
   assert(joinedList.first->rest->rest->rest->rest->rest->rest == NULL);
     
   printf("TEST 1 passed!\n");
   
   
   
   printf("TEST 2: join empty list to non-empty list\n");
   firstList.first = NULL;
   
   secondList.first = &first_b;
   first_b.value = FIRST_B;
   first_b.rest  = &second_b;
   second_b.value = SECOND_B;
   second_b.rest = &third_b;
   third_b.value = THIRD_B;
   third_b.rest = NULL;
   
   joinedList = concat(firstList, secondList);
   
   // input lists haven't been modified
   /*
   assert(firstList.first == NULL);
   
   assert(secondList.first == (void *)&first_b);
   assert(secondList.first->value == FIRST_B);
   
   assert(secondList.first->rest == (void *)&second_b);
   assert(secondList.first->rest->value == SECOND_B);
   
   assert(secondList.first->rest->rest == (void *)&third_b);
   assert(secondList.first->rest->rest->value == THIRD_B);
   
   assert(secondList.first->rest->rest->rest == NULL);
   */
   
   // joined list
   assert(joinedList.first == (void *)&first_b);
   assert(joinedList.first->value == FIRST_B);
   
   assert(joinedList.first->rest == (void *)&second_b);
   assert(joinedList.first->rest->value == SECOND_B);
   
   assert(joinedList.first->rest->rest == (void *)&third_b);
   assert(joinedList.first->rest->rest->value == THIRD_B);
   
   assert(joinedList.first->rest->rest->rest == NULL);
     
   printf("TEST 2 passed!\n");
   
   
   printf("TEST 3: join non-empty list to empty list\n");
   firstList.first = &first_a;
   first_a.value = FIRST_A;
   first_a.rest  = &second_a;
   second_a.value = SECOND_A;
   second_a.rest = &third_a;
   third_a.value = THIRD_A;
   third_a.rest = NULL;
   
   secondList.first = NULL;
   
   joinedList = concat(firstList, secondList);
   
   // input lists haven't been modified
   /*
   assert(firstList.first == (void *)&first_a);
   assert(firstList.first->value == FIRST_A);
   
   assert(firstList.first->rest == (void *)&second_a);
   assert(firstList.first->rest->value == SECOND_A);
   
   assert(firstList.first->rest->rest == (void *)&third_a);
   assert(firstList.first->rest->rest->value == THIRD_A);
   
   assert(firstList.first->rest->rest->rest == NULL);
   
   assert(secondList.first == NULL);
   */
   
   // joined list
   assert(joinedList.first == (void *)&first_a);
   assert(joinedList.first->value == FIRST_A);
   
   assert(joinedList.first->rest == (void *)&second_a);
   assert(joinedList.first->rest->value == SECOND_A);
   
   assert(joinedList.first->rest->rest == (void *)&third_a);
   assert(joinedList.first->rest->rest->value == THIRD_A);
   
   assert(joinedList.first->rest->rest->rest == NULL);
     
   printf("TEST 3 passed!\n");
   
   printf("TEST 4: join two empty lists\n");
   
   firstList.first = NULL;
   secondList.first = NULL;
   
   joinedList = concat(firstList, secondList);
   
   assert(firstList.first == NULL);
   assert(secondList.first == NULL);
   assert(joinedList.first == NULL);
   
   printf("TEST 4 passed!\n");
   
   printf("TEST 5: join single element list to another list\n");
   firstList.first = &first_a;
   first_a.value = FIRST_A;
   first_a.rest = NULL;
   
   secondList.first = &first_b;
   first_b.value = FIRST_B;
   first_b.rest  = &second_b;
   second_b.value = SECOND_B;
   second_b.rest = &third_b;
   third_b.value = THIRD_B;
   third_b.rest = &fourth_b;
   fourth_b.value = FOURTH_B;
   fourth_b.rest = &fifth_b;
   fifth_b.value = FIFTH_B;
   fifth_b.rest = &sixth_b;
   sixth_b.value = SIXTH_B;
   sixth_b.rest = NULL;
   
   joinedList = concat(firstList, secondList);
   
   // input lists haven't been modified
   /*
   assert(firstList.first == (void *)&first_a);
   assert(firstList.first->value == FIRST_A);
   assert(firstList.first->rest == NULL);
   
   assert(secondList.first == (void *)&first_b);
   assert(secondList.first->value == FIRST_B);
   
   assert(secondList.first->rest == (void *)&second_b);
   assert(secondList.first->rest->value == SECOND_B);
   
   assert(secondList.first->rest->rest == (void *)&third_b);
   assert(secondList.first->rest->rest->value == THIRD_B);
   
   assert(secondList.first->rest->rest->rest == (void *)&fourth_b);
   assert(secondList.first->rest->rest->rest->value == FOURTH_B);
   
   assert(secondList.first->rest->rest->rest->rest == (void *)&fifth_b);
   assert(secondList.first->rest->rest->rest->rest->value == FIFTH_B);
   
   assert(secondList.first->rest->rest->rest->rest->rest == (void *)&sixth_B);
   assert(secondList.first->rest->rest->rest->rest->rest->value == SIXTH_B);
   
   assert(secondList.first->rest->rest->rest->rest->rest->rest == NULL);
   
   */
   
   // joined list
   assert(joinedList.first == (void *)&first_a);
   assert(joinedList.first->value == FIRST_A);
   
   assert(joinedList.first->rest == (void *)&first_b);
   assert(joinedList.first->rest->value == FIRST_B);
   
   assert(joinedList.first->rest->rest == (void *)&second_b);
   assert(joinedList.first->rest->rest->value == SECOND_B);
   
   assert(joinedList.first->rest->rest->rest == (void *)&third_b);
   assert(joinedList.first->rest->rest->rest->value == THIRD_B);
   
   assert(joinedList.first->rest->rest->rest->rest == (void *)&fourth_b);
   assert(joinedList.first->rest->rest->rest->rest->value == FOURTH_B);
   
   assert(joinedList.first->rest->rest->rest->rest->rest == (void *)&fifth_b);
   assert(joinedList.first->rest->rest->rest->rest->rest->value == FIFTH_B);
   
   assert(joinedList.first->rest->rest->rest->rest->rest->rest == (void *)&sixth_B);
   assert(joinedList.first->rest->rest->rest->rest->rest->rest->value == SIXTH_B);
   
   assert(joinedList.first->rest->rest->rest->rest->rest->rest->rest == NULL);
   
   printf("TEST 5 passed!\n");
   
   printf("TEST 6: join list to single element list\n");
      
   firstList.first = &first_a;
   first_a.value = FIRST_A;
   first_a.rest  = &second_a;
   second_a.value = SECOND_A;
   second_a.rest = &third_a;
   third_a.value = THIRD_A;
   third_a.rest = &fourth_a;
   fourth_a.value = FOURTH_A;
   fourth_a.rest = &fifth_a;
   fifth_a.value = FIFTH_A;
   fifth_a.rest = &sixth_a;
   sixth_a.value = SIXTH_A;
   sixth_a.rest = NULL;
   
   secondList.first = &first_b;
   first_b.value = FIRST_B;
   first_b.rest = NULL;
   
   joinedList = concat(firstList, secondList);
   
   // input lists haven't been modified
   /*
   assert(firstList.first == (void *)&first_a);
   assert(firstList.first->value == FIRST_A);
   
   assert(firstList.first->rest == (void *)&second_a);
   assert(firstList.first->rest->value == SECOND_A);
   
   assert(firstList.first->rest->rest == (void *)&third_a);
   assert(firstList.first->rest->rest->value == THIRD_A);
   
   assert(firstList.first->rest->rest->rest == (void *)&fourth_a);
   assert(firstList.first->rest->rest->rest->value == FOURTH_A);
   
   assert(firstList.first->rest->rest->rest->rest == (void *)&fifth_a);
   assert(firstList.first->rest->rest->rest->rest->value == FIFTH_A);
   
   assert(firstList.first->rest->rest->rest->rest->rest == (void *)&sixth_a);
   assert(firstList.first->rest->rest->rest->rest->rest->value == SIXTH_A);
   
   assert(firstList.first->rest->rest->rest->rest->rest->rest == NULL);
   
   assert(secondList.first == (void *)&first_b);
   assert(secondList.first->value == FIRST_B);
   assert(secondList.first->rest == NULL);
   */
   
   // joined list
   assert(joinedList.first == (void *)&first_a);
   assert(joinedList.first->value == FIRST_A);
   
   assert(joinedList.first->rest == (void *)&second_a);
   assert(joinedList.first->rest->value == SECOND_A);
   
   assert(joinedList.first->rest->rest == (void *)&third_a);
   assert(joinedList.first->rest->rest->value == THIRD_A);
   
   assert(joinedList.first->rest->rest->rest == (void *)&fourth_a);
   assert(joinedList.first->rest->rest->rest->value == FOUTH_A);
   
   assert(joinedList.first->rest->rest->rest->rest == (void *)&fifth_a);
   assert(joinedList.first->rest->rest->rest->rest->value == FIFTH_A);
   
   assert(joinedList.first->rest->rest->rest->rest->rest == (void *)&sixth_a);
   assert(joinedList.first->rest->rest->rest->rest->rest->value == SIXTH_A);
   
   assert(joinedList.first->rest->rest->rest->rest->rest->rest == (void *)&first_b);
   assert(joinedList.first->rest->rest->rest->rest->rest->rest->value == FIRST_B);
   
   assert(joinedList.first->rest->rest->rest->rest->rest->rest->rest == NULL);
   
   printf("TEST 6 passed!\n");
   
   printf("TEST 7: join two longer lists\n");
   // TODO
   printf("TEST 7 passed!\n");
   
   printf("TEST 8: join two single-element lists\n");
   // TODO
   printf("TEST 8 passed!\n");
   
   printf("All PRAC EXAM tests passed! You are AWESOME!\n");
}
