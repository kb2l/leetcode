use std::collections::HashMap;
impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut m: HashMap<String, Vec<String>> = HashMap::new();
        for x in strs {
            let mut chars: Vec<char> = x.clone().chars().collect();
            chars.sort();
            let j: String = chars.into_iter().collect();
            if m.contains_key(&j) {
                m.get_mut(&j).unwrap().push(x.clone());
            } else {
                m.insert(j, [x.clone()].to_vec());
            }
        }
        let mut ret = Vec::new();
        m.into_iter().for_each(|x| ret.push(x.1));
        ret
    }
}