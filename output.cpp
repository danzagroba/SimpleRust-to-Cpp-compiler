#include <iostream>
float function_with_params(float a, float b, bool c) {
    if (c == 1) {
        return a;

    }
    return a + b;
}
bool function_no_params_with_return() {
    int x = 5;
    int y = 5;
    return x == y;
}
bool usingparameters(int xyz, bool asd) {
    if (asd == 1 && xyz > 10) {
        return 1;

    }
    std::cout << xyz;
    return 0;
}
int main() {
    int i = 10;
    float f = 2.500000;
    bool bb = 1;
    int uninitialized_var;
    uninitialized_var = 100;
    int arr_i[5];
    float arr_f[2];
    bool arr_b[3];
    arr_i[0] = 1;
    arr_i[4] = 2;
    arr_f[1] = 3.140000;
    arr_b[2] = 0;
    int add_res = 1 + 2;
    int sub_res = 10 - 5;
    int mul_res = 3 * 4;
    int div_res = 15 / 3;
    float mixed_ops = 1.500000 + 2.500000 * 3.000000 - 1.000000;
    bool eq_res = 1 == 1;
    bool ne_res = 1 != 2;
    bool lt_res = 5 < 10;
    bool le_res = 5 <= 5;
    bool gt_res = 10 > 5;
    bool ge_res = 10 >= 10;
    bool not_res = 0;
    bool and_res = 1 && 0;
    bool or_res = 1 || 0;
    if (i > 5) {
        std::cout << i << std::endl;

    }
    if (f == 2.500000) {
        std::cout << f << std::endl;

    }
    else {
        std::cout << -2.500000 << std::endl;

    }
    int counter = 0;
    while (counter < 3) {
        std::cout << counter << std::endl;

        counter = counter + 1;

    }
    for (int j = 0; j <= 4; j++) {
        std::cout << j << std::endl;
    }
    int user_input_i;
    std::cin >> user_input_i;
    std::cout << user_input_i << std::endl;
    int arr_access_res = arr_i[0] + arr_i[4];
    std::cout << arr_access_res << std::endl;
}
