/**
 * Create Phone Number
 * This file embeds the implementation and unit tests.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include "../test_helpers.h"

char *create_phone_number(char phnum[15], const unsigned char nums[10]) {
    phnum[0]  = '(';
    phnum[1]  = '0' + nums[0];
    phnum[2]  = '0' + nums[1];
    phnum[3]  = '0' + nums[2];
    phnum[4]  = ')';
    phnum[5]  = ' ';
    phnum[6]  = '0' + nums[3];
    phnum[7]  = '0' + nums[4];
    phnum[8]  = '0' + nums[5];
    phnum[9]  = '-';
    phnum[10] = '0' + nums[6];
    phnum[11] = '0' + nums[7];
    phnum[12] = '0' + nums[8];
    phnum[13] = '0' + nums[9];
    phnum[14] = '\0';
    return phnum;
}

/* ===== Tests ===== */

/* Test explanation:
   - Basic increasing digits
   - Random digits including zeros
   - Ensure null-termination and exact length 14 chars + '\0'
*/
static int tests_create_phone_number() {
    TEST_CASE("TC_1: Increasing digits 1..9,0");
    unsigned char a[10] = {1,2,3,4,5,6,7,8,9,0};
    char buf[16] = {0};
    ASSERT_EQ_STR("(123) 456-7890", create_phone_number(buf, a));
    TEST_CASE("TC_2: Check size");
    ASSERT_EQ_INT(14, (int)strlen(buf));

    TEST_CASE("TC_3: Mixed digits with repeats");
    unsigned char b[10] = {9,7,2,1,0,8,6,6,5,5};
    ASSERT_EQ_STR("(972) 108-6655", create_phone_number(buf, b));
    return 0;
}

int main(void) {
    // Run the test for this problem    
    RUN_TEST(tests_create_phone_number);
    return 0;
}
