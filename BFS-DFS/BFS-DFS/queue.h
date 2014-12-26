#pragma once
#include "stack.h"
/********************************/
/****      ���еĽṹ����      ****/
/********************************/
struct _queue
{
    pnode front;
    pnode rear;
};
typedef struct _queue QUEUE, *pqueue;

extern pqueue init_queue();
extern bool check_queue_empty(pqueue &);
extern void en_queue(pqueue &, int);
extern int de_queue(pqueue &);
