# get_next_line
### _Функция для построчного парсинга_
- *Для компиляции и запуска*
```sh
gcc -Wall -Wextra -Werror *.c -o GNL && ./GNL
```
- *Пример использования в main функции*


```
#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <printf.h>

int main(){
    char *line;
    int fd = open("txt.txt", O_RDONLY);
    
    while (get_next_line(&line, fd)){
        printf("%s\n", line);
        free(line);
    }
    printf("%s\n", line);
    free(line);
    return (0);
}
```
