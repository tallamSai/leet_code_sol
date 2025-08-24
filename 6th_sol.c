char* convert(char* s, int numRows) {
    if (numRows == 1) return s;  // No zigzag needed

    int len = strlen(s);
    int cycle = 2 * numRows - 2;
    
    // Allocate buffer for result (+1 for null terminator)
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int k = 0;

    for (int row = 0; row < numRows; row++) {
        for (int j = row; j < len; j += cycle) {
            res[k++] = s[j];  // vertical element

            // diagonal element (not first/last row)
            int diag = j + cycle - 2 * row;
            if (row != 0 && row != numRows - 1 && diag < len) {
                res[k++] = s[diag];
            }
        }
    }

    res[k] = '\0';
    return res;
}
