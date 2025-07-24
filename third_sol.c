int lengthOfLongestSubstring(char* s) {
    int lastIndex[128] = {0};
    int maxLen = 0;
    int start = 0;

    for (int end = 0; s[end] != '\0'; end++) {
        char c = s[end];
        if (lastIndex[(int)c] > start) {
            start = lastIndex[(int)c]; 
        }

        int currLen = end - start + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }

        lastIndex[(int)c] = end + 1;
    }

    return maxLen;
}
