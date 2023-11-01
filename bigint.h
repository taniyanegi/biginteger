// big_integer.h
#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data);
Node* addBigIntegers(Node* num1, Node* num2);
Node* subtractBigIntegers(Node* num1, Node* num2);
Node* multiplyBigIntegers(Node* num1, Node* num2);
//Node* divideBigIntegers(Node* num1, Node* num2);
void printBigInteger(Node* num);
void freeBigInteger(Node* num);

#endif