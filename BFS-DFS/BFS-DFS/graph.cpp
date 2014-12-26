#include "stdafx.h"
#include "graph.h"

// �����û����봴������ͼ�����ö�ά�������洢��
MGraph create_graph()
{	
	MGraph graph;
	printf("Enter vexnum arcnum:");

    // scanf����getchar�����س��ַ�
	scanf("%d %d", &graph.vexnum, &graph.arcnum);
	getchar();

    // ���춥����Ȩֵ����ȡĬ��ֵ���Ȩ�أ��൱�ڲ���ͨ
	for(int left_index = 0; left_index < graph.vexnum; left_index++)
	{
        // �ȳ�ʼ�������Ƿ񱻷��ʹ����ٳ�ʼ�����бߵ�Ȩֵ
        graph.is_visited[left_index] = false;
        for(int right_index = 0; right_index < graph.vexnum; right_index++)
        {
            graph.arcs[left_index][right_index].adj = INFINITY;
            graph.arcs[right_index][left_index].adj = INFINITY; 
        }
	}

    // ����������ַ�ֵ
	printf("Enter %d vex...\n", graph.vexnum);
	for(int vex_index = 0; vex_index < graph.vexnum; vex_index++)
	{
		printf("vex %d: ", vex_index);
		scanf("%c", &graph.vexs[vex_index]);
		getchar();
	}

    // �����
    int arc_weight = 0;
    int vex_index1 = 0;
    int vex_index2 = 0;
    char ch1, ch2;
    printf("Enter %d arc...\n", graph.arcnum);
	for(int arc_index = 0; arc_index < graph.arcnum; arc_index++)
	{
        do 
        {
            printf("arc %d: ", arc_index);
		    scanf("%c %c %d", &ch1, &ch2, &arc_weight);
		    getchar();

            vex_index1 = locate_vertex(graph, ch1);
		    vex_index2 = locate_vertex(graph, ch2);          
        }while ((vex_index1 == VERTEX_INDEX_INVALID) || (vex_index2 == VERTEX_INDEX_INVALID));
			
		graph.arcs[vex_index1][vex_index2].adj = arc_weight;
        graph.arcs[vex_index2][vex_index1].adj = arc_weight;
	}
    
	return graph;
}

// ��λ��ָ���Ķ���ؼ���ch����Ӧ������
int locate_vertex(MGraph &graph, char ch)
{
	for(int index = 0; index < graph.vexnum; index++)
	{
        if(ch == graph.vexs[index])
        {
            return index;
        }
	}
			
	return VERTEX_INDEX_INVALID;
}

// ָ���Ľڵ��ҵ���һ��������ͨ�Ľڵ�
int find_first_vex(MGraph &graph, int vex_index)
{
    if (vex_index >= graph.vexnum)
    {
        return VERTEX_INDEX_INVALID;
    }

    for(int first_index = 0; first_index < graph.vexnum; first_index++)
    {
        if(graph.arcs[vex_index][first_index].adj != INFINITY)
        {
            return first_index;
        }
    }
    
	return VERTEX_INDEX_INVALID;
}

// ָ���Ľڵ��һ���ߵ���һ����ͨ�ı�
int find_next_vex(MGraph &graph, int vex_index, int design_index)
{
    if ((vex_index >= graph.vexnum) || 
        (design_index >= graph.vexnum))
    {

        return VERTEX_INDEX_INVALID;
    }

    int next_index = design_index + 1;
    for(; next_index < graph.vexnum; next_index++)
    {
        if (check_connect(graph, vex_index, next_index))
        {
            return next_index;
        }
    }

    return VERTEX_INDEX_INVALID;
}

// ������ڵ�֮����ͨ��
bool check_connect(MGraph &graph, int root_index, int design_index)
{
    if ((root_index >= graph.vexnum) || 
        (design_index >= graph.vexnum))
    {

        return false;
    }

    if (graph.arcs[root_index][design_index].adj != INFINITY)
    {
        return true;
    }

    return false;
}

// ������������ĵݹ��㷨����ָ���ڵ���еݹ����
void depth_first_search(MGraph &graph, int root_index)
{
	if(!graph.is_visited[root_index])
	{
		graph.is_visited[root_index] = true;
		printf("%3c", graph.vexs[root_index]);

        int vex_index =find_first_vex(graph, root_index);
		for(; vex_index != VERTEX_INDEX_INVALID; vex_index = find_next_vex(graph, root_index, vex_index))
		{
            if (!graph.is_visited[vex_index])
            {
                depth_first_search(graph, vex_index);
	        }
        }
	}
}

// �������������������ͼ���б���
void depth_first_search(MGraph &graph)
{
	for(int vex_index = 0; vex_index < graph.vexnum; vex_index++)
	{
        if(!graph.is_visited[vex_index])
        {

            depth_first_search(graph, vex_index);
        }
	}			
}

// ������������ǵݹ��㷨������ջ��ʽ
void depth_first_search_by_stack(MGraph &graph)
{
	pstack stack = init_stack(graph.vexnum);
    if (stack == NULL)
    {
        return;
    }

    init_visited_record(graph);

    int root_vex = 0;
    int next_vex = 0;
	for(int vex_index = 0; vex_index < graph.vexnum; vex_index++)
	{
        if(!graph.is_visited[vex_index])
		{
			graph.is_visited[vex_index] = true;;
			printf("%3c", graph.vexs[vex_index]);
			push_stack(stack, vex_index);
			root_vex = vex_index;
			while (!check_stack_empty(stack))
			{
                next_vex = find_first_vex(graph, root_vex);
				for(; next_vex != VERTEX_INDEX_INVALID; next_vex = find_next_vex(graph, root_vex, next_vex))
				{
					if(!graph.is_visited[next_vex])
					{
						graph.is_visited[next_vex] = true;
						printf("%3c", graph.vexs[next_vex]);
						push_stack(stack, next_vex); 
						root_vex = next_vex; // �µĸ��ڵ�,�Դ�Ϊ����������
					}
				}
                
				root_vex = pop_stack(stack);
			}
		}
	}
		
}

void breadth_first_search_by_queue(MGraph &graph)
{
	pqueue queue = init_queue();
    if (queue == NULL)
    {
        return;
    }

    // ��ʼ���ڵ���ʼ�¼
	init_visited_record(graph);
    
    int front_index = 0;
    int next_index = 0;
    for (int vex_index = 0; vex_index < graph.vexnum; vex_index++)
    {
        if (!graph.is_visited[vex_index])
		{
			graph.is_visited[vex_index] = true;
			printf("%3c", graph.vexs[vex_index]);
            
			en_queue(queue, vex_index);
			while (!check_queue_empty(queue))
			{
				front_index = de_queue(queue);
                next_index = find_first_vex(graph, front_index);
				for(; next_index != VERTEX_INDEX_INVALID; next_index = find_next_vex(graph, front_index, next_index))
				{

                    if (!graph.is_visited[next_index])
                    {
                        graph.is_visited[next_index] = true;
                        printf("%3c", graph.vexs[next_index]);
						en_queue(queue, next_index);
                    }
                }
			}
		}
    }
}

// ��ʼ�����ʼ�¼������������
void init_visited_record(MGraph &graph)
{

	for(int vex_index = 0; vex_index < graph.vexnum; vex_index++)
	{
        graph.is_visited[vex_index] = false;
	}
}