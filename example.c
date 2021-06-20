/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 19:27:11 by lcandido          #+#    #+#             */
/*   Updated: 2021/06/20 18:33:59 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

static void test_gnl(int file_descriptor, char const *current_file)
{
	int gnl_return;
	int line_counter;
	char *current_line;

	printf("Testing file %s\n", current_file);
	line_counter = 0;
	while (true)
	{
		gnl_return = get_next_line(file_descriptor, &current_line);
		line_counter++;
		if (gnl_return == -1)
			break;
		printf("LINE %d: '%s'\n", line_counter, current_line);
		free(current_line);
		if (gnl_return == 0)
			break;
	}
	printf("LAST RETURN: %d\n", gnl_return);
	printf("---------------------------------------------------------------\n");
	close(file_descriptor);
}

int main(void)
{
	char const *current_file;
	int fd;
	char *buf;
	int ret;
	
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	current_file = "./examples/test1";
	fd = open(current_file, O_RDONLY);
	test_gnl(fd, current_file);

	// for(int i = 1; i < 10; i++)
	// {
	// 	ret = get_next_line(fd, &buf);
	// 	if (ret == -1)
	// 		printf("ERRO: '%d'\n", ret);
	// 	if (ret == 0)
	// 		break;
	// 	else
	// 		printf("LINE %d:'%s'\n", i, buf);
	// 	free(buf);
	// }
	// current_file = "./examples/example_files/test2";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/test3";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/test4";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/test5";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/test6";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/test7";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/41_no_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/41_with_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/42_no_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/42_with_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/43_no_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/43_with_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/alternate_line_nl_no_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/alternate_line_nl_with_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/big_line_no_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/big_line_with_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/empty";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/multiple_line_no_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/multiple_line_with_nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/multiple_nlx5";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	// current_file = "./examples/example_files/nl";
	// current_file_descriptor = open(current_file, O_RDONLY);
	// test_gnl(current_file_descriptor, current_file);

	return (0);
}
