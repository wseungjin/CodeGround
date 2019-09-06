/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define EMPTY 50000000

using namespace std;

int Answer;

class Point2D{
private: 
	int x;
	int y;

public:

	void setX(int X)
	{
		x=X;
	}

	void setY(int Y)
	{
		y=Y;
	}


	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	bool Point2D::operator==(Point2D& a) 
	{
		bool tr=false;
		if(x==a.x & y==a.y)
		{
			tr=true;
		}
		return tr; 
	}

	Point2D& Point2D::operator=(const Point2D& c)
	{
		x = c.x;
		y = c.y;
		return *this;
	}

	static bool include(Point2D const &small,Point2D const &big)
	{
		if(small.x>=big.x && small.y <= big.y)
		{
			return true;
		}
		return false;
	}


};

class tree_node {
private:
	Point2D value;
	tree_node *parent;
	tree_node *left;
	tree_node *right;
public:
	tree_node(Point2D val,tree_node *p=NULL,tree_node *l= NULL,tree_node *r= NULL) {
		this->value = val;
		this->parent = p;
		this->left = l;
		this->right = r;
	}
	Point2D getValue() const{
		return value;
	}
	tree_node* getLeft() const {
		return left;
	}
	tree_node* getRight() const{
		return right;
	}
	tree_node* getParent() const{
		return parent;
	}

	bool isLeftExist() const{
		return left != NULL;
	}
	bool isRightExist() const{
		return right != NULL;
	}
	
	void setLeft(tree_node* left) {
		this->left = left;
	}
	void setRight(tree_node* right) {
		this->right = right;
	}
	void setParent(tree_node* parent) {
		this->parent = parent;
	}
};


class tree {
private:
	tree_node *root;
	tree_node *ptr;
	int size;
public:
	tree()
	{
		this->ptr = NULL;
		this->root = NULL;
		this->size = 0;
	}
	void search(tree_node *cur, Point2D val) {
		if (Point2D::include(val,cur->getValue())) {
			ptr = cur;
		}
		if (cur->isLeftExist()) {
			search(cur->getLeft(), val);
		}
		if (cur->isRightExist()) {
			search(cur->getRight(), val);
		}
	}
	void search_terminal(tree_node *cur) {
		ptr = cur;
		if (cur->isLeftExist()) {
			search_terminal(cur->getLeft());
		}
		if (cur->isRightExist()) {
			search_terminal(cur->getRight());
		}
	}
	tree_node* getRoot() const {
		return root;
	}
	void insert(Point2D parent_value,Point2D val) {

		while(1)
		{
			tree_node *newNode = new tree_node(val);
			if (root == NULL) {
				root = newNode;
				return;
			}
			ptr = NULL;
			tree_node *Parent;
			search(root, parent_value);
			Parent = ptr;
			if (Parent == NULL) {
				// Parent Node not exist
				return;
			}
			else if (!Parent->isLeftExist()) {
				Parent->setLeft(newNode);
				newNode->setParent(Parent);
			}
			else if (!Parent->isRightExist()) {
				Parent->setRight(newNode);
				newNode->setParent(Parent);
			}
			else {
				// parent node has left,right node
			}
		}
	}

	void deletion(Point2D val) {
		tree_node *remove_node=NULL;
		search(root, val);
		remove_node = ptr;
		if (remove_node == NULL) {
			// node is not exist
			return;
		}
		// Restructuring
		tree_node *remove_parent = remove_node->getParent();
		if (remove_node->getLeft() == NULL &&remove_node->getRight() == NULL) {
			// this node is leaf/terminal node
			int LR = (remove_parent->getRight() == remove_node);
			if (LR == 0) {
				remove_parent->setLeft(NULL);
			}
			else if (LR == 1) {
				remove_parent->setRight(NULL);
			}
			if (remove_parent == NULL) {
				
				delete remove_node;
				root = NULL;
			}
		}
		else if(!(remove_node->getLeft() && remove_node->getRight())){
			// has only one child
			int remove_child_LR = (remove_node->getLeft() == NULL); // remove node has left node? right node? [Left : 0 , Right : 1 ]
			tree_node *remove_child = (remove_child_LR == 0) ? remove_node->getLeft() : remove_node->getRight();
			if (remove_parent == NULL) {
				// this is root node
				root = remove_child;
				root->setParent(NULL);
				delete remove_node ;
				return;
			}
			int LR = (remove_parent->getRight()==remove_node); // left node? right node? [ Left : 0, Right : 1 ]
			remove_child->setParent(remove_parent);
			if (LR == 0) {
				remove_parent->setLeft(remove_child);
			}
			else if (LR == 1) {
				remove_parent->setRight(remove_child);
			}
		}
		else {
			// has two node
			tree_node *swapnode=NULL;
			search_terminal(remove_node);
			swapnode = ptr;
			tree_node *swap_parent=swapnode->getParent();
			tree_node* left = remove_node->getLeft();
			tree_node* right = remove_node->getRight();
			if (swap_parent != NULL) {
				int swap_LR = (swap_parent->getRight() == swapnode);
				if (swap_LR == 0) {
					swap_parent->setLeft(NULL);
				}
				else if (swap_LR == 1) {
					swap_parent->setRight(NULL);
				}
			}
			if (left != swapnode)
			{
				swapnode->setLeft(left);
				left->setParent(swapnode);
			}
			if (right != swapnode) {
				swapnode->setRight(right);
				right->setParent(swapnode);
			}
			swapnode->setParent(remove_node->getParent());
			if (remove_parent != NULL) {
				int LR = (remove_parent->getRight() == remove_node);
				if (LR == 0) {
					remove_parent->setLeft(swapnode);
				}
				else if (LR == 1) {
					remove_parent->setRight(swapnode);
				}
			}
			if (remove_parent == NULL)
			{
				root = swapnode;
			}
		}
		delete remove_node;
	}

};
	



int compare(const void *fir, const void *sec)
{
    int x1=((Point2D*)(fir))->getY-((Point2D*)(fir))->getX;
    int x2=((Point2D*)(sec))->getY-((Point2D*)(sec))->getX;

    if (x1>x2)
        return 1;
    else if (x1 < x2)
        return -1;
    else 
        return 0;
}

int main(int argc, char** argv)
{
	int T, test_case;

	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        int tNum;
        int  max;
        int temp;
        int tempx;
        int tempy;
        cin >> tNum;
        vector <Point2D> nList(tNum);

        for(int i=0;i<tNum;i++)
        {
            cin >> tempx >> tempy;
			nList[i].setX(tempx);
			nList[i].setY(tempy);
        }
        qsort(&nList[0],nList.size(),sizeof(nList[0]),compare);

        
        tree tr;
		for(int i=0;i<tNum;i++)
        {
			
        }
		

		for(int i=0;i<tNum;i++)
        {
            
        }
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << max << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}