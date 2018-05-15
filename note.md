## 1 preorderTraversal 前序遍历

### 示例

```c++
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
```



### 解决方案:

```c++
//题目背景
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


/*--------------------------------------------------------
			My solution
--------------------------------------------------------*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> result;
		vector<int> tempVar;
		int a;
		if (root != NULL)
		{
			result.push_back(root->val);//保存根节点的值
			tempVar = preorderTraversal(root->left);//探索左节点的值
			for (int i = 0; i<tempVar.size(); i++)
				result.push_back(tempVar.at(i));

			tempVar = preorderTraversal(root->right);
			for (int i = 0; i<tempVar.size(); i++)
				result.push_back(tempVar.at(i));
		}
		return result;
	}
};


/*--------------------------------------------------------
				system solution
--------------------------------------------------------*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (root) {
			res.push_back(root->val);
			preorderTraversal(root->left);
			preorderTraversal(root->right);
		}
		return res;
	}
private:
	vector<int> res;
};
```

总结: 系统解法充分利用了类的优势, 用私有变量充当全局变量的效果, 比自己算法更为高明.