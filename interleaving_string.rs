use std::collections::{HashMap, HashSet};

impl Solution {
    fn solve(
        s1: &[u8],
        s2: &[u8],
        s3: &[u8],
        i: &mut usize,
        j: &mut usize,
        k: &mut usize,
        sol: &mut HashSet<(usize, usize, usize)>,
    ) -> bool {
        if sol.contains(&(*i, *j, *k)) {
            return false;
        }
        sol.insert((*i, *j, *k));
        let (n, m, l) = (s1.len(), s2.len(), s3.len());
        if *k == l && *i != 0 && *j != 0 {
            return true;
        }
        let mut ret = false;
        if *i < n
            && *j < m
            && *k < l
            && s1[*i] == s2[*j]
            && s1[*i] == s3[*k]
        {
            ret = Solution::solve(s1, s2, s3, &mut (i.clone()), &mut (j.clone()+1), &mut (k.clone() +1), sol)
                | Solution::solve(s1, s2, s3, &mut (i.clone() +1), &mut j.clone(), &mut (k.clone() +1), sol);
        } 
        else if *i < n && *k < l && s1[*i] == s3[*k] {
                *i += 1;
                *k += 1;
                ret = Solution::solve(s1, s2, s3, i, j, k, sol);
        } else if *j < m && *k < l && s2[*j] == s3[*k] {
                *j += 1;
                *k += 1;
                ret = Solution::solve(s1, s2, s3, i, j, k, sol);
        } else {
                return false;
        }
        ret
    }

    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let (n, m, l) = (s1.len(), s2.len(), s3.len());
        if n + m != l {
            return false;
        }
        if n == 0 {
            if m == 0 && l == 0  || m != 0 && l != 0 && s2 == s3{
                return true;
            }
            return false;
        }
        if m == 0 {
            if n != 0 && l != 0 && s1 == s3 {
                return true;
            }
            return false;
        }
        let (mut i, mut j, mut k, mut sol) = (0, 0, 0, HashSet::new());
        Solution::solve(&s1.as_bytes(), &s2.as_bytes(), &s3.as_bytes(), &mut i, &mut j, &mut k, &mut sol)
    }
}