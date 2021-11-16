# get_next_line
### _Функция для построчного парсинга_
- *Для компиляции*
```sh
make
```
- *Удаление объектных файлов и перекомпиляция*
```sh
make (f)clean // make re
```
- *Пример использования в main функции*


```
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
