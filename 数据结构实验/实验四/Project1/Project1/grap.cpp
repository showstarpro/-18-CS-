#include "stu.h"

int    Glength = 0;
bool visited[MAX_VERTEX_NUM];
using namespace std;


status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2])
{
	if (V[0].key == -1) return ERROR;//�ж϶�������Ƿ�Ϊ0
	int hash[MAX_VERTEX_NUM] = { 0 };//����ؼ��ֵ�λ��
	G.vexnum = 0;
	G.kind = UDG;//����ͼ

	while (V[G.vexnum].key != -1)//����
	{
		G.vexnum++;//�����������
		if (hash[V[G.vexnum - 1].key] != 0) return	ERROR;
		G.vertices[G.vexnum - 1].data = V[G.vexnum - 1];//�洢����
		G.vertices[G.vexnum - 1].firstarc = NULL;//���ĳ�ʼ��
		hash[V[G.vexnum - 1].key] = G.vexnum;//����λ�ü�1
	}

	if (G.vexnum > 20) return ERROR;

	G.arcnum = 0;//���ĸ���
	while (VR[G.arcnum][0] != -1)//��
	{
		int temp1 = hash[VR[G.arcnum][0]];//����1�ڶ��������е�λ�ü�1
		int temp2 = hash[VR[G.arcnum][1]];//����2�ڶ��������е�λ�ü�1
		if (temp1 == 0 | temp2 == 0) return ERROR;
		ArcNode* p1 = (ArcNode*)malloc(sizeof(ArcNode));//���ɻ�1
		ArcNode* p2 = (ArcNode*)malloc(sizeof(ArcNode));//���ɻ�2
		//��1��ֵ
		p1->adjvex = temp2 - 1;
		p1->nextarc = G.vertices[temp1 - 1].firstarc;
		G.vertices[temp1 - 1].firstarc = p1;
		//��2��ֵ
		p2->adjvex = temp1 - 1;
		p2->nextarc = G.vertices[temp2 - 1].firstarc;
		G.vertices[temp2 - 1].firstarc = p2;

		G.arcnum++;//���ĸ�����1
	}

	return OK;
}


status DestroyGraph(ALGraph& G)
/*��������ͼG*/
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	for (int i = 0; i < G.vexnum; i++)//��ÿ������������ٲ���
	{
		while (G.vertices[i].firstarc)//����Ϊ�����ͷ�
		{
			ArcNode* p = G.vertices[i].firstarc->nextarc;
			free(G.vertices[i].firstarc);//�ͷſռ�
			G.vertices[i].firstarc = p;
		}
	}

	G.vexnum = 0;
	G.arcnum = 0;
	return OK;

	/********** End **********/
}


int LocateVex(ALGraph G, KeyType u)
//����u��ͼG�в��Ҷ��㣬���ҳɹ�����λ�򣬷��򷵻�-1��
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data.key == u) return i;
	}

	return ERROR;

	/********** End **********/
}

status PutVex(ALGraph& G, KeyType u, VertexType value)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK��
//�������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	if (LocateVex(G, value.key) != ERROR) return ERROR;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data.key == u)
		{
			G.vertices[i].data = value;
			return OK;
		}
	}
	return ERROR;
	/********** End **********/
}

int FirstAdjVex(ALGraph G, KeyType u)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	int temp = 0;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data.key == u)
		{
			temp = G.vertices[i].firstarc->adjvex;
			return temp;
		}
	}

	return -1;
	/********** End **********/
}


int NextAdjVex(ALGraph G, KeyType v, KeyType w)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���v���ڽӶ��������w����һ�ڽӶ����λ�򣬲���ʧ�ܷ���-1��
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data.key == v)
		{
			ArcNode* p = G.vertices[i].firstarc;
			while (p->nextarc)
			{
				if (G.vertices[p->adjvex].data.key == w)
				{
					int temp = p->nextarc->adjvex;
					return temp;
				}
				else
				{
					p = p->nextarc;
				}
			}
			return -1;
		}
	}

	return -1;

	/********** End **********/
}

