#include <gtest/gtest.h>
#include "foo.h"

TEST(suite,testtest) {
    EXPECT_EQ(sum(-1, 3), 2);
}

#ifdef static
extern float sumF(float[],int);
TEST(suite, test1) {
    float data[] = {3.0f,2.0f,1.0f,10.0f};
    EXPECT_DOUBLE_EQ(sumF(data, 4), 16.0f);
}
#endif

TEST(suite, testAverage) {
    float data[] = {3.0f,2.0f,1.0f,10.0f};
    EXPECT_DOUBLE_EQ(average(data,4),4.0f);
    printf("%f, %f\n",average(data,4), pi);
}

/*int main(){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("testtest",NULL,NULL);
    CU_add_test(suite,"test1",testSum);
    CU_add_test(suite,"testAverage", testAverage);
#ifdef static
    CU_add_test(suite,"test2", testSumF);
#endif
    CU_console_run_tests();
    CU_cleanup_registry();
}*/
