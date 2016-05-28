

CC=clang++
CFLAGS=-Weverything -std=c++11 -Wno-c++98-compat
LFLAGS=

SRC=./src/
TEST_SRC=./test/
TEST_MAIN=$(TEST_SRC)main.cpp
TEST_EXE=utf8test

UTF8_HEADER=$(SRC)utf8_string.hpp
UTF8_SRC=$(SRC)utf8_string.cpp

UTF8_OBJ=utf8_string.o
TEST_OBJ=main.o
OBJS=$(UTF8_OBJ) $(TEST_OBJ)

all : test


test : $(TEST_EXE)
	@echo $(TEST_EXE)" generated. "


$(TEST_EXE) : $(UTF8_OBJ) $(TEST_OBJ)
	@echo $@" - Compiling..."
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)
	@echo $@" - done."

$(UTF8_OBJ) : $(UTF8_SRC) $(UTF8_HEADER)
	@echo $<" -> "$@
	$(CC) -c $(CFLAGS) -o $@ $< $(LFLAGS)
	@echo $<" -> "$@ " done."

$(TEST_OBJ) : $(TEST_MAIN) $(UTF8_HEADER)
	@echo $<" -> "$@
	$(CC) -c $(CFLAGS) -o $@ $< $(LFLAGS)
	@echo $<" -> "$@ " done."

clean :
	rm -f $(TEST_EXE) $(OBJS)
