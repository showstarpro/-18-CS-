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
typedef int ElemType; //����Ԫ�����Ͷ���

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct {  //˳���˳��ṹ���Ķ���
	ElemType* elem;
	int length;
	int listsize;
}SqList;


typedef struct {  //���Ա�Ĺ������
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
status LocateElem(SqList L,ElemType e); //�򻯹�
status PriorElem(SqList L, ElemType e, ElemType& pre);
status NextElem(SqList L, ElemType e, ElemType& next);
status ListInsert(SqList&L,int i,ElemType e);
status ListDelete(SqList& L, int i, ElemType& e);
status ListTraverse(SqList L);  //�򻯹�
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
		printf("��ѡ����Ĳ���[0~17]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			//printf("\n----IntiList���ܴ�ʵ�֣�\n");
			if (InitList(L) == OK) printf("���Ա����ɹ���\n");
			else printf("���Ա���ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 2:
			//printf("\n----DestroyList���ܴ�ʵ�֣�\n");
			if (DestroyList(L) == OK)  printf("���Ա����ٳɹ�\n");
			else printf("���Ա�����ʧ��\n");
			getchar(); getchar();
			break;
		case 3:
			//printf("\n----ClearList���ܴ�ʵ�֣�\n");
			if (ClearList(L) == OK)   printf("clear ok\n");
			else printf("clear error\n");
			getchar(); getchar();
			break;
		case 4:
			//printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
			if (ListEmpty(L) == OK)  printf("ListEmpty OK\n");
			else printf("ListEmpty error\n");
			getchar(); getchar();
			break;
		case 5:
			//printf("\n----ListLength���ܴ�ʵ�֣�\n");
		{
			if (( ListLength(L)) != FALSE) printf("ListLength=%d\n",L.length);
			else printf("ListLength error\n");
			getchar(); getchar();
			break;
		}
		case 6: 
		{
			  //printf("\n----GetElem���ܴ�ʵ�֣�\n");
			  printf("������Ԫ��λ��\n");
			  scanf("%d", &n);
			  if (GetElem(L, n, e) == OK) printf("��%d��Ԫ����:%d\n", n, e);
			  else printf("GetElem error\n");
			  getchar(); getchar();
			  break;
		}
		case 7: 
		{
			//printf("\n----LocateElem���ܴ�ʵ�֣�\n");
			printf("��������Ҫ���ҵ�Ԫ��\n");
			scanf("%d", &e);
			if ((i = LocateElem(L, e) )!= FALSE) printf("Ԫ��%d��λ��Ϊ%d\n", e, i);
			else printf("Locate error\n");
			getchar(); getchar();
			break; 
		}
		case 8:
		{
			//printf("\n----PriorElem���ܴ�ʵ�֣�\n");
			printf("��������Ҫȷ��ǰ����Ԫ��\n");
			scanf("%d", &e);
			int pre;
			if (PriorElem(L, e, pre) != FALSE) printf("%d ��ǰ���ǣ�%d\n", e, pre);
			else printf("PriorElem error\n");
			getchar(); getchar();
			break;
		}
		case 9:
		{
			//printf("\n----NextElem���ܴ�ʵ�֣�\n");
			printf("������Ҫȷ����̵�Ԫ��\n");
			scanf("%d", &e);
			int next;
			if (NextElem(L, e, next) != FALSE) printf("%d �ĺ���ǣ�%d\n", e, next);
			else printf("NextElem error\n");
			getchar(); getchar();
			break;
		}
		case 10:
		{
			//printf("\n----ListInsert���ܴ�ʵ�֣�\n");
			printf("������Ҫ�����Ԫ��\n");
			scanf("%d", &e);
			printf("������Ҫ�����λ��\n");
			scanf("%d", &n);
			if (ListInsert(L, n, e) != FALSE)  printf("����ɹ�\n");
			else printf("����ʧ��\n");
			getchar(); getchar();
			break;
		}
		case 11:
		{
			//printf("\n----ListDelete���ܴ�ʵ�֣�\n");
			printf("������Ҫɾ����λ��\n");
			scanf("%d", &i);
			if (ListDelete(L, i, e) != FALSE) printf("ɾ����%d��λ�õ�Ԫ���ǣ�%d\n", i, e);
			else printf("ɾ��ʧ��\n");
			getchar(); getchar();
			break;
		}
		case 12:
		{
			//printf("\n----ListTraverse���ܴ�ʵ�֣�\n");     
			if (!ListTraverse(L)) printf("���Ա��ǿձ�\n");
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
			printf("������Ҫ����ı�����֣�");
			char name[10] = { 0 };
			scanf("%s", name);
			if (AddList(Lists, name) != FALSE)  printf("����ɹ�\n");
			else printf("����ʧ��\n");
			getchar(); getchar();
			break;
		}
		case 15:
		{
			printf("������Ҫɾ���ı������:");
			char dname[10] = { 0 };
			scanf("%s", dname);
			if (RemoveList(Lists, dname) != FALSE) printf("delet ok \n");
			else printf("delet erro\n");
			getchar(); getchar();
			break;
		}
		case 16:
		{
			printf("������Ҫȷ��λ�õı���:");
			char qname[10] = { 0 };
			scanf("%s", qname);
			int q;
			if ((q = LocateList(Lists, qname)) != FALSE) printf("λ����%d\n", q);
			else printf("locate erro\n");
			getchar(); getchar();
			break;
		}
		case 17:
		{
			printf("������Ҫ�����ı������:");
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
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
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
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų�����OK�����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
	// �������ﲹ����룬��ɱ�������
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
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
{
	// �������ﲹ����룬��ɱ�������
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
// Lists��ɾ��һ������ΪListName�����Ա�
{
	// �������ﲹ����룬��ɱ�������
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
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{
	// �������ﲹ����룬��ɱ�������
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












