
#include "NODE.h"
#include <iterator> // for iterators 
using namespace std;

class Tree
{
public:
	DecisionTreeNode * root; //���� ���
	Tree() : root(NULL) {}; //ctor

	~Tree()//dtor
	{
		deleteSubTree(root->value);
	}

	void deleteSubTree(string val) // ����� ���� ������ ������ �� �� ���
	{
		DecisionTreeNode* ptr = searchNode(val, root);
		clear(ptr);
	}

	void clear(DecisionTreeNode* NODE) //����� ���� ������ �� �� �� ���
	{
		if (!(NODE->isLeaf)) // �� �� ��� ���� ������ ����� ��� ��� ������ ����� ��������
		{
			while (NODE->ptrListend != NODE->ptrListbeg)
			{
				clear((*(NODE->ptrListend))->son);
				(NODE->ptrListbeg)--;
			}
		}
		delete NODE; //�� ����� ���� ����
	}

	void addRoot(string val)// ����� ���� ������ ���. ������ ����� ������� ����� ���
	{
		if(root !=NULL)
		root= new DecisionTreeNode( val);
		//root->isLeaf = true;
	}

	DecisionTreeNode* searchNode(string val, DecisionTreeNode*& NodeFather) // �������� ������ ���� ������
	{
		NodeFather = root;
		bool flag = false;
		DecisionTreeNode* node = search(flag, val, root, NodeFather);
		return node;
	}

	DecisionTreeNode* search(bool& found, string val, DecisionTreeNode* Node, DecisionTreeNode*& NodeFather) //�������� ��� ������ ����� �������
	{
		DecisionTreeNode* retval = new DecisionTreeNode();
		if (Node->value == val) //�� ������� ������ ���� ����� �������
		{
			found = true;
			return Node;
		}
		else
		{
			NodeFather = Node; //����� ���� ����� ���
			if (!Node->isLeaf) //���� ��� ���
				while ((!found) && Node->ptrListbeg != Node->answersList.end())
				{
					retval = search(found, val, (*(Node->ptrListbeg))->son, NodeFather);
					Node->ptrListbeg++;
				}

		}
		if (retval->value == val) return retval; //�� ������� ������ ���� ����� �������

		else					  return NULL;	//�� �� ����� �� ������� ������

	}

	bool addSon(string father, string val, string sol) //father=���� val=����� ������� ������ sol= ������ ������ �� ��� ���� sol 
	{
		DecisionTreeNode* stam;

		DecisionTreeNode* FatherNode = searchNode(father, stam);
		if (FatherNode == NULL)
			return false;
		else
		{
			ValidAnswer* NewNode = new ValidAnswer;
			NewNode->ans = val;
			(NewNode->son)->value = sol;

			(FatherNode->answersList).push_back(NewNode);
		}
	}

	void printAllTree()
	{

	}

	void searchAndPrint(string val)
	{
		bool flag = false;
		DecisionTreeNode* Node = root;
		DecisionTreeNode* NodeFather = root;
		searchAndPrint(flag, val, Node, NodeFather);
	}

	DecisionTreeNode* searchAndPrint(bool& found, string val, DecisionTreeNode* Node, DecisionTreeNode*& NodeFather) //�������� ��� ������ ����� �������
	{
		DecisionTreeNode* retval = new DecisionTreeNode;
		if (Node->value == val) //�� ������� ������ ���� ����� �������
		{
			found = true;
			cout << Node->value;
			return Node;
		}
		else
		{
			NodeFather = Node; //����� ���� ����� ���
			if (!Node->isLeaf) //���� ��� ���
				while ((!found) && Node->ptrListbeg != Node->answersList.end())
				{
					retval = search(found, val, (*(Node->ptrListbeg))->son, NodeFather);
					if (found) //�� ������� ������ ���� ����� �������
					{
						//cout << (*(Node->ptrListbeg))->ans;
						cout << Node->value;
						return retval;
					}
					Node->ptrListbeg++;
				}

		}

		if (!found)
			return NULL;	//�� �� ����� �� ������� ������

	}

	void process()
	{

	}

};