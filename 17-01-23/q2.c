// Q2

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isDelimiter(char ch) {
    switch (ch) {
        case ' ':
        case '+':
        case '-':
        case '*':
        case '/':
        case '=':
        case ',':
        case ';':
        case '>':
        case '<':
        case '(':
        case ')':
        case '[':
        case ']':
        case '{':
        case '}':
            return true;
        default:
            return false;
    }
}

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}

bool isKeyword(char *str) {
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
        !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

bool isInteger(char *str) {
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

bool isRealNumber(char *str) {
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

char *subString(char *str, int left, int right) {
    int i;
    char *subStr = (char *) malloc(
            sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

void parse(char *str) {
    int left = 0, right = 0;
    int len = strlen(str);
    int t = 0, k = 0;
    bool id = false, key = false;

    while (right <= len && left <= right) {
        id = false;
        key = false;
        if (isDelimiter(str[right]) == false)
            right++;

        if (isDelimiter(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true)
                id = true;

            right++;
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right
                   || (right == len && left != right)) {
            char *subStr = subString(str, left, right - 1);
            if (isKeyword(subStr) == true) {
                key = true;
            } else if (isInteger(subStr) == true
                       || isRealNumber(subStr) == true
                       || isDelimiter(str[right - 1]) == false) {
                id = true;
            }
            if (key == false && id == true)
                printf("'%s' is a TOKEN\n", subStr);

            left = right;
        }
    }
    return;
}

void readData(char* filename) {
    FILE *fp = fopen(filename, "r+");
    char x[128];
    char str[128];
    int i, k = 0;

    if (fp == NULL) printf("FILE CANNOT BE OPENED\n\n");
    else {
        printf("Reading file : %s ...\n\n", filename);

        while (fgets(x, 128, fp) != NULL) {
            fscanf(fp, "%s", &str);
            parse(str);
        }
    }
    fclose(fp);
}

int main(int argc, char** argv) {
    readData(argv[1]);
    return (0);
}
