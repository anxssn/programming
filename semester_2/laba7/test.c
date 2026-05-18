#include <stdio.h>
#include <setjmp.h>    // нужно для jmp_buf
#include <stdarg.h>    // нужно для работы cmocka
#include <stddef.h>    // нужно для size_t
#include <cmocka.h>



int sum(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return (float)a / b;
}

// проверка на четность
int check_even(int num) {
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// поиск максимального числа
int max_num(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

//  ТЕСТЫ 

static void test_sum(void **state) {
    (void)state; // чтобы не было предупреждений
    
    assert_int_equal(sum(2, 3), 5);
    assert_int_equal(sum(-1, 1), 0);
    assert_int_equal(sum(0, 0), 0);
    assert_int_equal(sum(-5, -3), -8);
}

static void test_minus(void **state) {
    (void)state;
    
    assert_int_equal(minus(5, 3), 2);
    assert_int_equal(minus(0, 5), -5);
    assert_int_equal(minus(-2, -3), 1);
    assert_int_equal(minus(10, 20), -10);
}

static void test_multiply(void **state) {
    (void)state;
    
    assert_int_equal(multiply(3, 4), 12);
    assert_int_equal(multiply(0, 5), 0);
    assert_int_equal(multiply(-2, 3), -6);
    assert_int_equal(multiply(-4, -5), 20);
}

static void test_divide(void **state) {
    (void)state;
    
    assert_float_equal(divide(10, 2), 5.0, 0.01);
    assert_float_equal(divide(7, 2), 3.5, 0.01);
    assert_float_equal(divide(5, 0), 0.0, 0.01);
    assert_float_equal(divide(-9, 3), -3.0, 0.01);
}

static void test_check_even(void **state) {
    (void)state;
    
    assert_int_equal(check_even(2), 1);
    assert_int_equal(check_even(0), 1);
    assert_int_equal(check_even(-4), 1);
    assert_int_equal(check_even(3), 0);
    assert_int_equal(check_even(-5), 0);
}

static void test_max_num(void **state) {
    (void)state;
    
    assert_int_equal(max_num(5, 3), 5);
    assert_int_equal(max_num(3, 5), 5);
    assert_int_equal(max_num(-1, -5), -1);
    assert_int_equal(max_num(7, 7), 7);
}

// ЗАПУСК ВСЕХ ТЕСТОВ 

int main() {
    printf("\n");
    printf("========================================\n");
    printf("       НАЧАЛО ТЕСТИРОВАНИЯ\n");
    printf("========================================\n\n");

    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_sum),
        cmocka_unit_test(test_minus),
        cmocka_unit_test(test_multiply),
        cmocka_unit_test(test_divide),
        cmocka_unit_test(test_check_even),
        cmocka_unit_test(test_max_num),
    };

    int result = cmocka_run_group_tests(tests, NULL, NULL);

    printf("\n");
    printf("========================================\n");
    if (result == 0) {
        printf("   ВСЕ ТЕСТЫ ПРОШЛИ УСПЕШНО! ^_^\n");
        printf("   Протестировано 6 функций\n");
    } else {
        printf("   ОШИБКА: %d тестов НЕ ПРОШЛИ :(\n", result);
    }
    printf("========================================\n");
    printf("\n");

    return result;
}