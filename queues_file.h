//
// Created by napster on 9/12/19.
//

#ifndef MINER_PROCCESS_QUEUES_FILE_H
#define MINER_PROCCESS_QUEUES_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DATA; //Tipo de dato a almacenar
typedef struct {
    DATA *buf;
    size_t head, tail, alloc;
} queue_t, *queue;

queue q_new(){
    queue q = malloc(sizeof(queue_t));
    q->buf = malloc(sizeof(DATA) * (q->alloc = 4));
    q->head = q->tail = 0;
    return q;
}

int isEmpty(queue q){
    return q->tail == q->head;
}

void enqueue(queue q, DATA n){
    if (q->tail >= q->alloc) q->tail = 0;
    q->buf[q->tail++] = n;

    if (q->tail == q->alloc) {
        q->buf = realloc(q->buf, sizeof(DATA) * q->alloc * 2);
        if (q->head) {
            memcpy(q->buf + q->head + q->alloc, q->buf + q->head,
                   sizeof(DATA) * (q->alloc - q->head));
            q->head += q->alloc;
        } else
            q->tail = q->alloc;
        q->alloc *= 2;
    }
}

int dequeue(queue q, DATA *n){
    if (q->head == q->tail) return 0;
    *n = q->buf[q->head++];
    if (q->head >= q->alloc) {
        q->head = 0;
        if (q->alloc >= 512 && q->tail < q->alloc / 2)
            q->buf = realloc(q->buf, sizeof(DATA) * (q->alloc/=2));
    }
    return 1;
}

#endif //MINER_PROCCESS_QUEUES_FILE_H