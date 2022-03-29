#include <iostream>
#include "8.tree\Tree.h"
using namespace std;
/**
 * Title: 递归求解二叉树的深度
 * Description:
 * @created 2017年5月8日 下午6:34:50
 */

/**
 * @description 返回二叉数的深度
 * @param t
 * @return
 */
int getTreeDepth(Tree t)
{

    // 树为空
    if (t == NULL) // 递归终止条件
        return 0;

    //int left = getTreeDepth(t.left);  // 递归求左子树深度，缩小问题的规模
    //int right = getTreeDepth(t.left); // 递归求右子树深度，缩小问题的规模

    return left > right ? left + 1 : right + 1;
}
