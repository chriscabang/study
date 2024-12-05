#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_invalid_parentheses(const char* s, int* size) {
  for(int i = 0; i < (int) *size; i++) {
    char* _s = (char*) malloc(*size * sizeof(char)); 
    memcpy(_s, s, *size);
    memmove(_s + i, s + i + 1, *size);
    int _size = 0; while(_s[_size] != 0) _size += 1;
    printf("[%d] %s = ", _size, _s);
    int o = 0, c = 0;
    for(int n = 0; n < _size; n++) {
      if (_s[n] == '(') {
        o++;
      } else if (_s[n] == ')') {
        c++;
      } else {
        continue;
      }

      if (c > o) break;
    }
    printf("%d:%d ", o, c);
    if (o == c) printf("valid");
    printf("\n");
    free(_s);
    _s = 0;
  }
}

int main() {
  const char* s =
    "(a)())()"
    ;
  int size = 0; while(s[size] != 0) size += 1;
  printf("[%d] %s :\n", size, s);
  remove_invalid_parentheses(s, &size);
  return 0;
}

