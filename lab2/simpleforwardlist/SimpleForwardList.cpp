//
// Created by Zuzanna on 08.03.2018.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value){
    ForwardList* list = new ForwardList;
    list->value = value;
    list->next = nullptr;

    return list;
}


void DestroyList(ForwardList *list){
    ForwardList* toDelete = list;

    while(toDelete != nullptr){
        list = toDelete->next;
        delete toDelete;
        toDelete = list;
    }
}


ForwardList *PushFront(ForwardList *list, int value) {
    if (list == nullptr) {
        return nullptr;
    }

    ForwardList *first = CreateNode(value);
    first->next = list;
    list = first;

    return list;
}



void Append(ForwardList *list, ForwardList *tail){

    ForwardList *pointer = list;
    if (list == nullptr) {
        return;
    }
    while (pointer->next != nullptr){
        pointer = pointer->next;
    }

    pointer->next = tail;
}