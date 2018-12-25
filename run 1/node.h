
#include <iostream>
#include <list>
#include <string>
using namespace std;

class DecisionTreeNode; //הצהרה

class ValidAnswer
{
public:
	string ans;
	DecisionTreeNode* son;

};

class DecisionTreeNode //קודקוד של עץ החלטה
{
public:
	string value;
	bool isLeaf;
	list<ValidAnswer*> answersList; // רשימת תשובות אפשריות 
	list<ValidAnswer*>::iterator ptrListbeg = answersList.begin();//iterator to the begin of the list
	list<ValidAnswer*>::iterator ptrListend = answersList.end();//iterator to the end of the list
	DecisionTreeNode(string val = '\0') :value(val), isLeaf(true) {};//ctor

};

