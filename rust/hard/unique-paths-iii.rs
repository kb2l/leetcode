use std::{
    collections::{HashSet, VecDeque},
};

struct Solution {}
struct Node {
    pub p: (i32, i32),
    pub visited: HashSet<(i32, i32)>,
}

impl Node {
    pub fn new(p: (i32, i32), visited: HashSet<(i32, i32)>) -> Self {
        Node { p, visited }
    }
}
impl Solution {
    pub fn unique_paths_iii(grid: Vec<Vec<i32>>) -> i32 {
        fn IsEmpty(p: (i32, i32), grid: &Vec<Vec<i32>>) -> bool {
            match grid[p.0 as usize][p.1 as usize] {
                -1 => false,
                _ => true,
            }
        }
        fn IsDest(p: (i32, i32), grid: &Vec<Vec<i32>>) -> bool {
            match grid[p.0 as usize][p.1 as usize] {
                2 => true,
                _ => false,
            }
        }
        fn Neighbors(p: (i32, i32), grid: &Vec<Vec<i32>>) -> Vec<(i32, i32)> {
            let (h, w) = (grid[0].len() as i32, grid.len() as i32);
            [(0, 1), (0, -1), (1, 0), (-1, 0)].to_vec()
            .iter()
            .map(|(dx, dy)| {(dx + p.0, dy + p.1)})
            .filter(|(x, y)| { x >= &0 && x < &w && y >= &0 && y < &h }).collect()
        }

        let (h, w) = (grid[0].len(), grid.len());
        let mut starting_point = (-1, -1);
        let mut count = 0;
        (0..w).for_each(|i| {
            (0..h).for_each(|j| {
                match grid[i][j] {
                    1 => starting_point = (i as i32, j as i32),
                    0 => count += 1,
                    _ => {},
                }
            })
        });
        let mut visited: HashSet<(i32, i32)> = HashSet::new();
        visited.insert(starting_point);
        let mut q: VecDeque<Node> = VecDeque::new();
        let mut sol = 0;
        for ne in Neighbors(starting_point, &grid) {
            let n = Node::new(ne, visited.clone());
            q.push_back(n);
        }
        while !q.is_empty() {
            if let Some(mut current_node) = q.pop_front() {
                if IsDest(current_node.p, &grid)
                    && current_node.visited.len() == (count + 1) as usize
                {
                    sol += 1;
                } else {
                    current_node.visited.insert(current_node.p);
                    for neighbors_of_current_node in Neighbors(current_node.p, &grid) {
                        if !current_node.visited.contains(&neighbors_of_current_node)
                            && IsEmpty(neighbors_of_current_node, &grid)
                        {
                            let mut clone = current_node.visited.clone();
                            clone.insert(current_node.p);
                            q.push_back(Node::new(neighbors_of_current_node, clone));
                        }
                    }
                }
            }
        }
        sol
    }
}

fn main() {}

#[test]
fn test() {
    let grid = [
        [1, 0, 0, 0].to_vec(),
        [0, 0, 0, 0].to_vec(),
        [0, 0, 2, -1].to_vec(),
    ]
    .to_vec();
    assert_eq!(2, Solution::unique_paths_iii(grid));
}

#[test]
fn test2() {
    let grid = [
        [1, 0, 0, 0].to_vec(),
        [0, 0, 0, 0].to_vec(),
        [0, 0, 0, 2].to_vec(),
    ]
    .to_vec();
    assert_eq!(4, Solution::unique_paths_iii(grid));
}

#[test]
fn test3() {
    let grid = [[0, 1].to_vec(), [2, 0].to_vec()].to_vec();
    assert_eq!(0, Solution::unique_paths_iii(grid));
}

#[test]
fn test4() {
    let grid = [[1, 2].to_vec()].to_vec();
    assert_eq!(1, Solution::unique_paths_iii(grid));
}