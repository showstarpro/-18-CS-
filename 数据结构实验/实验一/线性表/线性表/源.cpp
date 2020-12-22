/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define INFEASIBLE  -1


typedef  int status;
typedef int ElemType; //数据元素类型定义

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct {  //顺序表（顺序结构）的定义
	ElemType* elem;
	int length;
	int listsize;
}SqList;


typedef struct {  //线性表的管理表定义
	struct {
		char name[30];
		SqList L;
	} elem[10];
	int length;
	int listsize;
}LISTS;


/*-----page 19 on textbook ---------*/
status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList&L);
status ListEmpty(SqList L);
int    ListLength(SqList L);
status GetElem(SqList L,int i,ElemType& e);
status LocateElem(SqList L,ElemType e); //简化过
status PriorElem(SqList L, ElemType e, ElemType& pre);
status NextElem(SqList L, ElemType e, ElemType& next);
status ListInsert(SqList&L,int i,ElemType e);
status ListDelete(SqList& L, int i, ElemType& e);
status ListTraverse(SqList L);  //简化过
status  InitLists(LISTS& Lists);
status workLists(LISTS Lists, char ListName[], SqList& L);
status AddList(LISTS& Lists, char ListName[]);
status RemoveList(LISTS& Lists, char ListName[]);
int LocateList(LISTS Lists, char ListName[]);
/*--------------------------------------------*/
int  main(void) {
	LISTS Lists;
	int e;
	int n;
	int i;
	SqList L;  int op = 1;
	while (op) {
		system("cls");	printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("	  1. InitList       7. LocateElem\n");
		printf("	  2. DestroyList    8. PriorElem\n");
		printf("	  3. ClearList       9. NextElem \n");
		printf("	  4. ListEmpty     10. ListInsert\n");
		printf("	  5. ListLength     11. ListDelete\n");
		printf("	  6. GetElem       12. ListTraverse\n");
		printf("	 13. InitLists     14. ADDLists\n");
		printf("	 15. RemoveList    16. LocateList\n");
		printf("	 17. workLists\n");
		printf("	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("请选择你的操作[0~17]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			//printf("\n----IntiList功能待实现！\n");
			if (InitList(L) == OK) printf("线性表创建成功！\n");
			else printf("线性表创建失败！\n");
			getchar(); getchar();
			break;
		case 2:
			//printf("\n----DestroyList功能待实现！\n");
			if (DestroyList(L) == OK)  printf("线性表销毁成功\n");
			else printf("线性表销毁失败\n");
			getchar(); getchar();
			break;
		case 3:
			//printf("\n----ClearList功能待实现！\n");
			if (ClearList(L) == OK)   printf("clear ok\n");
			else printf("clear error\n");
			getchar(); getchar();
			break;
		case 4:
			//printf("\n----ListEmpty功能待实现！\n");
			if (ListEmpty(L) == OK)  printf("ListEmpty OK\n");
			else printf("ListEmpty error\n");
			getchar(); getchar();
			break;
		case 5:
			//printf("\n----ListLength功能待实现！\n");
		{
			if (( ListLength(L)) != FALSE) printf("ListLength=%d\n",L.length);
			else printf("ListLength error\n");
			getchar(); getchar();
			break;
		}
		case 6: 
		{
			  //printf("\n----GetElem功能待实现！\n");
			  printf("请输入元素位置\n");
			  scanf("%d", &n);
			  if (GetElem(L, n, e) == OK) printf("第%d号元素是:%d\n", n, e);
			  else printf("GetElem error\n");
			  getchar(); getchar();
			  break;
		}
		case 7: 
		{
			//printf("\n----LocateElem功能待实现！\n");
			printf("输入你需要查找的元素\n");
			scanf("%d", &e);
			if ((i = LocateElem(L, e) )!= FALSE) printf("元素%d的位置为%d\n", e, i);
			else printf("Locate error\n");
			getchar(); getchar();
			break; 
		}
		case 8:
		{
			//printf("\n----PriorElem功能待实现！\n");
			printf("输入你需要确定前驱的元素\n");
			scanf("%d", &e);
			int pre;
			if (PriorElem(L, e, pre) != FALSE) printf("%d 的前驱是：%d\n", e, pre);
			else printf("PriorElem error\n");
			getchar(); getchar();
			break;
		}
		case 9:
		{
			//printf("\n----NextElem功能待实现！\n");
			printf("输入你要确定后继的元素\n");
			scanf("%d", &e);
			int next;
			if (NextElem(L, e, next) != FALSE) printf("%d 的后继是：%d\n", e, next);
			else printf("NextElem error\n");
			getchar(); getchar();
			break;
		}
		case 10:
		{
			//printf("\n----ListInsert功能待实现！\n");
			printf("输入你要插入的元素\n");
			scanf("%d", &e);
			printf("输入你要插入的位置\n");
			scanf("%d", &n);
			if (ListInsert(L, n, e) != FALSE)  printf("插入成功\n");
			else printf("插入失败\n");
			getchar(); getchar();
			break;
		}
		case 11:
		{
			//printf("\n----ListDelete功能待实现！\n");
			printf("输入你要删除的位置\n");
			scanf("%d", &i);
			if (ListDelete(L, i, e) != FALSE) printf("删除第%d号位置的元素是：%d\n", i, e);
			else printf("删除失败\n");
			getchar(); getchar();
			break;
		}
		case 12:
		{
			//printf("\n----ListTraverse功能待实现！\n");     
			if (!ListTraverse(L)) printf("线性表是空表！\n");
			getchar(); getchar();
			break;
		}
		case 13:
		{
			if (InitLists(Lists) == OK)  printf("Lists ok \n");
			else printf("Lists error\n");
			getchar(); getchar();
			break;
		}
		case 14:
		{
			printf("输入你要插入的表的名字：");
			char name[10] = { 0 };
			scanf("%s", name);
			if (AddList(Lists, name) != FALSE)  printf("插入成功\n");
			else printf("插入失败\n");
			getchar(); getchar();
			break;
		}
		case 15:
		{
			printf("输入你要删除的表的名字:");
			char dname[10] = { 0 };
			scanf("%s", dname);
			if (RemoveList(Lists, dname) != FALSE) printf("delet ok \n");
			else printf("delet erro\n");
			getchar(); getchar();
			break;
		}
		case 16:
		{
			printf("输入你要确定位置的表名:");
			char qname[10] = { 0 };
			scanf("%s", qname);
			int q;
			if ((q = LocateList(Lists, qname)) != FALSE) printf("位置是%d\n", q);
			else printf("locate erro\n");
			getchar(); getchar();
			break;
		}
		case 17:
		{
			printf("输入你要操作的表的名字:");
			char wname[10] = { 0 };
			scanf("%s", wname);
			if (workLists(Lists, wname, L) != FALSE)  printf("work start\n");
			else printf("work error\n");
			getchar(); getchar();
			break;
		}
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
}//end of main()


/*--------page 23 on textbook --------------------*/

status InitList(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}


/*
status ListTraverse(SqList L) {
	int i;
	printf("\n-----------all elements -----------------------\n");
	for (i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
	printf("\n------------------ end ------------------------\n");
	return L.length;
}
*/




status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem)
	{

		L.length = 0;
		L.listsize = 0;
		free(L.elem);
		L.elem = NULL;
		return OK;
	}
	else return INFEASIBLE;

	/********** End **********/
}


