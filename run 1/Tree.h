
#include "NODE.h"
#include <iterator> // for iterators 
using namespace std;

class Tree
{
public:
	DecisionTreeNode * root; //שורש העץ
	Tree() : root(NULL) {}; //ctor

	~Tree()//dtor
	{
		deleteSubTree(root->value);
	}

	void deleteSubTree(string val) // מחפשת צומת ושולחת למחיקת כל תת העץ
	{
		DecisionTreeNode* ptr = searchNode(val, root);
		clear(ptr);
	}

	void clear(DecisionTreeNode* NODE) //מקבלת צומת ומוחקת את על תת העץ
	{
		if (!(NODE->isLeaf)) // אם לא עלה ניגש לרשימה ונשלח אחד אחד למחיקה באופן רקורסיבי
		{
			while (NODE->ptrListend != NODE->ptrListbeg)
			{
				clear((*(NODE->ptrListend))->son);
				(NODE->ptrListbeg)--;
			}
		}
		delete NODE; //אם הגענו לעלה נמחק
	}

	void addRoot(string val)// בניית צומת ראשונה לעץ. בתחילה הצומת מאותחלת להיות עלה
	{
		if(root !=NULL)
		root= new DecisionTreeNode( val);
		//root->isLeaf = true;
	}

	DecisionTreeNode* searchNode(string val, DecisionTreeNode*& NodeFather) // פונקצייה למציאת שאלה מבוקשת
	{
		NodeFather = root;
		bool flag = false;
		DecisionTreeNode* node = search(flag, val, root, NodeFather);
		return node;
	}

	DecisionTreeNode* search(bool& found, string val, DecisionTreeNode* Node, DecisionTreeNode*& NodeFather) //פונקציית עזר למציאת השאלה המבוקשת
	{
		DecisionTreeNode* retval = new DecisionTreeNode();
		if (Node->value == val) //אם הקודקוד הנוכחי הינו השאלה שחיפשנו
		{
			found = true;
			return Node;
		}
		else
		{
			NodeFather = Node; //עדכון האבא להיות הבן
			if (!Node->isLeaf) //תנאי שלא עלה
				while ((!found) && Node->ptrListbeg != Node->answersList.end())
				{
					retval = search(found, val, (*(Node->ptrListbeg))->son, NodeFather);
					Node->ptrListbeg++;
				}

		}
		if (retval->value == val) return retval; //אם הקודקוד הנוכחי הינו השאלה שחיפשנו

		else					  return NULL;	//אם לא מצאנו את הקודקוד המבוקש

	}

	bool addSon(string father, string val, string sol) //father=שאלה val=תשובה שברצוני להוסיף sol= להוסיף קודקוד בן ובו הערך sol 
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

	DecisionTreeNode* searchAndPrint(bool& found, string val, DecisionTreeNode* Node, DecisionTreeNode*& NodeFather) //פונקציית עזר למציאת השאלה המבוקשת
	{
		DecisionTreeNode* retval = new DecisionTreeNode;
		if (Node->value == val) //אם הקודקוד הנוכחי הינו השאלה שחיפשנו
		{
			found = true;
			cout << Node->value;
			return Node;
		}
		else
		{
			NodeFather = Node; //עדכון האבא להיות הבן
			if (!Node->isLeaf) //תנאי שלא עלה
				while ((!found) && Node->ptrListbeg != Node->answersList.end())
				{
					retval = search(found, val, (*(Node->ptrListbeg))->son, NodeFather);
					if (found) //אם הקודקוד הנוכחי הינו השאלה שחיפשנו
					{
						//cout << (*(Node->ptrListbeg))->ans;
						cout << Node->value;
						return retval;
					}
					Node->ptrListbeg++;
				}

		}

		if (!found)
			return NULL;	//אם לא מצאנו את הקודקוד המבוקש

	}

	void process()
	{

	}

};