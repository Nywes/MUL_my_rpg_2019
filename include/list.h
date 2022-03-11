/*
** EPITECH PROJECT, 2020
** my
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct list_s
{
    void *data;
    struct list_s *next;
    struct list_s *prev;
} list_t;

list_t *chain_list(list_t **head, void *data);
list_t *append_list(list_t **head, void *data);
int free_list(list_t *head);
int add_node_at_index(list_t **head, void *data, int index);
int delete_node_at_index(list_t **head, int index);

#endif /* !LIST_H_ */