status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL)
	{
		return INFEASIBLE;
	}
	else
	{
		for (int i = 0; i <= L.length - 1; i++)
		{
			L.elem[i] = 0;
		}
		L.length = 0;

		return OK;
	}
	/********** End **********/
}


status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL)
	{
		return INFEASIBLE;
	}
	else if (L.length == 0)
	{
		return TRUE;
	}
	else return FALSE;
	/********** End **********/
}

status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL)
	{
		return INFEASIBLE;
	}
	else
	{
		int i = 0;
		while (L.elem[i] != 0)
		{
			i++;
			L.length++;
		}
		return L.length;
	}
	/********** End **********/
}


status GetElem(SqList L, int i, ElemType& e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL)
	{
		return INFEASIBLE;
	}
	else if (i<1 || i>L.length)
	{
		return ERROR;
	}
	else
	{
		e = L.elem[i - 1];
		return OK;
	}
	/********** End **********/
}

status LocateElem(SqList L, ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回OK；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL)
	{
		return INFEASIBLE;
	}
	for (int i = 0; i <= L.length - 1; i++)
	{
		if (e == L.elem[i])
			return i + 1;
	}

	return ERROR;

	/********** End **********/
}

status PriorElem(SqList L, ElemType e, ElemType& pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL)
	{
		return INFEASIBLE;
	}
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			if (i == 0)
				return ERROR;
			else
			{
				pre = L.elem[i - 1];
				return OK;
			}
		}
	}

	return ERROR;

	/********** End **********/
}

