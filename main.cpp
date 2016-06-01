/************************************************************
* programa : exercicio2
*
* autor : Luciano H Barroqueiro  dt 31/05/2016
*
* objetivo : fazer uma função que dada uma lista encadeada
*               verificar se o valor está dentro dela
*
*************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int val;
    struct Nodo * next;
} ;

void print_list(Nodo * head) {
    Nodo * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(Nodo ** head) {
    int retval = -1;
    Nodo * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

bool  busca_valor(int ch, Nodo * head) {
    /* TODO: fill in your code here */
    Nodo * current = head;

    while (current != NULL) {
        if(ch == current->val)
           return true;
        //printf("%d\n", current->val);
        current = current->next;
    }
    return false;
}

int main() {

    Nodo * test_list = (struct Nodo *)malloc(sizeof(Nodo));
    test_list->val = 1;
    test_list->next = (struct Nodo *)malloc(sizeof(Nodo));
    test_list->next->val = 2;
    test_list->next->next = (struct Nodo *)malloc(sizeof(Nodo));
    test_list->next->next->val = 3;
    test_list->next->next->next = (struct Nodo *)malloc(sizeof(Nodo));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

   // print_list(test_list);
    //remove_by_value(&test_list, 3);
    bool  ret = busca_valor(9,test_list);
    if (ret )
        printf("encontrado\n");
    else
        printf("não encontrado\n");
    print_list(test_list);
}


