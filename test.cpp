#include "histogram.h"
#include "svg.h"
#include <cassert>

void test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_same() {
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_one() {
    double min = 0;
    double max = 0;
    find_minmax({2}, min, max);
    assert(min == 2);
    assert(max == 2);
}

void test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void test_width() {
    assert(custome_width(50, 10, 10) == "Width < 70. Enter the width again:");
    assert(custome_width(850, 10, 10) == "Width > 800. Enter the width again:");
    assert(custome_width(500, 10, 10) == "");
    assert(custome_width(75, 24, 10) == "Width < BLOCK_WIDTH*number_count/3. Enter the width again:");
}

int main() {
    test_positive();
    test_negative();
    test_same();
    test_one();
    test_empty();
    test_width();
    return 0;
}
