
PROJECT_NAME = s21_math
FLAGS = -Wall -Wextra -Werror -std=c11
CHECKFLAG = -lcheck

all: clean ${PROJECT_NAME}.a gcov_report

$(PROJECT_NAME).a:
	gcc -c $(FLAGS) $(PROJECT_NAME).c
	ar rcs $(PROJECT_NAME).a $(PROJECT_NAME).o
	ranlib $(PROJECT_NAME).a

test: clean $(PROJECT_NAME).a
	gcc $(FLAGS) $(CHECKFLAG) $(PROJECT_NAME).a $(PROJECT_NAME)_test.c -o s21_test
	./s21_test

gcov_report: 
	gcc -c $(FLAGS) $(PROJECT_NAME)_test.c
	gcc $(FLAGS) --coverage $(CHECKFLAG) $(PROJECT_NAME).c $(PROJECT_NAME)_test.o -o s21_test
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open report/index.html

clean: 
	rm -rf *.o *.a *.gcno *.gcda *.info s21_test report *.out

format:
	clang-format -style=google -i *.c *.h 


