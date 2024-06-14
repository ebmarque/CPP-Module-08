# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 20:14:25 by ebmarque          #+#    #+#              #
#    Updated: 2024/06/14 22:05:46 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyFind
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g


SRC_DIR = sources
OBJ_DIR = objects
INCLUDE_DIR = includes


SRCS = $(addprefix $(SRC_DIR)/, main.cpp )


OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))



# Colors
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n"
	@echo "$(GREEN)Linking object files...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^ -I$(INCLUDE_DIR)
	@echo "$(GREEN)$(NAME) successfully compiled!$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@printf "\033[K$(GREEN)Compiling $< ...$(NC)\r"
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR)

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re