#include "minunit.h"
#include "except.h"
#include "assert.h"
#include <stdbool.h>


Except_T USER_EXCEPTION = {"user exception!"};

void _test_exception(int a){
    int result = 0;
    TRY{
        if (a >0){
            RAISE(USER_EXCEPTION);
        } else {
            assert(0);
        }
    }  
    Except(USER_EXCEPTION){
        result = 1;
    }
    ELSE{
        result = 2;
    }
    END_TRY
    return result;
}

MU_TEST(test_check_exception_user_exception) {
    mu_check(_test_exception(1) == 1);
}
MU_TEST(test_check_exception_excption_else) {
    mu_check(_test_exception(0) == 2);
}

void _test_finally(int a){
    int result = 0;
    TRY{
        if (a > 0){
            RAISE(USER_EXCEPTION);
        } else if (a == 0){
            assert(0);
        } else {
            result = 4
        }
    }
    Except(USER_EXCEPTION){
        result = 1;
    }
    ELSE{
        result = 2;
    }
    FINALLY{
        result = 3
    }
    END_TRY
    return result;
}

MU_TEST(test_check_finally_exception) {
    mu_check(_test_exception(1) == 3);
}
MU_TEST(test_check_finally_else) {
    mu_check(_test_exception(0) == 3);
}
MU_TEST(test_check_finally_no_exception) {
    mu_check(_test_exception(-1) == 3);
}

void _test_assert(int a){
    TRY{
        assert(a == 1);
    }
    Except(Assert_Failed){
        RETURN FALSE
    }
    END_TRY
    return TRUE
}

MU_TEST(test_asert) {
    mu_check(_test_assert(1));
}
MU_TEST(test_asert_false) {
    mu_check(_test_assert(2));
}


MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_check_exception_user_exception);
    MU_RUN_TEST(test_check_exception_excption_else);
    MU_RUN_TEST(test_asert);
    MU_RUN_TEST(test_asert_false);
    MU_RUN_TEST(test_check_finally_exception);
    MU_RUN_TEST(test_check_finally_else);
    MU_RUN_TEST(test_check_finally_no_exception);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}