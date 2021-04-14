# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 16:44:09 by rotrojan          #+#    #+#              #
#    Updated: 2021/04/14 15:42:22 by bigo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS_DIR = .objs
OBJS = $(SRCS:%.s=$(OBJS_DIR)/%.o)
NAME = libasm.a
INCLUDEDIR = includes
INCLUDES = libasm.h

AS = nasm
ASFLAGS = -f elf64
AR = ar
ARFLAGS = rcs
RM = rm -rf
MKDIR = mkdir -p
LD = ld
LDFLAGS = -m elf_x86_64 -e _start -I $(INCLUDEDIR)
CC = clang
CFLAGS = -Wall -Wextra -Werror

# Some compilation problems occurs on Arch Linux. The following lines fix it.
# This can also happen on some others distros like Gentoo. Edit the ditro name
# accordingly.
#
OS = $(shell grep ^ID= /etc/os-release | cut -d '=' -f 2)
ifeq ($(OS), arch)
	CFLAGS += -static
endif

vpath %.s srcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS_DIR)/%.o: %.s | $(OBJS_DIR)
	$(AS) $(ASFLAGS) $< -o $@

$(OBJS_DIR):
	$(MKDIR) $@

test: main.c $(NAME) $(INCLUDES:%=$(INCLUDEDIR)/%)
	$(CC) $(CFLAGS) $< -L. -lasm -I $(INCLUDEDIR) -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) test

re: fclean all
