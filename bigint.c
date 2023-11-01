// big_integer.c
#include "bigint.h"
#include <stdio.h>
#include <stdlib.h>

// Implement createNode, printBigInteger, and basic helper functions as before

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* addBigIntegers(Node* num1, Node* num2) {
    Node* result = NULL;
    Node* tail = NULL;
    int carry = 0;

    while (num1 || num2 || carry) {
        int sum = carry;

        if (num1) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        sum %= 10;

        Node* newNode = createNode(sum);

        if (result == NULL) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
}
Node* subtractBigIntegers(Node* num1, Node* num2) {
    Node* result = NULL;
    Node* tail = NULL;
    int borrow = 0;

    while (num1 || num2) {
        int diff = borrow;

        if (num1) {
            diff += num1->data;
            num1 = num1->next;
        }

        if (num2) {
            diff -= num2->data;
            num2 = num2->next;
        }

        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        Node* newNode = createNode(diff);

        if (result == NULL) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove leading zeros
    while (result && result->data == 0) {
        Node* temp = result;
        result = result->next;
        free(temp);
    }

    return result;
}
Node* multiplyBigIntegers(Node* num1, Node* num2) {
    // Implement multiplication logic
    Node* result = createNode(0);
    int resultLength = 1;

    while (num1 != NULL) {
        Node* currentResult = result;
        int carry = 0;

        for (Node* num2Digit = num2; num2Digit != NULL || carry > 0; num2Digit = (num2Digit == NULL) ? NULL : num2Digit->next) {
            int product = currentResult->data + (num1->data * ((num2Digit == NULL) ? 0 : num2Digit->data)) + carry;
            carry = product / 10;
            currentResult->data = product % 10;

            if (num2Digit == NULL && carry > 0) {
                currentResult->next = createNode(carry);
                resultLength++;
            }

            if (currentResult->next == NULL && (num2Digit != NULL || carry > 0)) {
                currentResult->next = createNode(0);
                resultLength++;
            }

            currentResult = currentResult->next;
        }

        num1 = num1->next;
        result = result->next;
    }

    // Trim leading zeros
    Node* temp = result;
    while (resultLength > 1 && temp != NULL && temp->data == 0) {
        Node* toFree = temp;
        temp = temp->next;
        free(toFree);
        resultLength--;
    }

    return result;
}
void printBigInteger(Node* num) {
    while (num != NULL) {
        printf("%d", num->data);
        num = num->next;
    }
    printf("\n");
}

void freeBigInteger(Node* num) {
    while (num != NULL) {
        Node* temp = num;
        num = num->next;
        free(temp);
    }
}
