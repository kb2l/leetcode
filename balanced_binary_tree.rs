// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;

use std::cmp::max;
impl Solution {
    pub fn core(root: &Option<Rc<RefCell<TreeNode>>>) -> (i32, bool) {
        match root {
            None => (0, true),
            Some(node) => {
                let result_left = Solution::core(&node.borrow().left);
                if !result_left.1 {
                    return (0, false);
                }
                let result_right = Solution::core(&node.borrow().right);
                if !result_right.1 || (result_left.0 - result_right.0).abs() > 1 {
                    return (0, false);
                }
                (max(result_right, result_left).0 + 1, true)
            }
        }
    }
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Solution::core(&root).1
    }
}