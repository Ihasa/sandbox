#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include "foo.h"

void testSum(){
    CU_ASSERT_EQUAL(sum(-1, 3), 2);
}

int main(){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("testtest",NULL,NULL);
    CU_add_test(suite,"test1",testSum);
    CU_console_run_tests();
    CU_cleanup_registry();
}