status InsertVex(ALGraph& G, VertexType v)
//��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	if (G.vexnum == MAX_VERTEX_NUM)  //��������
		return ERROR;

	for (int i = 0; i < G.vexnum; i++)//��ѯ�ؼ����Ƿ�Ψһ
	{
		if (G.vertices[i].data.key == v.key)
		{
			return ERROR;
		}
	}

	G.vertices[G.vexnum].data = v;//����ؼ���
	G.vexnum++;
	return OK;

	/********** End **********/
}


status DeleteVex(ALGraph& G, KeyType v)
//��ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK,���򷵻�ERROR
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	int place = -1;//��¼v��λ��
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data.key == v)
		{
			place = i;
			break;
		}
	}
	if (place == 0 && G.vexnum == 1) return ERROR;

	if (place == -1)
		return ERROR;//v������
	else//ɾ�����㼰���йصĻ�
	{
		for (int i = 0; i < G.vexnum; i++)//ɾ����
		{
			ArcNode* p = G.vertices[i].firstarc;
			if (p && p->adjvex == place)
			{
				G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
				p->nextarc = NULL;
				free(p);
				G.arcnum--;
			}
			if (G.vertices[i].firstarc)
			{
				if (G.vertices[i].firstarc->adjvex > place)
				{
					G.vertices[i].firstarc->adjvex--;
				}
				ArcNode* father = G.vertices[i].firstarc;
				p = G.vertices[i].firstarc->nextarc;
				while (p)
				{
					if (p->adjvex == place)
					{
						ArcNode* temp = p;
						p = p->nextarc;
						father->nextarc = temp->nextarc;
						temp->nextarc = NULL;
						free(temp);
						G.arcnum--;
					}
					else
					{
						if (p->adjvex > place)
							p->adjvex--;
						father = p;
						p = p->nextarc;
					}
				}
			}
		}

		ArcNode* tp = G.vertices[place].firstarc;
		while (tp)
		{
			ArcNode* tp0 = tp->nextarc;
			tp->nextarc = NULL;
			free(tp);
			tp = tp0;
		}
		for (int i = place; i < G.vexnum - 1; i++)//ɾ������
		{
			G.vertices[i].data = G.vertices[i + 1].data;
			ArcNode* temp1 = G.vertices[i + 1].firstarc;
			G.vertices[i].firstarc = temp1;
		}


		G.vertices[G.vexnum - 1].data.key = NULL;
		G.vertices[G.vexnum - 1].firstarc = NULL;
		G.vexnum--;

	}

	return OK;



	/********** End **********/
}


status InsertArc(ALGraph& G, KeyType v, KeyType w)
//��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	int place0 = -1;//��¼v��λ��
	int place1 = -1;//��¼w��λ��
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data.key == v)
		{
			place0 = i;
		}
		else if (G.vertices[i].data.key == w)
		{
			place1 = i;
		}
	}
	ArcNode* p = G.vertices[place0].firstarc;
	while (p)
	{
		if (p->adjvex == place1)
			return ERROR;
		p = p->nextarc;
	}
	if (place0 == -1 || place1 == -1) return ERROR;
	ArcNode* newnode = (ArcNode*)malloc(sizeof(ArcNode));
	newnode->adjvex = place1;
	newnode->nextarc = G.vertices[place0].firstarc;
	G.vertices[place0].firstarc = newnode;

	ArcNode* newnode1 = (ArcNode*)malloc(sizeof(ArcNode));
	newnode1->adjvex = place0;
	newnode1->nextarc = G.vertices[place1].firstarc;
	G.vertices[place1].firstarc = newnode1;
	G.arcnum++;
	return OK;
	/********** End **********/
}


