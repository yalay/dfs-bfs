#pragma once

#include "stack.h"
#include "queue.h"

/********************************/
/****      ͼ�Ľṹ����      ****/
/********************************/

struct _ArcCell
{
    VRType adj; // �ߵ�Ȩֵ
    InfoType *info; // �ߵ�������Ϣ
};

typedef struct _ArcCell ArcCell, AdjMatrix[MAX_VEX][MAX_VEX];

struct _MGraph
{
    VertexType vexs[MAX_VEX]; // ���ַ���ǽڵ� 
    bool is_visited[MAX_VEX]; // ����Ƿ񱻷��ʹ�
    AdjMatrix arcs; // ��ά���鶨��ߣ��ߵ�ȨֵΪINFINITY��ʾ���������������ʾ��ͨ
    int vexnum; // �ڵ����
    int arcnum; // �ߵĸ���
};

typedef struct _MGraph MGraph;

extern MGraph create_graph();
extern int locate_vertex(MGraph &, char);
extern void depth_first_search(MGraph &);
extern void depth_first_search_by_stack(MGraph &);
extern void breadth_first_search_by_queue(MGraph &);
extern bool check_connect(MGraph &, int, int);
extern void init_visited_record(MGraph &);