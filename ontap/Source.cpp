# include <iostream>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node() {
		data = NULL;
		left = right = NULL;
	}
	node(int x) {
		data = x;
		left = right = NULL;
	}
};
class tree {
	node* root;
public:
	tree() {
		root = NULL;
	}
	void add(int x) {
		node* p = new node(x);
		if (!root) root = p;
		else
			root=addroot(root, p);
			
	}
	node* addroot(node*root,node* p) {
		if (!root) return p;
		if (root->data < p->data) {
			root->right = addroot(root->right,p);
		}
		else
			root->left = addroot(root->left,p);
		return root;
	}
	void print(node* root) {
		if (root) {
			print(root->right);
			cout << root->data << "\n";
			print(root->left);
		}
	}
	void xuat() {
		print(root);
	}
	
	void timkiem(node* root,int x) {
		if (!root) {
			cout << "khong thay!!";
			return;
		}
		if (root->data == x) {
			cout << " tim thay!!\n";
			return;
		}
		else if (root->data < x) {
			timkiem(root->right, x);
		}
		else timkiem(root->left, x);
	}
	void tim(int x) {
		timkiem(root, x);
	}
	
	int size(node* root) {
		if (root) {
			int n = 1;
			n+=size(root->left);
			n+=size(root->right);
			return n;
		}
		else
			return 0;
		
	}
	void size1() {
		cout<<size(root);
	}
	void findleaf(node* root) { //tim` la
		if (root) {
			if (!root->left && !root->right)
				cout << root->data << "\n";
			findleaf(root->left);
			findleaf(root->right);
		}
	}
	void findleafl(node* root) { //rim la' trai'
		if (root) {
			if (root->left && !root->left->left && !root->left->right)
				cout << root->left->data << "\n";
			findleafl(root->left);
			findleafl(root->right);
		}
	}
	void findleafr(node* root) { //tim` la' phai
		if (root) {
			if (root->right&&!root->right->left && !root->right->right)
				cout << root->right->data << "\n";
			findleafr(root->left);
			findleafr(root->right);
		}
	}
	void timla() {
		findleafr(root);
	}
	void min(node* root) {
		if (root) {
			if (!root->left) {
				cout << root->data;
				return;
			}
				min(root->left);
				

		}
	}
	void timmin() {
		min(root);
	}
	void xoacay(node* root) {
		if (root) {
			xoacay(root->left);
			xoacay(root->right);
			delete root;
			root = NULL;
		}
	}
	void del() {
		xoacay(root);
	}
	void xoanodemin(node* root) {
		while (root->left) {
			if (!root->left->left) {
				if (root->left->right) {
					node* a = root->left;
					root->left = a->right;
					delete a;
					return;
				}
				else
				{
					node* a = root->left;
					delete a;
					return;
				}
			}
			root = root->left;
		}
	}
	void delmin() {
		xoanodemin(root);
	}
	void xoanodemax(node* root) {

	}
	void xoanodela(node* root) {

	}
	void xoanode(node* root,int x) {

	}
};
int main() {
	tree a;
	a.add(3);
	a.add(4);
	a.add(1);
	a.add(2);
	a.add(5);
	a.xuat();
	//a.nho();
	//a.tim(2);
	//a.size1();
	//a.timla();
	//a.del();
	//a.timmin();
	a.delmin();
	return 0;
 }