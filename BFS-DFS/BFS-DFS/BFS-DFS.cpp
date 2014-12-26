// BFS-DFS.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "graph.h"
#include "queue.h"
#include "stack.h"

int _tmain(int argc, _TCHAR* argv[])
{
    MGraph graph;

    // ��������Ȩ��ͼ
    graph = create_graph();

    // ������������ĵݹ鷽ʽ����
    printf("\nDFS: ");
    depth_first_search(graph);

    // �������������ջ��ʽ�ǵݹ鷽ʽ����
    printf("\nDFS: ");
    depth_first_search_by_stack(graph);

    // ������������Ķ��зǵݹ鷽ʽ����
    printf("\nBFS: ");
    breadth_first_search_by_queue(graph);
    printf("\n");

    // ������ͣ
    getchar();
    return 0;
}

