class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> map = new HashMap<>();

        if(s.length() != t.length()) {
             return false;
        }

        char[] chars1 = s.toCharArray();
        char[] chars2 = t.toCharArray();

        int freq = 1;

        for(int i = 0; i < s.length(); i++) {
            if(map.containsKey(chars1[i])) {
                freq = map.get(chars1[i]);
                map.put(chars1[i], freq + 1);
            }
            else {
                map.put(chars1[i], 1);
            }
        }

        for(int i = 0; i < s.length(); i++) {
            if(!map.containsKey(chars2[i])) {
                return false;
            }
            freq = map.get(chars2[i]);
            map.put(chars2[i], freq - 1);
        }

        for(int i : map.values()) {
            if(i != 0) {
                return false;
            }
        }
        return true;
    }
}