status DeleteArc(ALGraph& G, KeyType v, KeyType w)
//��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	int deleteflag = 0;
	int place0 = -1;//��¼v��λ��
	int place1 = -1;//��¼w��λ��
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data.key == v)
		{
			place0 = i;
		}
		else if (G.vertices[i].data.key == w)
		{
			place1 = i;
		}
	}
	if (place0 == -1 || place1 == -1) return ERROR;

	if (G.vertices[place0].firstarc->adjvex == place1)
	{
		ArcNode* p = G.vertices[place0].firstarc;
		G.vertices[place0].firstarc = p->nextarc;
		free(p);
		deleteflag = 1;
	}
	else
	{
		ArcNode* father = G.vertices[place0].firstarc;
		ArcNode* p = father->nextarc;
		while (p)
		{
			if (p->adjvex == place1)
			{
				father->nextarc = p->nextarc;
				free(p);
				deleteflag = 1;
				break;
			}
			else
			{
				father = p;
				p = p->nextarc;
			}
		}

	}
	if (deleteflag != 1) return ERROR;
	if (G.vertices[place1].firstarc->adjvex == place0)
	{
		ArcNode* p = G.vertices[place1].firstarc;
		G.vertices[place1].firstarc = p->nextarc;
		free(p);
	}
	else
	{
		ArcNode* father = G.vertices[place1].firstarc;
		ArcNode* p = father->nextarc;
		while (p)
		{
			if (p->adjvex == place0)
			{
				father->nextarc = p->nextarc;
				free(p);
				break;
			}
			else
			{
				father = p;
				p = p->nextarc;
			}
		}
	}

	G.arcnum--;
	return OK;




	/********** End **********/
}

void visit(VertexType v)
{
	printf(" %d %s", v.key, v.others);
}


void DFS(ALGraph G, int v, void (*visit)(VertexType))
{
	visited[v] = TRUE;
	visit(G.vertices[v].data);
	for (int w = G.vertices[v].firstarc->adjvex; w >= 0; w = NextAdjVex(G, G.vertices[v].data.key, G.vertices[w].data.key))
	{
		if (!visited[w]) DFS(G, w, visit);
	}
}



status DFSTraverse(ALGraph& G, void (*visit)(VertexType))
//��ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	int v = 0;
	for (v = 0; v < G.vexnum; v++)
	{
		visited[v] = FALSE;
	}

	for (v = 0; v < G.vexnum; v++)
	{
		if (!visited[v])
		{
			DFS(G, v, visit);
		}
	}


	/********** End **********/
}



status BFSTraverse(ALGraph& G, void (*visit)(VertexType))
//��ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	int v = 0;
	for (v = 0; v < G.vexnum; v++)
	{
		visited[v] = FALSE;
	}

	queue<int>  Q;//�ÿո�������

	for (v = 0; v < G.vexnum; v++)
	{
		if (!visited[v])
		{
			visited[v] = TRUE;
			visit(G.vertices[v].data);
			Q.push(v);
			while (!Q.empty())
			{
				int u = Q.front();
				Q.pop();
				for (int w = G.vertices[u].firstarc->adjvex; w >= 0; w = NextAdjVex(G, G.vertices[v].data.key, G.vertices[w].data.key))
				{
					if (!visited[w])
					{
						visited[w] = TRUE;
						visit(G.vertices[w].data);
						Q.push(w);
					}
				}
			}
		}
	}


	/********** End **********/
}


status SaveGraph(ALGraph G, char FileName[])
//��ͼ������д�뵽�ļ�FileName��
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin 1 *********/
	FILE* fp = fopen(FileName, "wb");
	VertexType V[MAX_VERTEX_NUM];//���涥����Ϣ
	int VR[1000][2];//���满

	for (int i = 0; i <= G.vexnum; i++)
	{
		fprintf(fp, "%d", G.vertices[i].data.key);
		fprintf(fp, "%s", G.vertices[i].data.others);
		fprintf(fp, "%c", '$');
	}//���涥��



	int j = 0;

	for (int i = 0; i < G.vexnum; i++)
	{
		ArcNode* p = G.vertices[i].firstarc;//��һ�ٽӵ�
		while (p)
		{
			if (p->adjvex > i)//���满����Ϣ
			{
				VR[j][0] = G.vertices[i].data.key;
				VR[j][1] = G.vertices[p->adjvex].data.key;
				j++;
			}
			p = p->nextarc;
		}
	}
	VR[j][0] = -1;
	VR[j][1] = -1;
	for (int i = 0; i <= j; i++)
	{
		fprintf(fp, "%d", VR[i][0]);
		fprintf(fp, "%c", '$');
		fprintf(fp, "%d", VR[i][1]);
		fprintf(fp, "%c", '$');
	}//���满

	fclose(fp);

	return OK;

	/********** End 1 **********/
}


