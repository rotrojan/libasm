# libasm
42 project aiming to get familiar with assembly language.

### Rules
- 64 bits ASM. Beware of the "calling convention";
- Inline ASM is forbidden, `.s` files are madatory;
- Compilation must be done using `nasm`;
- Intel syntax, not the AT&T.

The mandatory functions to re-implement are:

- `ft_strlen` (`man 3 strlen`);
- `ft_strcpy` (`man 3 strcpy`);
- `ft_strcmp` (`man 3 strcmp`);
- `ft_write` (`man 2 write`);
- `ft_read` (`man 2 read`);
- `ft_strdup` (`man 3 strdup`, using `malloc` is allowed).

### TO DO
The bonus part include the following functions:

---
```C
int ft_atoi_base(char *str, char *b);
```
Converts the initial portion of the string pointed by `str` to int
representation. `str` is in a specific base given as a second parameter. Excepted the base rule, the function should work exactly like `atoi`. If there is an invalid argument, the function should return 0. Examples of invalid
arguments :
- base is empty or size of 1;
- base contains the same character twice ;
- base contains + or - or whitespaces;

---
The following linked list functions will use this structure:
```C
typedef struct s_list {
  void *data;
  struct s_list *next;
} t_list;
```

---
```C
void ft_list_push_front(t_list **begin_list, void *data);
```
Adds a new element of type `t_list` to the beginning of the list. It should assign `data` to the given argument. If necessary, it will update the pointer at the beginning of the list.

---
```C
int ft_list_size(t_list *begin_list);
```
Returns the number of elements in the list.

---
```C
void ft_list_sort(t_list **begin_list, int (*cmp)());
```
Sorts the elements of the list by ascending order by comparing two elements by comparing their data with a function. The function pointed by `cmp` will be used as follows:
```C
(*cmp)(list_ptr->data, list_other_ptr->data);
```
(`cmp` could be for instance `strcmp`).

---
```C
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
```
Removes from the list all elements whose `data` compared to `data_ref` using `cmp`, makes `cmp` return 0. The data from an element to be erased should be freed using `free_fct`.
Function pointed by `cmp` and by `free_fct` will be used as follows :
```C
(*cmp)(list_ptr->data, data_ref);
(*free_fct)(list_ptr->data);
```
