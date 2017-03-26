#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct BinTree{
	int v;     //value
	BinTree* l; // leftChild;
	BinTree* r; //rightChild;
} BT, *PBT;

//Create binary tree
PBT CreateBinTree(char *str);

 char strBinTree[] = 
"+1\n"
" -2\n"
"  -4\n"
"  -5\n"
"   -6\n"
"   -7\n"
" -3\n"
"  -13\n"
"  -8\n"
"   -9\n"
"   -10\n"
"    -11\n"
"    -12\n";
/*
    1
   / \
  /   \
 2     3
 / \   / \
4  5  13  8 
  / \    /  \
  6  7  9   10
            / \
     	   11  12
*/
void pre (PBT root, int i = 0, int h = 0) {
	if (root) {
		cout << i << " : " << h << " --> "<< root->v << "\n";
		pre (root->l, i + 1, root->v);pre (root->r, i + 1, root->v);
	}
} 

PBT CreateBinTree(char *str)
{
	char val[12];//-2 147 483 648
	PBT root = NULL, tRoot = NULL;
	char * tmp = str, * t = NULL, * tt = NULL;
	int level = 0;
	stack<PBT> s; 
	while ((t = strchr(tmp, '\n')) != NULL) {
		if (root) {
			if ((tt = strchr(tmp, '-')) != NULL) {
				int tLevel = tt - tmp;
				if (tLevel <= level) {
					for (int i = 0; i < level - tLevel + 1; ++ i) {
						root = s.top();
						s.pop();
					}
					root->r = (PBT) malloc (sizeof(BT));
					memset (root->r, 0, sizeof(BT));
					strncpy (val, tt + 1, t - tmp - 1);
					val[t - tmp - 1] = 0;
					root->r->v = atoi (val);
					cout<<root->v<<"-> "<<root->r->v<<endl;
					s.push(root);
					root = root->r;
				}
				else {//更低层必定为左 
					root->l = (PBT) malloc (sizeof(BT));
					memset (root->l, 0, sizeof(BT));
					strncpy (val, tt + 1, t - tmp - 1);
					val[t - tmp - 1] = 0;
					root->l->v = atoi (val);
					cout<<root->v<<"-> "<<root->l->v<<endl;
					s.push(root);
					root = root->l;
				}
				level = tLevel;
			}
			else {
				continue;
			}
		}
		else {
			if ((tt = strchr(tmp, '+')) != NULL) {
				root = (PBT) malloc (sizeof(BT));
				memset (root, 0, sizeof(BT));
				strncpy (val, tt + 1, t - tmp - 1);
				val[t - tmp - 1] = 0;
				root->v = atoi (val);
				tRoot = root;
			}
			else {
				continue;
			}
		}
		tmp = t + 1;
	}
	//pre (tRoot);
	return tRoot;
}



bool IsBranch(BinTree* root, int nodeList[],int nodeListSize)
{
	bool bIsBranch = false;
	int counter = 0;
	if (root) {
		sort(nodeList, nodeList + nodeListSize);
		if (binary_search(nodeList, nodeList + nodeListSize, root->v)) {
			bIsBranch =  true;
			while (bIsBranch && root) {
				counter ++;
				if (root->l || root->r) 
					bIsBranch = false;
				else 
					break;
				if (root->l && binary_search(nodeList, nodeList + nodeListSize, root->l->v)) {
					root = root->l;
					bIsBranch = true;
				}
				else if (root->r && binary_search(nodeList, nodeList + nodeListSize, root->r->v)) {
					root = root->r;
					bIsBranch = true;
				}
			}
		}	
	}
	return bIsBranch ? counter ==  nodeListSize : bIsBranch; 
}

int main(int argc, char* argv[])
{
	PBT root = NULL;
	int nodeListSize = 0;

	//input node list size
	cin >> nodeListSize;
	int* NodeList = new int[nodeListSize];
	if (NodeList == NULL)
		return 0;

	//input each node
	for (int i = 0; i < nodeListSize; i++)
		cin >> NodeList[i];
	root= CreateBinTree(strBinTree);
	bool bIsBranch = IsBranch(root, NodeList, nodeListSize);
	if (bIsBranch)
		printf("true");
	else
		printf("false");

	if (NodeList)
		delete[]NodeList, NodeList=NULL;
	return 0;
}
