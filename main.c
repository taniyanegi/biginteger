#include "bigint.h"

int main() {
    Node* num1 = createNode(7);
    num1->next = createNode(2);
    num1->next->next = createNode(4);

    Node* num2 = createNode(3);
    num2->next = createNode(6);

    // Perform addition
    Node* result_add = addBigIntegers(num1, num2);

    // Perform subtraction
    Node* result_subtract = subtractBigIntegers(num1, num2);

    // Perform multiplication
    Node* result_multiply = multiplyBigIntegers(num1, num2);

    // Perform division
    //Node* result_divide = divideBigIntegers(num1, num2);

    // Print results
    printf("Num1: ");
    printBigInteger(num1);

    printf("Num2: ");
    printBigInteger(num2);

    printf("Addition Result: ");
    printBigInteger(result_add);

    printf("Subtraction Result: ");
    printBigInteger(result_subtract);

    printf("Multiplication Result: ");
    printBigInteger(result_multiply);

    //printf("Division Result: ");
    //printBigInteger(result_divide);

    // Clean up memory
    freeBigInteger(num1);
    freeBigInteger(num2);
    freeBigInteger(result_add);
    freeBigInteger(result_subtract);
    freeBigInteger(result_multiply);
    //freeBigInteger(result_divide);

    return 0;
}
