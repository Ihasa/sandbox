#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include "foo.h"

void testSum(){
    CU_ASSERT_EQUAL(sum(-1, 3), 2);
}

#ifdef static
extern float sumF(float[],int);
void testSumF(){
    float data[] = {3.0f,2.0f,1.0f,10.0f};
    CU_ASSERT_DOUBLE_EQUAL(sumF(data,4),16.0f,0.0001f);
}
#endif

void testAverage(){
    float data[] = {3.0f,2.0f,1.0f,10.0f};
    CU_ASSERT_DOUBLE_EQUAL(average(data,4),4.0f,0.0001f);
    printf("%f\n",average(data,4));
}

int main(){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("testtest",NULL,NULL);
    CU_add_test(suite,"test1",testSum);
    CU_add_test(suite,"testAverage", testAverage);
#ifdef static
    CU_add_test(suite,"test2", testSumF);
#endif
    CU_console_run_tests();
    CU_cleanup_registry();
}
