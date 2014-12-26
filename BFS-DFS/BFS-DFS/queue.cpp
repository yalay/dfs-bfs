#include "stdafx.h"
#include "queue.h"

// ��ʼ�����У���ʼ��һ��ͷ�ڵ�
pqueue init_queue()
{
    pnode queue_node = (pnode)malloc(sizeof(node));
    if (queue_node == NULL)
    {
        return NULL;
    }
    
    queue_node->next = NULL;
    queue_node->ivex = VERTEX_INDEX_INVALID;
    pqueue queue = (pqueue)malloc(sizeof(QUEUE));
    if (queue == NULL)
    {
        return NULL;
    }
    
    queue->front = queue->rear = queue_node;
    return queue;
}

// �������Ƿ�Ϊ��
bool check_queue_empty(pqueue &queue)
{
    if(queue->front == queue->rear)
    {
        return true;
    }

    return false;
}

// �����β
void en_queue(pqueue &queue, int vex_index)
{
    pnode queue_node = (pnode)malloc(sizeof(node));
    if (queue_node == NULL)
    {
        return;
    }
    
    queue_node->ivex = vex_index;
    queue_node->next = NULL;
    queue->rear->next = queue_node;
    queue->rear = queue_node;

    return;
}

// ������ͷ
int de_queue(pqueue &queue)
{
    int vex_index = VERTEX_INDEX_INVALID;
    if(!check_queue_empty(queue))
    {
        pnode queue_node = queue->front;
        queue->front = queue->front->next;
        vex_index = queue_node->ivex;
        free(queue_node);
    }
    
    return vex_index;
}