// BFS-DFS.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "graph.h"
#include "queue.h"
#include "stack.h"

int _tmain(int argc, _TCHAR* argv[])
{
    MGraph g;
    g=create_graph();
    printf("\nDFS: ");
    depth_first_search(g);       /* recursion */
    printf("\nDFS: ");
    depth_first_search_by_stack(g);      /* non recursion */
    printf("\nBFS: ");
    breadth_first_search_by_queue(g);
    printf("\n");

    getchar();
    return 0;
}

