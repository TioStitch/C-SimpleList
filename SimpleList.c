#include <stdio.h>
#include <stdlib.h>

struct SimpleList {
    int list[100];
    int length;
};

void set(struct SimpleList * simpleList, int index, int value) {

    if (index > 100) {
        printf("Parsed index don't exist!");
        return;
    }

    simpleList -> list[index] = value;
    return;
}

void add(struct SimpleList * simpleList, int value) {

    const int length = simpleList -> length;

    if (length >= 100) {
        perror("The limit of list has hitted!");
        return;
    }

    simpleList -> list[length] = value;
    simpleList -> length++;
    return;
}

void removeIndex(struct SimpleList * simpleList, int deleteIndex) {

    const int length = simpleList -> length;

    if (length > 100 || length < 0) {
        printf("Parsed index don't exist!");
        return;
    }

    for (int nextIndex = deleteIndex; nextIndex <= 100; nextIndex++) {
        int value = simpleList -> list[nextIndex];
        int posIndex = nextIndex-1;

        if (posIndex < 0) {
            set(simpleList, 0, value);
            continue;
        }

        set(simpleList, posIndex, value);
    }

    simpleList -> length--;
    return;
}

int get(struct SimpleList * simpleList, int index) {

    if (index > simpleList -> length) {
        printf("Parsed index don't exist!");
        return -1;
    }

    if (index > 100 || index < 0) {
        printf("Parsed index don't exist!");
        return -1;
    }

    return simpleList -> list[index];
}

int main() {

    struct SimpleList simpleList;

    add(&simpleList, 3);
    add(&simpleList, 6);
    add(&simpleList, 9);

    removeIndex(&simpleList, 0);
    printf("Indice: %d", get(&simpleList, 0));
    printf("Indice: %d", get(&simpleList, 1));
    printf("Indice: %d", get(&simpleList, 9));

    EXIT_SUCCESS;
}