status LoadGraph(ALGraph& G, char FileName[])
//�����ļ�FileName��ͼ���ݣ�����ͼ���ڽӱ�
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin 2 *********/
	VertexType V[MAX_VERTEX_NUM];//���涥����Ϣ
	char other[20] = {};
	int VR[1000][2];//���满
	FILE* fp = fopen(FileName, "rb");
	int i = 0;
	fscanf(fp, "%d", &V[i].key);
	fscanf(fp, "%c", other);
	int j = 0;
	while (*(other + j) != '$')
	{
		j++;
		fscanf(fp, "%c", other + j);
	}
	int k = 0;
	for (k = 0; *(other + k) != '$'; k++)
	{
		*(V[i].others + k) = *(other + k);
	}
	for (; k < 20; k++)
	{
		*(V[i].others + k) = NULL;
	}

	while (V[i].key != -1)
	{
		i++;
		char other[20] = {};
		fscanf(fp, "%d", &V[i].key);
		fscanf(fp, "%c", other);
		int j = 0;
		while (*(other + j) != '$')
		{
			j++;
			fscanf(fp, "%c", other + j);
		}
		int k = 0;
		for (k = 0; *(other + k) != '$'; k++)
		{
			*(V[i].others + k) = *(other + k);
		}
		for (; k < 20; k++)
		{
			*(V[i].others + k) = NULL;
		}
	}//��ȡ������Ϣ


	i = 0;
	char o = ' ';
	fscanf(fp, "%d", &VR[i][0]);
	fscanf(fp, "%c", &o);
	fscanf(fp, "%d", &VR[i][1]);
	fscanf(fp, "%c", &o);



	while (VR[i][0] != -1)
	{
		i++;
		fscanf(fp, "%d", &VR[i][0]);
		fscanf(fp, "%c", &o);
		fscanf(fp, "%d", &VR[i][1]);
		fscanf(fp, "%c", &o);
	}

	for (int i = 0; VR[i][0] != -1; i++)
	{
		int min0 = VR[i][0];
		int min1 = VR[i][1];
		int min = 10 * min0 + min1;
		for (int j = i + 1; VR[j][0] != -1; j++)
		{
			if (VR[j][0] * 10 + VR[j][1] < min)
			{
				int temp0 = VR[j][0];
				int temp1 = VR[j][1];
				VR[j][0] = VR[i][0];
				VR[j][1] = VR[i][1];
				VR[i][0] = temp0;
				VR[i][1] = temp1;
			}

		}
	}

	CreateCraph(G, V, VR);

	return OK;

	/********** End 2 **********/
}

int workGraph(Glist GList[], char name)
{
	for (int i = 0; i < Glength; i++)
	{
		if (GList[i].name == name)
		{
			return i;
		}
	}
	return -1;
}


status addGraph(Glist GList[], char name)
{
	GList[Glength].name = name;
	Glength++;
	return OK;
}

status deleteGraph(Glist GList[], char name)
{
	int flag = 0;
	int i = 0;
	for (i; i < Glength; i++)
	{
		if (GList[i].name == name)
		{
			flag = 1;
			break;
		}
	}//���ҵ���Ҫɾ����λ��
	if (flag == 0) return ERROR;

	DestroyGraph(GList[i].G);
	ALGraph* temp,*p;
	for (; i < Glength - 1; i++)
	{
		temp = &GList[i].G;
		p = &GList[i + 1].G;
		*temp = *p;
		GList[i].name = GList[i + 1].name;
	}
	DestroyGraph(GList[Glength - 1].G);
	Glength--;
	return OK;

}