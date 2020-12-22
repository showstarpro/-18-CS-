#pragma once
#include "def.h"
status CreateCraph(ALGraph &G, VertexType V[], KeyType VR[][2]);
status DestroyGraph(ALGraph& G);
int LocateVex(ALGraph G, KeyType u);
status PutVex(ALGraph& G, KeyType u, VertexType value);
int FirstAdjVex(ALGraph G, KeyType u);
int NextAdjVex(ALGraph G, KeyType v, KeyType w);
status InsertVex(ALGraph& G, VertexType v);
status DeleteVex(ALGraph& G, KeyType v);
status InsertArc(ALGraph& G, KeyType v, KeyType w);
status DeleteArc(ALGraph& G, KeyType v, KeyType w);
status DFSTraverse(ALGraph& G, void (*visit)(VertexType));
void visit(VertexType v);
void DFS(ALGraph G, int v, void (*visit)(VertexType));
status BFSTraverse(ALGraph& G, void (*visit)(VertexType));
status SaveGraph(ALGraph G, char FileName[]);
status LoadGraph(ALGraph& G, char FileName[]);

int   workGraph(Glist GList[], char name);
status   addGraph(Glist GList[], char name);
status   deleteGraph(Glist GList[], char name);
