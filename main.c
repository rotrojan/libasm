/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:30:28 by rotrojan          #+#    #+#             */
/*   Updated: 2021/04/14 16:42:20 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>

void test_strlen(void)
{
	char str[50];

	printf("===================\n");
	printf("TEST FT_STRLEN\n");
	printf("===================\n");
	printf("\n");

	bzero(&str, 50);
	strcpy(str, "yolo");
	printf("str = \"%s\"\n", str);
	printf("ft_strlen(str) = %lu\n", ft_strlen(str));
	printf("   strlen(str) = %lu\n", strlen(str));
	printf("\n");

	bzero(&str, 50);
	strcpy(str, "");
	printf("str = \"%s\"\n", str);
	printf("ft_strlen(str) = %lu\n", ft_strlen(str));
	printf("   strlen(str) = %lu\n", strlen(str));
	printf("\n");

	bzero(&str, 50);
	strcpy(str, "ilkjhgsadflkgdsflkhgsdflkuyygsdflkhbvcsadkuutf");
	printf("str = \"%s\"\n", str);
	printf("ft_strlen(str) = %lu\n", ft_strlen(str));
	printf("   strlen(str) = %lu\n", strlen(str));
}

void test_strcpy()
{
	char dest[10];
	char src1[] = "yolo";
	char src2[] = "";
	char src3[] = "ilkjhgsad";

	printf("===================\n");
	printf("TEST FT_STRCPY\n");
	printf("===================\n");
	printf("\n");

	bzero(&dest, 10);
	printf("dest = \"%s\"\n", dest);
	printf(" src = \"%s\"\n", src1);
	printf("strcpy(src, dest)\n");
	strcpy(dest, src1);
	printf("dest = \"%s\"\n", dest);
	printf(" src = \"%s\"\n", src1);
	bzero(&dest, 10);
	printf("ft_strcpy(src, dest)\n");
	ft_strcpy(dest, src1);
	printf("dest = \"%s\"\n", dest);
	printf(" src = \"%s\"\n", src1);
	printf("\n");

	bzero(&dest, 10);
	printf("dest = \"%s\"\n", dest);
	printf(" src = \"%s\"\n", src2);
	printf("strcpy(src, dest)\n");
	strcpy(dest, src2);
	printf("dest = \"%s\"\n", dest);
	printf(" src = \"%s\"\n", src2);
	bzero(&dest, 10);
	printf("ft_strcpy(src, dest)\n");
	ft_strcpy(dest, src2);
	printf("dest = \"%s\"\n", dest);
	printf(" src = \"%s\"\n", src2);
	printf("\n");

	bzero(&dest, 10);
	printf("dest = \"%s\"\n", dest);
	printf(" src = \"%s\"\n", src3);
	printf("ft_strcpy(src, dest)\n");
	ft_strcpy(dest, src3);
	printf("dest = \"%s\"\n", dest);
	printf(" src = \"%s\"\n", src3);
	bzero(&dest, 10);
	printf("strcpy(src, dest)\n");
	strcpy(dest, src3);
	printf("dest = \"%s\"\n", dest);
	printf(" src = \"%s\"\n", src3);
}

void test_strcmp()
{
	char str1[] = "yolo";
	char str2[10];

	printf("===================\n");
	printf("TEST FT_STRCMP\n");
	printf("===================\n");
	printf("\n");

	bzero(&str2, 10);
	strcpy(str2, "yolo");
	printf("str1 = \"%s\"\n", str1);
	printf("str2 = \"%s\"\n", str2);
	printf("   strcmp(str1, str2) = %i\n", strcmp(str1, str2));
	printf("ft_strcmp(str1, str2) = %i\n", ft_strcmp(str1, str2));
	printf("\n");

	bzero(&str2, 10);
	strcpy(str2, "yol0");
	printf("str1 = \"%s\"\n", str1);
	printf("str2 = \"%s\"\n", str2);
	printf("   strcmp(str1, str2) = %i\n", strcmp(str1, str2));
	printf("ft_strcmp(str1, str2) = %i\n", ft_strcmp(str1, str2));
	printf("\n");

	bzero(&str2, 10);
	strcpy(str2, "yol");
	printf("str1 = \"%s\"\n", str1);
	printf("str2 = \"%s\"\n", str2);
	printf("   strcmp(str1, str2) = %i\n", strcmp(str1, str2));
	printf("ft_strcmp(str1, str2) = %i\n", ft_strcmp(str1, str2));
	printf("\n");

	bzero(&str2, 10);
	strcpy(str2, "yoloto");
	printf("str1 = \"%s\"\n", str1);
	printf("str2 = \"%s\"\n", str2);
	printf("   strcmp(str1, str2) = %i\n", strcmp(str1, str2));
	printf("ft_strcmp(str1, str2) = %i\n", ft_strcmp(str1, str2));
}

void test_strdup()
{
	char *str;

	printf("===================\n");
	printf("TEST FT_STRDUP\n");
	printf("===================\n");
	printf("\n");

	str = ft_strdup("yolo");
	printf("str = \"%s\"\n", str);
	free(str);
	printf("\n");

	str = ft_strdup("yolo");
	printf("str = \"%s\"\n", str);
	free(str);
	printf("\n");

	str = ft_strdup("yolo");
	printf("str = \"%s\"\n", str);
	free(str);
	printf("\n");

	str = ft_strdup("yolo");
	printf("str = \"%s\"\n", str);
	free(str);
	printf("\n");
}

void test_write()
{
	char str[10];
	ssize_t ret_write;
	ssize_t ret_ft_write;

	printf("===================\n");
	printf("TEST FT_WRITE\n");
	printf("===================\n");
	printf("\n");

	bzero(&str, sizeof(str));
	strcpy(str, "Yolo");
	ret_write = write(1, str, sizeof(str));
	printf("\n");
	perror("Error");
	ret_ft_write = ft_write(1, str, sizeof(str));
	printf("\n");
	perror("Error");
	printf("ret_write    = %ld\n", ret_write);
	printf("ret_ft_write = %ld\n", ret_ft_write);
	printf("\n");

	bzero(&str, sizeof(str));
	strcpy(str, "");
	ret_write = write(1, str, sizeof(str));
	printf("\n");
	perror("Error");
	ret_ft_write = ft_write(1, str, sizeof(str));
	printf("\n");
	perror("Error");
	printf("ret_write    = %ld\n", ret_write);
	printf("ret_ft_write = %ld\n", ret_ft_write);
	printf("\n");

	bzero(&str, sizeof(str));
	strcpy(str, "Yolo");
	ret_write = write(-1, str, sizeof(str));
	printf("\n");
	perror("Error");
	ret_ft_write = ft_write(-1, str, sizeof(str));
	printf("\n");
	perror("Error");
	printf("ret_write    = %ld\n", ret_write);
	printf("ret_ft_write = %ld\n", ret_ft_write);
}

void test_read()
{
	char str[10];
	ssize_t ret_read;
	ssize_t ret_ft_read;

	printf("===================\n");
	printf("TEST FT_READ\n");
	printf("===================\n");
	printf("\n");

	bzero(&str, sizeof(str));
	ret_read = read(0, str, sizeof(str));
	printf("str = \"%s\"\n", str);
	printf("ret_read    = %ld\n", ret_read);
	perror("Error");
	bzero(&str, sizeof(str));
	ret_ft_read = ft_read(0, str, sizeof(str));
	printf("str = \"%s\"\n", str);
	printf("ret_ft_read = %ld\n", ret_ft_read);
	perror("Error");
	printf("\n");

	bzero(&str, sizeof(str));
	ret_read = read(-1, str, sizeof(str));
	printf("str = \"%s\"\n", str);
	printf("ret_read    = %ld\n", ret_read);
	perror("Error");
	bzero(&str, sizeof(str));
	ret_ft_read = ft_read(-1, str, sizeof(str));
	printf("str = \"%s\"\n", str);
	printf("ret_ft_read = %ld\n", ret_ft_read);
	perror("Error");
	printf("\n");
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	test_strlen();
	printf("\n");
	test_strcpy();
	printf("\n");
	test_strcmp();
	printf("\n");
	test_write();
	printf("\n");
	test_read();
	printf("\n");
	test_strdup();
	printf("\n");
	/* int ret = write(1, "toto", 22); */
	/* printf("ft_strlen(%s) = %zu\n", argv[1], ft_strlen(argv[1])); */
	/* printf("%d\n", ret, 57); */
	/* ft_write(1, "Hello, World !", 16); */
	/* char str2[] = "toto\0"; */
	/* printf("str1 = \"%s\"\n", str1); */
	/* printf("str2 = \"%s\"\n", str2); */
	/* printf("\n"); */
	/* ft_strcpy(str1, str2); */
	/* int ret = ft_strcmp(str1, str2); */
	/* printf("ft_strcmp = %i\n", ret); */
	/* ret = strcmp(str1, str2); */
	/* printf("   strcmp = %i\n", ret); */
	/* printf("str1 = \"%s\n", str1); */
	/* printf("str2 = \"%s\n", str2); */
	/* printf("Yolo\n"); */
	/* char *str; */

	/* str = ft_strdup(str1); */
	/* printf("toto\n"); */
	/* printf("str1 = \"%s\n", str); */
	/* free(str); */

	return (0);
}