status NextElem(SqList L, ElemType e, ElemType& next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL)
	{
		return INFEASIBLE;
	}
	for (int i = 0; i <= L.length; i++)
	{
		if (L.elem[i] == e)
		{
			if (i == L.length - 1)
				return ERROR;
			else
			{
				next = L.elem[i + 1];
				return OK;
			}
		}
	}

	return ERROR;

	/********** End **********/
}


status ListInsert(SqList& L, int i, ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL)  return INFEASIBLE;
	int j;
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length >= L.listsize)
	{
		int* newbase;
		newbase = (int*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
		if (newbase == NULL) return ERROR;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}

	for (j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
	/********** End **********/
}


status ListDelete(SqList& L, int i, ElemType& e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL) return INFEASIBLE;
	if ((i < 1) || (i > L.length))  return ERROR;
	int* p = &(L.elem[i - 1]);
	e = *p;
	int* q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--L.length;
	return OK;

	/********** End **********/
}

status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL)  return INFEASIBLE;
	if (L.length != 0)
	{
		for (int i = 0; i <= L.length - 2; i++)
		{
			printf("%d ", L.elem[i]);
		}

		printf("%d", L.elem[L.length - 1]);
	}
	return OK;
	/********** End **********/
}


status  SaveList(SqList L, char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem == NULL) return INFEASIBLE;
	FILE* pp;
	pp = fopen(FileName, "wb");
	if (pp == NULL)    return ERROR;
	for (int i = 0; i <= L.length - 1; i++)
	{
		fwrite(&L.elem[i], sizeof(int), 1, pp);
	}
	fclose(pp);
	return  OK;

	/********** End **********/
}
status  LoadList(SqList& L, char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if (L.elem != NULL) return INFEASIBLE;
	L.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	FILE* fr;
	fr = fopen(FileName, "rb");
	if (fr == NULL)  return ERROR;

	while (fread(&L.elem[L.length], sizeof(int), 1, fr))
	{
		L.length++;
	}
	fclose(fr);
	return OK;
	/********** End **********/
}

status  InitLists(LISTS& Lists)
{
	Lists.length = 0;
	Lists.listsize = LISTINCREMENT;
	return OK;
}

status workLists(LISTS Lists,char ListName[],SqList&L)
{
	for (int i = 0; i <= Lists.length - 1; i++)
	{
		if (strcmp(Lists.elem[i].name, ListName) == 0)
		{
			L = Lists.elem[i].L;
			L.length = Lists.elem[i].L.length;
			L.listsize = Lists.elem[i].L.listsize;
			L.elem = Lists.elem[i].L.elem;
			return OK;
		}
	}
	return FALSE;
}


status AddList(LISTS& Lists, char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	strcpy(Lists.elem[Lists.length].name, ListName);
	int* newbase;
	newbase = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	Lists.elem[Lists.length].L.elem = newbase;
	Lists.elem[Lists.length].L.length = 0;
	Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;
	Lists.length++;
	return OK;
	/********** End **********/
}

status RemoveList(LISTS& Lists, char ListName[])
// Lists中删除一个名称为ListName的线性表
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	int i = 0;
	bool coms;
	for (i = 0; i <= Lists.length - 1; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (Lists.elem[i].name[j] == ListName[j])
				coms = TRUE;
			else
			{
				coms = FALSE;
				break;
			}
		}
		if (coms == TRUE)
			break;
	}

	if (coms == FALSE)
		return ERROR;
	else
	{
		for (int k = i; k <= Lists.length - 2; k++)
		{
			Lists.elem[i] = Lists.elem[i + 1];
		}
		Lists.length--;
		return OK;
	}

	/********** End **********/
}

int LocateList(LISTS Lists, char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	int i = 0;
	bool coms=FALSE;
	for (i = 0; i <= Lists.length - 1; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (Lists.elem[i].name[j] == ListName[j])
				coms = TRUE;
			else
			{
				coms = FALSE;
				break;
			}
		}
		if (coms == TRUE)
			break;
	}
	if (coms == FALSE)
		return 0;
	else
		return i + 1;

	/********** End **********/
}












