# Author: Tanya Golovkova
# Makefile for tpmp-lab2-task3 project

	gcc -o bin/program obj/main.o obj/group.o

obj/main.o: src/main.c include/group.h | obj
	gcc -Iinclude -c src/main.c -o obj/main.o

obj/group.o: src/group.c include/group.h | obj
	gcc -Iinclude -c src/group.c -o obj/group.o

obj:
	mkdir -p obj

bin:
	mkdir -p bin

check:
	@echo "check target executed"

distcheck:
	@echo "distcheck target executed"

clean:
	rm -f obj/*.o bin/program


