CC=g++
# modify with your path to MyVector.h/MyIterator.h
HEADER_PATH=../
CFLAGS=-Wall -Wextra -g

CXXFLAGS=$(CFLAGS) -I$(HEADER_PATH)
build: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

test1: test1.o
	$(CC) $(CFLAGS) $< -o $@

test2: test2.o
	$(CC) $(CFLAGS) $< -o $@

test3: test3.o
	$(CC) $(CFLAGS) $< -o $@

test4: test4.o
	$(CC) $(CFLAGS) $< -o $@

test5: test5.o
	$(CC) $(CFLAGS) $< -o $@

test6: test6.o
	$(CC) $(CFLAGS) $< -o $@

test7: test7.o
	$(CC) $(CFLAGS) $< -o $@

test8: test8.o
	$(CC) $(CFLAGS) $< -o $@

test9: test9.o
	$(CC) $(CFLAGS) $< -o $@

test10: test10.o
	$(CC) $(CFLAGS) $< -o $@

test1.o: test1.cpp ${HEADER_PATH}/MyVector.h ${HEADER_PATH}/MyIterator.h

test2.o: test2.cpp $(HEADER_PATH)/MyVector.h $(HEADER_PATH)/MyIterator.h

test3.o: test3.cpp $(HEADER_PATH)/MyVector.h $(HEADER_PATH)/MyIterator.h

test4.o: test4.cpp $(HEADER_PATH)/MyVector.h $(HEADER_PATH)/MyIterator.h

test5.o: test5.cpp $(HEADER_PATH)/MyVector.h $(HEADER_PATH)/MyIterator.h

test6.o: test6.cpp $(HEADER_PATH)/MyVector.h $(HEADER_PATH)/MyIterator.h

test7.o: test7.cpp $(HEADER_PATH)/MyVector.h $(HEADER_PATH)/MyIterator.h

test8.o: test8.cpp $(HEADER_PATH)/MyVector.h $(HEADER_PATH)/MyIterator.h

test9.o: test9.cpp $(HEADER_PATH)/MyVector.h $(HEADER_PATH)/MyIterator.h

test10.o: test10.cpp $(HEADER_PATH)/MyVector.h $(HEADER_PATH)/MyIterator.h

clean:
	rm -rf *.o test1 test2 test3 test4 test5 test6 test7 test8 test9 test10
